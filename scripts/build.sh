#!/bin/bash

# Exit error
set -e

# Default flags
COVERAGE=false
ANALYZE=false

# Parse arguments
for arg in "$@"; do
  case $arg in
    --coverage)
      COVERAGE=true
      shift
      ;;
    --analyze)
      ANALYZE=true
      shift
      ;;
    *)
      echo "Unknown option: $arg"
      echo "Usage: $0 [--coverage] [--analyze]"
      exit 1
      ;;
  esac
done

# Compiler settings
CXX_COMPILER="clang++"
CMAKE_FLAGS="-DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=$CXX_COMPILER"
CMAKE_FLAGS+=" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON"

if [ "$COVERAGE" = true ]; then
  COVERAGE_OPTS="--coverage -fprofile-instr-generate -fcoverage-mapping"
  CMAKE_FLAGS+=" -DCMAKE_CXX_FLAGS=\"${COVERAGE_OPTS}\""
  CMAKE_FLAGS+=" -DCMAKE_EXE_LINKER_FLAGS=--coverage"
  CMAKE_FLAGS+=" -DCMAKE_SHARED_LINKER_FLAGS=--coverage"
  CMAKE_FLAGS+=" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON"
fi

BUILD_DIR="build"

# Clean and create build directory
#rm -rf "$BUILD_DIR"
mkdir -p "$BUILD_DIR"

# Run CMake configure step
if [ "$ANALYZE" = true ]; then
  echo "Running scan-build static analysis..."

  export CC=/opt/homebrew/opt/llvm/bin/clang
  export CXX=/opt/homebrew/opt/llvm/bin/clang++

  SCAN_BUILD_OPTS="-v --status-bugs --keep-empty -o $BUILD_DIR/reports"

  cmake -B "$BUILD_DIR" -S . $CMAKE_FLAGS
  scan-build $SCAN_BUILD_OPTS cmake --build "$BUILD_DIR"

  analyze-build \
  --cdb build/compile_commands.json \
  --use-analyzer /opt/homebrew/opt/llvm/bin/clang \
  --output build/reports


  echo "Static analysis complete. Reports saved in $BUILD_DIR/reports/"
else
  echo "Configuring and building project..."
  eval cmake -B "$BUILD_DIR" -S . $CMAKE_FLAGS
  cmake --build "$BUILD_DIR"
  echo "Build complete in $BUILD_DIR/"
fi
