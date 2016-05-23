program_NAME := closedFrameworks
lib_NAME := libcf
program_C_SRCS := $(wildcard cfsrc/SOIL/*.c)
program_CXX_SRCS := $(wildcard cfsrc/*.cpp)
program_CXX_SRCS += $(wildcard gamesrc/*.cpp)
program_C_OBJS := ${program_C_SRCS:.c=.o}
program_CXX_OBJS := ${program_CXX_SRCS:.cpp=.o}
program_OBJS := $(program_C_OBJS) $(program_CXX_OBJS) 
program_INCLUDE_DIRS :=
program_LIBRARY_DIRS := ./lib/
program_LIBRARIES := drawtext-noft GLEW glfw3


CPPFLAGS += $(foreach includedir,$(program_INCLUDE_DIRS),-I$(includedir)) -Wno-c++11-extensions -Wno-c++11-compat-deprecated-writable-strings
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
	$(LINK.cc) $(program_OBJS) -o $(program_NAME)

clean:
	@- $(RM) $(program_NAME)
	@- $(RM) $(program_OBJS)

distclean: clean