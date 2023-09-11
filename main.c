#include <stdio.h>

#include "src/zmath/zmath.h"
#include "src/zmath/zvec.h"
#include "src/zmath/zmatrix.h"

int main(void){


    printf("\n -----------------------------------------------\n");
    printf("|                   VECTORS                     |\n");
    printf(" -----------------------------------------------\n");
 
    printf("\nTEST: CREATE A NEW [VECTOR] {");
        zVec v1 = newZVector(1.0f, 2.0f, 3.0f, 4.0f);
        printVectorByIndex(1, v1);
    printf("}\n");

    printf("\nTEST: COPY FROM [VECTOR 1] TO [VECTOR 2] {");
        zVec v2;
        copyPtrVector(&v1, &v2);
        printVectorByIndex(2, v2);
    printf("}\n");

    printf("\nTEST: SUM [VECTOR 1]AND [VECTOR 2] {");
        zVec v3 = sumVector(v1, v2);
        printVectorByLabel("SUM VECTOR", v3);
    printf("}\n");

    printf("\nTEST: SUM [VECTOR 1] BY A SCALAR [2] {");
        v3 = sumVectorByScalar(v1, 2.0f);
        printVectorByLabel("SUM VECTOR", v3);
    printf("}\n");

    printf("\nTEST: SUBTRACT [VECTOR 1] AND [VECTOR 2] {");
        zVec v4 = subVector(v1, v2);
        printVectorByLabel("SUB VECTOR", v4);
    printf("}\n");

    printf("\nTEST: SUBTRACT [VECTOR 1] BY A SCALAR [2] {");
        v4 = subVectorByScalar(v1, 2.0f);
        printVectorByLabel("SUB VECTOR", v4);

        freeZVector(&v4);
    printf("}\n");

    printf("\nTEST: MULTIPLY [VECTOR 1] AND [VECTOR 2] {");
        zVec v5 = multVector(v1, v2);
        printVectorByLabel("PROD VECTOR", v5);
    printf("}\n");

    printf("\nTEST: MULTIPLY [VECTOR 1] BY A SCALAR [2] {");
        v5 = multVectorByScalar(v1, 2.0f);
        printVectorByLabel("PROD VECTOR", v5);

        freeZVector(&v5);
    printf("}\n");

    printf("\nTEST: DIVIDE [VECTOR 1] AND [VECTOR 2] {");
        zVec v6 = divVector(v1, v2);
        printVectorByLabel("DIV VECTOR", v6);
    printf("}\n");

    printf("\nTEST: DIVIDE [VECTOR 1] BY A SCALAR [2] {");
        v6 = divVectorByScalar(v1, 2.0f);
        printVectorByLabel("DIV VECTOR", v6);

        freeZVector(&v6);
    printf("}\n");

    printf("\nTEST: RAISE THE [VECTOR 1] TO THE POWER OF [4] {");
        zVec v7 = powerVectorToExp(v1, 4);
        printVectorByLabel("RAISED VECTOR", v7);

        freeZVector(&v7);
    printf("}\n");

    printf("\nTEST: CREATE A NEW [VECTOR 8] ORTHOGONAL TO [VECTOR 1] {");
        zVec v8 = newZVector(-2.0f, 1.0f , -4.0f, 3.0f);
        printVectorByLabel("ORTHOGONAL VECTOR", v8);
    printf("}\n");

    printf("\nTEST: CROSS PRODUCT BETWEEN [VECTOR 9] AND [VECTOR 10] {");
        zVec v9 = newZVector(-2.0f, 1.0f, -4.0);
        zVec v10 = newZVector(3.0f, 6.0f, -2.0);

        zVec v11 = crossProduct(v9, v10);
        printVectorByLabel("CROSS PRODUCT VECTOR", v11);
        
        freeZVector(&v9);
        freeZVector(&v10);
        freeZVector(&v11);
    printf("}\n");

    printf("\nTEST: NORMALIZE [VECTOR 12] WITH MAGNITUDE OF [%f] AFTER COPING IT FROM [VECTOR 3] {", magnitude(v3));
        zVec v12 = copyVector(v3);
        normalizeVector(&v12);
        printVectorByLabel("NORMALIZED VECTOR", v12);
    printf("}\n");

    printf("\n----------------------------------------------------------------\n");

        printf("\n> Are [VECTOR 1] and [VECTOR 3] equal: %s\n", areVecEqual(v1, v3) ? "True" : "False"); 
        printf("\n> Dot product between [VECTOR 1] and [VECTOR 3]: %f\n", dotProduct(v1, v3));
        printf("\n> Are [VECTOR 1] and [VECTOR 8] orthogonal: %s\n", areVecOrthogonal(v1, v8) ? "True" : "False");
        printf("\n> Magnitude of [VECTOR 3]: %f\n", magnitude(v3));
        printf("\n> Is [VECTOR 12] normalized : %s\n", isNormalized(v12) ? "True" : "False");


    freeZVector(&v1);
    freeZVector(&v3);
    freeZVector(&v8); 

    printf("\n -----------------------------------------------\n");
    printf("|                   MATRIXES                    |\n");
    printf(" -----------------------------------------------\n\n");

    printf("\nTEST: CREATE A NEW [MATRIX 1] {");
        zMat mat1 = newZMatrix(2 ,4  ,1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f);
        printMatrixByIndex(1, mat1);
    printf("}\n");

    printf("\nTEST: CREATE A NEW [MATRIX 2] AS AN IDENTITY MATRIX OF DIMENSION [6]{");
        zMat mat2 = idZMatrix(3);
        printMatrixByIndex(2, mat2);
    printf("}\n");

    printf("\nTEST: COPY THE POINTER AND DIMENSIONS FROM [MATRIX 1] TO [MATRIX 2] {");
        copyZMatrix(&mat1, &mat2);
        printMatrixByIndex(2, mat2);
    printf("}\n");  

    printf("\nTEST: CONVERT [VECTOR 13] TO [MATRIX 3] {");
        zVec v13 = newZVector(1.0f, 2.0f, 3.0f);
        printVectorByIndex(13, v13);
        zMat mat3 = vecToZMatrix(v13, VERTICAL); 
        printMatrixByIndex(3, mat3);
    printf("}\n"); 

    printf("\nTEST: CONVERT [MATRIX 4] TO [VECTOR 14] {");
        zMat mat4 = idZMatrix(3);
        printMatrixByIndex(4, mat4);
        zVec v14 = matrixToZVector(mat4);
        printVectorByIndex(14, v14);
    printf("}\n"); 

    printf("\nTEST: TAKE FROM [MATRIX 4] THE 2TH ROW {");
        mat4 = newRandomFloatMatrix(3, 3, 0.0f, 2.0f);
        printMatrixByIndex(4, mat4);
        zVec v15 = vecFromMatrixRow(mat4, 2);
        printVectorByLabel("2TH ROW TAKEN FROM [MATRIX 4]", v15);
    printf("}\n");

    printf("\nTEST: TAKE FROM [MATRIX 4] THE 3TH COL {");
        mat4 = newRandomFloatMatrix(3, 3, 0.0f, 2.0f);
        printMatrixByIndex(4, mat4);
        zVec v16 = vecFromMatrixCol(mat4, 3);
        printVectorByLabel("3TH COL TAKEN FROM [MATRIX 4]", v16);
    printf("}\n");

    printf("\nTEST: OPERATION BETWEEN [MATRIX 5] AND [MATRIX 6] INTO [MATRIX 7] {\n\n");
        zMat mat5 = newDefaultZMatrix(3, 3, 5.0f);
        zMat mat6 = newDefaultZMatrix(3, 3, 6.0f);
        printf("\nOP: SUM BETWEEN [MATRIX 5] AND [MATRIX 6] INTO [MATRIX 7] {");
            zMat mat7 = addMatrixes(mat5, mat6);
            printMatrixByLabel("SUM MATRIX", mat1);
        printf("}\n"); 
        printf("\nOP: SUBTRACTION BETWEEN [MATRIX 5] AND [MATRIX 6] INTO [MATRIX 7] {");
            mat7 = subMatrixes(mat5, mat6);
            printMatrixByLabel("SUB MATRIX", mat1);
            printf("}\n"); 
        printf("\nOP: PRODUCT BETWEEN [MATRIX 5] AND [MATRIX 6] INTO [MATRIX 7] {");
            mat7 = mulMatrixes(mat5, mat6);
            printMatrixByLabel("PROD MATRIX", mat1);
        printf("}\n"); 
        printf("\nOP: DIVISION BETWEEN [MATRIX 5] AND [MATRIX 6] INTO [MATRIX 7] {");
            mat7 = divMatrixes(mat5, mat6);
            printMatrixByLabel("DIV MATRIX", mat1);;
        printf("}\n\n");
        printf("\nOP: ROWS PER COLS PRODUCT BETWEEN [MATRIX 5] AND [MATRIX 6] INTO [MATRIX 7] {");
            mat7 = rowsColsProd(mat5, mat6);
            printMatrixByLabel("ROWS PER COLS PRODUCTS MATRIX", mat1);
        printf("}\n\n"); 
    printf("}\n"); 

    printf("\nTEST: TRANSPOSE [MATRIX 8] {");
        zMat mat8 = newRandomFloatMatrix(3, 3, 0.0f, 3.0f);
        printMatrixByIndex(8, mat8);
        mat8 = transposedMatrix(mat8);
        printMatrixByLabel("TRANSPOSED MATRIX", mat8);
    printf("}\n");

    printf("\nTEST: [MATRIX 9] TO ROW ECHELON FORM {");
        zMat mat9 = newRandomIntMatrix(3, 3, -5, 5);
        printMatrixByIndex(9, mat9);
        matrixToRowEchelonForm(&mat9);
        printMatrixByLabel("CONVERTED MATRIX", mat9);
    printf("}\n");

    return 0;
}