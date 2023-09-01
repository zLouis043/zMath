#ifndef ZMATH_H_
#define ZMATH_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>

/*! 

    Struct that holds the dimensions of the vector and its components
    @param dim The dimension of the vector
    @param element The element of the vector

*/
typedef struct zVec{
    size_t dim;
    float *element;
}zVec;

const zVec NULL_VECTOR = {0, NULL};

/*
*/
void printV(zVec vector);

/*
*/
void _zassert(bool condition, const char* message, const char* filepath, size_t line);

/*
*/
void freeZVector(zVec* vector);

/*
*/
zVec allocVector(size_t dim);

/*
*/
zVec newEmptyVector(size_t dim);

/*
*/
zVec newDefaultVector(size_t dim, float element);

/*
*/
zVec _newZVector(size_t dim, ...);

/*
*/
zVec copyVector(zVec vector);

/*
*/
zVec sumVector(zVec vector1 , zVec vector2);

/*
*/
zVec sumVectorByScalar(zVec vector1 , size_t scalar);

/*
*/
zVec subVector(zVec vector1 , zVec vector2);

/*
*/
zVec subVectorByScalar(zVec vector1 , size_t scalar);

/*
*/
zVec multVector(zVec vector1, zVec vector2);

/*
*/
zVec multVectorByScalar(zVec vector1, size_t scalar);

/*
*/
zVec divVector(zVec vector1, zVec vector2);

/*
*/
zVec divVectorByScalar(zVec vector1, size_t scalar);

/*
*/
zVec powerVectorToExp(zVec vector, size_t exponent);

/*
*/
zVec crossProduct(zVec vector1, zVec vector2);

/*
*/
zVec normalizeVector(zVec vector);

/*
*/
bool areVecEqual(zVec vector1, zVec vector2);

/*
*/
bool areVecOrthogonal(zVec vector1, zVec vector2);

/*
*/
float dotProduct(zVec vector1, zVec vector2);

/*
*/
float magnitude(zVec vector);

#ifndef ZMATH_DEF
#define ZMATH_DEF

#define EQUAL_ERROR "Dimension mismatch."
#define ALLOC_ERROR "Allocation failure."

/*
*/
#define NUMARGS(type, ...) (sizeof((type[]){0.0f, ##__VA_ARGS__}) / sizeof(type) - 1) 

/*
*/
#define newZVector(...) _newZVector(NUMARGS(float, ##__VA_ARGS__), __VA_ARGS__)

/*
*/
#define zassert(condition, message) _zassert(condition, message, __FILE__, __LINE__)

/*
*/
#define ValueAt(vector, index) (vector.element[index])

/*
*/
#define DIM(vector) (vector.dim)

#endif // ZMATH_DEF 

#endif // ZMATH_H_

#ifdef ZMATH_IMPLEMENTATION

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
void _zassert(bool condition, const char* message, const char* filepath, size_t line){
    if(condition){
        fprintf(stderr, "[ERROR] : %s:%zu > %s\n", filepath, line, message);
        #if EXIT_ON_ASSERT_FAILURE 
            exit(EXIT_FAILURE);
        #endif
    }
}

/*
*/
void freeZVector(zVec* vector){
    free(vector->element);
    vector->element = NULL;
    vector->dim = 0;
}

/*
*/
zVec allocVector(size_t dim){
    zVec result;
    result.dim = dim;
    result.element = malloc(dim);

    zassert(result.element == NULL, ALLOC_ERROR);

    return result;
}

/*
*/
zVec newEmptyVector(size_t dim){

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
zVec copyVector(zVec vector){

    zVec result = allocVector(DIM(vector));

    for(size_t i = 0; i < DIM(vector); i++){
        ValueAt(result , i) = ValueAt(vector, i);
    }

    return result;

}

/*
*/
zVec sumVector(zVec vector1 , zVec vector2){

    zassert(DIM(vector1) != DIM(vector2), EQUAL_ERROR);

    zVec result = allocVector(DIM(vector1));

    for(size_t i = 0; i < DIM(vector1); i++){
        ValueAt(result , i) = ValueAt(vector1, i) + ValueAt(vector2, i);
    }

    return result;

}

/*
*/
zVec sumVectorByScalar(zVec vector1 , size_t scalar){

    zVec result = allocVector(DIM(vector1));

    for(size_t i = 0; i < DIM(vector1); i++){
        ValueAt(result , i) = ValueAt(vector1, i) + scalar;
    }

    return result;
}
    
/*
*/
zVec subVector(zVec vector1 , zVec vector2){

    zassert(DIM(vector1) != DIM(vector2), EQUAL_ERROR);

    zVec result = allocVector(DIM(vector1));

    for(size_t i = 0; i < DIM(vector1); i++){
        ValueAt(result , i) = ValueAt(vector1, i) + ValueAt(vector2, i);
    }

    return result;  
}

/*
*/
zVec subVectorByScalar(zVec vector1 , size_t scalar){

    zVec result = allocVector(DIM(vector1));

    for(size_t i = 0; i < DIM(vector1); i++){
        ValueAt(result , i) = ValueAt(vector1, i) + scalar;
    }

    return result;
}

/*
*/
zVec multVector(zVec vector1, zVec vector2){

    zassert(DIM(vector1) != DIM(vector2), EQUAL_ERROR);

    zVec result = allocVector(DIM(vector1));

    for(size_t i = 0; i < DIM(vector1); i++){
        ValueAt(result , i) = ValueAt(vector1, i) + ValueAt(vector2, i);
    }

    return result;  
}

/*
*/
zVec multVectorByScalar(zVec vector1, size_t scalar){

    zVec result = allocVector(DIM(vector1));

    for(size_t i = 0; i < DIM(vector1); i++){
        ValueAt(result , i) = ValueAt(vector1, i) + scalar;
    }

    return result;
}

/*
*/
zVec divVector(zVec vector1, zVec vector2){

    zassert(DIM(vector1) != DIM(vector2), EQUAL_ERROR);

    zVec result = allocVector(DIM(vector1));

    for(size_t i = 0; i < DIM(vector1); i++){
        ValueAt(result , i) = ValueAt(vector1, i) + ValueAt(vector2, i);
    }

    return result;  
}

/*
*/
zVec divVectorByScalar(zVec vector1, size_t scalar){

    zVec result = allocVector(DIM(vector1));

    for(size_t i = 0; i < DIM(vector1); i++){
        ValueAt(result , i) = ValueAt(vector1, i) + scalar;
    }

    return result;
}

/*
*/
zVec powerVectorToExp(zVec vector, size_t exponent){

    zVec result = allocVector(DIM(vector));
    result = copyVector(vector);

    for(size_t i = 0; i < DIM(vector); i++){
        for(size_t j = 0; j < exponent; j++){
            ValueAt(result, i) *= ValueAt(vector, i);
        }
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

    ValueAt(result , 0 ) = (ValueAt(vector1, 1) * ValueAt( vector1, 2)) - (ValueAt(vector1 , 2) * ValueAt(vector1 , 1));
    ValueAt(result , 1 ) = -1 * (ValueAt(vector1, 0) * ValueAt( vector1, 2)) - (ValueAt(vector1 , 2) * ValueAt(vector1 , 0));
    ValueAt(result , 2 ) = (ValueAt(vector1, 0) * ValueAt( vector1, 1)) - (ValueAt(vector1 , 1) * ValueAt(vector1 , 0));

    return result;
}

/*
*/
zVec normalizeVector(zVec vector){

    zVec result = allocVector(DIM(vector));
    float mag = magnitude(vector);

    for(size_t i = 0 ; i < DIM(vector); i++){
        ValueAt(result, i ) = ValueAt(vector, i) / mag;
    }

    return result;

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
float dotProduct(zVec vector1, zVec vector2){

    zassert(DIM(vector1) != DIM(vector2), EQUAL_ERROR);

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

#endif  // ZMATH_IMPLEMENTATION