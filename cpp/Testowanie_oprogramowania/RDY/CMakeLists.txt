cmake_minimum_required(VERSION 3.10)
project(SpeedSensorSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(PROD_SOURCES
    SpeedSource.cpp
    SpeedFormatter.cpp
)

set(TEST_SOURCES
    test_gmock.cpp
)

include_directories(${CMAKE_SOURCE_DIR})

# 1. Flagi kompilacji dla Branch Coverage
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    # -fprofile-arcs -ftest-coverage to odpowiedniki --coverage, ale dodajemy jawnie
    # fno-elide-constructors pomaga w dokładniejszym śledzeniu linii
    add_compile_options(--coverage -O0 -g -fprofile-arcs -ftest-coverage)
    add_link_options(--coverage)
endif()

add_library(speedcore STATIC ${PROD_SOURCES})
target_include_directories(speedcore PUBLIC ${CMAKE_SOURCE_DIR})

add_executable(run_tests ${TEST_SOURCES})

target_link_libraries(run_tests
    speedcore
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

        # Zbieranie danych (włącz branch coverage) i ignorowanie znanych warningów
        COMMAND ${LCOV_PATH} --directory . --capture --output-file coverage.raw --rc branch_coverage=1 --ignore-errors mismatch,deprecated,inconsistent,unused

        # Filtrowanie raportu (zapis do coverage_cleaned.info). --ignore-errors by nie kończyło się błędem gdy wzorce nie pasują
        COMMAND ${LCOV_PATH} --remove coverage.raw '/usr/*' '*/test*' --output-file coverage_cleaned.info --rc branch_coverage=1 --ignore-errors mismatch,deprecated,inconsistent,unused

        # Usuń stary katalog HTML i utwórz nowy
        COMMAND ${CMAKE_COMMAND} -E remove_directory coverage_report
        COMMAND ${CMAKE_COMMAND} -E make_directory coverage_report

        # Generowanie HTML z widocznymi rozgałęzieniami (--branch-coverage)
        COMMAND ${GENHTML_PATH} coverage_cleaned.info --output-directory coverage_report --branch-coverage --ignore-errors mismatch,deprecated,inconsistent,unused

        COMMAND ${CMAKE_COMMAND} -E echo "Raport Branch Coverage gotowy: ${CMAKE_BINARY_DIR}/coverage_report/index.html"

        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
endif()
