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

// LU algorithm test
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
    
    // applies the method to the 7x7 Hilbert matrix and the vector b7
    Matrix v = fact_LU(&A7, &b7);
    Matrix A7_v = mul_matrix(&A7, &v);
    double res = max_res(b7, A7_v);
    double err = max_res(v, x7);
    printf("The maximum norm of the residual: %lf\n", res);
    printf("The maximum absolute error is: %lf\n", err);

    //free the memory
    d_matrix(&A7);
    d_matrix(&b7);
    d_matrix(&x7);
    d_matrix(&v);
    d_matrix(&A7_v);
    
    fflush(stdout);
    return 0;
}