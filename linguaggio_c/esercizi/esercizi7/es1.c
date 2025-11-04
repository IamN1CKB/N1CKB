#include <stdio.h>
#include <math.h>
/*
Scrivere una funzione che calcoli una qualunque potenza di esponente intero
*/
double potenza(double, int);

int main(){
    double x;
    int n; //esponente
    printf("scegli un numero di cui fare la potenza: ");
    scanf("%lf", &x);
    printf("scegli esponente (numero intero): ");
    scanf("%d", &n);

    if (potenza(x, n) != -1) printf("(%f)^%d = %lf", x, n, potenza(x, n));
    else printf("la potenza di 0^-n con n un numero naturale positivo, non si può fare\n");
}


double potenza(double x, int n) {
    double a=1;
    
    for (int i = 0; i < fabs(n); i++)
        a = a*x;

    if (n<0)
        if (x!=0) a = 1/a;
        else return -1;   //0^-n non si può fare
        
    return a;
}