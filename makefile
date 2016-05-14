all: main SOIL
	 g++ -g -o main *.o -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -framework CoreFoundation -Llib/ -Wl -ldrawtext-noft -lGLEW -lglfw3
	 ./main
main: src/*.cpp
	g++ -g -c src/*.cpp
SOIL: src/SOIL/*.c
	g++ -g -c src/SOIL/*.c