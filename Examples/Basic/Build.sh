#!/bin/bash
if [[ "$OSTYPE" == darwin* ]]; then
	echo "Building Basic example for OSX.."
	g++ *.cpp -std=c++11 -o Axilya -lAxilya -framework SDL2
	./Axilya
	echo "Basic Example complete"
elif [[ "$OSTYPE" == "linux-gnu"  ]]; then
	echo "Examples don't work on Linux yet"
fi