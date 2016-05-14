all: game main SOIL
	g++ -g -o main *.o -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -framework CoreFoundation -Llib/ -Wl -ldrawtext-noft -lGLEW -lglfw3
	./main
main: cfsrc/*.cpp
	g++ -g -c cfsrc/*.cpp -Wno-c++11-extensions
game: gamesrc/*.cpp
	g++ -g -c gamesrc/*.cpp -Wno-c++11-extensions
SOIL: cfsrc/SOIL/*.c
	g++ -g -c cfsrc/SOIL/*.c -Wno-c++11-compat-deprecated-writable-strings