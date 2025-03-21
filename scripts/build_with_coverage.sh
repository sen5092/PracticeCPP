#!/bin/bash

# Exit error
set -e

BUILD_DIR="build"

# Make sure the build directory exists
mkdir -p $BUILD_DIR

# Run CMake with coverage flags
cmake -B "$BUILD_DIR" \
    -DCMAKE_BUILD_TYPE=Debug \
    -DCMAKE_CXX_COMPILER=clang++ \
    -DCMAKE_CXX_FLAGS="--coverage -fprofile-instr-generate -fcoverage-mapping" \
    -DCMAKE_EXE_LINKER_FLAGS="--coverage" \
    -DCMAKE_SHARED_LINKER_FLAGS="--coverage"

# Build the project
cmake --build "$BUILD_DIR"

echo "Build complete with coverage."