#!/bin/bash

set -e

# Default options
RUN_TIDY=false
RUN_CSA=false
BUILD_DIR="build"
REPORT_DIR="build/reports"

# Create output directory
mkdir -p "$REPORT_DIR"

# Parse arguments
for arg in "$@"; do
  case $arg in
    --tidy)
      RUN_TIDY=true
      shift
      ;;
    --csa)
      RUN_CSA=true
      shift
      ;;
    *)
      echo "Unknown option: $arg"
      exit 1
      ;;
  esac
done

# Run clang-tidy
if [ "$RUN_TIDY" = true ]; then
  echo "Running clang-tidy..."

  FILES=$(find src include -name '*.cpp' -o -name '*.hpp')

  clang-tidy $FILES \
    -p "$BUILD_DIR" \
    --quiet \
    > "$REPORT_DIR/clang-tidy.txt" 2>&1

  echo "Clang-tidy complete. Report saved to $REPORT_DIR/clang-tidy.txt"
fi

# Run analyze-build (Clang Static Analyzer)
if [ "$RUN_CSA" = true ]; then
  echo "Running Clang Static Analyzer..."

  analyze-build \
    --cdb "$BUILD_DIR/compile_commands.json" \
    --use-analyzer "$(which clang)" \
    --output "$REPORT_DIR"

  echo "CSA complete. Report saved to $REPORT_DIR/index.html"
fi

if [ "$RUN_TIDY" = false ] && [ "$RUN_CSA" = false ]; then
  echo "No analysis type specified. Use --tidy and/or --csa"
  exit 1
fi
