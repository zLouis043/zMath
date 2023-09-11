#pragma once

#include <stdbool.h>

typedef enum {
    HORIZONTAL = 0,
    VERTICAL = 1,
    DIR_COUNT,
}Direction;

typedef struct zMatrix{
    unsigned int rows;
    unsigned int cols;
    float** elements;
}zMat;

extern zMat NULL_MATRIX;

/*!
*/
void printMatrix(zMat mat);

/*!
*/
void printMatrixByLabel(const char* label, zMat mat);

/*!
*/
void printMatrixByIndex(unsigned  index, zMat mat);

/*!
*/
void freeZMatrix(zMat* mat);

/*!
*/
void copyZMatrix(zMat *source, zMat *dest);

/*!
*/
zMat allocZMatrix(unsigned int rows, unsigned int cols);

/*!
*/
zMat newZeroZMatrix(unsigned int rows, unsigned int cols);

/*!
*/
zMat newRandomFloatMatrix(unsigned int rows, unsigned int cols, float min, float max);

/*!
*/
zMat newRandomIntMatrix(unsigned int rows, unsigned int cols, int min, int max);

/*!
*/
zMat newDefaultZMatrix(unsigned int rows, unsigned int cols, float value);

/*!
*/
zMat idZMatrix(unsigned int dim);

/*!
*/
zMat _newZMatrix(unsigned int rows, unsigned int cols, unsigned int numVals, ...);

/*!
*/
zMat vecToZMatrix(zVec source, Direction dir);

/*!
*/
zVec matrixToZVector(zMat source);

/*!
*/
zVec vecFromMatrixRow(zMat source, unsigned int row);

/*!
*/
zVec vecFromMatrixCol(zMat source, unsigned int col);

/*!
*/
zMat addMatrixes(zMat matrix1, zMat matrix2);

/*!
*/
zMat addMatrixesByScalar(zMat matrix1, float scalar);

/*!
*/
zMat subMatrixes(zMat matrix1, zMat matrix2);

/*!
*/
zMat subMatrixesByScalar(zMat matrix1, float scalar);

/*!
*/
zMat mulMatrixes(zMat matrix1, zMat matrix2);

/*!
*/
zMat mulMatrixesByScalar(zMat matrix1, float scalar);

/*!
*/
zMat divMatrixes(zMat matrix1, zMat matrix2);

/*!
*/
zMat divMatrixesByScalar(zMat matrix1, float scalar);

/*!
*/
zMat rowsColsProd(zMat matrix1, zMat matrix2);

/*!
*/
zMat transposedMatrix(zMat source);

/*!
*/
bool swapRows(zMat *source, unsigned int row1, unsigned int row2);

/*!
*/
bool addRows(zMat *source, unsigned int row1, unsigned int row2);

/*!
*/
bool mulRows(zMat *source, unsigned int row, int scalar);

/*!
*/
bool addmulRows(zMat *source, unsigned int row1, unsigned int row2, int scalar);

/*!
*/
void matrixToRowEchelonForm(zMat *source);

/*!
*/
void matrixToReducedRowEchelonForm(zMat *source);

/*!
*/
zMat appendVectorToMatrix(zMat source, zVec vector);

/*!
*/
zMat appendMatrixToMatrix(zMat source, zMat matrix);

/*!
*/
zMat subMatrix(zMat source, unsigned int remRow, unsigned int remCol);

/*!
*/
float determinant(zMat source);

/*
*/
float determinantExclusion(zMat source);

/*
*/
float _determinantExclusion(zMat source,
                            unsigned int row,
                            unsigned int col,
                            unsigned int *skipCols,
                            unsigned int *noSkipCols);

/*
*/
float cofactor(zMat source, unsigned int row, unsigned int col);

/*
*/
zMat cofactorMatrix(zMat source);

/*
*/
zMat adjugate(zMat source);

/*
*/
bool invertible(zMat source);

/*
*/
zMat inverseMatrix(zMat source);

/*
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




