#ifndef SYSTEMS_H
#define SYSTEMS_H

/*============================================================
 Creating linear algebra functions for manipulating matrices
============================================================*/
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

// return a element in the position (a, b)
double rab_matrix(Matrix *m, int a, int b);

// print a element in the position (a, b)
int pab_matrix(Matrix *m, int a, int b);

// insert a element in the position (a, b)
int iab_matrix(Matrix *m, int a, int b, double elem);

// create a hilbert matrix with size nxn
Matrix hilbert(int n);

// sum vector b of the hilbert matrix
Matrix vet_b(int n);

// returns the index of the highest value within a given array
int argmax_matrix(Matrix *m);

// returns the highest value within a given array
double max_matrix(Matrix *m);

// maximum residue norm
double max_res(Matrix xk_1, Matrix xk_0);

// matrix multiplication algorithm
Matrix mul_matrix(Matrix *A, Matrix *B);

/*==========================================
Creating methods for solving linear systems
===========================================*/
// LU factorization
Matrix fact_LU(Matrix *m, Matrix *b);

// Cholesky method
Matrix cholesky(Matrix *m, Matrix *b);

// Gauss-Jacobi method
Matrix gauss_jacobi(Matrix *m, Matrix *b, double e);

#endif