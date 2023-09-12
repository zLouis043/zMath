cmake_minimum_required(VERSION 3.27.1)
project(zmath)              

# defines targets and sources
add_subdirectory(src/zmath)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -Wall -Wextra -Wsign-compare -g3 -fsanitize=address -fsanitize=undefined")

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(${PROJECT_NAME} main.c src/zmath/zmath.h src/zmath/zstring.h)

