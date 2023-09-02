#pragma once

#ifndef ZMATH_DEF
#define ZMATH_DEF

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

/**
 * finds the maximum of two values
 * @param n the first value
 * @param m the second value
 * @return the larger element
 */
#define MAX(n, m) (n > m ? n : m)

/**
 * finds the minimum of two values
 * @param n the first value
 * @param m the second value
 * @return the smaller element
 */
#define MIN(n, m) (n < m ? n : m)

#endif // ZMATH_DEF