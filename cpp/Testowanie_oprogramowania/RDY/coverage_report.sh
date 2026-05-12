#!/usr/bin/env bash
set -euo pipefail

# Run coverage generation inside build directory to avoid polluting repo root.
# Usage: ./coverage_report.sh [build_dir]

BUILD_DIR="${1:-build}"

echo "Using build dir: $BUILD_DIR"
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

# Configure if needed
if [ ! -f CMakeCache.txt ]; then
  echo "Configuring project with cmake .."
  cmake ..
fi

# Build
echo "Building project (make -j)"
make -j || make || true

# Prefer CMake-provided 'coverage' target if it exists
if make -n coverage >/dev/null 2>&1; then
  echo "Running 'make coverage'"
  make coverage
  echo "Coverage target finished. See: $BUILD_DIR/coverage_report/index.html"
  exit 0
fi

# Fallback: run tests and generate coverage via lcov/genhtml
LCOV_BIN=$(command -v lcov || true)
GENHTML_BIN=$(command -v genhtml || true)

if [ -z "$LCOV_BIN" ] || [ -z "$GENHTML_BIN" ]; then
  echo "lcov or genhtml not found in PATH. Install lcov."
  exit 1
fi

# Zero counters
$LCOV_BIN --directory . --zerocounters

# Run tests (expecting test binary at ./run_tests or ./runTests)
if [ -x ./run_tests ]; then
  ./run_tests
elif [ -x ./runTests ]; then
  ./runTests
else
  echo "No test binary found in $PWD. Build tests first."
  exit 1
fi

# Capture coverage
$LCOV_BIN --directory . --capture --output-file coverage.raw --rc lcov_branch_coverage=1 --ignore-errors inconsistent || true

# Remove system and test files
$LCOV_BIN --remove coverage.raw '/usr/*' '*/CMakeFiles/*' '*/test*' --output-file coverage_cleaned.info --rc lcov_branch_coverage=1 --ignore-errors inconsistent || true

# Recreate HTML directory
cmake -E remove_directory coverage_report
cmake -E make_directory coverage_report

# Generate HTML
$GENHTML_BIN coverage_cleaned.info --output-directory coverage_report --branch-coverage --ignore-errors inconsistent

echo "HTML report generated at: $PWD/coverage_report/index.html"
exit 0
