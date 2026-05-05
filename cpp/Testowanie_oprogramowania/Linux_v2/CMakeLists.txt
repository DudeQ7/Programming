cmake_minimum_required(VERSION 3.10)
project(SpeedSensorSystem)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set(SOURCES
    SpeedSource.cpp
    SpeedFormatter.cpp
    TestValues.cpp
    gTest/test_gmock.cpp
)
include_directories(${CMAKE_SOURCE_DIR}/gTest)
include_directories(${CMAKE_SOURCE_DIR})
add_executable(run_tests ${SOURCES})
target_link_libraries(run_tests 
    GTest::GTest 
    GTest::Main 
    GTest::gmock_main
    GTest::gmock
    pthread
)