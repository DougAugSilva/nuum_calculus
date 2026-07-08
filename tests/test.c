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
/* Test bisection method
int main(){
    double root = bisec(f1, -1, 1, 1e-12);
    return 0;
}
*/

/* Test false position method
int main(){
    double root_bisec = bisec(f2, 0.0, 1.3, 0.05);
    printf("\n");
    double root_falposic = falposic(f2, 0.0, 1.3, 0.05);
    return 0;
}
*/

int main(){
    double root = fixpoint(f3, g2,  2.5, 1e-5, 150, false);
    return 0;
}