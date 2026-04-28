#!/bin/bash

# Clean previous coverage data
rm -rf coverage.info coverage_report CMakeFiles

# Create build directory
mkdir -p build_coverage
cd build_coverage

# Configure with coverage flags
cmake -DCMAKE_BUILD_TYPE=Coverage ..

# Build
make -j$(nproc)

# Run all tests
echo "Running tests..."
ctest --output-on-failure

# Generate coverage data
echo "Generating coverage report..."

# Collect coverage data
lcov -c -d . -o coverage.info --no-external

# Remove test files from coverage
lcov -r coverage.info '*/tests/*' -o coverage.info

# Remove gtest files
lcov -r coverage.info '/usr/*' -o coverage.info

# Generate HTML report
genhtml coverage.info -o coverage_report

echo "Coverage report generated in build_coverage/coverage_report/index.html"

# Show summary
lcov --list coverage.info

cd ..