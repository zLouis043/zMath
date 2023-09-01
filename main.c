#include <stdio.h>

#define ZMATH_IMPLEMENTATION
#include "src/zmath.h"

int main(void){

    printf("\n----------------------------------------------------------------\n");

    printf("\nTEST: CREATE A NEW [VECTOR] {");
        zVec v1 = newZVector(1.0f, 2.0f, 3.0f, 4.0f);
        printV(v1);
    printf("}\n");

    printf("\nTEST: COPY FROM [VECTOR 1] TO [VECTOR 2] {");
        zVec v2 = newDefaultVector(4, 1.0f);
        printV(v2);
    printf("}\n");

    printf("\nTEST: SUM [VECTOR 1]AND [VECTOR 2] {");
        zVec v3 = sumVector(v1, v2);
        printV(v3);
    printf("}\n");

    printf("\nTEST: SUM [VECTOR 1] BY A SCALAR [2] {");
        v3 = sumVectorByScalar(v1, 2);
        printV(v3);
    printf("}\n");

    printf("\nTEST: SUBTRACT [VECTOR 1] AND [VECTOR 2] {");
        zVec v4 = subVector(v1, v2);
        printV(v4);
    printf("}\n");

    printf("\nTEST: SUBTRACT [VECTOR 1] BY A SCALAR [2] {");
        v4 = subVectorByScalar(v1, 2);
        printV(v4);

        freeZVector(&v4);
    printf("}\n");

    printf("\nTEST: MULTIPLY [VECTOR 1] AND [VECTOR 2] {");
        zVec v5 = multVector(v1, v2);
        printV(v5);
    printf("}\n");

    printf("\nTEST: MULTIPLY [VECTOR 1] BY A SCALAR [2] {");
        v5 = multVectorByScalar(v1, 2);
        printV(v5);

        freeZVector(&v5);
    printf("}\n");

    printf("\nTEST: DIVIDE [VECTOR 1] AND [VECTOR 2] {");
        zVec v6 = divVector(v1, v2);
        printV(v6);
    printf("}\n");

    printf("\nTEST: DIVIDE [VECTOR 1] BY A SCALAR [2] {");
        v6 = divVectorByScalar(v1, 2);
        printV(v6);

        freeZVector(&v6);
    printf("}\n");

    printf("\nTEST: RAISE THE [VECTOR 1] TO THE POWER OF [4] {");
        zVec v7 = powerVectorToExp(v1, 4);
        printV(v7);

        freeZVector(&v7);
    printf("}\n");

    printf("\nTEST: CREATE A NEW [VECTOR 8] ORTHOGONAL TO [VECTOR 1] {");
        zVec v8 = newZVector(-2.0f, 1.0f , -4.0f, 3.0f);
        printV(v8);
    printf("}\n");

    printf("\nTEST: CROSS PRODUCT BETWEEN [VECTOR 9] AND [VECTOR 10] {");
        zVec v9 = newZVector(-2.0f, 1.0f, -4.0);
        zVec v10 = newZVector(3.0f, 6.0f, -2.0);

        zVec v11 = crossProduct(v9, v10);
        printV(v11);
        
        freeZVector(&v9);
        freeZVector(&v10);
        freeZVector(&v11);
    printf("}\n");

    printf("\nTEST: NORMALIZE [VECTOR 3] WITH MAGNITUDE OF [%f] {", magnitude(v3));
        zVec v12 = normalizeVector(v3);
        printV(v12);
    printf("}\n");

    printf("\n----------------------------------------------------------------\n");

        printf("\n> Are [VECTOR 1] and [VECTOR 3] equal: %s\n", areVecEqual(v1, v3) ? "True" : "False"); 
        printf("\n> Dot product between [VECTOR 1] and [VECTOR 3]: %f\n", dotProduct(v1, v3));
        printf("\n> Are [VECTOR 1] and [VECTOR 8] orthogonal: %s\n", areVecOrthogonal(v1, v8) ? "True" : "False");
        printf("\n> Magnitude of [VECTOR 3]: %f\n", magnitude(v3));

    printf("\n----------------------------------------------------------------\n");

    freeZVector(&v3);
    freeZVector(&v8); 

    return 0;
}