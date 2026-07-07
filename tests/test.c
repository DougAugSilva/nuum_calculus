#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "roots.h"

// Testing roots.c
double f1(double x){
    return cos(x) - x;
}

int main(){
    double root = bisec(f1, -1, 1, 1e-12);
    return 0;
}