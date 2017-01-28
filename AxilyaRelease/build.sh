#!/bin/zsh
g++ *.cpp -framework SDL2 -L./axsrc/ -laxilya -include ./axsrc/CoreMain.h -I. -o axilya -std=c++11
if [[ $? -eq 0 ]]; then
	./output
fi
