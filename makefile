all: main SOIL
	 g++ -g -o main temp/*.o -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -framework CoreFoundation -Llib/ -Wl -ldrawtext-noft -lGLEW -lglfw3
	 ./main
main: src/*.cpp
	g++ -g -c temp/ src/*.cpp
SOIL: src/SOIL/*.c
	g++ -g -c temp/ src/SOIL/*.c