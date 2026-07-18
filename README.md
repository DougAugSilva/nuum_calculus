# Numerical Calculus Library in C

## Repository objectives
With this repository I want to put into practice my studies in numerical calculus and the C programming language. The repository contains several numerical methods to approximate functions values such as Newtons method, or methods to solve numerical problems, such as find the best splines to approximate a function, with quadratic and cubic splines.

## Repository structure

```
nuum_calculus/
├── include/
│   ├── interpolation.h
│   ├── roots.h
│   └── systems.h
├── outputs/
│   ├── interpolation_test.txt
│   ├── roots_test.txt
│   └── systems_test.txt
├── src/
│   ├── interpolation.c
│   ├── roots.c
│   └── systems.c
├── .gitignore
├── LICENSE
├── README.md
└── tests/
    ├── interpolation_test.c
    ├── roots_test.c
    └── systems_test.c
```

## How use this repository
To use this repository you just need to compile the code with the function in they respective aquiver, and and call those files as libraries of C.
I use *Linux* and *GCC* to compile the code during the development and test, I use the respective commands to compile and run the compiled code:
- `gcc -Iinclude src/roots.c tests/roots_test.c -o roots_test -lm && ./roots_test`
- `gcc -Iinclude src/systems.c tests/systems_test.c -o systems_test -lm && ./systems_test`
- `.`

## Mathematical content of this repository
I choose not to focus too much deep in the mathematical rigorous theory in this repository, in the meaning that there is not proofs or explanation of the methods, just some comments in the code to help he readers to understand some "obscure mathematical tricks".
The topics covers in numerical analysis are the same as the ones I studied in my mathematical bachelor degree in 2025, and I enjoyed thanking my college professor at State University of Londrina Dr. ALine Aparecida de Souza Leão.

## Topics covers in this repository

- #### Numerical solutions of equations
  - Bisection method
  - False position method
  - Fixed-Point method
  - Newton's method
  - Secant method

- #### Direct and iterative methods for solving linear systems
  - LU factorization
  - Cholesky method
  - Gauss-Jacobi method
  - Gauss-Seidel method
  - SOR decomposition

- #### Polynomial interpolation and curve fitting using the least squares method
  - Linear system form
  - Lagrange form
  - Newton form
  - Splines (linear, quadratic and cubic)
  - Least squares (discrete and continuous methods)