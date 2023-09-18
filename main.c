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
    
    fprintf(fp, "\nTEST: PRINT NULL VECTOR {");
        MZ_print_vector_by_label(fp, "NULL VECTOR",NULL_VECTOR);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: CREATE A NEW [VECTOR] {");
        MZ_Vec v1 = MZ_new_vector(1.0f, 2.0f, 3.0f, 4.0f);
        MZ_print_vector_by_index(fp, 1, v1);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: COPY FROM [VECTOR 1] TO [VECTOR 2] {");
        MZ_Vec v2;
        MZ_copy_vector_pointer(&v1, &v2);
        MZ_print_vector_by_index(fp, 2, v2);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: SUM [VECTOR 1]AND [VECTOR 2] {");
        MZ_Vec v3 = MZ_add_two_vectors(v1, v2);
        MZ_print_vector_by_label(fp, "SUM VECTOR", v3);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: SUM [VECTOR 1] BY A SCALAR [2] {");
        v3 = MZ_add_vector_with_scalar(v1, 2.0f);
        MZ_print_vector_by_label(fp, "SUM VECTOR", v3);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: SUBTRACT [VECTOR 1] AND [VECTOR 2] {");
        MZ_Vec v4 = MZ_subtract_two_vectors(v1, v2);
        MZ_print_vector_by_label(fp, "SUB VECTOR", v4);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: SUBTRACT [VECTOR 1] BY A SCALAR [2] {");
        v4 = MZ_subtract_vector_with_scalar(v1, 2.0f);
        MZ_print_vector_by_label(fp, "SUB VECTOR", v4);

        MZ_free_vector(&v4);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: MULTIPLY [VECTOR 1] AND [VECTOR 2] {");
        MZ_Vec v5 = MZ_multiply_two_vectors(v1, v2);
        MZ_print_vector_by_label(fp, "PROD VECTOR", v5);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: MULTIPLY [VECTOR 1] BY A SCALAR [2] {");
        v5 = MZ_multiply_vector_by_scalar(v1, 2.0f);
        MZ_print_vector_by_label(fp, "PROD VECTOR", v5);

        MZ_free_vector(&v5);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: DIVIDE [VECTOR 1] AND [VECTOR 2] {");
        MZ_Vec v6 = MZ_divide_two_vectors(v1, v2);
        MZ_print_vector_by_label(fp, "DIV VECTOR", v6);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: DIVIDE [VECTOR 1] BY A SCALAR [2] {");
        v6 = MZ_divide_vector_by_scalar(v1, 2.0f);
        MZ_print_vector_by_label(fp, "DIV VECTOR", v6);

        MZ_free_vector(&v6);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: RAISE THE [VECTOR 1] TO THE POWER OF [4] {");
        MZ_Vec v7 = MZ_raise_vector_to_exp(v1, 4);
        MZ_print_vector_by_label(fp, "RAISED VECTOR", v7);

        MZ_free_vector(&v7);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: CREATE A NEW [VECTOR 8] ORTHOGONAL TO [VECTOR 1] {");
        MZ_Vec v8 = MZ_new_vector(-2.0f, 1.0f , -4.0f, 3.0f);
        MZ_print_vector_by_label(fp, "ORTHOGONAL VECTOR", v8);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: CROSS PRODUCT BETWEEN [VECTOR 9] AND [VECTOR 10] {");
        MZ_Vec v9 = MZ_new_vector(-2.0f, 1.0f, -4.0);
        MZ_Vec v10 = MZ_new_vector(3.0f, 6.0f, -2.0);

        MZ_Vec v11 = MZ_cross_product(v9, v10);
        MZ_print_vector_by_label(fp, "CROSS PRODUCT VECTOR", v11);
        
        MZ_free_vector(&v9);
        MZ_free_vector(&v10);
        MZ_free_vector(&v11);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: NORMALIZE [VECTOR 12] WITH MAGNITUDE OF [%f] AFTER COPING IT FROM [VECTOR 3] {", MZ_magnitude_of_vector(v3));
        MZ_Vec v12 = MZ_copy_vector(v3);
        MZ_normalize_vector(&v12);
        MZ_print_vector_by_label(fp, "NORMALIZED VECTOR", v12);
    fprintf(fp, "}\n");

    fprintf(fp, "\n----------------------------------------------------------------\n");

        fprintf(fp, "\n> Are [VECTOR 1] and [VECTOR 3] equal: %s\n", MZ_are_two_vectors_equal(v1, v3) ? "True" : "False");
        #if VISUALIZE_RATIONAL 
        fprintf(fp, "\n> DOT PRODUCT:\n");
        fprintf(fp, "   | DOT PRODUCT BETWEEN [VECTOR 1] and [VECTOR 3]: : {\n   |\tDOT: %s;\n   | }\n\n", rationalizeFloatToStr(MZ_dot_two_vectors(v1, v3), 3).data);
        #else
        fprintf(fp, "\n> DOT PRODUCT:\n");
        MZ_print_value(fp, "DOT PRODUCT BETWEEN [VECTOR 1] and [VECTOR 3]:", "DOT", MZ_dot_two_vectors(v1, v3));
        #endif
        fprintf(fp, "\n> Are [VECTOR 1] and [VECTOR 8] orthogonal: %s\n\n", MZ_are_two_vectors_orthogonal(v1, v8) ? "True" : "False");
        #if VISUALIZE_RATIONAL 
        fprintf(fp, "\n> VECTOR MAGNITUDE:\n");
        fprintf(fp, "   | Magnitude of [VECTOR 3]: : {\n   |\tMAG: %s;\n   | }\n\n", rationalizeFloatToStr(MZ_magnitude_of_vector(v3), 3).data);
        #else
        fprintf(fp, "\n> VECTOR MAGNITUDE:\n");
        MZ_print_value(fp, "MAGNITUDE OF [VECTOR 3]", "MAG", MZ_magnitude_of_vector(v3));
        #endif
        fprintf(fp, "\n> Is [VECTOR 12] normalized : %s\n", MZ_is_vector_normalized(v12) ? "True" : "False");


    MZ_free_vector(&v1);
    MZ_free_vector(&v3);
    MZ_free_vector(&v8); 
    
    fprintf(fp, "\n -----------------------------------------------\n");
    fprintf(fp, "|                   MATRIXES                    |\n");
    fprintf(fp, " -----------------------------------------------\n\n");

    fprintf(fp, "\nTEST: PRINT NULL MATRIX {");
        MZ_print_matrix_by_label(fp, "NULL MATRIX",NULL_MATRIX);
    fprintf(fp, "}\n");
    
    fprintf(fp, "\nTEST: CREATE A NEW [MATRIX 1] {");
        MZ_Matrix mat1 = MZ_new_matrix(2 ,4  ,1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f);
        MZ_print_matrix_by_index(fp, 1, mat1);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: CREATE A NEW [MATRIX 2] AS AN IDENTITY MATRIX OF DIM [6]{");
        MZ_Matrix mat2 = MZ_new_identity_matrix(3);
        MZ_print_matrix_by_index(fp, 2, mat2);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: COPY THE POINTER AND DIM FROM [MATRIX 1] TO [MATRIX 2] {");
        MZ_copy_matrix_pointer(&mat1, &mat2);
        MZ_print_matrix_by_index(fp, 2, mat2);
    fprintf(fp, "}\n");  

    fprintf(fp, "\nTEST: CONVERT [VECTOR 13] TO [MATRIX 3] {");
        MZ_Vec v13 = MZ_new_vector(1.0f, 2.0f, 3.0f);
        MZ_print_vector_by_index(fp, 13, v13);
        MZ_Matrix mat3 = MZ_Vector_to_matrix(v13, VERTICAL); 
        MZ_print_matrix_by_index(fp, 3, mat3);
    fprintf(fp, "}\n"); 

    fprintf(fp, "\nTEST: CONVERT [MATRIX 4] TO [VECTOR 14] {");
        MZ_Matrix mat4 = MZ_new_identity_matrix(3);
        MZ_print_matrix_by_index(fp, 4, mat4);
        MZ_Vec v14 = MZ_Matrix_to_vector(mat4);
        MZ_print_vector_by_index(fp, 14, v14);
    fprintf(fp, "}\n"); 

    fprintf(fp, "\nTEST: TAKE FROM [MATRIX 4] THE 2TH ROW {");
        mat4 = MZ_new_random_float_matrix(3, 3, 0.0f, 2.0f);
        MZ_print_matrix_by_index(fp, 4, mat4);
        MZ_Vec v15 = MZ_get_vector_from_matrix_row(mat4, 2);
        MZ_print_vector_by_label(fp, "2TH ROW TAKEN FROM [MATRIX 4]", v15);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: TAKE FROM [MATRIX 4] THE 3TH COL {");
        mat4 = MZ_new_random_float_matrix(3, 3, 0.0f, 2.0f);
        MZ_print_matrix_by_index(fp, 4, mat4);
        MZ_Vec v16 = MZ_get_vector_from_matrix_col(mat4, 3);
        MZ_print_vector_by_label(fp, "3TH COL TAKEN FROM [MATRIX 4]", v16);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: OPERATION BETWEEN [MATRIX 5] AND [MATRIX 6] INTO [MATRIX 7] {\n\n");
        MZ_Matrix mat5 = MZ_new_default_matrix(3, 3, 5.0f);
        MZ_print_matrix_by_index(fp, 5, mat5);
        MZ_Matrix mat6 = MZ_new_default_matrix(3, 3, 6.0f);
        MZ_print_matrix_by_index(fp, 6, mat6);
        fprintf(fp, "\nOP: SUM BETWEEN [MATRIX 5] AND [MATRIX 6] INTO [MATRIX 7] {");
            MZ_Matrix mat7 = MZ_add_two_matrices(mat5, mat6);
            MZ_print_matrix_by_label(fp, "SUM MATRIX", mat7);
        fprintf(fp, "}\n"); 
        fprintf(fp, "\nOP: SUBTRACTION BETWEEN [MATRIX 5] AND [MATRIX 6] INTO [MATRIX 7] {");
            mat7 = MZ_subtract_two_matrices(mat5, mat6);
            MZ_print_matrix_by_label(fp, "SUB MATRIX", mat7);
        fprintf(fp, "}\n"); 
        fprintf(fp, "\nOP: PRODUCT BETWEEN [MATRIX 5] AND [MATRIX 6] INTO [MATRIX 7] {");
            mat7 = MZ_multiply_two_matrices(mat5, mat6);
            MZ_print_matrix_by_label(fp, "PROD MATRIX", mat7);
        fprintf(fp, "}\n"); 
        fprintf(fp, "\nOP: DIVISION BETWEEN [MATRIX 5] AND [MATRIX 6] INTO [MATRIX 7] {");
            mat7 = MZ_divide_two_matrices(mat5, mat6);
            MZ_print_matrix_by_label(fp, "DIV MATRIX", mat7);;
        fprintf(fp, "}\n\n");
        fprintf(fp, "\nOP: HADAMARD PRODUCT BETWEEN [MATRIX 5] AND [MATRIX 6] INTO [MATRIX 7] {");
            mat7 = MZ_hadamard_multiply_two_matrices(mat5, mat6);
            MZ_print_matrix_by_label(fp, "PRODUCT ELEMENT BY ELEMENT", mat7);
        fprintf(fp, "}\n\n"); 
    fprintf(fp, "}\n"); 

    
    fprintf(fp, "\nTEST: TRANSPOSE [MATRIX 8] {");
        MZ_Matrix mat8 = MZ_new_random_float_matrix(3, 3, 0.0f, 3.0f);
        MZ_print_matrix_by_index(fp, 8, mat8);
        mat8 = MZ_transposed_matrix(mat8);
        MZ_print_matrix_by_label(fp, "TRANSPOSED MATRIX", mat8);
    fprintf(fp, "}\n");
    

    fprintf(fp, "\nTEST: [MATRIX 9] TO ROW ECHELON FORM {");
        MZ_Matrix mat9 = MZ_new_random_int_matrix(3, 3, -5, 5);
        MZ_print_matrix_by_index(fp, 9, mat9);
        MZ_to_reduced_echelon_form(&mat9);
        MZ_print_matrix_by_label(fp, "CONVERTED MATRIX", mat9);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: APPEND [VECTOR 17] TO [MATRIX 12] {");
        MZ_Matrix mat10 = MZ_new_random_int_matrix(3, 3, -5, 5);
        MZ_print_matrix_by_index(fp, 10, mat10);
        MZ_Vec v17 = MZ_new_default_vector(3, 7);
        MZ_print_vector_by_label(fp, "VECTOR TO APPEND", v17);
        mat10 = MZ_append_vector_to_matrix(mat10, v17);
        MZ_print_matrix_by_label(fp, "EXPANDED MATRIX", mat10);
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: APPEND [MATRIX 13] TO [MATRIX 14] {");
        MZ_Matrix mat11 = MZ_new_random_int_matrix(3, 4, -3, 2);
        MZ_print_matrix_by_index(fp, 13, mat11);
        MZ_Matrix mat12 = MZ_new_random_int_matrix(3, 3, -1, 7);
        MZ_print_matrix_by_label(fp, "MATRIX TO APPEND", mat12);
        mat11 = MZ_append_matrix_to_matrix(mat11, mat12);
        MZ_print_matrix_by_label(fp, "EXPANDED MATRIX", mat11);
    fprintf(fp, "}\n");

    // TODO: FIX THE DETERMINANT OF THE MATRIX 

    /*
    fprintf(fp, "\nTEST: DETERMINANT OF [MATRIX 13] {");
        MZ_Matrix mat13 = MZ_new_random_int_matrix(3, 3, -2, 4);
        MZ_print_matrix_by_index(fp, 15, mat13);
        #if VISUALIZE_RATIONAL
        zstring det = rationalizeFloatToStr(MZ_determinant_of_matrix(mat13),3);
        fprintf(fp, "   | THE DETERMINANT OF [MATRIX 15] IS: : {\n   |\tDET: %s;\n   | }\n\n", det.data);
        #else
        float det = MZ_determinant_of_matrix(mat13);
        MZ_print_value(fp, "THE DETERMINANT OF [MATRIX 15] IS", "DET", det);
        #endif
    fprintf(fp, "}\n");

    fprintf(fp, "\nTEST: INVERSE OF [MATRIX 14] {");
        MZ_Matrix mat14 = MZ_new_random_int_matrix(3, 3, 2, 5);
        MZ_print_matrix_by_index(fp, 14, mat14);
        fprintf(fp, "   | IS THE [MATRIX 14] INVERTIBLE?: : {\n   |\t %s;\n   | }", MZ_is_matrix_invertible(mat14) ? "TRUE" : "FALSE");
        mat14 = MZ_inverse_of_matrix(mat14);
        MZ_print_matrix_by_label(fp, "INVERTED MATRIX", mat14);
    fprintf(fp, "}\n");
    */

    fclose(fp);
    
    
    MZ_free_matrix(&mat1);
    MZ_free_matrix(&mat2);
    MZ_free_matrix(&mat3);
    MZ_free_matrix(&mat4);
    MZ_free_matrix(&mat5);
    MZ_free_matrix(&mat6);
    MZ_free_matrix(&mat7);
    MZ_free_matrix(&mat8);
    MZ_free_matrix(&mat9);
    MZ_free_matrix(&mat10);
    MZ_free_matrix(&mat11);
    MZ_free_matrix(&mat12);
   /* MZ_free_matrix(&mat13);
    MZ_free_matrix(&mat14);*/

    MZ_free_vector(&v13);
    MZ_free_vector(&v14);
    MZ_free_vector(&v15);
    MZ_free_vector(&v16);
    MZ_free_vector(&v17);

    return 0;
}