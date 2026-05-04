cmake_minimum_required(VERSION 3.10)
project(SpeedSensorSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Szukanie Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Pliki źródłowe - ZMIENIONE: usuwamy Units.cpp
set(SOURCES
    SpeedSource.cpp
    SpeedFormatter.cpp
    test.cpp
)

# Plik wykonywalny
add_executable(run_tests ${SOURCES})

# Linkowanie bibliotek
target_link_libraries(run_tests 
    GTest::GTest 
    GTest::Main 
    pthread
)