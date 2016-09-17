cmake_minimum_required(VERSION 3.6)
project(closedFrameworks)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wno-c++11-extensions -Wno-c++11-compat-deprecated-writable-strings -Wno-return-stack-address")
include_directories(${CMAKE_SOURCE_DIR})
FIND_LIBRARY(COCOA Cocoa)
FIND_LIBRARY(OPENGL OpenGL)
FIND_LIBRARY(IOKIT IOKit)
FIND_LIBRARY(COREVIDEO CoreVideo)
FIND_LIBRARY(COREFOUNDATION CoreFoundation)
SET(FRAMEWORKS ${COCOA} ${OPENGL} ${IOKIT} ${COREVIDEO} ${COREFOUNDATION})
file(GLOB_RECURSE cfSRC
        "*.cpp"
        )
LINK_DIRECTORIES(libs/)
add_executable(closedFrameworks ${cfSRC})
TARGET_LINK_LIBRARIES(closedFrameworks ${FRAMEWORKS} pugixml drawtext-noft enet GLEW glfw3 SOIL)
