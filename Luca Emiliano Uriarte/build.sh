#!/bin/bash

set -e  # Termina el script si algún comando falla

echo "Configuring project with CMake..."
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug

echo "Building project..."
cd build
make

echo "Build complete!"