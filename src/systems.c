#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "systems.h"

/*==================================
 Functions for manipulating matrices
===================================*/
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

// print the elements on a matrix from a array
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

// return a element in the position (a, b)
double rab_matrix(Matrix *m, int a, int b){
    return m->data[(m->cols)*a + b];
}

// print a element in the position (a, b)
int pab_matrix(Matrix *m, int a, int b){
    printf("Element (%d, %d): %lf\n",a ,b , m->data[(m->cols)*a + b]);
    return 0;
}

// insert a element in the position (a, b)
int iab_matrix(Matrix *m, int a, int b, double elem){
    m->data[(m->cols)*a + b] = elem;
    return 0;
}

// create a hilbert matrix with size nxn
Matrix hilbert(int n){
    Matrix H = c_matrix(n, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            iab_matrix(&H, i, j, 1.0 / (i + j + 1));
        }
    }
    return H;
}

// sum vector b of the hilbert matrix
Matrix vet_b(int n){
    Matrix H = hilbert(n);
    Matrix b = c_matrix(n, 1);
    for(int i = 0; i < n; i++){
        double sum = 0;
        for(int j = 0; j < n; j++){
            sum = sum + rab_matrix(&H, i, j);
        }
        iab_matrix(&b, i, 0, sum);
    }
    d_matrix(&H);
    return b;
}

// returns the index of the highest value within a given array
int argmax_matrix(Matrix *m){
    int max_idx = 0;
    double max_val = m->data[0];
    int size = m->rows * m->cols;
    for(int i = 1; i < size; i++){
        if(m->data[i] > max_val){
            max_val = m->data[i];
            max_idx = i;
        }
    }
    return max_idx;
}

// returns the highest value within a given array
double max_matrix(Matrix *m){
    double max_val = m->data[0];
    int size = m->rows * m->cols;
    for(int i = 1; i < size; i++){
        if(m->data[i] > max_val){
            max_val = m->data[i];
        }
    }
    return max_val;
}

// maximum residue norm
double max_res(Matrix xk_1, Matrix xk_0){
    int n = xk_1.rows;
    double max_diff = 0.0;
    for(int i = 0; i < n; i++){
        double diff = fabs(rab_matrix(&xk_1, i, 0) - rab_matrix(&xk_0, i, 0));
        if(diff > max_diff){
            max_diff = diff;
        }
    }
    return max_diff;
}

// matrix multiplication algorithm
Matrix mul_matrix(Matrix *A, Matrix *B){
    if(A->cols != B->rows){
        printf("Incompatibility for doing matrix multiplication!\n");
        return c_matrix(0, 0);
    }
    Matrix C = c_matrix(A->rows, B->cols);
    for(int i = 0; i < A->rows; i++){
        for(int j = 0; j < B->cols; j++){
            double sum = 0.0;
            for(int k = 0; k < A->cols; k++){
                sum += rab_matrix(A, i, k) * rab_matrix(B, k, j);
            }
            iab_matrix(&C, i, j, sum);
        }
    }
    return C;
}

/*=================================
 Methods for solving linear systems
 ==================================*/
// LU factorization
Matrix fact_LU(Matrix *m, Matrix *b){
    int n = m->rows;
    // LU = m
    Matrix LU = c_matrix(n, n);
    for(int i = 0; i < n * n; i++){
        LU.data[i] = m->data[i];
    }
    int *p = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        p[i] = i;
    }
    for(int k = 0; k < n - 1; k++){
        Matrix abs_col = c_matrix(n - k, 1);
        for(int i = 0; i < n - k; i++){
            iab_matrix(&abs_col, i, 0, fabs(rab_matrix(&LU, i + k, k)));
        }
        int max_rel_idx = argmax_matrix(&abs_col);
        int max_row_index = max_rel_idx + k;
        d_matrix(&abs_col);
        if(rab_matrix(&LU, max_row_index, k) == 0.0){
            printf("Error: The matrix is ​​singular.\n");
            free(p);
            d_matrix(&LU);
            return c_matrix(0, 0);
        }
        int r = max_row_index;
        if(r != k){
            int temp_p = p[k];
            p[k] = p[r];
            p[r] = temp_p;
            // swap rows k and r in LU
            for(int j = 0; j < n; j++){
                double temp_val = rab_matrix(&LU, k, j);
                iab_matrix(&LU, k, j, rab_matrix(&LU, r, j));
                iab_matrix(&LU, r, j, temp_val);
            }
        }
        for(int i = k + 1; i < n; i++){
            double m_val = rab_matrix(&LU, i, k) / rab_matrix(&LU, k, k);
            iab_matrix(&LU, i, k, m_val);
            for(int j = k + 1; j < n; j++){
                double val = rab_matrix(&LU, i, j) - m_val * rab_matrix(&LU, k, j);
                iab_matrix(&LU, i, j, val);
            }
        }
    }
    Matrix L = c_matrix(n, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i > j){
                iab_matrix(&L, i, j, rab_matrix(&LU, i, j));
            } else if(i == j){
                iab_matrix(&L, i, j, 1.0);
            } else {
                iab_matrix(&L, i, j, 0.0);
            }
        }
    }
    Matrix U = c_matrix(n, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i <= j){
                iab_matrix(&U, i, j, rab_matrix(&LU, i, j));
            } else {
                iab_matrix(&U, i, j, 0.0);
            }
        }
    }
    Matrix bp = c_matrix(n, 1);
    for(int i = 0; i < n; i++){
        iab_matrix(&bp, i, 0, rab_matrix(b, p[i], 0));
    }
    // --- Solving Ly = b ---
    Matrix y = c_matrix(n, 1);
    for(int i = 0; i < n; i++){
        double sum = 0.0;
        for(int j = 0; j < i; j++){
            sum = sum + rab_matrix(&L, i, j) * rab_matrix(&y, j, 0);
        }
        double y_val = (rab_matrix(&bp, i, 0) - sum) / rab_matrix(&L, i, i);
        iab_matrix(&y, i, 0, y_val);
    }
    // --- Solving Ux = y ---
    Matrix x = c_matrix(n, 1);
    for(int i = n - 1; i >= 0; i--){
        double sum = 0.0;
        for(int j = i + 1; j < n; j++){
            sum = sum + rab_matrix(&U, i, j) * rab_matrix(&x, j, 0);
        }
        double x_val = (rab_matrix(&y, i, 0) - sum) / rab_matrix(&U, i, i);
        iab_matrix(&x, i, 0, x_val);
    }
    printf("===========================================\n");
    printf("LU Factorization Method\n");
    printf("-------------------------------------------\n");
    printf("Result:\n");
    p_matrix(&x);
    printf("===========================================\n");
    fflush(stdout);
    
    d_matrix(&LU);
    d_matrix(&L);
    d_matrix(&U);
    d_matrix(&bp);
    d_matrix(&y);
    free(p);
    return x;
}

// Cholesky method
Matrix cholesky(Matrix *m, Matrix *b){
    int n = m->rows;
    Matrix G = c_matrix(n, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            iab_matrix(&G, i, j, 0.0);
        }
    }
    for(int i = 0; i < n; i++){
        double sum = 0.0;
        for(int k = 0; k < i; k++){
            double G_ki = rab_matrix(&G, k, i);
            sum += G_ki * G_ki;
        }
        double root_term = rab_matrix(m, i, i) - sum;
        if(root_term <= 0.0){
            printf("The matrix is ​​not positive definite or failed to converge due to floating-point rounding.\n");
            d_matrix(&G);
            return c_matrix(0, 0);
        }
        iab_matrix(&G, i, i, sqrt(root_term));
        for(int j = i + 1; j < n; j++){
            double sum2 = 0.0;
            for(int l = 0; l < i; l++){
                sum2 += rab_matrix(&G, l, i) * rab_matrix(&G, l, j);
            }
            double G_ij = (1.0 / rab_matrix(&G, i, i)) * (rab_matrix(m, i, j) - sum2);
            iab_matrix(&G, i, j, G_ij);
        }
    }
    
    Matrix y = c_matrix(n, 1);
    for(int i = 0; i < n; i++){
        double sum = 0.0;
        for(int j = 0; j < i; j++){
            sum += rab_matrix(&G, j, i) * rab_matrix(&y, j, 0);
        }
        double y_val = (rab_matrix(b, i, 0) - sum) / rab_matrix(&G, i, i);
        iab_matrix(&y, i, 0, y_val);
    }
    
    Matrix x = c_matrix(n, 1);
    for(int i = n - 1; i >= 0; i--){
        double sum = 0.0;
        for(int j = i + 1; j < n; j++){
            sum += rab_matrix(&G, i, j) * rab_matrix(&x, j, 0);
        }
        double x_val = (rab_matrix(&y, i, 0) - sum) / rab_matrix(&G, i, i);
        iab_matrix(&x, i, 0, x_val);
    }
    
    printf("===========================================\n");
    printf("Cholesky Decomposition Method\n");
    printf("-------------------------------------------\n");
    printf("Result:\n");
    p_matrix(&x);
    printf("===========================================\n");
    fflush(stdout);
    
    d_matrix(&G);
    d_matrix(&y);
    return x;
}