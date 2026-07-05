#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Bisection method
double bisec(double (*f)(double), double a, double b, double e){

    int i = 0;
    double x = (a + b)/2;

    while(fabs(b - a) > e && fabs(f(x)) > e){
        if(f(a)*f(x) < 0){
            b = x;
        }else {
            a = x;
        }
        x = (a + b)/2;
        i ++;
    }

    printf("==================================\n");
    printf("Bisection Method\n");
    printf("----------------------------------\n");
    printf("Value of |a - b |: %lf\n", fabs(a-b));
    printf("Interval that contains x: [%lf, %lf]\n", a, b);
    printf("value of f(x): %lf\n", f(x));
    printf("----------------------------------\n");
    printf("The method converges to: %lf\n", x);
    printf("==================================\n");

    return x;
}