UNAME := $(shell uname)
ARCH := $(shell getconf LONG_BIT)
ifeq ($(UNAME), Linux)
	#program_LIBRARIES := 
	SHELL := /bin/zsh
	LDFLAGS += `pkg-config --cflags --libs sdl2` -W
else
ifeq ($(UNAME), Darwin)
	#program_LIBRARIES := enetOSX
	SHELL := /bin/zsh
	LDFLAGS += -framework SDL2 -Wl
else
	#windows
	SHELL := sh.exe
endif
endif
program_NAME := axilya
lib_NAME := libaxilya
program_CXX_SRCS := $(shell find axsrc/ -type f -name '*.cpp')
lib_OBJS := ${program_CXX_SRCS:.cpp=.o}
program_CXX_SRCS += $(shell find gamesrc/ -type f -name '*.cpp')
program_OBJS := ${program_CXX_SRCS:.cpp=.o}
program_INCLUDE_DIRS := $(shell echo ./gamesrc/**/)
program_HEADERS := $(foreach directory, $(program_INCLUDE_DIRS), -I$(directory))
program_LIBRARY_DIRS := ./libs/

CPPFLAGS += $(program_HEADERS) -g -std=c++11 -Wno-c++11-compat-deprecated-writable-strings
LDFLAGS +=  $(foreach librarydir,$(program_LIBRARY_DIRS),-L$(librarydir))
LDFLAGS += $(foreach library,$(program_LIBRARIES),-l$(library)) 

.PHONY: all clean distclean

all: $(program_NAME) run

lib: $(lib_NAME)

run:
	./axilya
	
$(lib_NAME): $(lib_OBJS)
	ar rsc $(lib_NAME).a $(lib_OBJS)

$(program_NAME): $(program_OBJS)
	g++ $(program_OBJS) -o $(program_NAME) $(LDFLAGS)

clean:
	@- $(RM) $(program_NAME)
	@- $(RM) $(program_OBJS)

distclean: clean

