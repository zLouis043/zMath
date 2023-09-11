#pragma once

#include <stdbool.h>
#include <stdio.h>

/*
    Flag that if activated will crush the program if an assertion fails.
*/
#define EXIT_ON_ASSERT_FAILURE 1

/*
    Flag that if activated will print debug information.
*/
#define VISUALIZE_DEBUG 0
/*
    Flag that if activated will print each step done in a function.
*/
#define VISUALIZE_STEPS 0

#define EQUAL_ERROR "Dimension mismatch."
#define ALLOC_ERROR "Allocation failure."
#define PROD_ERROR  "Matrix 1 columns not equal to Matrix 2 rows."
#define DIRECTION_ERROR "Invalid direction."
#define SQUARE_ERROR "Matrix is not square."

/*!
 * finds the maximum of two values
 * @param n the first value
 * @param m the second value
 * @return the larger element
 */
#define MAX(n, m) (n > m ? n : m)

/*!
 * finds the minimum of two values
 * @param n the first value
 * @param m the second value
 * @return the smaller element
 */
#define MIN(n, m) (n < m ? n : m)

/*!
    Checks if the condition is true and printf an error message and exit the program if it is false.
    @param condition The condition to check.
    @param message The message to send if the condition is false.
*/
void _zassert(bool condition, const char* message, const char* filepath, size_t line);

/*!
*/
float float_rand( float min, float max );

/*!
*/
int int_rand( int min, int max );
   
/*!
*/
void swapInt(int* a, int* b);

/*!
*/
void swapFloat(float* a, float* b);

/*
*/
char arrContains(void **arr, int n, void *target);

/*!
    Checks if the condition is true and printf an error message and exit the program if it is false.
    @param condition The condition to check.
    @param message The message to send if the condition is false.
*/
#define zassert(condition, message) _zassert(condition, message, __FILE__, __LINE__)

