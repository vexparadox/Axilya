OS = $(shell uname)
ifeq ($(OS), Linux)
	CPFLAGS += 
	SDLRUN := @echo "Unpacking SDL2.0.5"; cd ./SDL && unzip ./SDL2-src.zip; echo "Configuring SDL2.0.5"; cd ./SDL2-2.0.5 && ./configure ; echo "Building..."; sudo make && sudo make install; echo "Cleaning up..."; cd ../ && rm -rf ./SDL2-2.0.5; echo "Install complete"
	SDLRUN += @echo "Unpacking SDL TTF"; unzip ./SDL2_ttf-src.zip; echo "Configuring SDL TTF"; cd ./SDL2_ttf-2.0.14 && ./configure ; echo "Building..."; sudo make && sudo make install; echo "Cleaning up..."; cd ../ && rm -rf ./SDL2_ttf-2.0.14; echo "Install complete"
else
ifeq ($(OS), Darwin)
	CPFLAGS += -mmacosx-version-min=10.9 -F/Library/Frameworks/
	SDLRUN := @echo "Unpacking SDL2.0.5"; cd ./SDL && unzip ./SDL2-osx.zip; echo "Copying SDL Framework";  cp -rf ./SDL2.framework /Library/Frameworks/; echo "Cleaning up..."; rm -rf ./SDL2.framework; echo "Install complete";
	SDLRUN += @echo "Unpacking SDL TTF"; unzip ./SDL2_ttf-osx.zip; echo "Copying SDL TTF Framework";  cp -rf ./SDL2_ttf.framework /Library/Frameworks/; echo "Cleaning up..."; rm -rf ./SDL2_ttf.framework; echo "Install complete";
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