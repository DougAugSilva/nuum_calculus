#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "roots.h"

// Testing functions
double f1(double x){
    return cos(x) - x;
}

double f2(double x){
    return pow(x, 10) - 1;
}

/* Test bisection method
int main(){
    double root = bisec(f1, -1, 1, 1e-12);
    return 0;
}
*/

int main(){
    double root_bisec = bisec(f2, 0.0, 1.3, 0.05);
    printf("\n");
    double root_falposic = falposic(f2, 0.0, 1.3, 0.05);
    return 0;
}
