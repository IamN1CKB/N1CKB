#include <stdio.h>
/*
vogliamo sommare tutti i numeri interi da 0 a un certo numero n
es: n = 4
somma = 1 + 2 + 3 + 4 = 10
*/
int main()
{
    int n, somma;
    printf("n=?\n");
    scanf("%d", &n);
    somma = 0;
    while (n>=0) {
        somma = somma + n;
        n = n - 1;
    }
    printf("somma = %d", somma);
    //matematico gauss ha usato una formula diversa, vedi file formula_gauss.c
}