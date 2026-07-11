#ifndef SYSTEMS_H
#define SYSTEMS_H

// matrix structure
typedef struct Matrix {
    int rows;
    int cols;
    double *data;
} Matrix;

// create a matrix
Matrix c_matrix(int rows, int cols);

// delete a matrix (free the memory)
void d_matrix(Matrix *m);

// return the number of rows in a matrix
int n_rows(Matrix *m);

// return the number of columns in a matrix
int n_cols(Matrix *m);

// insert elements in a matrix
int i_matrix(Matrix *m, double *data);

// print the elements in a matrix
int p_matrix(Matrix *m);

#endif