OS = $(shell uname)
ifeq ($(OS), Linux)
	CPFLAGS += `curl-config --libs` -I/usr/local/include/SDL2 -lSDL2_mixer -lSDL2_ttf
	SDLRUN := @echo "SDL install isn't supported from makefile on Linux, got to https://github.com/vexparadox/Axilya/wiki/Dependencies to see how to install the required libraries"
else
ifeq ($(OS), Darwin)
	CPFLAGS += -mmacosx-version-min=10.9 -F/Library/Frameworks/
	SDLRUN := @echo "Unpacking SDL2.0.5"; cd ./SDL && unzip -qq ./SDL2-osx.zip; echo "Copying SDL Framework";  cp -rf ./SDL2.framework /Library/Frameworks/; echo "Cleaning up..."; rm -rf ./SDL2.framework; echo "Install complete";
	SDLRUN += echo "Unpacking SDL TTF"; unzip -qq ./SDL2_ttf-osx.zip; echo "Copying SDL TTF Framework";  cp -rf ./SDL2_ttf.framework /Library/Frameworks/; echo "Cleaning up..."; rm -rf ./SDL2_ttf.framework; echo "Install complete";
	SDLRUN += echo "Unpacking SDL Mixer"; unzip -qq ./SDL2_mixer-osx.zip; echo "Copying SDL mixer Framework";  cp -rf ./SDL2_mixer.framework /Library/Frameworks/; echo "Cleaning up..."; rm -rf ./SDL2_mixer.framework; echo "Install complete";
endif
endif
temp = $(wildcard ./src/*.cpp)
cppFiles = $(patsubst ./src/%, ../../src/%, $(temp))
tempObjs = $(patsubst ./src/%, ./Build/objs/%, $(temp))
objFiles = $(patsubst %.cpp, %.o, $(tempObjs))
headers = $(wildcard ./src/headers/*.hpp)
headers += $(wildcard ./src/headers/*.h)

all: install examples


lib: 
	@mkdir -p ./Build/objs/
	@echo "Compiling the Axilya library, this may take a while..."
	@
	@cd ./Build/objs/; $(foreach file,$(cppFiles), echo $(file) ;g++ $(file) -c $(CPFLAGS) -std=c++11 -O3;)
	@# @cd ./Build/objs/ && g++ $(cppFiles) -c $(CPFLAGS) -std=c++11 -O3; 
	@ar rcs ./Build/libAxilya.a $(objFiles)
	@echo "Library compiled"

install: lib
	@echo "Starting install"
	@echo "Copying static library to /usr/local/lib/"
	@mkdir -p /usr/local/lib/
	@cp ./Build/libAxilya.a /usr/local/lib/
	@echo "Copy complete"
	@echo "Removing old headers"
	@rm -rf /usr/local/include/Axilya 2> /dev/null
	@mkdir -p /usr/local/include/Axilya/
	@echo "Copying headers to /usr/local/include/"
	@cp $(headers) /usr/local/include/Axilya/
	@echo "Copy complete"
	@echo "Install complete"

.PHONY: clean cleaninstall examples sdl
examples:
	@echo "Building examples..."
	@cd ./Examples/ && make

clean:
	@echo "Cleaning build files"
	@rm -rf ./Build
	@echo "Cleaning examples"
	@cd ./Examples/ && make clean
cleaninstall:
	@echo "Removing libraries and headers"
	@rm -rf /usr/local/include/Axilya 2> /dev/null
	@rm -f /usr/local/lib/libAxilya.a 2> /dev/null
	@echo "Install removed."
sdl:
	$(SDLRUN)