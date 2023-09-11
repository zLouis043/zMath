#pragma once

#include <stdbool.h>
#include <stdio.h>

/*
    Flag that if activated will crush the program if an assertion fails.
*/
#define EXIT_ON_ASSERT_FAILURE 0

/*
    Flag that if activated will print debug information.
*/
#define VISUALIZE_DEBUG 0

#define EQUAL_ERROR "Dimension mismatch."
#define ALLOC_ERROR "Allocation failure."
#define PROD_ERROR  "Matrix 1 columns not equal to Matrix 2 rows."

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
*/
#define SWAP(x, y) { float temp = x; x = y; y = temp; }

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
    Checks if the condition is true and printf an error message and exit the program if it is false.
    @param condition The condition to check.
    @param message The message to send if the condition is false.
*/
#define zassert(condition, message) _zassert(condition, message, __FILE__, __LINE__)

