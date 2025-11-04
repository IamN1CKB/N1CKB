#include <stdio.h>
/*
il matematico gauss ha scoperto che la somma di tutti i numeri interi da 0 a n è uguale a (n * (n + 1)) / 2
possiamo usare questa formula matematica per compiere meno operazioni rispetto a un ciclo
*/
int main() {
    int n, somma;
    printf("inserisci un numero: ");
    scanf("%d", &n);
    somma = (n*(n+1))/2;
    printf("somma = %d\n", somma);
}