#!/bin/bash
if [[ "$OSTYPE" == darwin* ]]; then
	echo "Building Basic example for OSX.."
	g++ *.cpp -std=c++11 -o Axilya -L../../Build/ -L../../Build/Release -lAxilya -framework SDL2
	echo "Basic Example complete"
elif [[ "$OSTYPE" == "linux-gnu"  ]]; then
	echo "Examples don't work on Linux yet"
fi