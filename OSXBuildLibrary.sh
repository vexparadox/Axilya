#!/bin/bash
echo "Building Axilya Library for OSX...."
mkdir Build
cd ./Build
mkdir objs
cd ./objs
cppfiles=$(find ../../src -type f -name '*.cpp')
echo "Compiling Axilya source..."
g++ $cppfiles -c -std=c++11 -mmacosx-version-min=10.9 -O3
cd ../
echo "Bundling objects..."
ar rcs libAxilya.a ./objs/**.o
echo "Static library built to ./Build/libAxilya.a"