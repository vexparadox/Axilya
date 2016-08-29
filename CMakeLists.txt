cmake_minimum_required(VERSION 3.6)
project(closedFrameworks)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wno-c++11-extensions -Wno-c++11-compat-deprecated-writable-strings -Wno-return-stack-address")
#INCLUDE_DIRECTORIES(cfsrc/SOIL)
#INCLUDE_DIRECTORIES(cfsrc/enet)
#INCLUDE_DIRECTORIES(cfsrc/GLFW)
#INCLUDE_DIRECTORIES(cfsrc/GL)
include_directories(${CMAKE_SOURCE_DIR})
FIND_LIBRARY(COCOA Cocoa)
FIND_LIBRARY(OPENGL OpenGL)
FIND_LIBRARY(IOKIT IOKit)
FIND_LIBRARY(COREVIDEO CoreVideo)
FIND_LIBRARY(COREFOUNDATION CoreFoundation)
SET(FRAMEWORKS ${COCOA} ${OPENGL} ${IOKIT} ${COREVIDEO} ${COREFOUNDATION})
#RUNTIME_OUTPUT_DIRECTORY(.)
file(GLOB_RECURSE cfSRC
#        "*.h"
#        "*.hpp"
        "*.cpp"
#        "cfsrc/*.cpp"
#        "cfsrc/*.c"
#        "cfsrc/*.h"
#        "cfsrc/*.hpp"
#        "cfsrc/*.cpp"
        )
LINK_DIRECTORIES(libs/)
add_executable(closedFrameworks ${cfSRC})
TARGET_LINK_LIBRARIES(closedFrameworks ${FRAMEWORKS} drawtext-noft enet GLEW glfw3 SOIL)
