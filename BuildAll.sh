#!/bin/bash
if [[ "$OSTYPE" == darwin* ]]; then
	echo "Building Axilya Library and examples for OSX..."
	sh OSXBuildLibrary.sh
	cd ./Examples/Basic/
	sh Build.sh
	cd ../../
elif [[ "$OSTYPE" == "linux-gnu"  ]]; then
	echo "You can't build for Linux yet"
fi