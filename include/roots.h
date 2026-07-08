#ifndef ROOTS_H
#define ROOTS_H

// Bisection method
double bisec(double (*f)(double), double a, double b, double e);

// False position method
double falposic(double (*f)(double), double a, double b, double e);

// Fixed-Point method 
double fixpoint(double (*f)(double), double (*g)(double), double x, double e, int maxint, bool I);

// Newton's method
double newton_meth(double (*f)(double), double (*g)(double), double x, double e, int maxint);

#endif