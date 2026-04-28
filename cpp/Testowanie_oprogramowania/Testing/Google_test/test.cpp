#include "pch.h"
#include <gtest/gtest.h>
#include "SpeedFormatter.hpp"
#include "SpeedSource.hpp"
#include "Units.hpp"
#include <thread>
#include <chrono>

// Test fixture for SpeedFormatter tests
class SpeedFormatterTest : public ::testing::Test
{
protected:
	SpeedSource speedSource;
	Units units;
	SpeedFormatter formatter{&speedSource, &units, 1};
};

// ============================================================================
// R1 Tests - Rounding (speed >= 5 rounds up, < 5 rounds down)
// ============================================================================

TEST_F(SpeedFormatterTest, R1_RoundDown_WhenDecimalPartLessThan5)
{
	speedSource.setSpeed(10.4);
	EXPECT_EQ(formatter.getFormattedSpeed(), 10);
}

TEST_F(SpeedFormatterTest, R1_RoundDown_WhenDecimalPartIs0)
{
	speedSource.setSpeed(15.0);
	EXPECT_EQ(formatter.getFormattedSpeed(), 15);
}

TEST_F(SpeedFormatterTest, R1_RoundUp_WhenDecimalPartIs5)
{
	speedSource.setSpeed(10.5);
	EXPECT_EQ(formatter.getFormattedSpeed(), 11);
}

TEST_F(SpeedFormatterTest, R1_RoundUp_WhenDecimalPartGreaterThan5)
{
	speedSource.setSpeed(20.7);
	EXPECT_EQ(formatter.getFormattedSpeed(), 21);
}

TEST_F(SpeedFormatterTest, R1_RoundUp_WhenDecimalPartIs9)
{
	speedSource.setSpeed(5.9);
	EXPECT_EQ(formatter.getFormattedSpeed(), 6);
}

TEST_F(SpeedFormatterTest, R1_RoundDown_VerySmallDecimal)
{
	speedSource.setSpeed(100.1);
	EXPECT_EQ(formatter.getFormattedSpeed(), 100);
}

// ============================================================================
// R2 Tests - Current unit of measurement shall be used
// ============================================================================

TEST_F(SpeedFormatterTest, R2_UsesKPH_ByDefault)
{
	speedSource.setSpeed(50.0);
	EXPECT_EQ(units.getSpeedUnit(), SpeedUnit::KPH);
	EXPECT_EQ(formatter.getFormattedSpeed(), 50);
}

TEST_F(SpeedFormatterTest, R2_UsesCurrentUnit_WhenKPH)
{
	units.setSpeedUnit(SpeedUnit::KPH);
	speedSource.setSpeed(100.3);
	EXPECT_EQ(formatter.getFormattedSpeed(), 100);
}

TEST_F(SpeedFormatterTest, R2_UsesCurrentUnit_WhenMPH)
{
	units.setSpeedUnit(SpeedUnit::MPH);
	speedSource.setSpeed(60.7);
	EXPECT_EQ(formatter.getFormattedSpeed(), 61);
}

TEST_F(SpeedFormatterTest, R2_SwitchesUnits_MidOperation)
{
	speedSource.setSpeed(50.4);
	units.setSpeedUnit(SpeedUnit::KPH);
	unsigned int speedInKPH = formatter.getFormattedSpeed();

	units.setSpeedUnit(SpeedUnit::MPH);
	unsigned int speedInMPH = formatter.getFormattedSpeed();

	// Both should use the respective unit without conversion
	EXPECT_EQ(speedInKPH, 50);
	EXPECT_EQ(speedInMPH, 50);
}

// ============================================================================
// R3 Tests - Small speed changes (< 2) delay update by 1 second
//            Large speed changes (>= 2) update immediately
// ============================================================================

TEST_F(SpeedFormatterTest, R3_LargeChange_UpdatesImmediately)
{
	speedSource.setSpeed(10.0);
	unsigned int initial = formatter.getFormattedSpeed();

	// Change by 3 (>= 2, should update immediately)
	speedSource.setSpeed(13.0);
	unsigned int updated = formatter.getFormattedSpeed();

	EXPECT_EQ(initial, 10);
	EXPECT_EQ(updated, 13);
}

TEST_F(SpeedFormatterTest, R3_SmallChange_NoImmediateUpdate)
{
	speedSource.setSpeed(10.0);
	unsigned int initial = formatter.getFormattedSpeed();

	// Change by 1 (< 2, should not update immediately)
	speedSource.setSpeed(11.0);
	unsigned int stillOld = formatter.getFormattedSpeed();

	EXPECT_EQ(initial, 10);
	EXPECT_EQ(stillOld, 10); // Still shows old value
}

TEST_F(SpeedFormatterTest, R3_SmallChange_UpdatesAfter1Second)
{
	speedSource.setSpeed(10.0);
	formatter.getFormattedSpeed(); // Initialize with 10

	// Change by 1 (< 2)
	speedSource.setSpeed(11.0);
	unsigned int beforeWait = formatter.getFormattedSpeed();
	EXPECT_EQ(beforeWait, 10); // Still old value

	// Wait 1 second
	std::this_thread::sleep_for(std::chrono::seconds(1));
	unsigned int afterWait = formatter.getFormattedSpeed();
	EXPECT_EQ(afterWait, 11); // Now updated
}

TEST_F(SpeedFormatterTest, R3_MultipleSmallChanges_ResetTimer)
{
	speedSource.setSpeed(10.0);
	formatter.getFormattedSpeed();

   // First small change
	speedSource.setSpeed(10.5);
	EXPECT_EQ(formatter.getFormattedSpeed(), 10);

	// Second small change (timer should reset)
	speedSource.setSpeed(11.0);
	unsigned int stillOld = formatter.getFormattedSpeed();
	EXPECT_EQ(stillOld, 10);

    // Wait long enough from the last change
	std::this_thread::sleep_for(std::chrono::milliseconds(1100));
	unsigned int afterWait = formatter.getFormattedSpeed();
	EXPECT_EQ(afterWait, 11);
}

TEST_F(SpeedFormatterTest, R3_ExactBoundary_2IsLargeChange)
{
	speedSource.setSpeed(10.0);
	formatter.getFormattedSpeed();

	// Change by exactly 2 (should update immediately)
	speedSource.setSpeed(12.0);
	unsigned int updated = formatter.getFormattedSpeed();

	EXPECT_EQ(updated, 12); // Should update immediately
}

TEST_F(SpeedFormatterTest, R3_JustUnder2_IsSmallChange)
{
	speedSource.setSpeed(10.0);
	formatter.getFormattedSpeed();

    // Change by 1.4 (< 2, should delay)
	speedSource.setSpeed(11.4);
	unsigned int beforeWait = formatter.getFormattedSpeed();
	EXPECT_EQ(beforeWait, 10); // Still old value

    // Wait long enough for the delayed update
	std::this_thread::sleep_for(std::chrono::milliseconds(1100));
	unsigned int afterWait = formatter.getFormattedSpeed();
    EXPECT_EQ(afterWait, 11); // Now updated (11.4 rounds to 11)
}

TEST_F(SpeedFormatterTest, R3_ZeroChange_NoUpdate)
{
	speedSource.setSpeed(50.0);
	formatter.getFormattedSpeed();

	// No change in speed
	unsigned int result = formatter.getFormattedSpeed();
	EXPECT_EQ(result, 50); // Should return same value
}

// ============================================================================
// Combined Tests - Multiple requirements together
// ============================================================================

TEST_F(SpeedFormatterTest, R1R2R3_Combined_RoundingWithUnitAndDelay)
{
	units.setSpeedUnit(SpeedUnit::KPH);
	speedSource.setSpeed(50.4);
	EXPECT_EQ(formatter.getFormattedSpeed(), 50); // R1: rounds down

	// Small change
	speedSource.setSpeed(51.2);
	EXPECT_EQ(formatter.getFormattedSpeed(), 50); // R3: no immediate update

	std::this_thread::sleep_for(std::chrono::seconds(1));
	EXPECT_EQ(formatter.getFormattedSpeed(), 51); // R1: now rounded to 51, R3: updated after 1s
}

TEST_F(SpeedFormatterTest, R1R2R3_LargeChangeBypassesDelay)
{
	speedSource.setSpeed(50.0);
	formatter.getFormattedSpeed();

	// Large change
	speedSource.setSpeed(60.0);
	unsigned int result = formatter.getFormattedSpeed();

	EXPECT_EQ(result, 60); // R3: updates immediately, R1: already integer
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
