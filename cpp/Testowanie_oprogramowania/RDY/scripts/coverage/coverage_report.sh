#!/usr/bin/env bash
set -euo pipefail

# Simple coverage HTML generator.
# Usage: scripts/coverage/coverage_report.sh [build_dir]
# This script DOES NOT run cmake or build; it expects coverage data (.gcda/.gcno) to already exist in build_dir.

BUILD_DIR="${1:-build}"
OUT_INFO="$BUILD_DIR/coverage.info"
CLEAN_INFO="$BUILD_DIR/coverage_cleaned.info"
HTML_DIR="$BUILD_DIR/coverage_report"

echo "Generating coverage HTML from build dir: $BUILD_DIR"

command -v lcov >/dev/null 2>&1 || { echo "lcov not found. Install lcov."; exit 1; }
command -v genhtml >/dev/null 2>&1 || { echo "genhtml not found. Install genhtml (part of lcov)."; exit 1; }

if [ ! -d "$BUILD_DIR" ]; then
  echo "Build directory '$BUILD_DIR' does not exist. Run cmake and build first."; exit 1
fi

# Capture coverage from build dir (will collect .gcda files therein)
# ignore-errors to avoid hard failure if some paths mismatch
lcov --capture --directory "$BUILD_DIR" --output-file "$OUT_INFO" --rc branch_coverage=1 --ignore-errors mismatch,deprecated,inconsistent || true

# Remove system and test files from report
lcov --remove "$OUT_INFO" '/usr/*' '*/CMakeFiles/*' '*/test*' --output-file "$CLEAN_INFO" --rc branch_coverage=1 --ignore-errors mismatch,deprecated,inconsistent || true

# Recreate HTML dir
rm -rf "$HTML_DIR"
mkdir -p "$HTML_DIR"

# Generate HTML
genhtml "$CLEAN_INFO" --output-directory "$HTML_DIR" --branch-coverage --ignore-errors missing,inconsistent || true

echo "Coverage HTML generated at: $HTML_DIR/index.html"
