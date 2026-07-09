#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "roots.h"

// Testing functions
double f1(double x){
    return cos(x) - x;
}

double f2(double x){
    return pow(x, 10) - 1;
}

double f3(double x){
    return x*log(x) - 3.2;
}

double g1(double x){
    return exp(3.2/x);
}

double g2(double x){
    return 3.2/log(x);
}

double g3(double x){
    return x - ((cos(x) - x)/(-sin(x) - 1));
}

// Print the results
int main(){
    printf("=================================================\n");
    printf("==  Numerical Solutions of Equations Examples  ==\n");
    printf("=================================================\n");
    // Test bisection method
    printf("Bisection Method\n");
    printf("-------------------------------------------------\n");
    printf("-> Function: cos(x) - x\n");
    double root_bisec = bisec(f1, -1, 1, 1e-12);

    // Test false position method
    printf("=================================================\n");
    printf("False Position Method\n");
    printf("-------------------------------------------------\n");
    printf("-> Function: x^10 - 1\n");
    double root_falposic = falposic(f2, 0.0, 1.3, 0.05);

    // Test Fixed-Point method
    printf("=================================================\n");
    printf("Fixed-Point Method\n");
    printf("-------------------------------------------------\n");
    printf("-> Function: x*log(x) - 3.2\n");
    printf("-> Proximity Function: 3.2/log(x)\n");
    double root_fixpoint = fixpoint(f3, g2,  2.5, 1e-5, 150, false);
    
    // Test Newton's method
    printf("=================================================\n");
    printf("Newton's Method\n");
    printf("-------------------------------------------------\n");
    printf("-> Function: cos(x) - x\n");
    printf("-> Proximity Function: x-((cos(x)-x)/(-sin(x)-1))\n");
    double root_newton = newton_meth(f1, g3, 1, 1e-12, 100);

    // Test Secant method
    printf("=================================================\n");
    printf("Secant method\n");
    printf("-------------------------------------------------\n");
    printf("-> Function: cos(x) - x\n");
    double root = secant(f1, 0, 1e-3, 1e-2, 100);

    return 0;
}