exename := closedFrameworks
all: game main SOIL
	g++ -g -o $(exename) *.o -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -framework CoreFoundation -Llib/ -Wl -ldrawtext-noft -lGLEW -lglfw3
	./$(exename)
main: cfsrc/*.cpp
	g++ -g -c cfsrc/*.cpp -Wno-c++11-extensions
game: gamesrc/*.cpp
	g++ -g -c gamesrc/*.cpp -Wno-c++11-extensions
SOIL: cfsrc/SOIL/*.cpp
	g++ -g -c cfsrc/SOIL/*.cpp -Wno-c++11-compat-deprecated-writable-strings