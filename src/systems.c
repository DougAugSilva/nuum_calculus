#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "systems.h"

//============================================================
// creating linear algebra functions for manipulating matrices

// create a matrix
Matrix c_matrix(int rows, int cols){
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = (double *)malloc(rows * cols * sizeof(double));
    return m;
}

// delete a matrix (free the memory)
void d_matrix(Matrix *m){
    free(m -> data);
    m -> data = NULL;
}

// return the number of rows in a matrix
int n_rows(Matrix *m){
    return m -> rows;
}

// return the number of columns in a matrix
int n_cols(Matrix *m){
    return m -> cols;
}

// insert elements in a matrix
int i_matrix(Matrix *m, double *data){
    for(int i = 0; i < n_rows(m)*n_cols(m); i++){
        m->data[i] = data[i];
    }
    return 0;
}

// print the elements in a matrix
int p_matrix(Matrix *m){
    for(int i = 0; i < m->rows; i++){
        printf("|");
        for(int j = 0; j < m->cols; j++){
            printf(" %lf ", m->data[i * m->cols + j]);
        }
        printf("|\n");
    }
    return 0;
}
