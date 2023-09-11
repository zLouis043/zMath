#pragma once

#include <stdbool.h>


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
    @param mat The matrix to print.
*/
void printMatrix(zMat mat);

/*!
    Prints the information about a matrix with a labe.
    @param label The label of the matrix.
    @param mat The matrix to print.
*/
void printMatrixByLabel(const char* label, zMat mat);

/*!
    Prints the information about a matrix with an index.
    @param index The index of the matrix.
    @param mat The matrix to print.
*/
void printMatrixByIndex(unsigned  index, zMat mat);

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

#define STRAIGHT_LINE 196
#define LEFT_UP_CORNER 218
#define RIGHT_UP_CORNER 191
#define SIDE_CHAR 179
#define LEFT_DOWN_CORNER 192
#define RIGHT_DOWN_CORNER 217

// double coords to single coord = rows * index + rows;
#define ValueMatAt(matrix, x, y) (matrix.elements[x][y])

// double coords to single coord = rows * index + rows;
#define ValueMatPtrAt(matrix, x, y) (matrix->elements[x][y])

#define newZMatrix(rows, cols, ...)  _newZMatrix(rows, cols, rows*cols, __VA_ARGS__)




