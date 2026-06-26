#!/bin/bash

includes="-Iinclude -Isrc"
defines=""
warnings="-Wno-writable-strings -Wno-format-security"

if [[ "$(uname)" == "Linux" ]]; then
    echo "Building for Linux..."
    libs="-Llib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11"
    outputFile="bin/main"

elif [[ "$(uname)" == "Darwin" ]]; then
    echo "Building for macOS..."
    libs="-Llib -lraylib -lGL -lm"
    outputFile="bin/main"

else
    echo "Building for Windows..."
    libs="-Llib -lraylib -luser32 -lopengl32 -lgdi32"
    outputFile="bin/main.exe"
fi

mkdir -p bin
clang++ -std=c++17 -g $includes $defines $warnings src/main.cpp -o $outputFile $libs