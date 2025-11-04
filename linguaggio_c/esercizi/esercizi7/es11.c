#include <stdio.h>
#include <math.h>
/*
Scrivere una funzione che calcoli, al variare di x, il valore dell’espressione:
f(x) = 3x^3- sqrt((x^2+3)/2)
*/
double f(double x);

void main() {
    double x;
    printf("inserisci valore di x: ");
    scanf("%lf", &x);
    printf("f(%lf) = %lf\n", x, f(x));
}

double f(double x) {
    return 3*x*x*x-sqrt((x*x+3)/2);
}