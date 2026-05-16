#!/usr/bin/env bash
set -euo pipefail

# Simple coverage HTML generator.
# Usage: scripts/coverage/coverage_report.sh [build_dir]
# This script DOES NOT run cmake or build; it expects coverage data (.gcda/.gcno) to already exist in build_dir.
# If ZERO_COUNTERS=1 is set in the environment, lcov --zerocounters will be run before capture.

REQUESTED_DIR="${1:-}"

if [ -n "$REQUESTED_DIR" ]; then
  BUILD_DIR="$REQUESTED_DIR"
else
  # try to find any .gcda/.gcno and use its directory
  GCDA_PATH=$(find . -type f \( -name '*.gcda' -o -name '*.gcno' \) -print -quit || true)
  if [ -n "$GCDA_PATH" ]; then
    BUILD_DIR=$(dirname "$GCDA_PATH")
  else
    BUILD_DIR="."
  fi
fi

OUT_INFO="$BUILD_DIR/coverage.info"
CLEAN_INFO="$BUILD_DIR/coverage_cleaned.info"
HTML_DIR="$BUILD_DIR/coverage_report"

echo "Generating coverage HTML from build dir: $BUILD_DIR"

command -v lcov >/dev/null 2>&1 || { echo "lcov not found. Install lcov."; exit 1; }
command -v genhtml >/dev/null 2>&1 || { echo "genhtml not found. Install genhtml (part of lcov)."; exit 1; }

if [ ! -d "$BUILD_DIR" ]; then
  echo "Build directory '$BUILD_DIR' does not exist. Run cmake and build first."; exit 1
fi

# Ensure there are coverage data files
GC_COUNT=$(find "$BUILD_DIR" -type f \( -name '*.gcda' -o -name '*.gcno' \) | wc -l || true)
if [ "${GC_COUNT:-0}" -eq 0 ]; then
  echo "No .gcda or .gcno files found under '$BUILD_DIR'. Nothing to capture."; exit 1
fi

# Optionally zero counters if requested by environment
if [ "${ZERO_COUNTERS:-0}" != "0" ]; then
  echo "Zeroing coverage counters in $BUILD_DIR"
  lcov --directory "$BUILD_DIR" --zerocounters --rc lcov_branch_coverage=1
fi

echo "Capturing coverage..."
# Use correct rc key to enable branch coverage in lcov
lcov --capture --directory "$BUILD_DIR" --output-file "$OUT_INFO" --rc lcov_branch_coverage=1

echo "Filtering coverage..."
# Be conservative when removing files from report
lcov --remove "$OUT_INFO" '/usr/*' '*/CMakeFiles/*' '*/tests/*' '*/test/*' --output-file "$CLEAN_INFO" --rc lcov_branch_coverage=1

echo "Generating HTML..."
rm -rf "$HTML_DIR"
mkdir -p "$HTML_DIR"

genhtml "$CLEAN_INFO" --output-directory "$HTML_DIR" --branch-coverage

echo "Coverage HTML generated at: $HTML_DIR/index.html"
