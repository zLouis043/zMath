#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>

#include "zmath.h"
#include "zvec.h"
#include "zmatrix.h"

zMat NULL_MATRIX = {0, 0, NULL};

/*
*/
void printMatrix(zMat mat){
	
	int spaces = 11;
	printf("\n\n   | Matrix of size %zux%zu: {\n", mat.rows, mat.cols);
	printf("   |\t%c   ", LEFT_UP_CORNER);
	for(int i = 0; i < mat.cols; i++){
		for(int i = 0; i < spaces; i++){
			printf(" ");
		}	
	}
	printf("%c   \n", RIGHT_UP_CORNER);
	
	
	for(int i = 0; i < mat.rows; i++){
		
		printf("   |\t%c   ", SIDE_CHAR);
		
		for(int j = 0; j < mat.cols; j++){
			printf("%-11f", ValueMatAt(mat, i, j));
		}		
		printf("%c\n", SIDE_CHAR);
	}
	
	printf("   |\t%c   ", LEFT_DOWN_CORNER);
	for(int i = 0; i < mat.cols; i++){
		for(int i = 0; i < spaces; i++){
			printf(" ");
		}
	}
	printf("%c   \n", RIGHT_DOWN_CORNER);
    printf("   |  }\n\n");
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
void copyPtrMatrix(zMat *source, zMat *dest){

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

    result.elements = malloc(result.rows * sizeof(float));
    for(unsigned int i=0; i<result.rows; i++){
        result.elements[i] = malloc(result.cols * sizeof(float));
    }

    zassert(result.elements != NULL, ALLOC_ERROR);

    return result;

}

/*
*/
zMat newZeroMatrix(unsigned int rows, unsigned int cols){

    zMat result = allocZMatrix(rows, cols);

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            ValueMatAt(result, i, j) = 0.0f;
        }
    }

    return result;

}

/*
*/
zMat newDefaultMatrix(unsigned int rows, unsigned int cols, float value){

    zMat result = allocZMatrix(rows, cols);

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            ValueMatAt(result, i, j) = value;
        }
    }

    return result;

}

zMat idMatrix(unsigned int dim){
    zMat result = allocZMatrix(dim, dim);

    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
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
zMat newZMatrix(unsigned int rows, unsigned int cols, ...){

    zMat result = allocZMatrix(rows, cols);

    int size = result.rows * result.cols;

    va_list args;
    va_start(args, size);

    for(size_t i = 0; i < result.rows; i++){
        for(size_t j = 0 ; j < result.cols; j++){
            ValueMatAt(result, i, j) =  va_arg(args, double);
        }
    }

    va_end(args);

    return result;

}

zMat copyMatrix(zMat source){

    return source;
}

/*
*/
zVec getMatRow(zMat source, unsigned int row){

    row--;

    if(row < 0 || row >= source.rows){
        return NULL_VECTOR;
    }

    zVec result = allocVector(source.cols);
    for(int i = 0; i < source.cols; i++){
        result.elements[i] = ValueMatAt(source, row, i);
    }

    return result;
}

/*
*/
zVec getMatCol(zMat source, unsigned int col){

    col--;

    if(col < 0 || col  >= source.rows){
        return NULL_VECTOR;
    }

    zVec result = allocVector(source.rows);
    for(int i = 0; i < source.rows; i++){
        result.elements[i] = ValueMatAt(source, i, col);
    }

    return result;
}