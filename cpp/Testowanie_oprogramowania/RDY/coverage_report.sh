#!/usr/bin/env bash
set -euo pipefail

# Usage: ./coverage_report.sh [build_dir] [out_info] [clean_info] [html_dir]
# Defaults: build, coverage.info, coverage_cleaned.info, coverage_report

BUILD_DIR="${1:-build}"
OUT_INFO="${2:-${BUILD_DIR}/coverage.info}"
CLEAN_INFO="${3:-${BUILD_DIR}/coverage_cleaned.info}"
HTML_DIR="${4:-${BUILD_DIR}/coverage_report}"

# Ensure required tools are available
command -v lcov >/dev/null 2>&1 || { echo "lcov not found. Install lcov."; exit 1; }
command -v genhtml >/dev/null 2>&1 || { echo "genhtml not found. Install lcov (genhtml)."; exit 1; }

echo "Capturing coverage data from directory: $BUILD_DIR -> $OUT_INFO"
# Enable branch coverage support if lcov was built with it
lcov --capture --directory "$BUILD_DIR" --output-file "$OUT_INFO" --ignore-errors inconsistent,deprecated,mismatch --rc branch_coverage=1

echo "Removing unwanted files from coverage: /usr/* and CMakeFiles and tests -> $CLEAN_INFO"
lcov --remove "$OUT_INFO" '/usr/*' '*/CMakeFiles/*' '*/test_gmock.cpp' '*/test.cpp' --output-file "$CLEAN_INFO" --ignore-errors inconsistent,deprecated,unused --rc branch_coverage=1

echo "Cleaning previous HTML output: $HTML_DIR"
rm -rf "$HTML_DIR"
mkdir -p "$HTML_DIR"

echo "Generating HTML report in: $HTML_DIR"
genhtml "$CLEAN_INFO" --output-directory "$HTML_DIR" --branch-coverage

echo "Done. Open $HTML_DIR/index.html in a browser to view the report."