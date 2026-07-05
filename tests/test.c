#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "roots.h"

// Testing roots.c
double f1(double x){
    return x * x - 2.0;
}

int main(){
    double root = bisec(f1, 0.0, 2.0, 1e-12);
    printf("Root found: %lf\n", root);
    return 0;
}