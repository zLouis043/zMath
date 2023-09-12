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

#define VISUALIZE_RATIONAL 0

#define EQUAL_ERROR "Dimension mismatch."
#define ALLOC_ERROR "Allocation failure."
#define PROD_ERROR  "Matrix 1 columns not equal to Matrix 2 rows."
#define DIRECTION_ERROR "Invalid direction."
#define SQUARE_ERROR "Matrix is not square."

/*!
    Finds the maximum of two values
    @param n the first value
    @param m the second value
    @return the larger element
*/
#define MAX(n, m) ({\
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
#define MIN(n, m) ({\
    __auto_type _a = (n);\
    __auto_type _b = (m);\
    _a < _b ? _a : _b;\
})

/*!
    Alloc macro.
    @param count The size of the chunk to allocate.
    @param type The type of the chunk.
*/
#define alloc(count, type) \
    (type*)malloc((count) * sizeof(type))\

/*!
    Swap two values.
*/
#define swap(n, m) ({\
    typeof(n) _tmp = (n);\
    (n) = (m);\
    (m) = _tmp;\
})

/*!
    Checks if the condition is true and printf an error message and exit the program if it is false.
    @param condition The condition to check.
    @param message The message to send if the condition is false.
*/
void _zassert(bool condition, const char* message, const char* filepath, size_t line);

/*!
    Gives a random float random in a certain range.
    @param min The minimum value.
    @param max The maximum value.
    @return a random float value.
*/
float float_rand( float min, float max );

/*!
    Gives a random int random in a certain range.
    @param min The minimum value.
    @param max The maximum value.
    @return a random int value.
*/
int int_rand( int min, int max );
   
/*!
    Swap two int numbers.
    @param a the pointer to the first number.
    @param b the pointer to the second number.
*/
void swapInt(int* a, int* b);

/*!
    Swap two float numbers.
    @param a the pointer to the first number.
    @param b the pointer to the second number.
*/
void swapFloat(float* a, float* b);

/*!
    Checks if the array contains a value.
    @param arr The pointer to the array.
    @param n The number of elements in the array 
    @param target The target element.
    @return if the element exists in the array
*/
bool arrContains(unsigned int *arr, int n, float target);

/*!
    Checks if the condition is true and printf an error message and exit the program if it is false.
    @param condition The condition to check.
    @param message The message to send if the condition is false.
*/
#define zassert(condition, message) _zassert(condition, message, __FILE__, __LINE__)

#endif // MATHZ_DEF

#ifndef ZVEC_DEF
#define ZVEC_DEF

/*! 

    Struct that holds the dimensions of the vector and its components
    @param dim The dimension of the vector
    @param elements The element of the vector

*/
typedef struct zVec{
    size_t dim;
    float *elements;
}zVec;

extern zVec NULL_VECTOR;

/*!
    Prints the dimensions of the vector and its components.
    @param fp The file to write the vector.
    @param vector The vector to print.
*/
void printVector(FILE* fp, zVec vector);

/*!
    Prints the dimensions of the vector by its label and its components.
    @param fp The file to write the vector.
    @param label The vector label.
    @param vector The vector to print.
*/
void printVectorByLabel(FILE* fp, const char* label, zVec vector);

/*!
    Prints the dimensions of the vector by its index and its components.
    @param fp The file to write the vector.
    @param index The vector index.
    @param vector The vector to print.
*/
void printVectorByIndex(FILE* fp, int index, zVec vector);

/*!
    Free the vector and sets its dimension to 0.
*/
void freeZVector(zVec* vector);

/*!
    Copy one vector into another.
    @param source The vector to copy.
    @param dest The destination vector.
*/
void copyPtrVector(zVec* source, zVec* dest);

/*!
    Allocate memory for the vector.
    @param dim The dimension of the vector.
    @return The memory allocated. 
*/
zVec allocZVector(size_t dim);

/*!
    Create a new vector of dim Dimension with every component in the vector equal to 0.
    @param dim The dimension of the vector.
    @return The new vector with every element in the vector equal to 0.
*/
zVec newZeroZVector(size_t dim);

/*!
    Create a new vector of dim Dimension with every component in the vector equal to to element.
    @param dim The dimension of the vector.
    @param element The element of which the vector will be filled.
    @returnThe new vector with every component in the vector equal to element.
*/
zVec newDefaultZVector(size_t dim, float element);

/*!
    Create a new vector of dim Dimension.
    @param dim The dimension of the vector.
    @param ... The components of the vector.
    @return The new vector of dim Dimension.
*/
zVec _newZVector(size_t dim, ...);

/*!
    Copy the dimension and the components from a vector to another one.
    @param source The vector to copy.
    @return The copy of the vector.
*/
zVec copyVector(zVec source);

/*!
    Sums the two vectors.
    @param vector1
    @param vector2
    @return The sum between vector1 and vector2.
*/
zVec sumVector(zVec vector1 , zVec vector2);

/*!
    Sums a vector and a scalar.
    @param vector1
    @param scalar
    @return The sum between vector1 and a scalar.
*/
zVec sumVectorByScalar(zVec vector1 , float scalar);

/*!
    Sums the two vectors.
    @param vector1
    @param vector2
    @return The sum between vector1 and vector2.
*/
zVec subVector(zVec vector1 , zVec vector2);

/*!
    Subtract a vector and a scalar.
    @param vector1
    @param scalar
    @return The subtraction between vector1 and a scalar.
*/
zVec subVectorByScalar(zVec vector1 , float scalar);

/*!
    Multiply two vectors.
    @param vector1
    @param vector2
    @return The product between vector1 and  vector2.
*/
zVec multVector(zVec vector1, zVec vector2);

/*!
    Multiply a vector and a scalar.
    @param vector1
    @param scalar
    @return The product between vector1 and a scalar.
*/
zVec multVectorByScalar(zVec vector1, float scalar);

/*!
    Divide two vectors.
    @param vector1
    @param vector2
    @return The division between vector1 and  vector2.
*/
zVec divVector(zVec vector1, zVec vector2);

/*!
    Divide a vector and a scalar.
    @param vector1
    @param scalar
    @return The division between vector1 and a scalar.
*/
zVec divVectorByScalar(zVec vector1, float scalar);

/*!
    Raise every component of a vector to the exponent given.
    @param vector The vector to raise.
    @param exponent The exponent of the power.
    @return The vector raised to the exponent.
*/
zVec powerVectorToExp(zVec vector, size_t exponent);

/*!
    The cross product between two vectors.
    @param vector1
    @param vector2
    @return The cross product between two vectors.
*/
zVec crossProduct(zVec vector1, zVec vector2);

/*!
    This function return the normalized version of a vector given.
    @param vector The vector to normalize.
    @return The normalized vector.
*/
zVec normalizedVector(zVec vector);

/*!
    This function return the normalized version of a vector given.
    @param vector The vector pointer to normalize.
*/
void normalizeVector(zVec* vector);

/*!
    Checks if two vectors are equal.
    @param vector1
    @param vector2
    @return true if they are equal false if otherwise.
*/
bool areVecEqual(zVec vector1, zVec vector2);

/*!
    Checks if the two vectors are orthogonal.
    @param vector1.
    @param vector2.
    @return true if they are orthogonal false if otherwise
*/
bool areVecOrthogonal(zVec vector1, zVec vector2);

/*!
    Checks if the vector is normalized.
    @param vector The vector.
    @return true if the vector is normalized.
*/
bool isNormalized(zVec vector);

/*!
    This functions return the dot product of two vectors.
    @param vector1
    @param vector2
    @return The dot product of the two vectors.
*/
float dotProduct(zVec vector1, zVec vector2);

/*!
    This function return the magnitude of a vector.
    @param vector @
    @return The magnitude of the vector.
*/
float magnitude(zVec vector);


/*!
    Find the arguments given 
    @param type The type of the arguments.
    @param ... The variable arguments.
*/
#define NUMARGS(type, ...) (sizeof((type[]){0.0f, ##__VA_ARGS__}) / sizeof(type) - 1) 

/*!
    Create a new vector of dim Dimension.
    @param ... The components of the vector.
    @result The new vector of dim Dimension.
*/
#define newZVector(...) _newZVector(NUMARGS(float, ##__VA_ARGS__), __VA_ARGS__)

/*!
    Return the value of the specified vector at the specified index.
    @param vector The vector from which to retrieve the value.
    @param index The index where to retrieve the value.
    @result The value at the specified index.
*/
#define ValueAt(vector, index) (vector.elements[index])

/*!
    Return the value of the specified vector at the specified index.
    @param vector The vector from which to retrieve the value.
    @param index The index where to retrieve the value.
    @result The value at the specified index.
*/
#define ValuePtrAt(vector, index) (vector->elements[index])

/*!
    Return the dimension of the specified vector.
    @param vector The vector from which we pick the dimension.
    @result The dimension of the vector.
*/
#define DIM(vector) (vector.dim)

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
typedef struct zMatrix{
    unsigned int rows;
    unsigned int cols;
    float** elements;
}zMat;

extern zMat NULL_MATRIX;

/*!
    Prints the information about a matrix.
    @param fp The file to write the matrix.
    @param mat The matrix to print.
*/
void printMatrix(FILE *fp, zMat mat);

/*!
    Prints the information about a matrix with a label.
    @param fp The file to write the matrix.
    @param label The label of the matrix.
    @param mat The matrix to print.
*/
void printMatrixByLabel(FILE *fp, const char* label, zMat mat);

/*!
    Prints the information about a matrix with an index.
    @param fp The file to write the matrix.
    @param index The index of the matrix.
    @param mat The matrix to print.
*/
void printMatrixByIndex(FILE *fp, unsigned  index, zMat mat);

/*!
    Frees the matrix and set the rows and cols to 0.
    @param mat The matrix to free.
*/
void freeZMatrix(zMat* mat);

/*!
    Copy the source matrix to the destination matrix by the pointer.
    @param source The source matrix to copy.
    @param dest The destination matrix.
*/
void copyZMatrix(zMat *source, zMat *dest);

/*!
    Allocate memory chunk to the matrix through its rows and cols.
    @param rows The rows of the matrix.
    @param cols The cols of the matrix.
    @return The allocated memory chunk.
*/
zMat allocZMatrix(unsigned int rows, unsigned int cols);

/*!
    Create a matrix of rows * cols dimensions all set to 0.
    @param rows The rows of the matrix.
    @param cols The cols of the matrix.
    @return The matrix of rows * cols dimensions all set to 0.
*/
zMat newZeroZMatrix(unsigned int rows, unsigned int cols);

/*!
    Create a matrix of rows * cols dimension filled with random float values.
    @param rows The rows of the matrix.
    @param cols The cols of the matrix.
    @param min The minimum value.
    @param max The maximum value.
    @return The matrix of rows * cols dimension filled with random float values.
*/
zMat newRandomFloatMatrix(unsigned int rows, unsigned int cols, float min, float max);

/*!
    Create a matrix of rows * cols dimension filled with random int values.
    @param rows The rows of the matrix.
    @param cols The cols of the matrix.
    @param min The minimum value.
    @param max The maximum value.
    @return The matrix of rows * cols dimension filled with random int values.
*/
zMat newRandomIntMatrix(unsigned int rows, unsigned int cols, int min, int max);

/*!
    Create a matrix of rows * cols dimensions all set to a certain value.
    @param rows The rows of the matrix.
    @param cols The cols of the matrix.
    @param value The value used to fill the matrix.
    @return The matrix of rows * cols dimensions all set to a certain value.
*/
zMat newDefaultZMatrix(unsigned int rows, unsigned int cols, float value);

/*!
    Create a matrix of rows * cols dimensions all set to 0.0f except for the main diagonal that is set to 1.0f.
    @param dim The rows of the matrix.
    @return The matrix of rows * cols dimensions all set to 0.0f except for the main diagonal that is set to 1.0f. 
*/
zMat idZMatrix(unsigned int dim);

/*!
    Create a matrix of rows * cols dimensions.
    @param rows The rows of the matrix.
    @param cols The cols of the matrix.
    @param numVals the number of values inside the matrix.
    @return The matrix of rows * cols dimensions with the values specified.
*/
zMat _newZMatrix(unsigned int rows, unsigned int cols, unsigned int numVals, ...);

/*!
    Create a Row or a Col Matrix from a vector.
    @param source The source vector.
    @param dir Whether it will be a Row Matrix or a Col Matrix.
    @return The vector converted to a Matrix.
*/
zMat vecToZMatrix(zVec source, Direction dir);

/*!
    Create a vector from a matrix.
    @param source The source matrix.
    @return The vector converted from the Matrix.
*/
zVec matrixToZVector(zMat source);

/*!
    Create a vector from a matrix's row.
    @param source The source matrix.
    @param row The row that will be converted to a vector.
    @return The vector converted from the Matrix's row.
*/
zVec vecFromMatrixRow(zMat source, unsigned int row);

/*!
    Create a vector from a matrix's col.
    @param source The source matrix.
    @param col The col that will be converted to a vector.
    @return The vector converted from the Matrix's col.
*/
zVec vecFromMatrixCol(zMat source, unsigned int col);

/*!
    Add two matrices together.
    @param matrix1.
    @param matrix2.
    @return The sum of the two matrices.
*/
zMat addMatrixes(zMat matrix1, zMat matrix2);

/*!
    Add a scalar to every single element of the matrix.
    @param matrix1.
    @param scalar.
    @return The sum of every single element of the matrix to a certain scalar.
*/
zMat addMatrixesByScalar(zMat matrix1, float scalar);

/*!
    Subtract two matrices together.
    @param matrix1.
    @param matrix2.
    @return The subtracted of the two matrices.
*/
zMat subMatrixes(zMat matrix1, zMat matrix2);

/*!
    Subtract a scalar to every single element of the matrix.
    @param matrix1.
    @param scalar.
    @return The subtracted of every single element of the matrix to a certain scalar.
*/
zMat subMatrixesByScalar(zMat matrix1, float scalar);

/*!
    Multiply two matrices together.
    @param matrix1.
    @param matrix2.
    @return The product of the two matrices.
*/
zMat mulMatrixes(zMat matrix1, zMat matrix2);

/*!
    Multiply a scalar to every single element of the matrix.
    @param matrix1.
    @param scalar.
    @return The product of every single element of the matrix to a certain scalar.
*/
zMat mulMatrixesByScalar(zMat matrix1, float scalar);

/*!
    Divide two matrices together.
    @param matrix1.
    @param matrix2.
    @return The division of the two matrices.
*/
zMat divMatrixes(zMat matrix1, zMat matrix2);

/*!
    Divide a scalar to every single element of the matrix.
    @param matrix1.
    @param scalar.
    @return The division of every single element of the matrix to a certain scalar.
*/
zMat divMatrixesByScalar(zMat matrix1, float scalar);

/*!
    Multiply two matrices together by the rows per cols product.
    @param matrix1.
    @param matrix2
    @return The product of two matrices together by the rows per cols product.
*/
zMat rowsColsProd(zMat matrix1, zMat matrix2);

/*!
    Transpose a matrix.
    @param source The matrix to transpose.
    @return The transposed matrix.
*/
zMat transposedMatrix(zMat source);

/*!
    Swap two rows in a matrix.
    @param source The original matrix.
    @param row1.
    @param row2.
    @return The matrix in which row1 and row2 have been swapped.
*/
bool swapRows(zMat *source, unsigned int row1, unsigned int row2);

/*!
    Add two rows in a matrix.
    @param source The original matrix.
    @param row1.
    @param row2.
    @return The matrix in which row1 and row2 have been added.
*/
bool addRows(zMat *source, unsigned int row1, unsigned int row2);

/*!
    Multiply two rows in a matrix.
    @param source The original matrix.
    @param row1.
    @param row2.
    @return The matrix in which row1 and row2 have been multiplied.
*/
bool mulRows(zMat *source, unsigned int row, int scalar);

/*!
    Multiply one row to a scalar and then add it to the other row.
    @param source The original matrix.
    @param row1.
    @param row2.
    @return The matrix in which row2 have been multiplied to a scalar and then add it to the row1.
*/
bool addmulRows(zMat *source, unsigned int row1, unsigned int row2, int scalar);

/*!
    Convert a matrix to its Row Echelon Form.
    @param source The source matrix.
    @return The Row Echelon Form of the Matrix.
*/
void matrixToRowEchelonForm(zMat *source);

/*!
    Convert a matrix to its Reduced Row Echelon Form.
    @param source The source matrix.
    @return The Reduced Row Echelon Form of the Matrix.
*/
void matrixToReducedRowEchelonForm(zMat *source);

/*!
    Append a vector to a matrix.
    @param source The source matrix.
    @param vector The vector to append.
    @return The matrix with the added vector.
*/
zMat appendVectorToMatrix(zMat source, zVec vector);

/*!
    Append a matrix to a matrix.
    @param source The source matrix.
    @param matrix The matrix to append.
    @return The matrix with the added matrix.
*/
zMat appendMatrixToMatrix(zMat source, zMat matrix);

/*!
    Remove a row and a col from a matrix.
    @param source The source matrix.
    @param remRow The row to remove.
    @param remCol The col to remove.
    @return The sub Matrix with the row and col removed.
*/
zMat subMatrix(zMat source, unsigned int remRow, unsigned int remCol);

/*!
    Find the determinant of a matrix.
    @param source The source Matrix.
    @return The determinant of the matrix.
*/
float determinant(zMat source);

/*!
    Find the determinant of a matrix through cofactor expansion with an exclusion list.
    @param source The source Matrix.
    @return The determinant of the matrix.
*/
float determinantExclusion(zMat source);

/*!
    Calculate the determinant of a matrix through cofactor expansion using an exclusion list.
    @param source The source matrix.
    @param row The row to expand on.
    @param col The new column to exclude.
    @param skipCols The existing list of columns to exclude.
    @param noSkipCols The number of columns in the list to skip.
    @return The determinant.
*/
float _determinantExclusion(zMat source,
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
float cofactor(zMat source, unsigned int row, unsigned int col);

/*!
    Calculates the matrix in which the elements are the cofactor of every element of the source matrix.
    @param source The source matrix.
    @return The matrix in which the elements are the cofactor of every element of the source matrix.
*/
zMat cofactorMatrix(zMat source);

/*!
    Find the transpose of the cofactor Matrix.
    @param source The source matrix.
    @return The transpose of the cofactor Matrix.
*/
zMat adjugate(zMat source);

/*!
    Checks if the matrix is invertible.
    @param source The source matrix.
    @return true if the matrix is invertible and false otherwise.
*/
bool invertible(zMat source);

/*!
    Calculates the inverse of the source matrix.
    @param source The source matrix.
    @return The inverse of the source matrix.
*/
zMat inverseMatrix(zMat source);

/*!
    Calculates the inverse of the source matrix using Gaussian Elimination.
    @param source The source matrix.
    @return The inverse of the source matrix.
*/
zMat inverseMatrixRREF(zMat source);

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
#define ValueMatAt(matrix, x, y) (matrix.elements[x][y])

// double coords to single coord = rows * index + rows;
#define ValueMatPtrAt(matrix, x, y) (matrix->elements[x][y])


#define newZMatrix(rows, cols, ...)  _newZMatrix(rows, cols, rows*cols, __VA_ARGS__)

#endif // ZMATRIX_DEF

#ifdef ZMATH_IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <time.h>

#if VISUALIZE_RATIONAL
#define ZSTRING_IMPLEMENTATION
#include "zstring.h"
#endif

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

    int* tmp = a;
    a = b;
    b = tmp;

}

/*
*/
void swapFloat(float* a, float* b){
    
    float* tmp = a;
    a = b;
    b = tmp;
}

/*
*/
bool arrContains(unsigned int *arr, int n, float target){
    for (int i = 0; i < n; i++){
        if (arr[i] == target)
        {
            return true;
        }
    }

    return false;
}

zVec NULL_VECTOR = {0, NULL};

/*
*/
void printVector(FILE* fp, zVec vector){
    fprintf(fp ,"\n\n   | Vector of size %zu: {\n   |\t[", DIM(vector));
    for(size_t i = 0; i < DIM(vector); i++){
        #if !VISUALIZE_RATIONAL
        fprintf(fp ," %f", ValueAt(vector, i));
        #else
        zstring value = rationalizeFloatToStr(ValueAt(vector, i), 3);
        fprintf(fp, " %s", value.data);
        #endif
        fprintf(fp ,"%c", (i < DIM(vector) - 1 ? ',' : ' '));
    }
    fprintf(fp ,"]\n   |  }\n\n");
}

/*
*/
void printVectorByLabel(FILE* fp, const char* label, zVec vector){
    fprintf(fp ,"\n\n   | [%s] of size %zu: {\n   |\t[", label, DIM(vector));
    for(size_t i = 0; i < DIM(vector); i++){
        #if !VISUALIZE_RATIONAL 
        fprintf(fp ," %f", ValueAt(vector, i));
        #else
        zstring value = rationalizeFloatToStr(ValueAt(vector, i), 3);
        fprintf(fp, " %s", value.data);
        #endif
        fprintf(fp ,"%c", (i < DIM(vector) - 1 ? ',' : ' '));
    }
    fprintf(fp ,"]\n   |  }\n\n");
}

/*
*/
void printVectorByIndex(FILE* fp, int index, zVec vector){
    fprintf(fp ,"\n\n   | [VECTOR %d] of size %zu: {\n   |\t[", index, DIM(vector));
    for(size_t i = 0; i < DIM(vector); i++){
        #if !VISUALIZE_RATIONAL 
        fprintf(fp ," %f", ValueAt(vector, i));
        #else
        zstring value = rationalizeFloatToStr(ValueAt(vector, i), 3);
        fprintf(fp, " %s", value.data);
        #endif
        fprintf(fp ,"%c", (i < DIM(vector) - 1 ? ',' : ' '));
    }
    fprintf(fp ,"]\n   |  }\n\n");
}

/*
*/
void freeZVector(zVec* vector){

    zassert(vector != NULL, "Vector must not be NULL.");

    free(vector->elements);
    vector->elements = NULL;
    vector->dim = 0;
}

/*
*/
void copyPtrVector(zVec* source, zVec* dest){

    if(dest->elements == NULL){ 
        *dest= allocZVector(source->dim); 
    }

    dest->dim = source->dim;
    dest->elements = source->elements;

}

/*
*/
zVec allocZVector(size_t dim){
    zVec result;
    result.dim = dim;
    result.elements = alloc(dim, float);

    zassert(result.elements != NULL, ALLOC_ERROR);

    return result;
}

/*
*/
zVec newZeroZVector(size_t dim){

    zVec result = allocZVector(dim);

    for(size_t i = 0; i < dim; i++){
        ValueAt(result, i) = 0.0f;
    }

    return result;

}

/*
*/
zVec newDefaultZVector(size_t dim, float element){

    zVec result = allocZVector(dim);

    for(size_t i = 0; i < dim; i++){
        ValueAt(result, i) = element;
    }

    return result;

}

/*
*/
zVec _newZVector(size_t dim, ...){

    zVec result = allocZVector(dim);

    va_list elem;
    va_start(elem, dim);

    for(size_t i = 0 ; i < dim; i++){
        ValueAt(result, i) = va_arg(elem, double);
    }

    va_end(elem);

    return result;

}

/*
*/
zVec copyVector(zVec source){

    zVec result = allocZVector(DIM(source));

    for(size_t i = 0; i < DIM(source); i++){
        ValueAt(result , i) = ValueAt(source, i);
    }

    return result;

}

/*
*/
zVec sumVector(zVec vector1 , zVec vector2){

    zassert(DIM(vector1) == DIM(vector2), EQUAL_ERROR);

    zVec result = allocZVector(DIM(vector1));

    for(size_t i = 0; i < DIM(vector1); i++){
        ValueAt(result , i) = ValueAt(vector1, i) + ValueAt(vector2, i);
    }

    return result;

}

/*
*/
zVec sumVectorByScalar(zVec vector1 , float scalar){

    zVec result = allocZVector(DIM(vector1));

    for(size_t i = 0; i < DIM(vector1); i++){
        ValueAt(result , i) = ValueAt(vector1, i) + scalar;
    }

    return result;
}
    
/*
*/
zVec subVector(zVec vector1 , zVec vector2){

    zassert(DIM(vector1) == DIM(vector2), EQUAL_ERROR);

    zVec result = allocZVector(DIM(vector1));

    for(size_t i = 0; i < DIM(vector1); i++){
        ValueAt(result , i) = ValueAt(vector1, i) - ValueAt(vector2, i);
    }

    return result;  
}

/*
*/
zVec subVectorByScalar(zVec vector1 , float scalar){

    zVec result = allocZVector(DIM(vector1));

    for(size_t i = 0; i < DIM(vector1); i++){
        ValueAt(result , i) = ValueAt(vector1, i) - scalar;
    }

    return result;
}

/*
*/
zVec multVector(zVec vector1, zVec vector2){

    zassert(DIM(vector1) == DIM(vector2), EQUAL_ERROR);

    zVec result = allocZVector(DIM(vector1));

    for(size_t i = 0; i < DIM(vector1); i++){
        ValueAt(result , i) = ValueAt(vector1, i) * ValueAt(vector2, i);
    }

    return result;  
}

/*
*/
zVec multVectorByScalar(zVec vector1, float scalar){

    zVec result = allocZVector(DIM(vector1));

    for(size_t i = 0; i < DIM(vector1); i++){
        ValueAt(result , i) = ValueAt(vector1, i) * scalar;
    }

    return result;
}

/*
*/
zVec divVector(zVec vector1, zVec vector2){

    zassert(DIM(vector1) == DIM(vector2), EQUAL_ERROR);


    zVec result = allocZVector(DIM(vector1));

    for(size_t i = 0; i < DIM(vector1); i++){
        if(ValueAt(vector2 , i) == 0.0f) return NULL_VECTOR;
        ValueAt(result , i) = ValueAt(vector1, i) / ValueAt(vector2, i);
    }

    return result;  
}

/*
*/
zVec divVectorByScalar(zVec vector1, float scalar){

    zVec result = allocZVector(DIM(vector1));

    for(size_t i = 0; i < DIM(vector1); i++){
        ValueAt(result , i) = ValueAt(vector1, i) / scalar;
    }

    return result;
}

/*
*/
zVec powerVectorToExp(zVec vector, size_t exponent){

    zVec result = copyVector(vector);
    
    printf("\n");
    for(size_t i = 0; i < DIM(result); i++){
        for(size_t j = 0; j < exponent; j++){
            ValueAt(result, i) *= ValueAt(vector, i);

            #if VISUALIZE_STEPS
            printf("%f -> %f |", ValueAt(result, i) / ValueAt(vector, i), ValueAt(result, i));
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
zVec crossProduct(zVec vector1, zVec vector2){

    if(DIM(vector1) != 3 || DIM(vector2) != 3){
        return NULL_VECTOR;
    }

    zVec result = allocZVector(3);

    ValueAt(result , 0 ) = (ValueAt(vector1, 1) * ValueAt( vector2, 2)) - (ValueAt(vector1 , 2) * ValueAt(vector2 , 1));
    ValueAt(result , 1 ) = -1 * (ValueAt(vector1, 0) * ValueAt( vector2, 2)) - (ValueAt(vector1 , 2) * ValueAt(vector2 , 0));
    ValueAt(result , 2 ) = (ValueAt(vector1, 0) * ValueAt( vector2, 1)) - (ValueAt(vector1 , 1) * ValueAt(vector2 , 0));

    return result;
}

/*
*/
zVec normalizedVector(zVec vector){

    zVec result = allocZVector(DIM(vector));
    float mag = magnitude(vector);

    for(size_t i = 0 ; i < DIM(vector); i++){
        ValueAt(result, i ) = ValueAt(vector, i) / mag;
    }

    return result;

}

/*
*/
void normalizeVector(zVec* vector){

    float mag = magnitude(*vector);

    for(size_t i = 0 ; i < vector->dim; i++){
        vector->elements[i] /= mag;
    }
}

/*
*/
bool areVecEqual(zVec vector1, zVec vector2){

    if(DIM(vector1) != DIM(vector2)) return false;

    for(size_t i = 0; i < DIM(vector1); i++){
        if(ValueAt(vector1, i) != ValueAt(vector2, i)) return false;
    }

    return true;

}

/*
*/
bool areVecOrthogonal(zVec vector1, zVec vector2){
    return dotProduct(vector1, vector2) == 0; 
}

/*
*/
bool isNormalized(zVec vector){

    return fabs(magnitude(vector) - 1.0) < 0.0001;
}

/*
*/
float dotProduct(zVec vector1, zVec vector2){

    zassert(DIM(vector1) == DIM(vector2), EQUAL_ERROR);

    float result = 0.0f;

    for(size_t i = 0; i < DIM(vector1); i++){
        result += ValueAt(vector1, i) * ValueAt(vector2, i);
    }

    return result;

}

/*
*/
float magnitude(zVec vector){

    float result = 0.0f;

    for(size_t i = 0; i < DIM(vector); i++){
        result += ValueAt(vector, i) * ValueAt(vector, i);
    }

    return sqrt(result);

}

zMat NULL_MATRIX = {0, 0, NULL};

/*
*/
void printMatrix(FILE *fp, zMat mat){
	
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
			fprintf(fp, "%-11f", ValueMatAt(mat, i, j));
            #else
            zstring value = rationalizeFloatToStr(ValueMatAt(mat, i, j), 3);
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
void printMatrixByLabel(FILE *fp, const char* label, zMat mat){
	
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
			fprintf(fp, "%-11f", ValueMatAt(mat, i, j));
            #else
            zstring value = rationalizeFloatToStr(ValueMatAt(mat, i, j), 3);
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
void printMatrixByIndex(FILE *fp, unsigned int index, zMat mat){
	
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
			fprintf(fp, "%-11f", ValueMatAt(mat, i, j));
            #else
            zstring value = rationalizeFloatToStr(ValueMatAt(mat, i, j), 3);
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
void freeZMatrix(zMat* mat){
    zassert(mat->elements != NULL, "Matrix must not be NULL.");

    free(mat->elements);
    mat->elements = NULL;
    mat->rows = 0;
    mat->cols = 0;
}

/*
*/
void copyZMatrix(zMat *source, zMat *dest){

    if(dest->elements == NULL){ 
        *dest= allocZMatrix(source->rows, source->cols); 
    }

    dest->rows = source->rows;
    dest->cols = source->cols;
    dest->elements = source->elements;

}

/*
*/
zMat allocZMatrix(unsigned int rows, unsigned int cols){

    zMat result;
    result.rows = rows;
    result.cols = cols;

    result.elements = (float**)malloc(rows*sizeof(float*));
    for(unsigned int i=0; i<rows; i++){
        result.elements[i] = (float*)malloc(cols*sizeof(float));
    }

    zassert(result.elements != NULL, ALLOC_ERROR);

    return result;

}

/*
*/
zMat newZeroZMatrix(unsigned int rows, unsigned int cols){

    zMat result = allocZMatrix(rows, cols);

    for(unsigned int i = 0; i < rows; i++){
        for(unsigned int j = 0; j < cols; j++){
            ValueMatAt(result, i, j) = 0.0f;
        }
    }

    return result;

}

/*
*/
zMat newRandomFloatMatrix(unsigned int rows, unsigned int cols, float min, float max){

    zMat result = allocZMatrix(rows, cols);
    
    srand((unsigned)time(NULL)); 
    for(unsigned int i = 0; i < rows; i++){
        for(unsigned int j = 0; j < cols; j++){
            ValueMatAt(result, i, j) = float_rand(min, max);
        }
    }

    return result;
   
}

/*
*/
zMat newRandomIntMatrix(unsigned int rows, unsigned int cols, int min, int max){

    zMat result = allocZMatrix(rows, cols);

    srand((unsigned)time(NULL)); 
    for(unsigned int i = 0; i < rows; i++){
        for(unsigned int j = 0; j < cols; j++){
            ValueMatAt(result, i, j) = (float)int_rand(min, max);
        }
    }

    return result;
   
}

/*
*/
zMat newDefaultZMatrix(unsigned int rows, unsigned int cols, float value){

    zMat result = allocZMatrix(rows, cols);

    for(unsigned int i = 0; i < rows; i++){
        for(unsigned int j = 0; j < cols; j++){
            ValueMatAt(result, i, j) = value;
        }
    }

    return result;

}

zMat idZMatrix(unsigned int dim){
    zMat result = allocZMatrix(dim, dim);

    for(unsigned int i = 0; i < dim; i++){
        for(unsigned int j = 0; j < dim; j++){
            if(i == j){
                ValueMatAt(result, i, j) = 1.0f;
            }else {
                ValueMatAt(result, i, j) = 0.0f;
            }
        }
    }

    return result;

}

/*
*/
zMat _newZMatrix(unsigned int rows, unsigned int cols, unsigned int numVals, ...){

    zMat result = allocZMatrix(rows, cols);

    va_list args;
    va_start(args, numVals);

    unsigned int vals = 0;

    for(unsigned int i = 0; i < result.rows; i++){
        for(unsigned int j = 0 ; j < result.cols; j++){
            if(vals++ < numVals){
                ValueMatAt(result, i, j) =  va_arg(args, double);
            }else {
                ValueMatAt(result, i, j) = 0.0f;
            }
        }
    }

    va_end(args);

    return result;

}

/*
*/
zMat vecToZMatrix(zVec source, Direction dir){

    zassert(dir < DIR_COUNT, DIRECTION_ERROR);

    zMat result;

    switch(dir){
        case HORIZONTAL: {
            result = allocZMatrix(1, DIM(source));

            for(unsigned int i = 0; i < result.cols; i++){
                ValueMatAt(result, 0, i) = source.elements[i];
            }       

        } break;
        case VERTICAL: {
            result = allocZMatrix(source.dim, 1); 

            for(unsigned int i = 0; i < result.rows; i++){
                ValueMatAt(result, i, 0) = source.elements[i];
            }  

        } break;
        default: break;
    }

    return result;

}

/*
*/
zVec matrixToZVector(zMat source){

    zVec result = allocZVector(source.rows * source.cols);   

    for(unsigned int i = 0; i < source.rows; i++){
        for(unsigned int j = 0; j < source.cols; j++){
            result.elements[j + i * source.cols] = ValueMatAt(source, i, j);
        }
    }

    return result;
}

/*
*/
zVec vecFromMatrixRow(zMat source, unsigned int row){

    row--;

    if(row > source.rows){ return NULL_VECTOR; }

    zVec result = allocZVector(source.cols);   

    for(unsigned int i = 0; i < source.cols; i++){
        result.elements[i] = ValueMatAt(source, row, i);
    }

    return result;
}

/*
*/
zVec vecFromMatrixCol(zMat source, unsigned int col){

    col--;

    if(col > source.cols){ return NULL_VECTOR; }

    zVec result = allocZVector(source.rows);   

    for(unsigned int i = 0; i < source.cols; i++){
        result.elements[i] = ValueMatAt(source, i, col);
    }

    return result;
}

/*
*/
zMat addMatrixes(zMat matrix1, zMat matrix2){

    zassert(matrix1.rows == matrix2.rows && matrix1.cols == matrix2.cols, EQUAL_ERROR);
    
    zMat result = allocZMatrix(matrix1.rows, matrix1.cols);

    for(unsigned int i = 0; i < result.rows; i++){
        for(unsigned int j = 0; j < result.cols; j++){
            ValueMatAt(result, i, j) = ValueMatAt(matrix1, i, j) + ValueMatAt(matrix2, i, j);
        }
    }

    return result;

}

/*
*/
zMat addMatrixesByScalar(zMat matrix1, float scalar){
    
    zMat result = allocZMatrix(matrix1.rows, matrix1.cols);

    for(unsigned int i = 0; i < result.rows; i++){
        for(unsigned int j = 0; j < result.cols; j++){
            ValueMatAt(result, i, j) = ValueMatAt(matrix1, i, j) + scalar;
        }
    }

    return result;

}

/*
*/
zMat subMatrixes(zMat matrix1, zMat matrix2){

    zassert(matrix1.rows == matrix2.rows && matrix1.cols == matrix2.cols, EQUAL_ERROR);

    zMat result = allocZMatrix(matrix1.rows, matrix1.cols);

    for(unsigned int i = 0; i < result.rows; i++){
        for(unsigned int j = 0; j < result.cols; j++){
            ValueMatAt(result, i, j) = ValueMatAt(matrix1, i, j) - ValueMatAt(matrix2, i, j);
        }
    }

    return result;

}

/*
*/
zMat subMatrixesByScalar(zMat matrix1, float scalar){
    
    zMat result = allocZMatrix(matrix1.rows, matrix1.cols);

    for(unsigned int i = 0; i < result.rows; i++){
        for(unsigned int j = 0; j < result.cols; j++){
            ValueMatAt(result, i, j) = ValueMatAt(matrix1, i, j) - scalar;
        }
    }

    return result;

}

/*
*/
zMat mulMatrixes(zMat matrix1, zMat matrix2){

    zassert(matrix1.rows == matrix2.rows && matrix1.cols == matrix2.cols, EQUAL_ERROR);

    zMat result = allocZMatrix(matrix1.rows, matrix1.cols);
    
    for(unsigned int i = 0; i < result.rows; i++){
        for(unsigned int j = 0; j < result.cols; j++){
            ValueMatAt(result, i, j) = ValueMatAt(matrix1, i, j) * ValueMatAt(matrix2, i, j);
        }
    }

    return result;
    
}

/*
*/
zMat mulMatrixesByScalar(zMat matrix1, float scalar){
    
    zMat result = allocZMatrix(matrix1.rows, matrix1.cols);

    for(unsigned int i = 0; i < result.rows; i++){
        for(unsigned int j = 0; j < result.cols; j++){
            ValueMatAt(result, i, j) = ValueMatAt(matrix1, i, j) * scalar;
        }
    }

    return result;

}

/*
*/
zMat divMatrixes(zMat matrix1, zMat matrix2){

    zassert(matrix1.rows == matrix2.rows && matrix1.cols == matrix2.cols, EQUAL_ERROR);

    zMat result = allocZMatrix(matrix1.rows, matrix1.cols);

    for(unsigned int i = 0; i < result.rows; i++){
        for(unsigned int j = 0; j < result.cols; j++){
            if(ValueMatAt(matrix2, i, j) != 0.0f){
                ValueMatAt(result, i, j) = ValueMatAt(matrix1, i, j) / ValueMatAt(matrix2, i, j);
            }else {
                ValueMatAt(result, i, j) = 0.0f;
            }
        }
    }

    return result;

}

/*
*/
zMat divMatrixesByScalar(zMat matrix1, float scalar){
    
    zMat result = allocZMatrix(matrix1.rows, matrix1.cols);

    for(unsigned int i = 0; i < result.rows; i++){
        for(unsigned int j = 0; j < result.cols; j++){
            if(scalar != 0.0f){
                ValueMatAt(result, i, j) = ValueMatAt(matrix1, i, j) / scalar;
            }else {
                return NULL_MATRIX;
            }
        }
    }

    return result;

}

/*
*/
zMat rowsColsProd(zMat matrix1, zMat matrix2){

    zassert(matrix1.cols == matrix2.rows, PROD_ERROR);

    zMat result = allocZMatrix(matrix1.rows, matrix2.cols);
    
    for(unsigned int i = 0; i < result.rows; i++){
		for(unsigned int j = 0; j < result.cols; j++){
			ValueMatAt(result, i, j) = 0;
			for(unsigned int k = 0; k < matrix2.rows; k++){
				ValueMatAt(result, i, j) += ValueMatAt(matrix1, i, k) * ValueMatAt(matrix2, k, j); 
			}
		}
	}

    return result;

}

/*
*/
zMat transposedMatrix(zMat source){
    zMat result = allocZMatrix(source.cols, source.rows);

    for(unsigned int i = 0; i < result.rows; i++){
        for(unsigned int j = 0; j < result.rows; j++){
            ValueMatAt(result, i, j) = ValueMatAt(source, j, i);
        }
    }

    return result;
}

/*
*/
float dotProductMatrix(zMat matrix1, zMat matrix2){
    
    if(matrix1.rows != matrix2.rows || matrix1.cols != matrix2.cols) return 0.0f;

    float result = 0.0f;

    for(unsigned int i = 0; i < matrix1.rows; i++){
        for(unsigned int j = 0; j < matrix1.cols; j++){
            result += ValueMatAt(matrix1, i, j) * ValueMatAt(matrix2, i, j);
        }
    }

    return result;

}

/*
*/
bool swapRows(zMat *source, unsigned int row1, unsigned int row2){


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
bool addRows(zMat *source, unsigned int row1, unsigned int row2){


    if(row1 >= source->rows || row2 >= source->rows || row1 == row2){
        return false;
    }

    for(unsigned int i = 0; i < source->cols; i++){
        //source->elements[row1][i] += source->elements[row2][i];
        ValueMatPtrAt(source, row1, i) += ValueMatPtrAt(source, row2, i);
    }

    return true;
}

/*
*/
bool mulRows(zMat *source, unsigned int row, int scalar){


    if(row >= source->rows || scalar == 0.0f){
        return false;
    }

    for(unsigned int i = 0; i < source->cols; i++){
        ValueMatPtrAt(source, row, i)  *= scalar;
    }

    return true;
}

/*
*/
bool addmulRows(zMat *source, unsigned int row1, unsigned int row2, int scalar){


    if(row1 >= source->rows || row2 >= source->rows || 
       scalar == 0.0f || row1 == row2){
        return false;
    }

    for(unsigned int i = 0; i < source->cols; i++){
        //source->elements[row1][i] += source->elements[row2][i] * scalar;
        ValueMatPtrAt(source, row1, i) += ValueMatPtrAt(source, row2, i) * scalar;
    }

    return true;
}

/*
*/
void matrixToRowEchelonForm(zMat *source){

    unsigned int curRow = 0;

    for(unsigned int i = 0; i < source->cols; i++){
        
        #if VISUALIZE_STEPS
        printMatrixByIndex(curRow, *source);
        #endif

        unsigned int row = curRow;

        if(row >= source->rows) break;

        for(; row < source->rows; row++){
            if(ValueMatPtrAt(source, row, i) != 0.0f) break;
        }

        if(row == source->rows) continue;

        swapRows(source, curRow, row);

        float factor = 1 / ValueMatPtrAt(source, curRow, i);

        for(unsigned int col = i; col < source->cols; col++){
            ValueMatPtrAt(source, curRow, col) *= factor;
        }

        for(row = curRow + 1; row < source->rows; row++){
            addmulRows(source, row, curRow, -1 * ValueMatPtrAt(source, curRow, i));
        }

        curRow++;

    }

}

/*
*/
void matrixToReducedRowEchelonForm(zMat *source){

    unsigned int curRow = 0;

    for(unsigned int i = 0; i < source->cols; i++){
        
        #if VISUALIZE_STEPS
        printMatrixByIndex(curRow, *source);
        #endif

        unsigned int row = curRow;

        if(row >= source->rows) break;

        for(; row < source->rows; row++){
            if(ValueMatPtrAt(source, row, i) != 0.0f) break;
        }

        if(row == source->rows) continue;

        swapRows(source, curRow, row);

        float factor = 1 / ValueMatPtrAt(source, curRow, i);

        for(unsigned int col = i; col < source->cols; col++){
            ValueMatPtrAt(source, curRow, col) *= factor;
        }

        for(row = 0; row < source->rows; row++){
            if(row == curRow) continue;
            addmulRows(source, row, curRow, -1 * ValueMatPtrAt(source, row, i));
        }

        curRow++;

    }
}

/*
*/
zMat appendVectorToMatrix(zMat source, zVec vector){

    zassert(source.rows == vector.dim, EQUAL_ERROR);
    
    zMat result = allocZMatrix(source.rows, source.cols + 1);

    for(unsigned int i = 0; i < source.rows; i++){
        unsigned int j = 0;
        for(; j < source.cols; j++){
            #if VISUALIZE_DEBUG
            printf("%d\n", j);
            #endif
            ValueMatAt(result, i, j) = ValueMatAt(source, i, j);
        }
        ValueMatAt(result, i, j) = ValueAt(vector, i);
        #if VISUALIZE_DEBUG
        printf("%f at %d:%d\n", ValueMatAt(result, i, j), i, j);
        #endif
    }

    return result;

}

/*
*/
zMat appendMatrixToMatrix(zMat source, zMat matrix){

    zassert(source.rows == matrix.rows, EQUAL_ERROR);
    
    zMat result = allocZMatrix(source.rows, source.cols + matrix.cols);

    for(unsigned int i = 0; i < source.rows; i++){
        unsigned int j = 0;
        for(; j < source.cols; j++){
            ValueMatAt(result, i, j) = ValueMatAt(source, i, j);
        }
        for(unsigned int k = 0; k < matrix.cols; k++){
            ValueMatAt(result, i, k + j) = ValueMatAt(matrix, i, k);
        }
        
    }

    return result;

}

/*
*/
zMat subMatrix(zMat source, unsigned int remRow, unsigned int remCol){

    remRow--;
    remCol--;

    zMat result = allocZMatrix(source.rows - 1, source.cols - 1);

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
            ValueMatAt(result, i, j) = ValueMatAt(source, i + rowOffset, j + colOffset);//source.elements[i + rowOffset][j + colOffset];
        }
    }

    return result;
}

/*
*/
float determinant(zMat source){
    zassert(source.rows == source.cols, SQUARE_ERROR);

    if(source.rows == 1){
        return ValueMatAt(source, 0, 0);  
    }

    float result = 0.0f;

    for(unsigned int i = 0; i < source.cols; i++){
        result += ValueMatAt(source, 0 , i) * cofactor(source, 1, i + 1);
    }

    return result;

}

/*
*/
float determinantExclusion(zMat source){
    if (source.rows != source.cols || source.rows == 0)
    {
        return 0.0f;
    }

    // initialize array
    unsigned int *skipCols = malloc(source.cols * sizeof(unsigned int));
    unsigned int noSkipCols = 0;

    float result = _determinantExclusion(source, 1, 0, skipCols, &noSkipCols);

    free(skipCols);

    return result;
}

/*
*/
float _determinantExclusion(zMat source,
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
                while (arrContains(skipCols, *noSkipCols, i))
                {
                    i--;
                }
                (*noSkipCols)--;
            }
        }
        return ValueMatAt(source, row-1, i-1);//source.elements[row - 1][i - 1];
    }

    float result = 0.0f;
    char cofactorSign = 1;

    // cofactor expansion across current row
    for (unsigned int i = 1; i <= source.cols; i++)
    {
        // skip excluded cols
        if (arrContains(skipCols, *noSkipCols, i))
        {
            continue;
        }

        float res = 0.0f;
        if (ValueMatAt(source, row-1, i-1) != 0.0f)
        {
            // recursive
            res = cofactorSign *
                  ValueMatAt(source, row-1, i-1) *
                  _determinantExclusion(source, row + 1, i, skipCols, noSkipCols);
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
float cofactor(zMat source, unsigned int row, unsigned int col){

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

    zMat subbedMat = subMatrix(source, row, col);

    // cofactor = sign * determinant of the matrix without row and col
    float result = sign * determinantExclusion(subbedMat);

    freeZMatrix(&subbedMat);

    return result;
}

/*
*/
zMat cofactorMatrix(zMat source){

    // must be a square matrix with at least 1 row
    if (source.rows != source.cols || source.rows == 0)
    {
        return NULL_MATRIX;
    }

    zMat result = allocZMatrix(source.rows, source.cols);

    for (unsigned int i = 0; i < result.rows; i++)
    {
        for (unsigned int j = 0; j < result.cols; j++)
        {
            ValueMatAt(result, i, j) = cofactor(source, i + 1, j + 1);
        }
    }

    return result;
}

/*
*/
zMat adjugate(zMat source){

    // must be a square matrix with at least 1 row
    if (source.rows != source.cols || source.rows == 0)
    {
        return NULL_MATRIX;
    }

    zMat result = allocZMatrix(source.rows, source.cols);

    for (unsigned int i = 0; i < result.rows; i++)
    {
        for (unsigned int j = 0; j < result.cols; j++)
        {
            ValueMatAt(result, i, j) = cofactor(source, j + 1, i + 1);
        }
    }

    return result;
}

/*
*/
bool invertible(zMat source){

    // must be a square matrix with at least 1 row
    if (source.rows != source.cols || source.rows == 0)
    {
        return false;
    }

    return determinant(source) != 0.0f;
}

/*
*/
zMat inverseMatrix(zMat source){

    // must be a square matrix with at least 1 row
    if (source.rows != source.cols || source.rows == 0)
    {
        return NULL_MATRIX;
    }

    // get the adjugate
    zMat adj = adjugate(source);

    // calculate the determinant using the adjugate
    float det = 0.0f;

    // expand across first row of the matrix
    for (unsigned int i = 0; i < source.cols; i++)
    {
        if (ValueMatAt(source, 0, i) != 0.0f)
        {
            det += ValueMatAt(source, 0, i) * ValueMatAt(adj, i, 0); // [c][0] because the adjugate is the transpose of the cofactor matrix
        }
    }

    if (det == 0.0f)
    {
        return NULL_MATRIX;
    }

    // inverse = 1 / det * adj
    zMat result = mulMatrixesByScalar(adj, 1.0f / det);

    freeZMatrix(&adj);

    return result;
}

/*
*/
zMat inverseMatrixRREF(zMat source){

    if (!invertible(source))
    {
        return NULL_MATRIX;
    }

    // augment the identity matrix
    zMat idMat = idZMatrix(source.rows);
    zMat opMat = appendMatrixToMatrix(source, idMat);

    // row reduce the augmented matrix
    matrixToReducedRowEchelonForm(&opMat);

    // take the right half of the matrix -> that is the inverse
    zMat result = allocZMatrix(source.rows, source.cols);

    for (unsigned int i = 0; i < result.rows; i++)
    {
        for (unsigned int j = 0; j < result.cols; j++)
        {
            ValueMatAt(result, i, j) = ValueMatAt(opMat, i, result.cols + j);
        }
    }

    freeZMatrix(&idMat);
    freeZMatrix(&opMat);

    return result;
}

#endif // ZMATH_IMPLEMENTATION