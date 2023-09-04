cmake_minimum_required(VERSION 3.27.1)
project(zmath)              

# defines targets and sources
add_subdirectory(src/zmath)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(${PROJECT_NAME} main.c 
                                ./src/zmath/zmath.h ./src/zmath/zmath.c
                                ./src/zmath/zvec.c ./src/zmath/zvec.h 
                                ./src/zmath/zmatrix.c ./src/zmath/zmatrix.h)
