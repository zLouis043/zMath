#ifndef ZMATH_DEF
#define ZMATH_DEF

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

/*
    Flag that if activated will print each number in its rational representation
*/
#define VISUALIZE_RATIONAL 0

#define ZM_EQUAL_ERROR      "Dimension mismatch."
#define ZM_ALLOC_ERROR      "Allocation failure."
#define ZM_PROD_ERROR       "Matrix 1 columns not equal to Matrix 2 rows."
#define ZM_DIRECTION_ERROR  "Invalid direction."
#define ZM_SQUARE_ERROR     "Matrix is not square."

/*!
    Finds the maximum of two values
    @param n the first value
    @param m the second value
    @return the larger element
*/
#define ZM_MAX(n, m) ({\
    __auto_type _a = (n);\
    __auto_type _b = (m);\
    _a > _b ? _a : _b;\
})

/*!
    Finds the minimum of two values
    @param n the first value
    @param m the second value
    @return the smaller element
*/
#define ZM_MIN(n, m) ({\
    __auto_type _a = (n);\
    __auto_type _b = (m);\
    _a < _b ? _a : _b;\
})

/*!
    Alloc macro.
    @param count The size of the chunk to allocate.
    @param type The type of the chunk.
*/
#define ZM_ALLOC(count, type) \
    (type*)malloc((count) * sizeof(type))\

/*!
    Swap two values.
*/
#define ZM_SWAP(n, m) ({\
    typeof(n) _tmp = (n);\
    (n) = (m);\
    (m) = _tmp;\
})

/*!
    Checks if the condition is true and printf an error message and exit the program if it is false.
    @param condition The condition to check.
    @param message The message to send if the condition is false.
*/
void _zm_assert(bool condition, const char* message, const char* filepath, size_t line);

/*!
    Gives a random float random in a certain range.
    @param min The minimum value.
    @param max The maximum value.
    @return a random float value.
*/
float zm_rand_float( float min, float max );

/*!
    Gives a random int random in a certain range.
    @param min The minimum value.
    @param max The maximum value.
    @return a random int value.
*/
int zm_rand_int( int min, int max );
   
/*!
    Swap two int numbers.
    @param a the pointer to the first number.
    @param b the pointer to the second number.
*/
void zm_swap_int(int* a, int* b);

/*!
    Swap two float numbers.
    @param a the pointer to the first number.
    @param b the pointer to the second number.
*/
void zm_swap_float(float* a, float* b);

/*!
    Checks if the array contains a value.
    @param arr The pointer to the array.
    @param n The number of elements in the array 
    @param target The target element.
    @return if the element exists in the array
*/
bool zm_is_in_array(unsigned int *arr, int n, float target);

/*!
    Checks if the condition is true and printf an error message and exit the program if it is false.
    @param condition The condition to check.
    @param message The message to send if the condition is false.
*/
#define zm_assert(condition, message) _zm_assert(condition, message, __FILE__, __LINE__)

#endif // ZMATH_DEF

#ifndef ZVEC_DEF
#define ZVEC_DEF

/*! 

    Struct that holds the dimensions of the vector and its components
    @param dim The dimension of the vector
    @param elements The element of the vector

*/

typedef struct zm_Vec{
    size_t dim;
    float *elements;
}zm_Vec;

extern zm_Vec NULL_VECTOR;

/*!
    Prints the dimensions of the vector and its components.
    @param fp The file to write the vector.
    @param vector The vector to print.
*/
void zm_print_vector(FILE* fp, zm_Vec vector);

/*!
    Prints the dimensions of the vector by its label and its components.
    @param fp The file to write the vector.
    @param label The vector label.
    @param vector The vector to print.
*/
void zm_print_vector_by_label(FILE* fp, const char* label, zm_Vec vector);

/*!
    Prints the dimensions of the vector by its index and its components.
    @param fp The file to write the vector.
    @param index The vector index.
    @param vector The vector to print.
*/
void zm_print_vector_by_index(FILE* fp, int index, zm_Vec vector);

/*!
    Free the vector and sets its dimensions to 0.
*/
void zm_free_vector(zm_Vec* vector);

/*!
    Copy one vector into another.
    @param source The vector to copy.
    @param dest The destination vector.
*/
void zm_copy_vector_pointer(zm_Vec* source, zm_Vec* dest);

/*!
    Allocate memory for the vector.
    @param dim The dimensions of the vector.
    @return The memory allocated. 
*/
zm_Vec zm_alloc_vector(size_t dim);

/*!
    Create a new vector of ZM_DIM_OF_VECTOR dimensions with every component in the vector equal to 0.
    @param dim The dimensions of the vector.
    @return The new vector with every element in the vector equal to 0.
*/
zm_Vec zm_new_zero_vector(size_t dim);

/*!
    Create a new vector of ZM_DIM_OF_VECTOR dimensions with every component in the vector equal to to element.
    @param dim The dimensions of the vector.
    @param element The element of which the vector will be filled.
    @returnThe new vector with every component in the vector equal to element.
*/
zm_Vec zm_new_default_vector(size_t dim, float element);

/*!
    Create a new vector of ZM_DIM_OF_VECTOR dimensions with every component being randomly generated.
    @param dim The dimensions of the vector.
    @return The new vector with every element in the vector equal to 0.
*/
zm_Vec zm_new_random_float_vector(size_t dim, float min, float max);

/*!
    Create a new vector of dimensions with every component being randomly generated.
    @param dim The dimensions of the vector.
    @return The new vector with every element in the vector equal to 0.
*/
zm_Vec zm_new_random_int_vector(size_t dim, float min, float max);

/*!
    Create a new vector of ZM_DIM_OF_VECTOR dimensions.
    @param dim The dimensions of the vector.
    @param ... The components of the vector.
    @return The new vector of ZM_DIM_OF_VECTOR dimensions.
*/
zm_Vec _zm_new_vector(size_t dim, ...);

/*!
    Copy the dimensions and the components from a vector to another one.
    @param source The vector to copy.
    @return The copy of the vector.
*/
zm_Vec zm_copy_vector(zm_Vec source);

/*!
    Sums the two vectors.
    @param vector1
    @param vector2
    @return The sum between vector1 and vector2.
*/
zm_Vec zm_add_two_vectors(zm_Vec vector1 , zm_Vec vector2);

/*!
    Sums a vector and a scalar.
    @param vector1
    @param scalar
    @return The sum between vector1 and a scalar.
*/
zm_Vec zm_add_vector_with_scalar(zm_Vec vector1 , float scalar);

/*!
    Sums the two vectors.
    @param vector1
    @param vector2
    @return The sum between vector1 and vector2.
*/
zm_Vec zm_subtract_two_vectors(zm_Vec vector1 , zm_Vec vector2);

/*!
    Subtract a vector and a scalar.
    @param vector1
    @param scalar
    @return The subtraction between vector1 and a scalar.
*/
zm_Vec zm_subtract_vector_with_scalar(zm_Vec vector1 , float scalar);

/*!
    Multiply two vectors.
    @param vector1
    @param vector2
    @return The product between vector1 and  vector2.
*/
zm_Vec zm_multiply_two_vectors(zm_Vec vector1, zm_Vec vector2);

/*!
    Multiply a vector and a scalar.
    @param vector1
    @param scalar
    @return The product between vector1 and a scalar.
*/
zm_Vec zm_multiply_vector_by_scalar(zm_Vec vector1, float scalar);

/*!
    Divide two vectors.
    @param vector1
    @param vector2
    @return The division between vector1 and  vector2.
*/
zm_Vec zm_divide_two_vectors(zm_Vec vector1, zm_Vec vector2);

/*!
    Divide a vector and a scalar.
    @param vector1
    @param scalar
    @return The division between vector1 and a scalar.
*/
zm_Vec zm_divide_vector_by_scalar(zm_Vec vector1, float scalar);

/*!
    Raise every component of a vector to the exponent given.
    @param vector The vector to raise.
    @param exponent The exponent of the power.
    @return The vector raised to the exponent.
*/
zm_Vec zm_raise_vector_to_exp(zm_Vec vector, size_t exponent);

/*!
    The cross product between two vectors.
    @param vector1
    @param vector2
    @return The cross product between two vectors.
*/
zm_Vec zm_cross_product(zm_Vec vector1, zm_Vec vector2);

/*!
    This function return the normalized version of a vector given.
    @param vector The vector to normalize.
    @return The normalized vector.
*/
zm_Vec zm_normalized_vector(zm_Vec vector);

/*!
    This function return the normalized version of a vector given.
    @param vector The vector pointer to normalize.
*/
void zm_normalize_vector(zm_Vec* vector);

/*!
    Checks if two vectors are equal.
    @param vector1
    @param vector2
    @return true if they are equal false if otherwise.
*/
bool zm_are_two_vectors_equal(zm_Vec vector1, zm_Vec vector2);

/*!
    Checks if the two vectors are orthogonal.
    @param vector1.
    @param vector2.
    @return true if they are orthogonal false if otherwise
*/
bool zm_are_two_vectors_orthogonal(zm_Vec vector1, zm_Vec vector2);

/*!
    Checks if the vector is normalized.
    @param vector The vector.
    @return true if the vector is normalized.
*/
bool zm_is_vector_normalized(zm_Vec vector);

/*!
    This functions return the dot product of two vectors.
    @param vector1
    @param vector2
    @return The dot product of the two vectors.
*/
float zm_dot_two_vectors(zm_Vec vector1, zm_Vec vector2);

/*!
    This function return the magnitude of a vector.
    @param vector 
    @return The magnitude of the vector.
*/
float zm_magnitude_of_vector(zm_Vec vector);


/*!
    Find the arguments given 
    @param type The type of the arguments.
    @param ... The variable arguments.
*/
#define ZM_NUM_OF_ARGS(type, ...) (sizeof((type[]){0.0f, ##__VA_ARGS__}) / sizeof(type) - 1) 

/*!
    Create a new vector of ZM_DIM_OF_VECTOR dimensions.
    @param ... The components of the vector.
    @result The new vector of ZM_DIM_OF_VECTOR dimensions.
*/
#define zm_new_vector(...) _zm_new_vector(ZM_NUM_OF_ARGS(float, ##__VA_ARGS__), __VA_ARGS__)

/*!
    Return the value of the specified vector at the specified index.
    @param vector The vector from which to retrieve the value.
    @param index The index where to retrieve the value.
    @result The value at the specified index.
*/
#define ZM_VALUE_OF_VECTOR_AT(vector, index) (vector.elements[index])

/*!
    Return the value of the specified vector at the specified index.
    @param vector The vector from which to retrieve the value.
    @param index The index where to retrieve the value.
    @result The value at the specified index.
*/
#define ZM_VALUE_OF_VECTOR_POINTER_AT(vector, index) (vector->elements[index])

/*!
    Return the dimensions of the specified vector.
    @param vector The vector from which we pick the dimensions.
    @result The dimensions of the vector.
*/
#define ZM_DIM_OF_VECTOR(vector) (vector.dim)

#endif // ZVEC_DEF

#ifndef ZMATRIX_DEF
#define ZMATRIX_DEF

/*!
    The direction of the vec to matrix conversion
*/
typedef enum {
    HORIZONTAL = 0,
    VERTICAL = 1,
    DIR_COUNT,
}Direction;


/*!
    The struct that holds the information about a matrix.
    @param rows The number of rows.
    @param cols The number of columns.
    @param elements The elements of the matrix.
*/
typedef struct zm_Matrix{
    unsigned int rows;
    unsigned int cols;
    float** elements;
}zm_Matrix;

extern zm_Matrix NULL_MATRIX;

/*!
    Prints the information about a matrix.
    @param fp The file to write the matrix.
    @param mat The matrix to print.
*/
void zm_print_matrix(FILE *fp, zm_Matrix mat);

/*!
    Prints the information about a matrix with a label.
    @param fp The file to write the matrix.
    @param label The label of the matrix.
    @param mat The matrix to print.
*/
void zm_print_matrix_by_label(FILE *fp, const char* label, zm_Matrix mat);

/*!
    Prints the information about a matrix with an index.
    @param fp The file to write the matrix.
    @param index The index of the matrix.
    @param mat The matrix to print.
*/
void zm_print_matrix_by_index(FILE *fp, unsigned  index, zm_Matrix mat);

/*!
    Frees the matrix and set the rows and cols to 0.
    @param mat The matrix to free.
*/
void zm_free_matrix(zm_Matrix* mat);

/*!
    Copy the source matrix to the destination matrix by the pointer.
    @param source The source matrix to copy.
    @param dest The destination matrix.
*/
void zm_copy_matrix_pointer(zm_Matrix *source, zm_Matrix *dest);

/*!
    Allocate memory chunk to the matrix through its rows and cols.
    @param rows The rows of the matrix.
    @param cols The cols of the matrix.
    @return The allocated memory chunk.
*/
zm_Matrix zm_alloc_matrix(unsigned int rows, unsigned int cols);

/*!
    Create a matrix of rows * cols dimensions all set to 0.
    @param rows The rows of the matrix.
    @param cols The cols of the matrix.
    @return The matrix of rows * cols dimensions all set to 0.
*/
zm_Matrix zm_new_zero_matrix(unsigned int rows, unsigned int cols);

/*!
    Create a matrix of rows * cols dimensions filled with random float values.
    @param rows The rows of the matrix.
    @param cols The cols of the matrix.
    @param min The minimum value.
    @param max The maximum value.
    @return The matrix of rows * cols dimensions filled with random float values.
*/
zm_Matrix zm_new_random_float_matrix(unsigned int rows, unsigned int cols, float min, float max);

/*!
    Create a matrix of rows * cols dimensions filled with random int values.
    @param rows The rows of the matrix.
    @param cols The cols of the matrix.
    @param min The minimum value.
    @param max The maximum value.
    @return The matrix of rows * cols dimensions filled with random int values.
*/
zm_Matrix zm_new_random_int_matrix(unsigned int rows, unsigned int cols, int min, int max);

/*!
    Create a matrix of rows * cols dimensions all set to a certain value.
    @param rows The rows of the matrix.
    @param cols The cols of the matrix.
    @param value The value used to fill the matrix.
    @return The matrix of rows * cols dimensions all set to a certain value.
*/
zm_Matrix zm_new_default_matrix(unsigned int rows, unsigned int cols, float value);

/*!
    Create a matrix of rows * cols dimensions all set to 0.0f except for the main diagonal that is set to 1.0f.
    @param dim The rows of the matrix.
    @return The matrix of rows * cols dimensions all set to 0.0f except for the main diagonal that is set to 1.0f. 
*/
zm_Matrix zm_new_identity_matrix(unsigned int dim);

/*!
    Create a matrix of rows * cols dimensions.
    @param rows The rows of the matrix.
    @param cols The cols of the matrix.
    @param numVals the number of values inside the matrix.
    @return The matrix of rows * cols dimensions with the values specified.
*/
zm_Matrix _zm_new_matrix(unsigned int rows, unsigned int cols, unsigned int numVals, ...);

/*!
    Create a Row or a Col Matrix from a vector.
    @param source The source vector.
    @param dir Whether it will be a Row Matrix or a Col Matrix.
    @return The vector converted to a Matrix.
*/
zm_Matrix zm_Vector_to_matrix(zm_Vec source, Direction dir);

/*!
    Create a vector from a matrix.
    @param source The source matrix.
    @return The vector converted from the Matrix.
*/
zm_Vec zm_Matrix_to_vector(zm_Matrix source);

/*!
    Create a vector from a matrix's row.
    @param source The source matrix.
    @param row The row that will be converted to a vector.
    @return The vector converted from the Matrix's row.
*/
zm_Vec zm_get_vector_from_matrix_row(zm_Matrix source, unsigned int row);

/*!
    Create a vector from a matrix's col.
    @param source The source matrix.
    @param col The col that will be converted to a vector.
    @return The vector converted from the Matrix's col.
*/
zm_Vec zm_get_vector_from_matrix_col(zm_Matrix source, unsigned int col);

/*!
    Add two matrices together.
    @param matrix1.
    @param matrix2.
    @return The sum of the two matrices.
*/
zm_Matrix zm_add_two_matrices(zm_Matrix matrix1, zm_Matrix matrix2);

/*!
    Add a scalar to every single element of the matrix.
    @param matrix1.
    @param scalar.
    @return The sum of every single element of the matrix to a certain scalar.
*/
zm_Matrix zm_add_matrix_with_scalar(zm_Matrix matrix1, float scalar);

/*!
    Subtract two matrices together.
    @param matrix1.
    @param matrix2.
    @return The subtracted of the two matrices.
*/
zm_Matrix zm_subtract_two_matrices(zm_Matrix matrix1, zm_Matrix matrix2);

/*!
    Subtract a scalar to every single element of the matrix.
    @param matrix1.
    @param scalar.
    @return The subtracted of every single element of the matrix to a certain scalar.
*/
zm_Matrix zm_subtract_matrix_with_scalar(zm_Matrix matrix1, float scalar);

/*!
    Multiply two matrices together.
    @param matrix1.
    @param matrix2.
    @return The product of the two matrices.
*/
zm_Matrix zm_multiply_two_matrices(zm_Matrix matrix1, zm_Matrix matrix2);

/*!
    Multiply a scalar to every single element of the matrix.
    @param matrix1.
    @param scalar.
    @return The product of every single element of the matrix to a certain scalar.
*/
zm_Matrix zm_multiply_matrix_by_scalar(zm_Matrix matrix1, float scalar);

/*!
    Divide two matrices together.
    @param matrix1.
    @param matrix2.
    @return The division of the two matrices.
*/
zm_Matrix zm_divide_two_matrices(zm_Matrix matrix1, zm_Matrix matrix2);

/*!
    Divide a scalar to every single element of the matrix.
    @param matrix1.
    @param scalar.
    @return The division of every single element of the matrix to a certain scalar.
*/
zm_Matrix zm_divide_matrix_by_scalar(zm_Matrix matrix1, float scalar);

/*!
    Multiply two matrices together by the rows per cols product.
    @param matrix1.
    @param matrix2
    @return The product of two matrices together by the rows per cols product.
*/
zm_Matrix zm_dot_two_matrices(zm_Matrix matrix1, zm_Matrix matrix2);

/*!
    Transpose a matrix.
    @param source The matrix to transpose.
    @return The transposed matrix.
*/
zm_Matrix zm_transposed_matrix(zm_Matrix source);

/*!
    Swap two rows in a matrix.
    @param source The original matrix.
    @param row1.
    @param row2.
    @return The matrix in which row1 and row2 have been swapped.
*/
bool zm_swap_two_matrix_rows(zm_Matrix *source, unsigned int row1, unsigned int row2);

/*!
    Add two rows in a matrix.
    @param source The original matrix.
    @param row1.
    @param row2.
    @return The matrix in which row1 and row2 have been added.
*/
bool zm_add_two_matrix_rows(zm_Matrix *source, unsigned int row1, unsigned int row2);

/*!
    Multiply two rows in a matrix.
    @param source The original matrix.
    @param row1.
    @param row2.
    @return The matrix in which row1 and row2 have been multiplied.
*/
bool zm_multiply_two_matrix_rows(zm_Matrix *source, unsigned int row, int scalar);

/*!
    Multiply one row to a scalar and then add it to the other row.
    @param source The original matrix.
    @param row1.
    @param row2.
    @return The matrix in which row2 have been multiplied to a scalar and then add it to the row1.
*/
bool zm_multiply_add_two_matrix_rows(zm_Matrix *source, unsigned int row1, unsigned int row2, int scalar);

/*!
    Convert a matrix to its Row Echelon Form.
    @param source The source matrix.
    @return The Row Echelon Form of the Matrix.
*/
void zm_to_echelon_form(zm_Matrix *source);

/*!
    Convert a matrix to its Reduced Row Echelon Form.
    @param source The source matrix.
    @return The Reduced Row Echelon Form of the Matrix.
*/
void zm_to_reduced_echelon_form(zm_Matrix *source);

/*!
    Append a vector to a matrix.
    @param source The source matrix.
    @param vector The vector to append.
    @return The matrix with the added vector.
*/
zm_Matrix zm_append_vector_to_matrix(zm_Matrix source, zm_Vec vector);

/*!
    Append a matrix to a matrix.
    @param source The source matrix.
    @param matrix The matrix to append.
    @return The matrix with the added matrix.
*/
zm_Matrix zm_append_matrix_to_matrix(zm_Matrix source, zm_Matrix matrix);

/*!
    Remove a row and a col from a matrix.
    @param source The source matrix.
    @param remRow The row to remove.
    @param remCol The col to remove.
    @return The sub Matrix with the row and col removed.
*/
zm_Matrix zm_get_sub_matrix(zm_Matrix source, unsigned int remRow, unsigned int remCol);

/*!
    Find the determinant of a matrix.
    @param source The source Matrix.
    @return The determinant of the matrix.
*/
float zm_determinant_of_matrix_old(zm_Matrix source);

/*!
    Find the determinant of a matrix through cofactor expansion with an exclusion list.
    @param source The source Matrix.
    @return The determinant of the matrix.
*/
float zm_determinant_of_matrix(zm_Matrix source);

/*!
    Calculate the determinant of a matrix through cofactor expansion using an exclusion list.
    @param source The source matrix.
    @param row The row to expand on.
    @param col The new column to exclude.
    @param skipCols The existing list of columns to exclude.
    @param noSkipCols The number of columns in the list to skip.
    @return The determinant.
*/
float _zm_determinant_of_matrix(zm_Matrix source,
                            unsigned int row,
                            unsigned int col,
                            unsigned int *skipCols,
                            unsigned int *noSkipCols);

/*!
    Finds the cofactor of a matrix at the specific row and col.
    @param source The source matrix.
    @param row The row index.
    @param col The col index.
    @return The cofactor value.
*/
float zm_cofactor_of_matrix_at_coord(zm_Matrix source, unsigned int row, unsigned int col);

/*!
    Calculates the matrix in which the elements are the cofactor of every element of the source matrix.
    @param source The source matrix.
    @return The matrix in which the elements are the cofactor of every element of the source matrix.
*/
zm_Matrix zm_cofactor_matrix(zm_Matrix source);

/*!
    Find the transpose of the cofactor Matrix.
    @param source The source matrix.
    @return The transpose of the cofactor Matrix.
*/
zm_Matrix zm_adjugate_matrix(zm_Matrix source);

/*!
    Checks if the matrix is invertible.
    @param source The source matrix.
    @return true if the matrix is invertible and false otherwise.
*/
bool zm_is_matrix_invertible(zm_Matrix source);

/*!
    Calculates the inverse of the source matrix.
    @param source The source matrix.
    @return The inverse of the source matrix.
*/
zm_Matrix zm_inverse_of_matrix(zm_Matrix source);

/*!
    Calculates the inverse of the source matrix using Gaussian Elimination.
    @param source The source matrix.
    @return The inverse of the source matrix.
*/
zm_Matrix zm_inverse_of_matrix_by_rref(zm_Matrix source);

#define sSTRAIGHT_LINE 196
#define STRAIGHT_LINE '_'
#define sLEFT_UP_CORNER 218
#define LEFT_UP_CORNER 'x'
#define sRIGHT_UP_CORNER 191
#define RIGHT_UP_CORNER 'x'
#define sSIDE_CHAR 179
#define SIDE_CHAR '|'
#define sLEFT_DOWN_CORNER 192
#define LEFT_DOWN_CORNER 'x'
#define sRIGHT_DOWN_CORNER 217
#define RIGHT_DOWN_CORNER 'x'

// double coords to single coord = rows * index + rows;
#define ZM_VALUE_OF_MAT_AT(matrix, x, y) (matrix.elements[x][y])

// double coords to single coord = rows * index + rows;
#define ZM_VALUE_OF_MAT_POINTER_AT(matrix, x, y) (matrix->elements[x][y])


#define zm_new_matrix(rows, cols, ...)  _zm_new_matrix(rows, cols, rows*cols, __VA_ARGS__)

#endif // ZMATRIX_DEF

#ifdef ZMATH_IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <time.h>

#if defined (__unix__) || (defined (__APPLE__) && defined (__MACH__))
#include <unistd.h>
#elif _WIN32
#include <process.h>
#endif 

#if VISUALIZE_RATIONAL
#define ZSTRING_IMPLEMENTATION
#include "zstring.h"
#endif

/*
*/
void _zm_assert(bool condition, const char* message, const char* filepath, size_t line){
    if(!condition){
        fprintf(stderr, "\n[ERROR] : %s:%zu > %s\n", filepath, line, message);
        #if EXIT_ON_ASSERT_FAILURE 
            exit(EXIT_FAILURE);
        #endif
    }
}

/*
*/
float zm_rand_float( float min, float max ){
    float scale = rand() / (float) RAND_MAX; 
    return min + scale * ( max - min );      
}

/*!
*/
int zm_rand_int( int min, int max ){
    return (rand() % (max - min)) + min;
}

/*
*/
void zm_swap_int(int* a, int* b){

    int* tmp = a;
    a = b;
    b = tmp;

}

/*
*/
void zm_swap_float(float* a, float* b){
    
    float* tmp = a;
    a = b;
    b = tmp;
}

/*
*/
bool zm_is_in_array(unsigned int *arr, int n, float target){
    for (int i = 0; i < n; i++){
        if (arr[i] == target)
        {
            return true;
        }
    }

    return false;
}

zm_Vec NULL_VECTOR = {0, NULL};

/*
*/
void zm_print_vector(FILE* fp, zm_Vec vector){
    fprintf(fp ,"\n\n   | Vector of size %zu: {\n   |\t[", ZM_DIM_OF_VECTOR(vector));
    for(size_t i = 0; i < ZM_DIM_OF_VECTOR(vector); i++){
        #if !VISUALIZE_RATIONAL
        fprintf(fp ," %f", ZM_VALUE_OF_VECTOR_AT(vector, i));
        #else
        zstring value = rationalizeFloatToStr(ZM_VALUE_OF_VECTOR_AT(vector, i), 3);
        fprintf(fp, " %s", value.data);
        #endif
        fprintf(fp ,"%c", (i < ZM_DIM_OF_VECTOR(vector) - 1 ? ',' : ' '));
    }
    fprintf(fp ,"]\n   |  }\n\n");
}

/*
*/
void zm_print_vector_by_label(FILE* fp, const char* label, zm_Vec vector){
    fprintf(fp ,"\n\n   | [%s] of size %zu: {\n   |\t[", label, ZM_DIM_OF_VECTOR(vector));
    for(size_t i = 0; i < ZM_DIM_OF_VECTOR(vector); i++){
        #if !VISUALIZE_RATIONAL 
        fprintf(fp ," %f", ZM_VALUE_OF_VECTOR_AT(vector, i));
        #else
        zstring value = rationalizeFloatToStr(ZM_VALUE_OF_VECTOR_AT(vector, i), 3);
        fprintf(fp, " %s", value.data);
        #endif
        fprintf(fp ,"%c", (i < ZM_DIM_OF_VECTOR(vector) - 1 ? ',' : ' '));
    }
    fprintf(fp ,"]\n   |  }\n\n");
}

/*
*/
void zm_print_vector_by_index(FILE* fp, int index, zm_Vec vector){
    fprintf(fp ,"\n\n   | [VECTOR %d] of size %zu: {\n   |\t[", index, ZM_DIM_OF_VECTOR(vector));
    for(size_t i = 0; i < ZM_DIM_OF_VECTOR(vector); i++){
        #if !VISUALIZE_RATIONAL 
        fprintf(fp ," %f", ZM_VALUE_OF_VECTOR_AT(vector, i));
        #else
        zstring value = rationalizeFloatToStr(ZM_VALUE_OF_VECTOR_AT(vector, i), 3);
        fprintf(fp, " %s", value.data);
        #endif
        fprintf(fp ,"%c", (i < ZM_DIM_OF_VECTOR(vector) - 1 ? ',' : ' '));
    }
    fprintf(fp ,"]\n   |  }\n\n");
}

/*
*/
void zm_free_vector(zm_Vec* vector){

    zm_assert(vector != NULL, "Vector must not be NULL.");

    free(vector->elements);
    vector->elements = NULL;
    vector->dim = 0;
}

/*
*/
void zm_copy_vector_pointer(zm_Vec* source, zm_Vec* dest){

    if(dest->elements == NULL){ 
        *dest= zm_alloc_vector(source->dim); 
    }

    dest->dim = source->dim;
    dest->elements = source->elements;

}

/*
*/
zm_Vec zm_alloc_vector(size_t dim){
    zm_Vec result;
    result.dim = dim;
    result.elements = ZM_ALLOC(dim, float);

    zm_assert(result.elements != NULL, ZM_ALLOC_ERROR);

    return result;
}

/*
*/
zm_Vec zm_new_zero_vector(size_t dim){

    zm_Vec result = zm_alloc_vector(dim);

    for(size_t i = 0; i < dim; i++){
        ZM_VALUE_OF_VECTOR_AT(result, i) = 0.0f;
    }

    return result;

}

/*
*/
zm_Vec zm_new_default_vector(size_t dim, float element){

    zm_Vec result = zm_alloc_vector(dim);

    for(size_t i = 0; i < dim; i++){
        ZM_VALUE_OF_VECTOR_AT(result, i) = element;
    }

    return result;

}

/*
*/
zm_Vec zm_new_random_float_vector(size_t dim, float min, float max){

    zm_Vec result = zm_alloc_vector(dim);

    srand((unsigned)time(NULL) * _getpid());
    for(size_t i = 0; i < dim; i++){
        ZM_VALUE_OF_VECTOR_AT(result, i) = zm_rand_float(min, max);
    }

    return result;
}

/*
*/
zm_Vec zm_new_random_int_vector(size_t dim, float min, float max){

    zm_Vec result = zm_alloc_vector(dim);

    srand((unsigned)time(NULL) * _getpid());
    for(size_t i = 0; i < dim; i++){
        ZM_VALUE_OF_VECTOR_AT(result, i) = zm_rand_int(min, max);
    }

    return result;
}

/*
*/
zm_Vec _zm_new_vector(size_t dim, ...){

    zm_Vec result = zm_alloc_vector(dim);

    va_list elem;
    va_start(elem, dim);

    for(size_t i = 0 ; i < dim; i++){
        ZM_VALUE_OF_VECTOR_AT(result, i) = va_arg(elem, double);
    }

    va_end(elem);

    return result;

}

/*
*/
zm_Vec zm_copy_vector(zm_Vec source){

    zm_Vec result = zm_alloc_vector(ZM_DIM_OF_VECTOR(source));

    for(size_t i = 0; i < ZM_DIM_OF_VECTOR(source); i++){
        ZM_VALUE_OF_VECTOR_AT(result , i) = ZM_VALUE_OF_VECTOR_AT(source, i);
    }

    return result;

}

/*
*/
zm_Vec zm_add_two_vectors(zm_Vec vector1 , zm_Vec vector2){

    zm_assert(ZM_DIM_OF_VECTOR(vector1) == ZM_DIM_OF_VECTOR(vector2), ZM_EQUAL_ERROR);

    zm_Vec result = zm_alloc_vector(ZM_DIM_OF_VECTOR(vector1));

    for(size_t i = 0; i < ZM_DIM_OF_VECTOR(vector1); i++){
        ZM_VALUE_OF_VECTOR_AT(result , i) = ZM_VALUE_OF_VECTOR_AT(vector1, i) + ZM_VALUE_OF_VECTOR_AT(vector2, i);
    }

    return result;

}

/*
*/
zm_Vec zm_add_vector_with_scalar(zm_Vec vector1 , float scalar){

    zm_Vec result = zm_alloc_vector(ZM_DIM_OF_VECTOR(vector1));

    for(size_t i = 0; i < ZM_DIM_OF_VECTOR(vector1); i++){
        ZM_VALUE_OF_VECTOR_AT(result , i) = ZM_VALUE_OF_VECTOR_AT(vector1, i) + scalar;
    }

    return result;
}
    
/*
*/
zm_Vec zm_subtract_two_vectors(zm_Vec vector1 , zm_Vec vector2){

    zm_assert(ZM_DIM_OF_VECTOR(vector1) == ZM_DIM_OF_VECTOR(vector2), ZM_EQUAL_ERROR);

    zm_Vec result = zm_alloc_vector(ZM_DIM_OF_VECTOR(vector1));

    for(size_t i = 0; i < ZM_DIM_OF_VECTOR(vector1); i++){
        ZM_VALUE_OF_VECTOR_AT(result , i) = ZM_VALUE_OF_VECTOR_AT(vector1, i) - ZM_VALUE_OF_VECTOR_AT(vector2, i);
    }

    return result;  
}

/*
*/
zm_Vec zm_subtract_vector_with_scalar(zm_Vec vector1 , float scalar){

    zm_Vec result = zm_alloc_vector(ZM_DIM_OF_VECTOR(vector1));

    for(size_t i = 0; i < ZM_DIM_OF_VECTOR(vector1); i++){
        ZM_VALUE_OF_VECTOR_AT(result , i) = ZM_VALUE_OF_VECTOR_AT(vector1, i) - scalar;
    }

    return result;
}

/*
*/
zm_Vec zm_multiply_two_vectors(zm_Vec vector1, zm_Vec vector2){

    zm_assert(ZM_DIM_OF_VECTOR(vector1) == ZM_DIM_OF_VECTOR(vector2), ZM_EQUAL_ERROR);

    zm_Vec result = zm_alloc_vector(ZM_DIM_OF_VECTOR(vector1));

    for(size_t i = 0; i < ZM_DIM_OF_VECTOR(vector1); i++){
        ZM_VALUE_OF_VECTOR_AT(result , i) = ZM_VALUE_OF_VECTOR_AT(vector1, i) * ZM_VALUE_OF_VECTOR_AT(vector2, i);
    }

    return result;  
}

/*
*/
zm_Vec zm_multiply_vector_by_scalar(zm_Vec vector1, float scalar){

    zm_Vec result = zm_alloc_vector(ZM_DIM_OF_VECTOR(vector1));

    for(size_t i = 0; i < ZM_DIM_OF_VECTOR(vector1); i++){
        ZM_VALUE_OF_VECTOR_AT(result , i) = ZM_VALUE_OF_VECTOR_AT(vector1, i) * scalar;
    }

    return result;
}

/*
*/
zm_Vec zm_divide_two_vectors(zm_Vec vector1, zm_Vec vector2){

    zm_assert(ZM_DIM_OF_VECTOR(vector1) == ZM_DIM_OF_VECTOR(vector2), ZM_EQUAL_ERROR);


    zm_Vec result = zm_alloc_vector(ZM_DIM_OF_VECTOR(vector1));

    for(size_t i = 0; i < ZM_DIM_OF_VECTOR(vector1); i++){
        if(ZM_VALUE_OF_VECTOR_AT(vector2 , i) == 0.0f) return NULL_VECTOR;
        ZM_VALUE_OF_VECTOR_AT(result , i) = ZM_VALUE_OF_VECTOR_AT(vector1, i) / ZM_VALUE_OF_VECTOR_AT(vector2, i);
    }

    return result;  
}

/*
*/
zm_Vec zm_divide_vector_by_scalar(zm_Vec vector1, float scalar){

    zm_Vec result = zm_alloc_vector(ZM_DIM_OF_VECTOR(vector1));

    for(size_t i = 0; i < ZM_DIM_OF_VECTOR(vector1); i++){
        ZM_VALUE_OF_VECTOR_AT(result , i) = ZM_VALUE_OF_VECTOR_AT(vector1, i) / scalar;
    }

    return result;
}

/*
*/
zm_Vec zm_raise_vector_to_exp(zm_Vec vector, size_t exponent){

    zm_Vec result = zm_copy_vector(vector);
    
    printf("\n");
    for(size_t i = 0; i < ZM_DIM_OF_VECTOR(result); i++){
        for(size_t j = 0; j < exponent; j++){
            ZM_VALUE_OF_VECTOR_AT(result, i) *= ZM_VALUE_OF_VECTOR_AT(vector, i);

            #if VISUALIZE_STEPS
            printf("%f -> %f |", ZM_VALUE_OF_VECTOR_AT(result, i) / ZM_VALUE_OF_VECTOR_AT(vector, i), ZM_VALUE_OF_VECTOR_AT(result, i));
            #endif
        }

        #if VISUALIZE_STEPS
        printf("\n");
        #endif
    }

    return result;

}

/*
*/
zm_Vec zm_cross_product(zm_Vec vector1, zm_Vec vector2){

    if(ZM_DIM_OF_VECTOR(vector1) != 3 || ZM_DIM_OF_VECTOR(vector2) != 3){
        return NULL_VECTOR;
    }

    zm_Vec result = zm_alloc_vector(3);

    ZM_VALUE_OF_VECTOR_AT(result , 0 ) = (ZM_VALUE_OF_VECTOR_AT(vector1, 1) * ZM_VALUE_OF_VECTOR_AT( vector2, 2)) - (ZM_VALUE_OF_VECTOR_AT(vector1 , 2) * ZM_VALUE_OF_VECTOR_AT(vector2 , 1));
    ZM_VALUE_OF_VECTOR_AT(result , 1 ) = -1 * (ZM_VALUE_OF_VECTOR_AT(vector1, 0) * ZM_VALUE_OF_VECTOR_AT( vector2, 2)) - (ZM_VALUE_OF_VECTOR_AT(vector1 , 2) * ZM_VALUE_OF_VECTOR_AT(vector2 , 0));
    ZM_VALUE_OF_VECTOR_AT(result , 2 ) = (ZM_VALUE_OF_VECTOR_AT(vector1, 0) * ZM_VALUE_OF_VECTOR_AT( vector2, 1)) - (ZM_VALUE_OF_VECTOR_AT(vector1 , 1) * ZM_VALUE_OF_VECTOR_AT(vector2 , 0));

    return result;
}

/*
*/
zm_Vec zm_normalized_vector(zm_Vec vector){

    zm_Vec result = zm_alloc_vector(ZM_DIM_OF_VECTOR(vector));
    float mag = zm_magnitude_of_vector(vector);

    for(size_t i = 0 ; i < ZM_DIM_OF_VECTOR(vector); i++){
        ZM_VALUE_OF_VECTOR_AT(result, i ) = ZM_VALUE_OF_VECTOR_AT(vector, i) / mag;
    }

    return result;

}

/*
*/
void zm_normalize_vector(zm_Vec* vector){

    float mag = zm_magnitude_of_vector(*vector);

    for(size_t i = 0 ; i < vector->dim; i++){
        vector->elements[i] /= mag;
    }
}

/*
*/
bool zm_are_two_vectors_equal(zm_Vec vector1, zm_Vec vector2){

    if(ZM_DIM_OF_VECTOR(vector1) != ZM_DIM_OF_VECTOR(vector2)) return false;

    for(size_t i = 0; i < ZM_DIM_OF_VECTOR(vector1); i++){
        if(ZM_VALUE_OF_VECTOR_AT(vector1, i) != ZM_VALUE_OF_VECTOR_AT(vector2, i)) return false;
    }

    return true;

}

/*
*/
bool zm_are_two_vectors_orthogonal(zm_Vec vector1, zm_Vec vector2){
    return zm_dot_two_vectors(vector1, vector2) == 0; 
}

/*
*/
bool zm_is_vector_normalized(zm_Vec vector){

    return fabs(zm_magnitude_of_vector(vector) - 1.0) < 0.0001;
}

/*
*/
float zm_dot_two_vectors(zm_Vec vector1, zm_Vec vector2){

    zm_assert(ZM_DIM_OF_VECTOR(vector1) == ZM_DIM_OF_VECTOR(vector2), ZM_EQUAL_ERROR);

    float result = 0.0f;

    for(size_t i = 0; i < ZM_DIM_OF_VECTOR(vector1); i++){
        result += ZM_VALUE_OF_VECTOR_AT(vector1, i) * ZM_VALUE_OF_VECTOR_AT(vector2, i);
    }

    return result;

}

/*
*/
float zm_magnitude_of_vector(zm_Vec vector){

    float result = 0.0f;

    for(size_t i = 0; i < ZM_DIM_OF_VECTOR(vector); i++){
        result += ZM_VALUE_OF_VECTOR_AT(vector, i) * ZM_VALUE_OF_VECTOR_AT(vector, i);
    }

    return sqrt(result);

}

zm_Matrix NULL_MATRIX = {0, 0, NULL};

/*
*/
void zm_print_matrix(FILE *fp, zm_Matrix mat){
	
	#if VISUALIZE_RATIONAL
	int spaces = 12;
    #else
    int spaces = 11;
    #endif

	fprintf(fp, "\n\n   | Matrix of size %ux%u: {\n", mat.rows, mat.cols);
	fprintf(fp, "   |\t\t%c   ", LEFT_UP_CORNER);
	for(unsigned int i = 0; i < mat.cols; i++){
		for(int i = 0; i < spaces; i++){
			fprintf(fp, " ");
		}	
	}
	fprintf(fp, "%c   \n", RIGHT_UP_CORNER);
	
	
	for(unsigned int i = 0; i < mat.rows; i++){
		
		fprintf(fp, "   |\t\t%c   ", SIDE_CHAR);
		
		for(unsigned int j = 0; j < mat.cols; j++){
            #if !VISUALIZE_RATIONAL
			fprintf(fp, "%-11f", ZM_VALUE_OF_MAT_AT(mat, i, j));
            #else
            zstring value = rationalizeFloatToStr(ZM_VALUE_OF_MAT_AT(mat, i, j), 3);
            fprintf(fp, " %-11s", value.data);
            #endif
		}		
		fprintf(fp, "%c\n", SIDE_CHAR);
	}
	
	fprintf(fp, "   |\t\t%c   ", LEFT_DOWN_CORNER);
	for(unsigned int i = 0; i < mat.cols; i++){
		for(int i = 0; i < spaces; i++){
			fprintf(fp, " ");
		}
	}
	fprintf(fp, "%c   \n", RIGHT_DOWN_CORNER);
    fprintf(fp, "   | }\n\n");
}

/*
*/
void zm_print_matrix_by_label(FILE *fp, const char* label, zm_Matrix mat){
	
	#if VISUALIZE_RATIONAL
	int spaces = 12;
    #else
    int spaces = 11;
    #endif

	fprintf(fp, "\n\n   | [%s] of size %ux%u: {\n", label, mat.rows, mat.cols);
	fprintf(fp, "   |\t\t%c   ", LEFT_UP_CORNER);
	for(unsigned int i = 0; i < mat.cols; i++){
		for(int i = 0; i < spaces; i++){
			fprintf(fp, " ");
		}	
	}
	fprintf(fp, "%c   \n", RIGHT_UP_CORNER);
	
	
	for(unsigned int i = 0; i < mat.rows; i++){
		
		fprintf(fp, "   |\t\t%c   ", SIDE_CHAR);
		
		for(unsigned int j = 0; j < mat.cols; j++){
            #if !VISUALIZE_RATIONAL
			fprintf(fp, "%-11f", ZM_VALUE_OF_MAT_AT(mat, i, j));
            #else
            zstring value = rationalizeFloatToStr(ZM_VALUE_OF_MAT_AT(mat, i, j), 3);
            fprintf(fp, " %-11s", value.data);
            #endif
		}		
		fprintf(fp, "%c\n", SIDE_CHAR);
	}
	
	fprintf(fp, "   |\t\t%c   ", LEFT_DOWN_CORNER);
	for(unsigned int i = 0; i < mat.cols; i++){
		for(int i = 0; i < spaces; i++){
			fprintf(fp, " ");
		}
	}
	fprintf(fp, "%c   \n", RIGHT_DOWN_CORNER);
    fprintf(fp, "   | }\n\n");
}

/*
*/
void zm_print_matrix_by_index(FILE *fp, unsigned int index, zm_Matrix mat){
	
    #if VISUALIZE_RATIONAL
	int spaces = 12;
    #else
    int spaces = 11;
    #endif

	fprintf(fp, "\n\n   | [MATRIX %d] of size %ux%u: {\n", index, mat.rows, mat.cols);
	fprintf(fp, "   |\t\t%c   ", LEFT_UP_CORNER);
	for(unsigned int i = 0; i < mat.cols; i++){
		for(int i = 0; i < spaces; i++){
			fprintf(fp, " ");
		}	
	}
	fprintf(fp, "%c   \n", RIGHT_UP_CORNER);
	
	
	for(unsigned int i = 0; i < mat.rows; i++){
		
		fprintf(fp, "   |\t\t%c   ", SIDE_CHAR);
		
		for(unsigned int j = 0; j < mat.cols; j++){
            #if !VISUALIZE_RATIONAL
			fprintf(fp, "%-11f", ZM_VALUE_OF_MAT_AT(mat, i, j));
            #else
            zstring value = rationalizeFloatToStr(ZM_VALUE_OF_MAT_AT(mat, i, j), 3);
            fprintf(fp, " %-11s", value.data);
            #endif
		}		
		fprintf(fp, "%c\n", SIDE_CHAR);
	}
	
	fprintf(fp, "   |\t\t%c   ", LEFT_DOWN_CORNER);
	for(unsigned int i = 0; i < mat.cols; i++){
		for(int i = 0; i < spaces; i++){
			fprintf(fp, " ");
		}
	}
	fprintf(fp, "%c   \n", RIGHT_DOWN_CORNER);
    fprintf(fp, "   | }\n\n");
}

/*
*/
void zm_free_matrix(zm_Matrix* mat){
    zm_assert(mat->elements != NULL, "Matrix must not be NULL.");

    free(mat->elements);
    mat->elements = NULL;
    mat->rows = 0;
    mat->cols = 0;
}

/*
*/
void zm_copy_matrix_pointer(zm_Matrix *source, zm_Matrix *dest){

    if(dest->elements == NULL){ 
        *dest= zm_alloc_matrix(source->rows, source->cols); 
    }

    dest->rows = source->rows;
    dest->cols = source->cols;
    dest->elements = source->elements;

}

/*
*/
zm_Matrix zm_alloc_matrix(unsigned int rows, unsigned int cols){

    zm_Matrix result;
    result.rows = rows;
    result.cols = cols;

    result.elements = (float**)malloc(rows*sizeof(float*));
    for(unsigned int i=0; i<rows; i++){
        result.elements[i] = (float*)malloc(cols*sizeof(float));
    }

    zm_assert(result.elements != NULL, ZM_ALLOC_ERROR);

    return result;

}

/*
*/
zm_Matrix zm_new_zero_matrix(unsigned int rows, unsigned int cols){

    zm_Matrix result = zm_alloc_matrix(rows, cols);

    for(unsigned int i = 0; i < rows; i++){
        for(unsigned int j = 0; j < cols; j++){
            ZM_VALUE_OF_MAT_AT(result, i, j) = 0.0f;
        }
    }

    return result;

}

/*
*/
zm_Matrix zm_new_random_float_matrix(unsigned int rows, unsigned int cols, float min, float max){

    zm_Matrix result = zm_alloc_matrix(rows, cols);
    
    srand((unsigned)time(NULL) * _getpid()); 
    for(unsigned int i = 0; i < rows; i++){
        for(unsigned int j = 0; j < cols; j++){
            ZM_VALUE_OF_MAT_AT(result, i, j) = zm_rand_float(min, max);
        }
    }

    return result;
   
}

/*
*/
zm_Matrix zm_new_random_int_matrix(unsigned int rows, unsigned int cols, int min, int max){

    zm_Matrix result = zm_alloc_matrix(rows, cols);

    srand((unsigned)time(NULL) * _getpid()); 
    for(unsigned int i = 0; i < rows; i++){
        for(unsigned int j = 0; j < cols; j++){
            ZM_VALUE_OF_MAT_AT(result, i, j) = (float)zm_rand_int(min, max);
        }
    }

    return result;
   
}

/*
*/
zm_Matrix zm_new_default_matrix(unsigned int rows, unsigned int cols, float value){

    zm_Matrix result = zm_alloc_matrix(rows, cols);

    for(unsigned int i = 0; i < rows; i++){
        for(unsigned int j = 0; j < cols; j++){
            ZM_VALUE_OF_MAT_AT(result, i, j) = value;
        }
    }

    return result;

}

zm_Matrix zm_new_identity_matrix(unsigned int ZM_DIM_OF_VECTOR){
    zm_Matrix result = zm_alloc_matrix(ZM_DIM_OF_VECTOR, ZM_DIM_OF_VECTOR);

    for(unsigned int i = 0; i < ZM_DIM_OF_VECTOR; i++){
        for(unsigned int j = 0; j < ZM_DIM_OF_VECTOR; j++){
            if(i == j){
                ZM_VALUE_OF_MAT_AT(result, i, j) = 1.0f;
            }else {
                ZM_VALUE_OF_MAT_AT(result, i, j) = 0.0f;
            }
        }
    }

    return result;

}

/*
*/
zm_Matrix _zm_new_matrix(unsigned int rows, unsigned int cols, unsigned int numVals, ...){

    zm_Matrix result = zm_alloc_matrix(rows, cols);

    va_list args;
    va_start(args, numVals);

    unsigned int vals = 0;

    for(unsigned int i = 0; i < result.rows; i++){
        for(unsigned int j = 0 ; j < result.cols; j++){
            if(vals++ < numVals){
                ZM_VALUE_OF_MAT_AT(result, i, j) =  va_arg(args, double);
            }else {
                ZM_VALUE_OF_MAT_AT(result, i, j) = 0.0f;
            }
        }
    }

    va_end(args);

    return result;

}

/*
*/
zm_Matrix zm_Vector_to_matrix(zm_Vec source, Direction dir){

    zm_assert(dir < DIR_COUNT, ZM_DIRECTION_ERROR);

    zm_Matrix result;

    switch(dir){
        case HORIZONTAL: {
            result = zm_alloc_matrix(1, ZM_DIM_OF_VECTOR(source));

            for(unsigned int i = 0; i < result.cols; i++){
                ZM_VALUE_OF_MAT_AT(result, 0, i) = source.elements[i];
            }       

        } break;
        case VERTICAL: {
            result = zm_alloc_matrix(source.dim, 1); 

            for(unsigned int i = 0; i < result.rows; i++){
                ZM_VALUE_OF_MAT_AT(result, i, 0) = source.elements[i];
            }  

        } break;
        default: break;
    }

    return result;

}

/*
*/
zm_Vec zm_Matrix_to_vector(zm_Matrix source){

    zm_Vec result = zm_alloc_vector(source.rows * source.cols);   

    for(unsigned int i = 0; i < source.rows; i++){
        for(unsigned int j = 0; j < source.cols; j++){
            result.elements[j + i * source.cols] = ZM_VALUE_OF_MAT_AT(source, i, j);
        }
    }

    return result;
}

/*
*/
zm_Vec zm_get_vector_from_matrix_row(zm_Matrix source, unsigned int row){

    row--;

    if(row > source.rows){ return NULL_VECTOR; }

    zm_Vec result = zm_alloc_vector(source.cols);   

    for(unsigned int i = 0; i < source.cols; i++){
        result.elements[i] = ZM_VALUE_OF_MAT_AT(source, row, i);
    }

    return result;
}

/*
*/
zm_Vec zm_get_vector_from_matrix_col(zm_Matrix source, unsigned int col){

    col--;

    if(col > source.cols){ return NULL_VECTOR; }

    zm_Vec result = zm_alloc_vector(source.rows);   

    for(unsigned int i = 0; i < source.cols; i++){
        result.elements[i] = ZM_VALUE_OF_MAT_AT(source, i, col);
    }

    return result;
}

/*
*/
zm_Matrix zm_add_two_matrices(zm_Matrix matrix1, zm_Matrix matrix2){

    zm_assert(matrix1.rows == matrix2.rows && matrix1.cols == matrix2.cols, ZM_EQUAL_ERROR);
    
    zm_Matrix result = zm_alloc_matrix(matrix1.rows, matrix1.cols);

    for(unsigned int i = 0; i < result.rows; i++){
        for(unsigned int j = 0; j < result.cols; j++){
            ZM_VALUE_OF_MAT_AT(result, i, j) = ZM_VALUE_OF_MAT_AT(matrix1, i, j) + ZM_VALUE_OF_MAT_AT(matrix2, i, j);
        }
    }

    return result;

}

/*
*/
zm_Matrix zm_add_matrix_with_scalar(zm_Matrix matrix1, float scalar){
    
    zm_Matrix result = zm_alloc_matrix(matrix1.rows, matrix1.cols);

    for(unsigned int i = 0; i < result.rows; i++){
        for(unsigned int j = 0; j < result.cols; j++){
            ZM_VALUE_OF_MAT_AT(result, i, j) = ZM_VALUE_OF_MAT_AT(matrix1, i, j) + scalar;
        }
    }

    return result;

}

/*
*/
zm_Matrix zm_subtract_two_matrices(zm_Matrix matrix1, zm_Matrix matrix2){

    zm_assert(matrix1.rows == matrix2.rows && matrix1.cols == matrix2.cols, ZM_EQUAL_ERROR);

    zm_Matrix result = zm_alloc_matrix(matrix1.rows, matrix1.cols);

    for(unsigned int i = 0; i < result.rows; i++){
        for(unsigned int j = 0; j < result.cols; j++){
            ZM_VALUE_OF_MAT_AT(result, i, j) = ZM_VALUE_OF_MAT_AT(matrix1, i, j) - ZM_VALUE_OF_MAT_AT(matrix2, i, j);
        }
    }

    return result;

}

/*
*/
zm_Matrix zm_subtract_matrix_with_scalar(zm_Matrix matrix1, float scalar){
    
    zm_Matrix result = zm_alloc_matrix(matrix1.rows, matrix1.cols);

    for(unsigned int i = 0; i < result.rows; i++){
        for(unsigned int j = 0; j < result.cols; j++){
            ZM_VALUE_OF_MAT_AT(result, i, j) = ZM_VALUE_OF_MAT_AT(matrix1, i, j) - scalar;
        }
    }

    return result;

}

/*
*/
zm_Matrix zm_multiply_two_matrices(zm_Matrix matrix1, zm_Matrix matrix2){

    zm_assert(matrix1.rows == matrix2.rows && matrix1.cols == matrix2.cols, ZM_EQUAL_ERROR);

    zm_Matrix result = zm_alloc_matrix(matrix1.rows, matrix1.cols);
    
    for(unsigned int i = 0; i < result.rows; i++){
        for(unsigned int j = 0; j < result.cols; j++){
            ZM_VALUE_OF_MAT_AT(result, i, j) = ZM_VALUE_OF_MAT_AT(matrix1, i, j) * ZM_VALUE_OF_MAT_AT(matrix2, i, j);
        }
    }

    return result;
    
}

/*
*/
zm_Matrix zm_multiply_matrix_by_scalar(zm_Matrix matrix1, float scalar){
    
    zm_Matrix result = zm_alloc_matrix(matrix1.rows, matrix1.cols);

    for(unsigned int i = 0; i < result.rows; i++){
        for(unsigned int j = 0; j < result.cols; j++){
            ZM_VALUE_OF_MAT_AT(result, i, j) = ZM_VALUE_OF_MAT_AT(matrix1, i, j) * scalar;
        }
    }

    return result;

}

/*
*/
zm_Matrix zm_divide_two_matrices(zm_Matrix matrix1, zm_Matrix matrix2){

    zm_assert(matrix1.rows == matrix2.rows && matrix1.cols == matrix2.cols, ZM_EQUAL_ERROR);

    zm_Matrix result = zm_alloc_matrix(matrix1.rows, matrix1.cols);

    for(unsigned int i = 0; i < result.rows; i++){
        for(unsigned int j = 0; j < result.cols; j++){
            if(ZM_VALUE_OF_MAT_AT(matrix2, i, j) != 0.0f){
                ZM_VALUE_OF_MAT_AT(result, i, j) = ZM_VALUE_OF_MAT_AT(matrix1, i, j) / ZM_VALUE_OF_MAT_AT(matrix2, i, j);
            }else {
                ZM_VALUE_OF_MAT_AT(result, i, j) = 0.0f;
            }
        }
    }

    return result;

}

/*
*/
zm_Matrix zm_divide_matrix_by_scalar(zm_Matrix matrix1, float scalar){
    
    zm_Matrix result = zm_alloc_matrix(matrix1.rows, matrix1.cols);

    for(unsigned int i = 0; i < result.rows; i++){
        for(unsigned int j = 0; j < result.cols; j++){
            if(scalar != 0.0f){
                ZM_VALUE_OF_MAT_AT(result, i, j) = ZM_VALUE_OF_MAT_AT(matrix1, i, j) / scalar;
            }else {
                return NULL_MATRIX;
            }
        }
    }

    return result;

}

/*
*/
zm_Matrix zm_dot_two_matrices(zm_Matrix matrix1, zm_Matrix matrix2){

    zm_assert(matrix1.cols == matrix2.rows, ZM_PROD_ERROR);

    zm_Matrix result = zm_alloc_matrix(matrix1.rows, matrix2.cols);
    
    for(unsigned int i = 0; i < result.rows; i++){
		for(unsigned int j = 0; j < result.cols; j++){
			ZM_VALUE_OF_MAT_AT(result, i, j) = 0;
			for(unsigned int k = 0; k < matrix2.rows; k++){
				ZM_VALUE_OF_MAT_AT(result, i, j) += ZM_VALUE_OF_MAT_AT(matrix1, i, k) * ZM_VALUE_OF_MAT_AT(matrix2, k, j); 
			}
		}
	}

    return result;

}

/*
*/
zm_Matrix zm_transposed_matrix(zm_Matrix source){
    zm_Matrix result = zm_alloc_matrix(source.cols, source.rows);

    for(unsigned int i = 0; i < result.rows; i++){
        for(unsigned int j = 0; j < result.rows; j++){
            ZM_VALUE_OF_MAT_AT(result, i, j) = ZM_VALUE_OF_MAT_AT(source, j, i);
        }
    }

    return result;
}


/*
*/
bool zm_swap_two_matrix_rows(zm_Matrix *source, unsigned int row1, unsigned int row2){


    if(row1 >= source->rows || row2 >= source->rows || row1 == row2){
        return false;
    }

    float* tmp = source->elements[row1];
    source->elements[row1] = source->elements[row2];
    source->elements[row2] = tmp; 

    return true;
}

/*
*/
bool zm_add_two_matrix_rows(zm_Matrix *source, unsigned int row1, unsigned int row2){


    if(row1 >= source->rows || row2 >= source->rows || row1 == row2){
        return false;
    }

    for(unsigned int i = 0; i < source->cols; i++){
        //source->elements[row1][i] += source->elements[row2][i];
        ZM_VALUE_OF_MAT_POINTER_AT(source, row1, i) += ZM_VALUE_OF_MAT_POINTER_AT(source, row2, i);
    }

    return true;
}

/*
*/
bool zm_multiply_two_matrix_rows(zm_Matrix *source, unsigned int row, int scalar){


    if(row >= source->rows || scalar == 0.0f){
        return false;
    }

    for(unsigned int i = 0; i < source->cols; i++){
        ZM_VALUE_OF_MAT_POINTER_AT(source, row, i)  *= scalar;
    }

    return true;
}

/*
*/
bool zm_multiply_add_two_matrix_rows(zm_Matrix *source, unsigned int row1, unsigned int row2, int scalar){


    if(row1 >= source->rows || row2 >= source->rows || 
       scalar == 0.0f || row1 == row2){
        return false;
    }

    for(unsigned int i = 0; i < source->cols; i++){
        //source->elements[row1][i] += source->elements[row2][i] * scalar;
        ZM_VALUE_OF_MAT_POINTER_AT(source, row1, i) += ZM_VALUE_OF_MAT_POINTER_AT(source, row2, i) * scalar;
    }

    return true;
}

/*
*/
void zm_to_echelon_form(zm_Matrix *source){

    unsigned int curRow = 0;

    for(unsigned int i = 0; i < source->cols; i++){
        
        #if VISUALIZE_STEPS
        printMatrixByIndex(curRow, *source);
        #endif

        unsigned int row = curRow;

        if(row >= source->rows) break;

        for(; row < source->rows; row++){
            if(ZM_VALUE_OF_MAT_POINTER_AT(source, row, i) != 0.0f) break;
        }

        if(row == source->rows) continue;

        zm_swap_two_matrix_rows(source, curRow, row);

        float factor = 1 / ZM_VALUE_OF_MAT_POINTER_AT(source, curRow, i);

        for(unsigned int col = i; col < source->cols; col++){
            ZM_VALUE_OF_MAT_POINTER_AT(source, curRow, col) *= factor;
        }

        for(row = curRow + 1; row < source->rows; row++){
            zm_multiply_add_two_matrix_rows(source, row, curRow, -1 * ZM_VALUE_OF_MAT_POINTER_AT(source, curRow, i));
        }

        curRow++;

    }

}

/*
*/
void zm_to_reduced_echelon_form(zm_Matrix *source){

    unsigned int curRow = 0;

    for(unsigned int i = 0; i < source->cols; i++){
        
        #if VISUALIZE_STEPS
        printMatrixByIndex(curRow, *source);
        #endif

        unsigned int row = curRow;

        if(row >= source->rows) break;

        for(; row < source->rows; row++){
            if(ZM_VALUE_OF_MAT_POINTER_AT(source, row, i) != 0.0f) break;
        }

        if(row == source->rows) continue;

        zm_swap_two_matrix_rows(source, curRow, row);

        float factor = 1 / ZM_VALUE_OF_MAT_POINTER_AT(source, curRow, i);

        for(unsigned int col = i; col < source->cols; col++){
            ZM_VALUE_OF_MAT_POINTER_AT(source, curRow, col) *= factor;
        }

        for(row = 0; row < source->rows; row++){
            if(row == curRow) continue;
            zm_multiply_add_two_matrix_rows(source, row, curRow, -1 * ZM_VALUE_OF_MAT_POINTER_AT(source, row, i));
        }

        curRow++;

    }
}

/*
*/
zm_Matrix zm_append_vector_to_matrix(zm_Matrix source, zm_Vec vector){

    zm_assert(source.rows == vector.dim, ZM_EQUAL_ERROR);
    
    zm_Matrix result = zm_alloc_matrix(source.rows, source.cols + 1);

    for(unsigned int i = 0; i < source.rows; i++){
        unsigned int j = 0;
        for(; j < source.cols; j++){
            #if VISUALIZE_DEBUG
            printf("%d\n", j);
            #endif
            ZM_VALUE_OF_MAT_AT(result, i, j) = ZM_VALUE_OF_MAT_AT(source, i, j);
        }
        ZM_VALUE_OF_MAT_AT(result, i, j) = ZM_VALUE_OF_VECTOR_AT(vector, i);
        #if VISUALIZE_DEBUG
        printf("%f at %d:%d\n", ZM_VALUE_OF_MAT_AT(result, i, j), i, j);
        #endif
    }

    return result;

}

/*
*/
zm_Matrix zm_append_matrix_to_matrix(zm_Matrix source, zm_Matrix matrix){

    zm_assert(source.rows == matrix.rows, ZM_EQUAL_ERROR);
    
    zm_Matrix result = zm_alloc_matrix(source.rows, source.cols + matrix.cols);

    for(unsigned int i = 0; i < source.rows; i++){
        unsigned int j = 0;
        for(; j < source.cols; j++){
            ZM_VALUE_OF_MAT_AT(result, i, j) = ZM_VALUE_OF_MAT_AT(source, i, j);
        }
        for(unsigned int k = 0; k < matrix.cols; k++){
            ZM_VALUE_OF_MAT_AT(result, i, k + j) = ZM_VALUE_OF_MAT_AT(matrix, i, k);
        }
        
    }

    return result;

}

/*
*/
zm_Matrix zm_get_sub_matrix(zm_Matrix source, unsigned int remRow, unsigned int remCol){

    remRow--;
    remCol--;

    zm_Matrix result = zm_alloc_matrix(source.rows - 1, source.cols - 1);

    unsigned int rowOffset = 0;
    for (unsigned int i = 0; i < result.rows; i++){
        unsigned int colOffset = 0;

        if (i == remRow){
            rowOffset++;
        }

        for (unsigned int j = 0; j < result.cols; j++){
            if (j == remCol)
            {
                colOffset++;
            }

            // assign value
            ZM_VALUE_OF_MAT_AT(result, i, j) = ZM_VALUE_OF_MAT_AT(source, i + rowOffset, j + colOffset);//source.elements[i + rowOffset][j + colOffset];
        }
    }

    return result;
}

/*
*/
float zm_determinant_of_matrix_old(zm_Matrix source){
    zm_assert(source.rows == source.cols, ZM_SQUARE_ERROR);

    if(source.rows == 1){
        return ZM_VALUE_OF_MAT_AT(source, 0, 0);  
    }

    float result = 0.0f;

    for(unsigned int i = 0; i < source.cols; i++){
        result += ZM_VALUE_OF_MAT_AT(source, 0 , i) * zm_cofactor_of_matrix_at_coord(source, 1, i + 1);
    }

    return result;

}

/*
*/
float zm_determinant_of_matrix(zm_Matrix source){
    if (source.rows != source.cols || source.rows == 0)
    {
        return 0.0f;
    }

    // initialize array
    unsigned int *skipCols = malloc(source.cols * sizeof(unsigned int));
    unsigned int noSkipCols = 0;

    float result = _zm_determinant_of_matrix(source, 1, 0, skipCols, &noSkipCols);

    free(skipCols);

    return result;
}

/*
*/
float _zm_determinant_of_matrix(zm_Matrix source,
                            unsigned int row,
                            unsigned int col,
                            unsigned int *skipCols,
                            unsigned int *noSkipCols){

    skipCols[*noSkipCols] = col;
    (*noSkipCols)++;

    /*if (row == source.rows - 1)
    {
        printf("");
    }*/

    // base case to return single element
    if (row == source.rows)
    {
        unsigned int i = source.cols;
        // find last column not in exclusion list
        if (*noSkipCols != 0)
        {
            if (skipCols[*noSkipCols - 1] != 0)
            {
                while (zm_is_in_array(skipCols, *noSkipCols, i))
                {
                    i--;
                }
                (*noSkipCols)--;
            }
        }
        return ZM_VALUE_OF_MAT_AT(source, row-1, i-1);//source.elements[row - 1][i - 1];
    }

    float result = 0.0f;
    char cofactorSign = 1;

    // cofactor expansion across current row
    for (unsigned int i = 1; i <= source.cols; i++)
    {
        // skip excluded cols
        if (zm_is_in_array(skipCols, *noSkipCols, i))
        {
            continue;
        }

        float res = 0.0f;
        if (ZM_VALUE_OF_MAT_AT(source, row-1, i-1) != 0.0f)
        {
            // recursive
            res = cofactorSign *
                  ZM_VALUE_OF_MAT_AT(source, row-1, i-1) *
                  _zm_determinant_of_matrix(source, row + 1, i, skipCols, noSkipCols);
        }

        result += res;
        cofactorSign = -cofactorSign;
    }

    // remove current column from the list
    (*noSkipCols)--;
    return result;
}

/*
*/
float zm_cofactor_of_matrix_at_coord(zm_Matrix source, unsigned int row, unsigned int col){

    // must be a square matrix with at least 1 row
    if (source.rows != source.cols || source.rows == 0)
    {
        return 0.0f;
    }

    // boundary condition
    if (row > source.rows || col > source.cols)
    {
        return 0.0f;
    }

    // alternate signs
    // if row + col is even, positive
    // if row + col is odd, negative
    char sign = ((row + col) & 1) == 0 ? 1 : -1;

    zm_Matrix subbedMat = zm_get_sub_matrix(source, row, col);

    // cofactor = sign * determinant of the matrix without row and col
    float result = sign * zm_determinant_of_matrix(subbedMat);

    zm_free_matrix(&subbedMat);

    return result;
}

/*
*/
zm_Matrix zm_cofactor_matrix(zm_Matrix source){

    // must be a square matrix with at least 1 row
    if (source.rows != source.cols || source.rows == 0)
    {
        return NULL_MATRIX;
    }

    zm_Matrix result = zm_alloc_matrix(source.rows, source.cols);

    for (unsigned int i = 0; i < result.rows; i++)
    {
        for (unsigned int j = 0; j < result.cols; j++)
        {
            ZM_VALUE_OF_MAT_AT(result, i, j) = zm_cofactor_of_matrix_at_coord(source, i + 1, j + 1);
        }
    }

    return result;
}

/*
*/
zm_Matrix zm_adjugate_matrix(zm_Matrix source){

    // must be a square matrix with at least 1 row
    if (source.rows != source.cols || source.rows == 0)
    {
        return NULL_MATRIX;
    }

    zm_Matrix result = zm_alloc_matrix(source.rows, source.cols);

    for (unsigned int i = 0; i < result.rows; i++)
    {
        for (unsigned int j = 0; j < result.cols; j++)
        {
            ZM_VALUE_OF_MAT_AT(result, i, j) = zm_cofactor_of_matrix_at_coord(source, j + 1, i + 1);
        }
    }

    return result;
}

/*
*/
bool zm_is_matrix_invertible(zm_Matrix source){

    // must be a square matrix with at least 1 row
    if (source.rows != source.cols || source.rows == 0)
    {
        return false;
    }

    return zm_determinant_of_matrix(source) != 0.0f;
}

/*
*/
zm_Matrix zm_inverse_of_matrix(zm_Matrix source){

    // must be a square matrix with at least 1 row
    if (source.rows != source.cols || source.rows == 0)
    {
        return NULL_MATRIX;
    }

    // get the adjugate
    zm_Matrix adj = zm_adjugate_matrix(source);

    // calculate the determinant using the adjugate
    float det = 0.0f;

    // expand across first row of the matrix
    for (unsigned int i = 0; i < source.cols; i++)
    {
        if (ZM_VALUE_OF_MAT_AT(source, 0, i) != 0.0f)
        {
            det += ZM_VALUE_OF_MAT_AT(source, 0, i) * ZM_VALUE_OF_MAT_AT(adj, i, 0); // [c][0] because the adjugate is the transpose of the cofactor matrix
        }
    }

    if (det == 0.0f)
    {
        return NULL_MATRIX;
    }

    // inverse = 1 / det * adj
    zm_Matrix result = zm_multiply_matrix_by_scalar(adj, 1.0f / det);

    zm_free_matrix(&adj);

    return result;
}

/*
*/
zm_Matrix zm_inverse_of_matrix_by_rref(zm_Matrix source){

    if (!zm_is_matrix_invertible(source))
    {
        return NULL_MATRIX;
    }

    // augment the identity matrix
    zm_Matrix idMat = zm_new_identity_matrix(source.rows);
    zm_Matrix opMat = zm_append_matrix_to_matrix(source, idMat);

    // row reduce the augmented matrix
    zm_to_reduced_echelon_form(&opMat);

    // take the right half of the matrix -> that is the inverse
    zm_Matrix result = zm_alloc_matrix(source.rows, source.cols);

    for (unsigned int i = 0; i < result.rows; i++)
    {
        for (unsigned int j = 0; j < result.cols; j++)
        {
            ZM_VALUE_OF_MAT_AT(result, i, j) = ZM_VALUE_OF_MAT_AT(opMat, i, result.cols + j);
        }
    }

    zm_free_matrix(&idMat);
    zm_free_matrix(&opMat);

    return result;
}

#endif // ZMATH_IMPLEMENTATION