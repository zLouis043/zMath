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
    @param elements The element of the vector

*/
typedef struct zVec{
    size_t dim;
    float *elements;
}zVec;

const zVec NULL_VECTOR = {0, NULL};

/*!
    Prints the dimensions of the vector and its components.
*/
void printV(zVec vector);

/*!
    Checks if the condition is true and printf an error message and exit the program if it is false.
    @param condition The condition to check.
    @param message The message to send if the condition is false.
    @param filepath The path of the file where the assertion failed.
    @param line The line in the file where the assertion failed.
*/
void _zassert(bool condition, const char* message, const char* filepath, size_t line);

/*!
    Free the vector and sets its dimension to 0.
*/
void freeZVector(zVec* vector);

/*!
    Allocate memory for the vector.
    @param dim The dimension of the vector.
    @return The memory allocated. 
*/
zVec allocVector(size_t dim);

/*!
    Create a new vector of dim Dimension with every component in the vector equal to 0.
    @param dim The dimension of the vector.
    @return The new vector with every element in the vector equal to 0.
*/
zVec newZeroVector(size_t dim);

/*!
    Create a new vector of dim Dimension with every component in the vector equal to to element.
    @param dim The dimension of the vector.
    @param element The element of which the vector will be filled.
    @returnThe new vector with every component in the vector equal to element.
*/
zVec newDefaultVector(size_t dim, float element);

/*!
    Create a new vector of dim Dimension.
    @param dim The dimension of the vector.
    @param ... The components of the vector.
    @return The new vector of dim Dimension.
*/
zVec _newZVector(size_t dim, ...);

/*!
    Copy the dimension and the components from a vector to another one.
    @param vector The vector to copy.
    @return The copy of the vector.
*/
zVec copyVector(zVec vector);

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
zVec sumVectorByScalar(zVec vector1 , size_t scalar);

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
zVec subVectorByScalar(zVec vector1 , size_t scalar);

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
zVec multVectorByScalar(zVec vector1, size_t scalar);

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
zVec divVectorByScalar(zVec vector1, size_t scalar);

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
zVec normalizeVector(zVec* vector);

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
    Checks if the condition is true and printf an error message and exit the program if it is false.
    @param condition The condition to check.
    @param message The message to send if the condition is false.
*/
#define zassert(condition, message) _zassert(condition, message, __FILE__, __LINE__)

/*!
    Return the value of the specified vector at the specified index.
    @param vector The vector from which to retrieve the value.
    @param index The index where to retrieve the value.
    @result The value at the specified index.
*/
#define ValueAt(vector, index) (vector.elements[index])

/*!
    Return the dimension of the specified vector.
    @param vector The vector from which we pick the dimension.
    @result The dimension of the vector.
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
    if(!condition){
        fprintf(stderr, "[ERROR] : %s:%zu > %s\n", filepath, line, message);
        #if EXIT_ON_ASSERT_FAILURE 
            exit(EXIT_FAILURE);
        #endif
    }
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

    zassert(DIM(vector1) == DIM(vector2), EQUAL_ERROR);

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

    zassert(DIM(vector1) == DIM(vector2), EQUAL_ERROR);

    zVec result = allocVector(DIM(vector1));

    for(size_t i = 0; i < DIM(vector1); i++){
        ValueAt(result , i) = ValueAt(vector1, i) - ValueAt(vector2, i);
    }

    return result;  
}

/*
*/
zVec subVectorByScalar(zVec vector1 , size_t scalar){

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
zVec multVectorByScalar(zVec vector1, size_t scalar){

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
zVec divVectorByScalar(zVec vector1, size_t scalar){

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

#endif  // ZMATH_IMPLEMENTATION