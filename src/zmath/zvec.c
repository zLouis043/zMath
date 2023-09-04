#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>

#include "zmath.h"
#include "zvec.h"

zVec NULL_VECTOR = {0, NULL};

/*
*/
void printV(zVec vector){
    printf("\n\n   | Vector of size %zu: {\n   |\t[", DIM(vector));
    for(size_t i = 0; i < DIM(vector); i++){
        printf(" %f", ValueAt(vector, i));
        printf("%c", (i < DIM(vector) - 1 ? ',' : ' '));
    }
    printf("]\n   |  }\n\n");
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
        *dest= allocVector(source->dim); 
    }

    dest->dim = source->dim;
    dest->elements = source->elements;

}

/*
*/
zVec allocVector(size_t dim){
    zVec result;
    result.dim = dim;
    result.elements = malloc(dim);

    zassert(result.elements != NULL, ALLOC_ERROR);

    return result;
}

/*
*/
zVec newZeroVector(size_t dim){

    zVec result = allocVector(dim);

    for(size_t i = 0; i < dim; i++){
        ValueAt(result, i) = 0.0f;
    }

    return result;

}

/*
*/
zVec newDefaultVector(size_t dim, float element){

    zVec result = allocVector(dim);

    for(size_t i = 0; i < dim; i++){
        ValueAt(result, i) = element;
    }

    return result;

}

/*
*/
zVec _newZVector(size_t dim, ...){

    zVec result = allocVector(dim);

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

    zVec result = allocVector(DIM(source));

    for(size_t i = 0; i < DIM(source); i++){
        ValueAt(result , i) = ValueAt(source, i);
    }

    return result;

}

/*
*/
zVec sumVector(zVec vector1 , zVec vector2){

    zassert(DIM(vector1) == DIM(vector2), EQUAL_ERROR);

    zVec result = allocVector(DIM(vector1));

    for(size_t i = 0; i < DIM(vector1); i++){
        ValueAt(result , i) = ValueAt(vector1, i) + ValueAt(vector2, i);
    }

    return result;

}

/*
*/
zVec sumVectorByScalar(zVec vector1 , float scalar){

    zVec result = allocVector(DIM(vector1));

    for(size_t i = 0; i < DIM(vector1); i++){
        ValueAt(result , i) = ValueAt(vector1, i) + scalar;
    }

    return result;
}
    
/*
*/
zVec subVector(zVec vector1 , zVec vector2){

    zassert(DIM(vector1) == DIM(vector2), EQUAL_ERROR);

    zVec result = allocVector(DIM(vector1));

    for(size_t i = 0; i < DIM(vector1); i++){
        ValueAt(result , i) = ValueAt(vector1, i) - ValueAt(vector2, i);
    }

    return result;  
}

/*
*/
zVec subVectorByScalar(zVec vector1 , float scalar){

    zVec result = allocVector(DIM(vector1));

    for(size_t i = 0; i < DIM(vector1); i++){
        ValueAt(result , i) = ValueAt(vector1, i) - scalar;
    }

    return result;
}

/*
*/
zVec multVector(zVec vector1, zVec vector2){

    zassert(DIM(vector1) == DIM(vector2), EQUAL_ERROR);

    zVec result = allocVector(DIM(vector1));

    for(size_t i = 0; i < DIM(vector1); i++){
        ValueAt(result , i) = ValueAt(vector1, i) * ValueAt(vector2, i);
    }

    return result;  
}

/*
*/
zVec multVectorByScalar(zVec vector1, float scalar){

    zVec result = allocVector(DIM(vector1));

    for(size_t i = 0; i < DIM(vector1); i++){
        ValueAt(result , i) = ValueAt(vector1, i) * scalar;
    }

    return result;
}

/*
*/
zVec divVector(zVec vector1, zVec vector2){

    zassert(DIM(vector1) == DIM(vector2), EQUAL_ERROR);

    zVec result = allocVector(DIM(vector1));

    for(size_t i = 0; i < DIM(vector1); i++){
        ValueAt(result , i) = ValueAt(vector1, i) / ValueAt(vector2, i);
    }

    return result;  
}

/*
*/
zVec divVectorByScalar(zVec vector1, float scalar){

    zVec result = allocVector(DIM(vector1));

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

            #if VISUALIZE_DEBUG
            printf("%f -> %f |", ValueAt(result, i) / ValueAt(vector, i), ValueAt(result, i));
            #endif
        }

        #if VISUALIZE_DEBUG
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

    zVec result = allocVector(3);

    ValueAt(result , 0 ) = (ValueAt(vector1, 1) * ValueAt( vector2, 2)) - (ValueAt(vector1 , 2) * ValueAt(vector2 , 1));
    ValueAt(result , 1 ) = -1 * (ValueAt(vector1, 0) * ValueAt( vector2, 2)) - (ValueAt(vector1 , 2) * ValueAt(vector2 , 0));
    ValueAt(result , 2 ) = (ValueAt(vector1, 0) * ValueAt( vector2, 1)) - (ValueAt(vector1 , 1) * ValueAt(vector2 , 0));

    return result;
}

/*
*/
zVec normalizedVector(zVec vector){

    zVec result = allocVector(DIM(vector));
    float mag = magnitude(vector);

    for(size_t i = 0 ; i < DIM(vector); i++){
        ValueAt(result, i ) = ValueAt(vector, i) / mag;
    }

    return result;

}

/*
*/
zVec normalizeVector(zVec* vector){

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
