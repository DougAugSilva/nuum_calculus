#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "systems.h"
/*
comand for compiling in linux using GCC: 
gcc -Iinclude src/systems.c tests/systems_test.c -o systems_test -lm
*/

// Testing the methods
int main(){
    // hilbert matrix
    Matrix A7 = hilbert(7);
    
    // vector sum b
    Matrix b7 = vet_b(7);
    
    // response vector x = (1, ..., 1)
    Matrix x7 = c_matrix(7, 1);
    for(int i = 0; i < 7; i++){
        iab_matrix(&x7, i, 0, 1.0);
    }

    FILE * fp = fopen("outputs/systems_test.txt", "w");
    fprintf(fp, "========================================================================\n");
    fprintf(fp, "==  Direct and Iterative Methods for Solving Linear Systems Examples  ==\n");
    fprintf(fp, "========================================================================\n");
    fclose(fp);

    // applies the LU method to the 7x7 Hilbert matrix and the vector b7
    FILE *FP1 = freopen("outputs/systems_test.txt", "a", stdout);
    Matrix v1 = fact_LU(&A7, &b7);
    Matrix A7_v1 = mul_matrix(&A7, &v1);
    double res1 = max_res(b7, A7_v1);
    double err1 = max_res(v1, x7);
    fclose(stdout);
    
    FILE *fp1 = fopen("outputs/systems_test.txt", "a");
    fprintf(fp1, "The maximum norm of the residual: %lf\n", res1);
    fprintf(fp1, "The maximum absolute error is: %lf\n", err1);
    fclose(fp1);

    // applies the cholesky method to the 7x7 Hilbert matrix and the vector b7
    FILE *FP2 = freopen("outputs/systems_test.txt", "a", stdout);
    Matrix v2 = cholesky(&A7, &b7);
    Matrix A7_v2 = mul_matrix(&A7, &v2);
    double res2 = max_res(b7, A7_v2);
    double err2 = max_res(v2, x7);
    fclose(stdout);

    FILE *fp2 = fopen("outputs/systems_test.txt", "a");
    fprintf(fp2, "The maximum norm of the residual: %lf\n", res2);
    fprintf(fp2, "The maximum absolute error is: %lf\n", err2);
    fclose(fp2);

    // applies the Gauss-Jacobi  method to the 7x7 Hilbert matrix and the vector b7
    FILE *FP3 = freopen("outputs/systems_test.txt", "a", stdout);
    Matrix v3 = gauss_jacobi(&A7, &b7, 1e-8);
    Matrix A7_v3 = mul_matrix(&A7, &v3);
    double res3 = max_res(b7, A7_v3);
    double err3 = max_res(v3, x7);
    fclose(stdout);

    FILE *fp3 = fopen("outputs/systems_test.txt", "a");
    fprintf(fp3, "The maximum norm of the residual: %lf\n", res3);
    fprintf(fp3, "The maximum absolute error is: %lf\n", err3);
    fclose(fp3);
    
    // applies the Gauss-Seidel method to the 7x7 Hilbert matrix and the vector b7
    FILE *FP4 = freopen("outputs/systems_test.txt", "a", stdout);
    Matrix v4 = gauss_seidel(&A7, &b7, 1e-8);
    Matrix A7_v4 = mul_matrix(&A7, &v4);
    double res4 = max_res(b7, A7_v4);
    double err4 = max_res(v4, x7);
    fclose(stdout);

    FILE *fp4 = fopen("outputs/systems_test.txt", "a");
    fprintf(fp4, "The maximum norm of the residual: %lf\n", res4);
    fprintf(fp4, "The maximum absolute error is: %lf\n", err4);
    fclose(fp4);
    
    // applies the SOR method to the 7x7 Hilbert matrix and the vector b7
    FILE *FP5 = freopen("outputs/systems_test.txt", "a", stdout);
    Matrix v5 = sor(&A7, &b7, 1e-8, 0.5);
    Matrix A7_v5 = mul_matrix(&A7, &v5);
    double res5 = max_res(b7, A7_v5);
    double err5 = max_res(v5, x7);
    fclose(stdout);

    FILE *fp5 = fopen("outputs/systems_test.txt", "a");
    fprintf(fp5, "The maximum residual norm is: %lf\n", res5);
    fprintf(fp5, "The maximum absolute error is: %lf\n", err5);
    fprintf(fp5, "===============================================\n");
    fclose(fp5);

    //free the memory
    d_matrix(&A7);
    d_matrix(&b7);
    d_matrix(&x7);

    d_matrix(&v1);
    d_matrix(&A7_v1);

    d_matrix(&v2);
    d_matrix(&A7_v2);

    d_matrix(&v3);
    d_matrix(&A7_v3);

    d_matrix(&v4);
    d_matrix(&A7_v4);

    d_matrix(&v5);
    d_matrix(&A7_v5);
    
    //fflush(stdout);
    return 0;
}