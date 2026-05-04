#include <gtest/gtest.h>
#include "SpeedFormatter.hpp"
#include "SpeedSource.hpp"
// #include "MockUnits.hpp" // Jeśli używasz mocków

// R1 - Test zaokrąglania
TEST(SpeedFormatterTest, ShouldRoundSpeedCorrectlty) {
    // Przykład: 10.4 -> 10, 10.5 -> 11
    // Zakładając, że SpeedFormatter ma metodę format(double speed)
    // SpeedFormatter formatter;
    // EXPECT_EQ(formatter.formatAsInt(10.4), 10);
    // EXPECT_EQ(formatter.formatAsInt(10.5), 11);
}

// R2 - Test użycia aktualnej jednostki
TEST(SpeedFormatterTest, ShouldUseCurrentUnit) {
    // Sprawdź czy przy zmianie jednostki w UnitsInterface, 
    // formatter zwraca poprawną wartość (np. km/h vs mph)
}

// R3 - Test histerezy i czasu (Small change vs Big change)
TEST(SpeedSourceTest, ShouldHandleSmallChangesWithDelay) {
    // 1. Ustaw prędkość na 50
    // 2. Zmień na 51.5 (różnica < 2) -> Prędkość powinna nadal być 50
    // 3. Odczekaj 1 sekundę (możesz użyć symulacji czasu lub sleep)
    // 4. Prędkość powinna zmienić się na 51.5 (zaokrąglone zgodnie z R1)
}

TEST(SpeedSourceTest, ShouldUpdateImmediatelyForBigChanges) {
    // 1. Ustaw prędkość na 50
    // 2. Zmień na 53 (różnica > 2)
    // 3. Prędkość powinna zmienić się natychmiast
}