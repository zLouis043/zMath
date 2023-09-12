#include <stdio.h>
#include <errno.h>

#define ZMATH_IMPLEMENTATION
#include "src/zmath/zmath.h"

int main(int argc, char **argv){
    
    if(argc < 2){
        fprintf(stderr,"[USAGE]: %s <filename>\n",argv[0]);
        exit(1);
    }

    const char *filename = argv[1];

    FILE *fp;
    fopen_s(&fp, filename, "w");

    if(fp == NULL){
        fprintf(stderr,"[ERROR] : Could not open file %s : %d", filename, errno);
        exit(1);
    }

    fprintf(fp, "\n -----------------------------------------------\n");
    fprintf(fp, "|                   VECTORS                     |\n");
    fprintf(fp, " -----------------------------------------------\n");
 
    fprintf(fp, "\nTEST: CREATE A NEW [VECTOR] {");
        zVec v1 = newZVector(1.0f, 2.0f, 3.0f, 4.0f);
        printVectorByIndex(fp, 1, v1);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: COPY FROM [VECTOR 1] TO [VECTOR 2] {");
        zVec v2;
        copyPtrVector(&v1, &v2);
        printVectorByIndex(fp, 2, v2);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: SUM [VECTOR 1]AND [VECTOR 2] {");
        zVec v3 = sumVector(v1, v2);
        printVectorByLabel(fp, "SUM VECTOR", v3);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: SUM [VECTOR 1] BY A SCALAR [2] {");
        v3 = sumVectorByScalar(v1, 2.0f);
        printVectorByLabel(fp, "SUM VECTOR", v3);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: SUBTRACT [VECTOR 1] AND [VECTOR 2] {");
        zVec v4 = subVector(v1, v2);
        printVectorByLabel(fp, "SUB VECTOR", v4);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: SUBTRACT [VECTOR 1] BY A SCALAR [2] {");
        v4 = subVectorByScalar(v1, 2.0f);
        printVectorByLabel(fp, "SUB VECTOR", v4);

        freeZVector(&v4);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: MULTIPLY [VECTOR 1] AND [VECTOR 2] {");
        zVec v5 = multVector(v1, v2);
        printVectorByLabel(fp, "PROD VECTOR", v5);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: MULTIPLY [VECTOR 1] BY A SCALAR [2] {");
        v5 = multVectorByScalar(v1, 2.0f);
        printVectorByLabel(fp, "PROD VECTOR", v5);

        freeZVector(&v5);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: DIVIDE [VECTOR 1] AND [VECTOR 2] {");
        zVec v6 = divVector(v1, v2);
        printVectorByLabel(fp, "DIV VECTOR", v6);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: DIVIDE [VECTOR 1] BY A SCALAR [2] {");
        v6 = divVectorByScalar(v1, 2.0f);
        printVectorByLabel(fp, "DIV VECTOR", v6);

        freeZVector(&v6);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: RAISE THE [VECTOR 1] TO THE POWER OF [4] {");
        zVec v7 = powerVectorToExp(v1, 4);
        printVectorByLabel(fp, "RAISED VECTOR", v7);

        freeZVector(&v7);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: CREATE A NEW [VECTOR 8] ORTHOGONAL TO [VECTOR 1] {");
        zVec v8 = newZVector(-2.0f, 1.0f , -4.0f, 3.0f);
        printVectorByLabel(fp, "ORTHOGONAL VECTOR", v8);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: CROSS PRODUCT BETWEEN [VECTOR 9] AND [VECTOR 10] {");
        zVec v9 = newZVector(-2.0f, 1.0f, -4.0);
        zVec v10 = newZVector(3.0f, 6.0f, -2.0);

        zVec v11 = crossProduct(v9, v10);
        printVectorByLabel(fp, "CROSS PRODUCT VECTOR", v11);
        
        freeZVector(&v9);
        freeZVector(&v10);
        freeZVector(&v11);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: NORMALIZE [VECTOR 12] WITH MAGNITUDE OF [%f] AFTER COPING IT FROM [VECTOR 3] {", magnitude(v3));
        zVec v12 = copyVector(v3);
        normalizeVector(&v12);
        printVectorByLabel(fp, "NORMALIZED VECTOR", v12);
    fprintf(fp, "}\n");

    fprintf(fp, "\n----------------------------------------------------------------\n");

        fprintf(fp, "\n> Are [VECTOR 1] and [VECTOR 3] equal: %s\n", areVecEqual(v1, v3) ? "True" : "False");
        #if VISUALIZE_RATIONAL 
        fprintf(fp, "\n> Dot product between [VECTOR 1] and [VECTOR 3]: %s\n", rationalizeFloatToStr(dotProduct(v1, v3), 3).data);
        #else
        fprintf(fp, "\n> Dot product between [VECTOR 1] and [VECTOR 3]: %f\n", dotProduct(v1, v3));
        #endif
        fprintf(fp, "\n> Are [VECTOR 1] and [VECTOR 8] orthogonal: %s\n", areVecOrthogonal(v1, v8) ? "True" : "False");
        #if VISUALIZE_RATIONAL 
        fprintf(fp, "\n> Magnitude of [VECTOR 3]: %s\n", rationalizeFloatToStr(magnitude(v3), 3).data);
        #else
        fprintf(fp, "\n> Magnitude of [VECTOR 3]: %f\n", magnitude(v3));
        #endif
        fprintf(fp, "\n> Is [VECTOR 12] normalized : %s\n", isNormalized(v12) ? "True" : "False");


    freeZVector(&v1);
    freeZVector(&v3);
    freeZVector(&v8); 

    fprintf(fp, "\n -----------------------------------------------\n");
    fprintf(fp, "|                   MATRIXES                    |\n");
    fprintf(fp, " -----------------------------------------------\n\n");

    fprintf(fp, "\nTEST: CREATE A NEW [MATRIX 1] {");
        zMat mat1 = newZMatrix(2 ,4  ,1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f);
        printMatrixByIndex(fp, 1, mat1);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: CREATE A NEW [MATRIX 2] AS AN IDENTITY MATRIX OF DIMENSION [6]{");
        zMat mat2 = idZMatrix(3);
        printMatrixByIndex(fp, 2, mat2);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: COPY THE POINTER AND DIMENSIONS FROM [MATRIX 1] TO [MATRIX 2] {");
        copyZMatrix(&mat1, &mat2);
        printMatrixByIndex(fp, 2, mat2);
    fprintf(fp, "}\n");  

    fprintf(fp, "\nTEST: CONVERT [VECTOR 13] TO [MATRIX 3] {");
        zVec v13 = newZVector(1.0f, 2.0f, 3.0f);
        printVectorByIndex(fp, 13, v13);
        zMat mat3 = vecToZMatrix(v13, VERTICAL); 
        printMatrixByIndex(fp, 3, mat3);
    fprintf(fp, "}\n"); 

    fprintf(fp, "\nTEST: CONVERT [MATRIX 4] TO [VECTOR 14] {");
        zMat mat4 = idZMatrix(3);
        printMatrixByIndex(fp, 4, mat4);
        zVec v14 = matrixToZVector(mat4);
        printVectorByIndex(fp, 14, v14);
    fprintf(fp, "}\n"); 

    fprintf(fp, "\nTEST: TAKE FROM [MATRIX 4] THE 2TH ROW {");
        mat4 = newRandomFloatMatrix(3, 3, 0.0f, 2.0f);
        printMatrixByIndex(fp, 4, mat4);
        zVec v15 = vecFromMatrixRow(mat4, 2);
        printVectorByLabel(fp, "2TH ROW TAKEN FROM [MATRIX 4]", v15);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: TAKE FROM [MATRIX 4] THE 3TH COL {");
        mat4 = newRandomFloatMatrix(3, 3, 0.0f, 2.0f);
        printMatrixByIndex(fp, 4, mat4);
        zVec v16 = vecFromMatrixCol(mat4, 3);
        printVectorByLabel(fp, "3TH COL TAKEN FROM [MATRIX 4]", v16);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: OPERATION BETWEEN [MATRIX 5] AND [MATRIX 6] INTO [MATRIX 7] {\n\n");
        zMat mat5 = newDefaultZMatrix(3, 3, 5.0f);
        zMat mat6 = newDefaultZMatrix(3, 3, 6.0f);
        fprintf(fp, "\nOP: SUM BETWEEN [MATRIX 5] AND [MATRIX 6] INTO [MATRIX 7] {");
            zMat mat7 = addMatrixes(mat5, mat6);
            printMatrixByLabel(fp, "SUM MATRIX", mat1);
        fprintf(fp, "}\n"); 
        fprintf(fp, "\nOP: SUBTRACTION BETWEEN [MATRIX 5] AND [MATRIX 6] INTO [MATRIX 7] {");
            mat7 = subMatrixes(mat5, mat6);
            printMatrixByLabel(fp, "SUB MATRIX", mat1);
        fprintf(fp, "}\n"); 
        fprintf(fp, "\nOP: PRODUCT BETWEEN [MATRIX 5] AND [MATRIX 6] INTO [MATRIX 7] {");
            mat7 = mulMatrixes(mat5, mat6);
            printMatrixByLabel(fp, "PROD MATRIX", mat1);
        fprintf(fp, "}\n"); 
        fprintf(fp, "\nOP: DIVISION BETWEEN [MATRIX 5] AND [MATRIX 6] INTO [MATRIX 7] {");
            mat7 = divMatrixes(mat5, mat6);
            printMatrixByLabel(fp, "DIV MATRIX", mat1);;
        fprintf(fp, "}\n\n");
        fprintf(fp, "\nOP: ROWS PER COLS PRODUCT BETWEEN [MATRIX 5] AND [MATRIX 6] INTO [MATRIX 7] {");
            mat7 = rowsColsProd(mat5, mat6);
            printMatrixByLabel(fp, "ROWS PER COLS PRODUCTS MATRIX", mat1);
        fprintf(fp, "}\n\n"); 
    fprintf(fp, "}\n"); 

    fprintf(fp, "\nTEST: TRANSPOSE [MATRIX 8] {");
        zMat mat8 = newRandomFloatMatrix(3, 3, 0.0f, 3.0f);
        printMatrixByIndex(fp, 8, mat8);
        mat8 = transposedMatrix(mat8);
        printMatrixByLabel(fp, "TRANSPOSED MATRIX", mat8);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: FIND THE DOT PRODUCT BETWEEN [MATRIX 9] AND [MATRIX 10] {");
        zMat mat9 = newRandomIntMatrix(3, 3, -5, 5);
        printMatrixByIndex(fp, 9, mat9);
        zMat mat10 = newRandomIntMatrix(3, 3, -2, 7);
        printMatrixByIndex(fp, 10, mat10);
        #if VISUALIZE_RATIONAL
        zstring dot = rationalizeFloatToStr(dotProductMatrix(mat9, mat10),3);
        fprintf(fp, "   | DOT PRODUCT: {\n   |\tDot Prod: %s;\n   | }\n", dot.data);
        #else
        float dot = dotProductMatrix(mat9, mat10);
        fprintf(fp, "   | DOT PRODUCT: {\n   |\tDot Prod: %f;\n   | }\n", dot);
        #endif
        fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: [MATRIX 9] TO ROW ECHELON FORM {");
        zMat mat11 = newRandomIntMatrix(3, 3, -5, 5);
        printMatrixByIndex(fp, 11, mat11);
        matrixToRowEchelonForm(&mat11);
        printMatrixByLabel(fp, "CONVERTED MATRIX", mat11);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: APPEND [VECTOR 17] TO [MATRIX 12] {");
        zMat mat12 = newRandomIntMatrix(3, 3, -5, 5);
        printMatrixByIndex(fp, 12, mat12);
        zVec v17 = newDefaultZVector(3, 7);
        printVectorByLabel(fp, "VECTOR TO APPEND", v17);
        mat12 = appendVectorToMatrix(mat12, v17);
        printMatrixByLabel(fp, "EXPANDED MATRIX", mat12);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: APPEND [MATRIX 13] TO [MATRIX 14] {");
        zMat mat13 = newRandomIntMatrix(3, 4, -3, 2);
        printMatrixByIndex(fp, 13, mat11);
        zMat mat14 = newRandomIntMatrix(3, 3, -1, 7);
        printMatrixByLabel(fp, "MATRIX TO APPEND", mat14);
        mat13 = appendMatrixToMatrix(mat13, mat14);
        printMatrixByLabel(fp, "EXPANDED MATRIX", mat13);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: DETERMINANT OF [MATRIX 13] {");
        zMat mat15 = newRandomIntMatrix(3, 3, -2, 4);
        printMatrixByIndex(fp, 15, mat15);
        #if VISUALIZE_RATIONAL
        zstring det = rationalizeFloatToStr(determinantExclusion(mat15),3);
        fprintf(fp, "   | THE DETERMINANT OF [MATRIX 15] IS: {\n   |\tDet: %s;\n   | }\n\n", det.data);
        #else
        float det = determinantExclusion(mat15);
        fprintf(fp, "   | THE DETERMINANT OF [MATRIX 15] IS: {\n   |\tDet: %f;\n   | }\n\n", det);
        #endif
    fprintf(fp, "}\n");

    fclose(fp);

    freeZMatrix(&mat1);
    freeZMatrix(&mat2);
    freeZMatrix(&mat3);
    freeZMatrix(&mat4);
    freeZMatrix(&mat5);
    freeZMatrix(&mat6);
    freeZMatrix(&mat7);
    freeZMatrix(&mat8);
    freeZMatrix(&mat9);
    freeZMatrix(&mat10);
    freeZMatrix(&mat11);
    freeZMatrix(&mat12);
    freeZMatrix(&mat13);
    freeZMatrix(&mat14);
    freeZMatrix(&mat15);
    
    freeZVector(&v13);
    freeZVector(&v14);
    freeZVector(&v15);
    freeZVector(&v16);
    freeZVector(&v17);

    return 0;
}