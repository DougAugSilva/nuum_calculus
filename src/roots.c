#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Bisection method [OK]
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

    printf("=================================================\n");
    printf("Bisection Method\n");
    printf("-------------------------------------------------\n");
    printf("Value of |a - b|: %lf\n", fabs(a-b));
    printf("Interval that contains x: [%lf, %lf]\n", a, b);
    printf("value of f(x): %lf\n", f(x));
    printf("-------------------------------------------------\n");
    printf("The method converges to: %lf\n", x);
    printf("=================================================\n");

    return x;
}

// False position method [OK]
double falposic(double (*f)(double), double a, double b, double e){
    double x;
    int i;
    if(f(a)*f(b) > 0){
        printf("=================================================\n");
        printf("False position method\n");
        printf("-------------------------------------------------\n");
        printf("There is not roots in this interval!\n");
        printf("=================================================\n");
        return 0;
    }else{
        x = (f(b)*a - f(a)*b)/(f(b) - f(a));
        i = 0;
        while(fabs(f(x)) > e){
            x = (f(b)*a - f(a)*b)/(f(b) - f(a));
            if(f(a)*f(x) < 0){
                b = x;
            }else{
                a = x;
            }
            i++;
        }
    }
    printf("=================================================\n");
    printf("False position method\n");
    printf("-------------------------------------------------\n");
    printf("Number of interactions: %d\n", i);
    printf("Value of x: %lf\n", x);
    printf("Interval that contains x: [%lf, %lf]\n", a, b);
    printf("=================================================\n");

    return x;
}