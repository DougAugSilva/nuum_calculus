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

int main(){
    Matrix m;
    m.rows = 3;
    m.cols = 3;
    m = c_matrix(m.rows, m.cols);
    i_matrix(&m, (double[]){1, 2, 3, 4, 5, 6, 7, 8, 9});
    p_matrix(&m);
    d_matrix(&m);
    return 0;
}