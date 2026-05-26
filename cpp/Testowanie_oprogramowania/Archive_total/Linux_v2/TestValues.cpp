#include "TestValues.hpp"
#include <limits>

// Test value constants used by tests R1, R2, R3.
// To intentionally break tests, edit the values below or the mocked returns in gTest/test_gmock.cpp:
//  - R1 (rounding): change the rounding source values in gTest/test_gmock.cpp (10.4/10.5) or the hardcoded values in test.cpp (10.4/10.5).
//  - R2 (unit conversion): change TV_units_multiplier_kph or TV_units_multiplier_mph here, or alter mocked getMultiplier() in gTest/test_gmock.cpp.
//  - R3 (hysteresis): change TV_speed_initial, TV_speed_small_change, TV_speed_big_change here to values that violate hysteresis thresholds.

const double TV_speed_initial = 50.0;
const double TV_speed_small_change = 51.5;
const double TV_speed_big_change = 53.0;
const double TV_units_multiplier_kph = 1.0;
const double TV_units_multiplier_mph = 0.621371;
