OS = $(shell uname)
ifeq ($(OS), Linux)
	FLAGS += `pkg-config --cflags --libs sdl2`
else
ifeq ($(OS), Darwin)
	FLAGS += -framework SDL2
endif
endif
all:
	@echo "Compiling Basic example"
	@g++ *.cpp -std=c++11 -o Axilya -lAxilya $(FLAGS)
	@echo "Complete."
run: all
	./Axilya
clean:
	@rm -f Axilya 2> /dev/null