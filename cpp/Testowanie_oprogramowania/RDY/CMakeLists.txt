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
    test_gmock.cpp
    test.cpp
)

include_directories(${CMAKE_SOURCE_DIR})

# 1. Flagi kompilacji dla Branch Coverage
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    # -fprofile-arcs -ftest-coverage to odpowiedniki --coverage, ale dodajemy jawnie
    # fno-elide-constructors pomaga w dokładniejszym śledzeniu linii
    add_compile_options(--coverage -O0 -g -fprofile-arcs -ftest-coverage)
    add_link_options(--coverage)
endif()

add_executable(run_tests ${SOURCES})

target_link_libraries(run_tests
    GTest::GTest
    GTest::Main
    GTest::gmock_main
    GTest::gmock
    pthread
)

# 2. Automatyzacja Branch Coverage (Custom Target)
find_program(LCOV_PATH lcov)
find_program(GENHTML_PATH genhtml)

if(LCOV_PATH AND GENHTML_PATH)
    add_custom_target(coverage
        # Zerowanie liczników
        COMMAND ${LCOV_PATH} --directory . --zerocounters
        
        # Uruchomienie testów
        COMMAND ./run_tests
        
        # Zbieranie danych Z FLAGĄ --rc lcov_branch_coverage=1 (Wymusza Branch Coverage)
        COMMAND ${LCOV_PATH} --directory . --capture --output-file coverage.raw 
                --rc lcov_branch_coverage=1 --ignore-errors inconsistent
        
        # Filtrowanie raportu (również z obsługą rozgałęzień)
        COMMAND ${LCOV_PATH} --remove coverage.raw '/usr/*' '*/CMakeFiles/*' '*/test*' 
                --output-file coverage.info --rc lcov_branch_coverage=1 --ignore-errors inconsistent
        
        # Generowanie HTML z widocznymi rozgałęzieniami (--branch-coverage)
        COMMAND ${GENHTML_PATH} coverage.info --output-directory coverage_report 
                --branch-coverage --ignore-errors inconsistent
        
        COMMAND ; echo "Raport Branch Coverage gotowy: build/coverage_report/index.html"
        
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
endif()