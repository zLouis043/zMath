#pragma once

#include <stdbool.h>

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
void freeZMatrix(zMat* mat);

/*!
*/
void copyPtrMatrix(zMat *source, zMat *dest);

/*!
*/
zMat allocZMatrix(unsigned int rows, unsigned int cols);

/*!
*/
zMat newZeroMatrix(unsigned int rows, unsigned int cols);

/*!
*/
zMat newDefaultMatrix(unsigned int rows, unsigned int cols, float value);

/*!
*/
zMat idMatrix(unsigned int dim);

/*!
*/
zMat newZMatrix(unsigned int rows, unsigned int cols, ...);

/*!
*/
zMat copyMatrix(zMat source);

/*!
*/
zVec getMatRow(zMat source, unsigned int row);

/*!
*/
zVec getMatCol(zMat source, unsigned int col);

#define STRAIGHT_LINE 196
#define LEFT_UP_CORNER 218
#define RIGHT_UP_CORNER 191
#define SIDE_CHAR 179
#define LEFT_DOWN_CORNER 192
#define RIGHT_DOWN_CORNER 217

// double coords to single coord = rows * index + rows;
#define ValueMatAt(matrix, x, y) (matrix.elements[x][y])



