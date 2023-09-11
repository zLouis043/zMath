#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <time.h>

#include "zmath.h"

/*
*/
void _zassert(bool condition, const char* message, const char* filepath, size_t line){
    if(!condition){
        fprintf(stderr, "\n[ERROR] : %s:%zu > %s\n", filepath, line, message);
        #if EXIT_ON_ASSERT_FAILURE 
            exit(EXIT_FAILURE);
        #endif
    }
}

/*
*/
float float_rand( float min, float max ){
    float scale = rand() / (float) RAND_MAX; 
    return min + scale * ( max - min );      
}

/*!
*/
int int_rand( int min, int max ){
    return (rand() % (max - min)) + min;
}

/*
*/
void swapInt(int* a, int* b){

    *a ^= *b;
    *b = *a ^ *b;
    *a ^= *b;

}

/*
*/
void swapFloat(float* a, float* b){
    swapInt((int*)a, (int*)b);
}

/*
*/
char arrContains(void **arr, int n, void *target){
    for (unsigned int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return 1;
        }
    }

    return 0;
}