#pragma once 

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

extern zVec NULL_VECTOR;

/*!
    Prints the dimensions of the vector and its components.
*/
void printV(zVec vector);

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

#ifndef ZVEC_DEF
#define ZVEC_DEF

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
    Return the dimension of the specified vector.
    @param vector The vector from which we pick the dimension.
    @result The dimension of the vector.
*/
#define DIM(vector) (vector.dim)

#endif // ZVEC_DEF 


