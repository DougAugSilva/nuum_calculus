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
    
    // applies the LU method to the 7x7 Hilbert matrix and the vector b7
    Matrix v1 = fact_LU(&A7, &b7);
    Matrix A7_v1 = mul_matrix(&A7, &v1);
    double res1 = max_res(b7, A7_v1);
    double err1 = max_res(v1, x7);
    printf("The maximum norm of the residual: %lf\n", res1);
    printf("The maximum absolute error is: %lf\n", err1);

    // applies the cholesky method to the 7x7 Hilbert matrix and the vector b7
    Matrix v2 = cholesky(&A7, &b7);
    Matrix A7_v2 = mul_matrix(&A7, &v2);
    double res2 = max_res(b7, A7_v2);
    double err2 = max_res(v2, x7);
    printf("The maximum norm of the residual: %lf\n", res2);
    printf("The maximum absolute error is: %lf\n", err2);

    //free the memory
    d_matrix(&A7);
    d_matrix(&b7);

    d_matrix(&x7);
    d_matrix(&v1);
    d_matrix(&A7_v1);

    d_matrix(&v2);
    d_matrix(&A7_v2);
    
    //fflush(stdout);
    return 0;
}