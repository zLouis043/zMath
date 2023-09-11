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
void printMatrixByLabel(const char* label, zMat mat){
	
	int spaces = 11;
	printf("\n\n   | [%s] of size %zux%zu: {\n", label, mat.rows, mat.cols);
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
void printMatrixByIndex(unsigned int index, zMat mat){
	
	int spaces = 11;
	printf("\n\n   | [MATRIX %d] of size %zux%zu: {\n", index, mat.rows, mat.cols);
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

    result.elements = malloc(rows * sizeof(float));
    for(unsigned int i=0; i<rows; i++){
        result.elements[i] = malloc(cols * sizeof(float));
    }

    zassert(result.elements != NULL, ALLOC_ERROR);

    return result;

}

/*
*/
zMat newZeroZMatrix(unsigned int rows, unsigned int cols){

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
zMat newRandomFloatMatrix(unsigned int rows, unsigned int cols, float min, float max){

    zMat result = allocZMatrix(rows, cols);

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            ValueMatAt(result, i, j) = float_rand(min, max);
        }
    }

    return result;
   
}

/*
*/
zMat newRandomIntMatrix(unsigned int rows, unsigned int cols, int min, int max){

    zMat result = allocZMatrix(rows, cols);

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            ValueMatAt(result, i, j) = (float)int_rand(min, max);
        }
    }

    return result;
   
}

/*
*/
zMat newDefaultZMatrix(unsigned int rows, unsigned int cols, float value){

    zMat result = allocZMatrix(rows, cols);

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            ValueMatAt(result, i, j) = value;
        }
    }

    return result;

}

zMat idZMatrix(unsigned int dim){
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
zMat _newZMatrix(unsigned int rows, unsigned int cols, unsigned int numVals, ...){

    zMat result = allocZMatrix(rows, cols);

    int size = result.rows * result.cols;

    va_list args;
    va_start(args, numVals);

    unsigned int vals = 0;

    for(size_t i = 0; i < result.rows; i++){
        for(size_t j = 0 ; j < result.cols; j++){
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

            for(int i = 0; i < result.cols; i++){
                ValueMatAt(result, 0, i) = source.elements[i];
            }       

        } break;
        case VERTICAL: {
            result = allocZMatrix(source.dim, 1); 

            for(int i = 0; i < result.rows; i++){
                ValueMatAt(result, i, 0) = source.elements[i];
            }  

        } break;
    }

    return result;

}

/*
*/
zVec matrixToZVector(zMat source){

    zVec result = allocZVector(source.rows * source.cols);   

    for(int i = 0; i < source.rows; i++){
        for(int j = 0; j < source.cols; j++){
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

    for(int i = 0; i < source.cols; i++){
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

    for(int i = 0; i < source.cols; i++){
        result.elements[i] = ValueMatAt(source, i, col);
    }

    return result;
}

/*
*/
zMat addMatrixes(zMat matrix1, zMat matrix2){

    zassert(matrix1.rows == matrix2.rows && matrix1.cols == matrix2.cols, EQUAL_ERROR);
    
    zMat result = allocZMatrix(matrix1.rows, matrix1.cols);

    for(int i = 0; i < result.rows; i++){
        for(int j = 0; j < result.cols; j++){
            ValueMatAt(result, i, j) = ValueMatAt(matrix1, i, j) + ValueMatAt(matrix2, i, j);
        }
    }

    return result;

}

/*
*/
zMat addMatrixesByScalar(zMat matrix1, float scalar){
    
    zMat result = allocZMatrix(matrix1.rows, matrix1.cols);

    for(int i = 0; i < result.rows; i++){
        for(int j = 0; j < result.cols; j++){
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

    for(int i = 0; i < result.rows; i++){
        for(int j = 0; j < result.cols; j++){
            ValueMatAt(result, i, j) = ValueMatAt(matrix1, i, j) - ValueMatAt(matrix2, i, j);
        }
    }

    return result;

}

/*
*/
zMat subMatrixesByScalar(zMat matrix1, float scalar){
    
    zMat result = allocZMatrix(matrix1.rows, matrix1.cols);

    for(int i = 0; i < result.rows; i++){
        for(int j = 0; j < result.cols; j++){
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
    
    for(int i = 0; i < result.rows; i++){
        for(int j = 0; j < result.cols; j++){
            ValueMatAt(result, i, j) = ValueMatAt(matrix1, i, j) * ValueMatAt(matrix2, i, j);
        }
    }

    return result;
    
}

/*
*/
zMat mulMatrixesByScalar(zMat matrix1, float scalar){
    
    zMat result = allocZMatrix(matrix1.rows, matrix1.cols);

    for(int i = 0; i < result.rows; i++){
        for(int j = 0; j < result.cols; j++){
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

    for(int i = 0; i < result.rows; i++){
        for(int j = 0; j < result.cols; j++){
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

    for(int i = 0; i < result.rows; i++){
        for(int j = 0; j < result.cols; j++){
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
    
    for(int i = 0; i < result.rows; i++){
		for(int j = 0; j < result.cols; j++){
			ValueMatAt(result, i, j) = 0;
			for(int k = 0; k < matrix2.rows; k++){
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

    for(int i = 0; i < result.rows; i++){
        for(int j = 0; j < result.rows; j++){
            ValueMatAt(result, i, j) = ValueMatAt(source, j, i);
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

    for(int i = 0; i < source->cols; i++){
        source->elements[row1][i] += source->elements[row2][i];
    }

    return true;
}

/*
*/
bool mulRows(zMat *source, unsigned int row, int scalar){


    if(row >= source->rows || scalar == 0.0f){
        return false;
    }

    for(int i = 0; i < source->cols; i++){
        source->elements[row][i] *= scalar;
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

    for(int i = 0; i < source->cols; i++){
        source->elements[row1][i] += source->elements[row2][i] * scalar;
    }
}

/*
*/
void matrixToRowEchelonForm(zMat *source){

    unsigned int curRow = 0;

    for(int i = 0; i < source->cols; i++){
        
        #if VISUALIZE_STEPS
        printMatrixByIndex(curRow, *source);
        #endif

        unsigned int row = curRow;

        if(row >= source->rows) break;

        for(; row < source->rows; row++){
            if(source->elements[row][i] != 0.0f) break;
        }

        if(row == source->rows) continue;

        swapRows(source, curRow, row);

        float factor = 1 / source->elements[curRow][i];

        for(unsigned int col = i; col < source->cols; col++){
            source->elements[curRow][col] *= factor;
        }

        for(row = curRow + 1; row < source->rows; row++){
            addmulRows(source, row, curRow, -1 * source->elements[row][i]);
        }

        curRow++;

    }

}

/*
*/
void matrixToReducedRowEchelonForm(zMat *source){

    unsigned int curRow = 0;

    for(int i = 0; i < source->cols; i++){
        
        #if VISUALIZE_STEPS
        printMatrixByIndex(curRow, *source);
        #endif

        unsigned int row = curRow;

        if(row >= source->rows) break;

        for(; row < source->rows; row++){
            if(source->elements[row][i] != 0.0f) break;
        }

        if(row == source->rows) continue;

        swapRows(source, curRow, row);

        float factor = 1 / source->elements[curRow][i];

        for(unsigned int col = i; col < source->cols; col++){
            source->elements[curRow][col] *= factor;
        }

        for(row = 0; row < source->rows; row++){
            if(row == curRow) continue;
            addmulRows(source, row, curRow, -1 * source->elements[row][i]);
        }

        curRow++;

    }
}