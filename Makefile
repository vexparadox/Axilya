OS = $(shell uname)
ifeq ($(OS), Linux)
	CPFLAGS += `curl-config --libs` -I/usr/local/include/SDL2 -lSDL2_mixer -lSDL2_ttf
	SDLRUN := ./LinuxDependenciesInstall.sh
else
ifeq ($(OS), Darwin)
	CPFLAGS += -mmacosx-version-min=10.9 -F/Library/Frameworks/
	SDLRUN := ./OSXDependenciesInstall.sh
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