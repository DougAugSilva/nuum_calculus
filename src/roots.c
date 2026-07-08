#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

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
// Fixed-Point method [ok]
double fixpoint(double (*f)(double), double (*g)(double), double x, double e, int maxint, bool I){
    double x0;
    double x1;
    double fx1 = 0;
    bool stop;
    int i;
    printf("=================================================\n");
    printf("Fixed-Point method\n");
    if(I == true){
        x1 = x;
        stop = false;
        i = 0;
        while(stop == false){
            x0 = x1;
            x1 = g(x0);
            if(fabs(x1) == INFINITY){
                printf("The method diverges to infinity!\n");
                return x1;
            }
            fx1 = f(x1);
            i++;
            if((fabs(x1 - x0) < e)||(i >= maxint)||fabs(fx1) < e){
                stop = true;
            }
            printf("-------------------------------------------------\n");
            printf("Iteration: %d\n", i);
            printf("Value of x1: %lf\n", x1);
            printf("Value of f(x1): %lf\n", fx1);
            printf("Value of |x1 - x0|: %lf\n", fabs(x1 - x0));
        }if((fabs(x1 - x0) < e)||(fabs(fx1) < e)){
            printf("-------------------------------------------------\n");
            printf("The method converges to: %lf\n", x1);
        }else{
            printf("-------------------------------------------------\n");
            printf("The method diverges to infinity!\n");
        }
    }else{
        x1 = x;
        stop = false;
        i = 0;
        while(stop == false){
            x0 = x1;
            x1 = g(x0);
            if(fabs(x1) == INFINITY){
                printf("The method diverges to infinity!\n");
                return x1;
            }
            fx1 = f(x1);
            i++;
            if((fabs(x1 - x0) < e)||(fabs(fx1) < e)||(i >= maxint)){
                stop = true;
            }
        }
        if((fabs(x1 - x0) < e)||fabs(fx1) < e){
            printf("-------------------------------------------------\n");
            printf("Iteration: %d\n", i);
            printf("Value of x1: %lf\n", x1);
            printf("Value of f(x1): %lf\n", fx1);
            printf("Value of |x1 - x0|: %lf\n", fabs(x1 - x0));
            printf("-------------------------------------------------\n");
            printf("The method has converged to: %lf\n", x1);
        }else{
            printf("The method has not converged\n");
        }
    }
    return x1;
}