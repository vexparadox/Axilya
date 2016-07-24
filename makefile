program_NAME := closedFrameworks
SHELL := /bin/zsh
lib_NAME := libcf
program_CXX_SRCS := $(wildcard cfsrc/*.cpp)
program_CXX_SRCS += $(shell find gamesrc/ -type f -name '*.cpp')
program_OBJS := ${program_CXX_SRCS:.cpp=.o}
program_INCLUDE_DIRS := $(shell echo ./gamesrc/**/)
program_HEADERS := $(foreach directory, $(program_INCLUDE_DIRS), -I$(directory))
program_LIBRARY_DIRS := ./lib/
program_LIBRARIES := drawtext-noft GLEW glfw3 SOIL enet


CPPFLAGS += $(program_HEADERS) -Wno-c++11-extensions -Wno-c++11-compat-deprecated-writable-strings -Wno-return-stack-address
LDFLAGS += -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -framework CoreFoundation -Wl $(foreach librarydir,$(program_LIBRARY_DIRS),-L$(librarydir))
LDFLAGS += $(foreach library,$(program_LIBRARIES),-l$(library)) 

.PHONY: all clean distclean

all: $(program_NAME) run

lib: $(lib_NAME)

run:
	./closedFrameworks
	
$(lib_NAME): $(program_OBJS)
	ar rsc $(lib_NAME).a $(program_OBJS)

$(program_NAME): $(program_OBJS)
	g++ $(program_OBJS) -o $(program_NAME) $(LDFLAGS)

clean:
	@- $(RM) $(program_NAME)
	@- $(RM) $(program_OBJS)

distclean: clean
