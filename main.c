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
        zVec v1 = zm_new_vector(1.0f, 2.0f, 3.0f, 4.0f);
        zm_print_vector_by_index(fp, 1, v1);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: COPY FROM [VECTOR 1] TO [VECTOR 2] {");
        zVec v2;
        zm_copy_vector_pointer(&v1, &v2);
        zm_print_vector_by_index(fp, 2, v2);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: SUM [VECTOR 1]AND [VECTOR 2] {");
        zVec v3 = zm_add_two_vectors(v1, v2);
        zm_print_vector_by_label(fp, "SUM VECTOR", v3);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: SUM [VECTOR 1] BY A SCALAR [2] {");
        v3 = zm_add_vector_with_scalar(v1, 2.0f);
        zm_print_vector_by_label(fp, "SUM VECTOR", v3);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: SUBTRACT [VECTOR 1] AND [VECTOR 2] {");
        zVec v4 = zm_subtract_two_vectors(v1, v2);
        zm_print_vector_by_label(fp, "SUB VECTOR", v4);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: SUBTRACT [VECTOR 1] BY A SCALAR [2] {");
        v4 = zm_subtract_vector_with_scalar(v1, 2.0f);
        zm_print_vector_by_label(fp, "SUB VECTOR", v4);

        zm_free_vector(&v4);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: MULTIPLY [VECTOR 1] AND [VECTOR 2] {");
        zVec v5 = zm_multiply_two_vectors(v1, v2);
        zm_print_vector_by_label(fp, "PROD VECTOR", v5);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: MULTIPLY [VECTOR 1] BY A SCALAR [2] {");
        v5 = zm_multiply_vector_by_scalar(v1, 2.0f);
        zm_print_vector_by_label(fp, "PROD VECTOR", v5);

        zm_free_vector(&v5);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: DIVIDE [VECTOR 1] AND [VECTOR 2] {");
        zVec v6 = zm_divide_two_vectors(v1, v2);
        zm_print_vector_by_label(fp, "DIV VECTOR", v6);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: DIVIDE [VECTOR 1] BY A SCALAR [2] {");
        v6 = zm_divide_vector_by_scalar(v1, 2.0f);
        zm_print_vector_by_label(fp, "DIV VECTOR", v6);

        zm_free_vector(&v6);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: RAISE THE [VECTOR 1] TO THE POWER OF [4] {");
        zVec v7 = zm_raise_vector_to_exp(v1, 4);
        zm_print_vector_by_label(fp, "RAISED VECTOR", v7);

        zm_free_vector(&v7);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: CREATE A NEW [VECTOR 8] ORTHOGONAL TO [VECTOR 1] {");
        zVec v8 = zm_new_vector(-2.0f, 1.0f , -4.0f, 3.0f);
        zm_print_vector_by_label(fp, "ORTHOGONAL VECTOR", v8);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: CROSS PRODUCT BETWEEN [VECTOR 9] AND [VECTOR 10] {");
        zVec v9 = zm_new_vector(-2.0f, 1.0f, -4.0);
        zVec v10 = zm_new_vector(3.0f, 6.0f, -2.0);

        zVec v11 = zm_cross_product(v9, v10);
        zm_print_vector_by_label(fp, "CROSS PRODUCT VECTOR", v11);
        
        zm_free_vector(&v9);
        zm_free_vector(&v10);
        zm_free_vector(&v11);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: NORMALIZE [VECTOR 12] WITH MAGNITUDE OF [%f] AFTER COPING IT FROM [VECTOR 3] {", zm_magnitude_of_vector(v3));
        zVec v12 = zm_copy_vector(v3);
        zm_normalize_vector(&v12);
        zm_print_vector_by_label(fp, "NORMALIZED VECTOR", v12);
    fprintf(fp, "}\n");

    fprintf(fp, "\n----------------------------------------------------------------\n");

        fprintf(fp, "\n> Are [VECTOR 1] and [VECTOR 3] equal: %s\n", zm_are_two_vectors_equal(v1, v3) ? "True" : "False");
        #if VISUALIZE_RATIONAL 
        fprintf(fp, "\n> Dot product between [VECTOR 1] and [VECTOR 3]: %s\n", rationalizeFloatToStr(zm_dot_two_vectors(v1, v3), 3).data);
        #else
        fprintf(fp, "\n> Dot product between [VECTOR 1] and [VECTOR 3]: %f\n", zm_dot_two_vectors(v1, v3));
        #endif
        fprintf(fp, "\n> Are [VECTOR 1] and [VECTOR 8] orthogonal: %s\n", zm_are_two_vectors_orthogonal(v1, v8) ? "True" : "False");
        #if VISUALIZE_RATIONAL 
        fprintf(fp, "\n> Magnitude of [VECTOR 3]: %s\n", rationalizeFloatToStr(zm_magnitude_of_vector(v3), 3).data);
        #else
        fprintf(fp, "\n> Magnitude of [VECTOR 3]: %f\n", zm_magnitude_of_vector(v3));
        #endif
        fprintf(fp, "\n> Is [VECTOR 12] normalized : %s\n", zm_is_vector_normalized(v12) ? "True" : "False");


    zm_free_vector(&v1);
    zm_free_vector(&v3);
    zm_free_vector(&v8); 

    fprintf(fp, "\n -----------------------------------------------\n");
    fprintf(fp, "|                   MATRIXES                    |\n");
    fprintf(fp, " -----------------------------------------------\n\n");

    fprintf(fp, "\nTEST: CREATE A NEW [MATRIX 1] {");
        zMat mat1 = zm_new_matrix(2 ,4  ,1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f);
        zm_print_matrix_by_index(fp, 1, mat1);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: CREATE A NEW [MATRIX 2] AS AN IDENTITY MATRIX OF DIM [6]{");
        zMat mat2 = zm_new_identity_matrix(3);
        zm_print_matrix_by_index(fp, 2, mat2);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: COPY THE POINTER AND DIM FROM [MATRIX 1] TO [MATRIX 2] {");
        zm_copy_matrix_pointer(&mat1, &mat2);
        zm_print_matrix_by_index(fp, 2, mat2);
    fprintf(fp, "}\n");  

    fprintf(fp, "\nTEST: CONVERT [VECTOR 13] TO [MATRIX 3] {");
        zVec v13 = zm_new_vector(1.0f, 2.0f, 3.0f);
        zm_print_vector_by_index(fp, 13, v13);
        zMat mat3 = zm_vector_to_matrix(v13, VERTICAL); 
        zm_print_matrix_by_index(fp, 3, mat3);
    fprintf(fp, "}\n"); 

    fprintf(fp, "\nTEST: CONVERT [MATRIX 4] TO [VECTOR 14] {");
        zMat mat4 = zm_new_identity_matrix(3);
        zm_print_matrix_by_index(fp, 4, mat4);
        zVec v14 = zm_matrix_to_vector(mat4);
        zm_print_vector_by_index(fp, 14, v14);
    fprintf(fp, "}\n"); 

    fprintf(fp, "\nTEST: TAKE FROM [MATRIX 4] THE 2TH ROW {");
        mat4 = zm_new_random_float_matrix(3, 3, 0.0f, 2.0f);
        zm_print_matrix_by_index(fp, 4, mat4);
        zVec v15 = zm_get_vector_from_matrix_row(mat4, 2);
        zm_print_vector_by_label(fp, "2TH ROW TAKEN FROM [MATRIX 4]", v15);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: TAKE FROM [MATRIX 4] THE 3TH COL {");
        mat4 = zm_new_random_float_matrix(3, 3, 0.0f, 2.0f);
        zm_print_matrix_by_index(fp, 4, mat4);
        zVec v16 = zm_get_vector_from_matrix_col(mat4, 3);
        zm_print_vector_by_label(fp, "3TH COL TAKEN FROM [MATRIX 4]", v16);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: OPERATION BETWEEN [MATRIX 5] AND [MATRIX 6] INTO [MATRIX 7] {\n\n");
        zMat mat5 = zm_new_default_matrix(3, 3, 5.0f);
        zMat mat6 = zm_new_default_matrix(3, 3, 6.0f);
        fprintf(fp, "\nOP: SUM BETWEEN [MATRIX 5] AND [MATRIX 6] INTO [MATRIX 7] {");
            zMat mat7 = zm_add_two_matrices(mat5, mat6);
            zm_print_matrix_by_label(fp, "SUM MATRIX", mat1);
        fprintf(fp, "}\n"); 
        fprintf(fp, "\nOP: SUBTRACTION BETWEEN [MATRIX 5] AND [MATRIX 6] INTO [MATRIX 7] {");
            mat7 = zm_subtract_two_matrices(mat5, mat6);
            zm_print_matrix_by_label(fp, "SUB MATRIX", mat1);
        fprintf(fp, "}\n"); 
        fprintf(fp, "\nOP: PRODUCT BETWEEN [MATRIX 5] AND [MATRIX 6] INTO [MATRIX 7] {");
            mat7 = zm_multiply_two_matrices(mat5, mat6);
            zm_print_matrix_by_label(fp, "PROD MATRIX", mat1);
        fprintf(fp, "}\n"); 
        fprintf(fp, "\nOP: DIVISION BETWEEN [MATRIX 5] AND [MATRIX 6] INTO [MATRIX 7] {");
            mat7 = zm_divide_two_matrices(mat5, mat6);
            zm_print_matrix_by_label(fp, "DIV MATRIX", mat1);;
        fprintf(fp, "}\n\n");
        fprintf(fp, "\nOP: ROWS PER COLS PRODUCT BETWEEN [MATRIX 5] AND [MATRIX 6] INTO [MATRIX 7] {");
            mat7 = zm_dot_two_matrices(mat5, mat6);
            zm_print_matrix_by_label(fp, "ROWS PER COLS PRODUCTS MATRIX", mat1);
        fprintf(fp, "}\n\n"); 
    fprintf(fp, "}\n"); 

    fprintf(fp, "\nTEST: TRANSPOSE [MATRIX 8] {");
        zMat mat8 = zm_new_random_float_matrix(3, 3, 0.0f, 3.0f);
        zm_print_matrix_by_index(fp, 8, mat8);
        mat8 = zm_transposed_matrix(mat8);
        zm_print_matrix_by_label(fp, "TRANSPOSED MATRIX", mat8);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: [MATRIX 9] TO ROW ECHELON FORM {");
        zMat mat9 = zm_new_random_int_matrix(3, 3, -5, 5);
        zm_print_matrix_by_index(fp, 9, mat9);
        zm_to_echelon_form(&mat9);
        zm_print_matrix_by_label(fp, "CONVERTED MATRIX", mat9);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: APPEND [VECTOR 17] TO [MATRIX 12] {");
        zMat mat10 = zm_new_random_int_matrix(3, 3, -5, 5);
        zm_print_matrix_by_index(fp, 10, mat10);
        zVec v17 = zm_new_default_vector(3, 7);
        zm_print_vector_by_label(fp, "VECTOR TO APPEND", v17);
        mat10 = zm_append_vector_to_matrix(mat10, v17);
        zm_print_matrix_by_label(fp, "EXPANDED MATRIX", mat10);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: APPEND [MATRIX 13] TO [MATRIX 14] {");
        zMat mat11 = zm_new_random_int_matrix(3, 4, -3, 2);
        zm_print_matrix_by_index(fp, 13, mat11);
        zMat mat12 = zm_new_random_int_matrix(3, 3, -1, 7);
        zm_print_matrix_by_label(fp, "MATRIX TO APPEND", mat12);
        mat11 = zm_append_matrix_to_matrix(mat11, mat12);
        zm_print_matrix_by_label(fp, "EXPANDED MATRIX", mat11);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: DETERMINANT OF [MATRIX 13] {");
        zMat mat13 = zm_new_random_int_matrix(3, 3, -2, 4);
        zm_print_matrix_by_index(fp, 15, mat13);
        #if VISUALIZE_RATIONAL
        zstring det = rationalizeFloatToStr(zm_determinant_of_matrix(mat13),3);
        fprintf(fp, "   | THE DETERMINANT OF [MATRIX 15] IS: {\n   |\tDet: %s;\n   | }\n\n", det.data);
        #else
        float det = zm_determinant_of_matrix(mat13);
        fprintf(fp, "   | THE DETERMINANT OF [MATRIX 15] IS: {\n   |\tDet: %f;\n   | }\n\n", det);
        #endif
    fprintf(fp, "}\n");

    fclose(fp);

    zm_free_matrix(&mat1);
    zm_free_matrix(&mat2);
    zm_free_matrix(&mat3);
    zm_free_matrix(&mat4);
    zm_free_matrix(&mat5);
    zm_free_matrix(&mat6);
    zm_free_matrix(&mat7);
    zm_free_matrix(&mat8);
    zm_free_matrix(&mat9);
    zm_free_matrix(&mat10);
    zm_free_matrix(&mat11);
    zm_free_matrix(&mat12);
    zm_free_matrix(&mat13);

    zm_free_vector(&v13);
    zm_free_vector(&v14);
    zm_free_vector(&v15);
    zm_free_vector(&v16);
    zm_free_vector(&v17);

    return 0;
}