all: game main SOIL
	g++ -g -o main *.o -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -framework CoreFoundation -Llib/ -Wl -ldrawtext-noft -lGLEW -lglfw3
	./main
main: cfsrc/*.cpp
	g++ -g -c cfsrc/*.cpp
game: gamesrc/*.cpp
	g++ -g -c gamesrc/*.cpp
SOIL: cfsrc/SOIL/*.c
	g++ -g -c cfsrc/SOIL/*.c