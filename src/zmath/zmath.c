#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>

#include "zmath.h"

void _zassert(bool condition, const char* message, const char* filepath, size_t line){
    if(!condition){
        fprintf(stderr, "[ERROR] : %s:%zu > %s\n", filepath, line, message);
        #if EXIT_ON_ASSERT_FAILURE 
            exit(EXIT_FAILURE);
        #endif
    }
}