#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "roots.h"
/*
* comand for compiling in linux using GCC: 
* gcc -Iinclude src/roots.c tests/roots_test.c -o bin/roots_test -lm
*/
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

    FILE * fp1 = fopen("outputs/roots_test.txt", "w");
    fprintf(fp1, "=================================================\n");
    fprintf(fp1, "==  Numerical Solutions of Equations Examples  ==\n");
    fprintf(fp1, "=================================================\n");
    // Test bisection method
    fprintf(fp1, "Bisection Method\n");
    fprintf(fp1, "-------------------------------------------------\n");
    fprintf(fp1, "-> Function: cos(x) - x\n");
    fclose(fp1);

    FILE *FP1 = freopen("outputs/roots_test.txt", "a", stdout);
    double root_bisec = bisec(f1, -1, 1, 1e-12);
    fclose(stdout);
  
    // Test false position method
    FILE * fp2 = fopen("outputs/roots_test.txt", "a");
    fprintf(fp2, "=================================================\n");
    fprintf(fp2, "False Position Method\n");
    fprintf(fp2, "-------------------------------------------------\n");
    fprintf(fp2, "-> Function: x^10 - 1\n");
    fclose(fp2);
    
    FILE *FP2 = freopen("outputs/roots_test.txt", "a", stdout);
    double root_falposic = falposic(f2, 0.0, 1.3, 0.05);
    fclose(stdout);

    // Test Fixed-Point method
    FILE * fp3 = fopen("outputs/roots_test.txt", "a");
    fprintf(fp3, "=================================================\n");
    fprintf(fp3, "Fixed-Point Method\n");
    fprintf(fp3, "-------------------------------------------------\n");
    fprintf(fp3, "-> Function: x*log(x) - 3.2\n");
    fprintf(fp3, "-> Proximity Function: 3.2/log(x)\n");
    fclose(fp3);

    FILE *FP3 = freopen("outputs/roots_test.txt", "a", stdout);
    double root_fixpoint = fixpoint(f3, g2,  2.5, 1e-5, 150, false);
    fclose(stdout);
    
    // Test Newton's method
    FILE * fp4 = fopen("outputs/roots_test.txt", "a");
    fprintf(fp4, "=================================================\n");
    fprintf(fp4, "Newton's Method\n");
    fprintf(fp4, "-------------------------------------------------\n");
    fprintf(fp4, "-> Function: cos(x) - x\n");
    fprintf(fp4, "-> Proximity Function: x-((cos(x)-x)/(-sin(x)-1))\n");
    fclose(fp4);

    FILE *FP4 = freopen("outputs/roots_test.txt", "a", stdout);
    double root_newton = newton_meth(f1, g3, 1, 1e-12, 100);
    fclose(stdout);

    // Test Secant method
    FILE * fp5 = fopen("outputs/roots_test.txt", "a");
    fprintf(fp5, "=================================================\n");
    fprintf(fp5, "Secant method\n");
    fprintf(fp5, "-------------------------------------------------\n");
    fprintf(fp5, "-> Function: cos(x) - x\n");
    fclose(fp5);

    FILE *FP5 = freopen("outputs/roots_test.txt", "a", stdout);
    double root = secant(f1, 0, 1e-3, 1e-2, 100);
    fprintf(FP5, "=================================================\n");
    fclose(stdout);

    return 0;
}