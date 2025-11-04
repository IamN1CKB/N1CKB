#include <stdio.h>
/*
Predisporre un programma che calcola il valore dei fattoriali di tutte i numeri interi minori uguali a n
*/
int main(void) {
    int n, fat;
    do {
        printf("Inserisci un numero naturale n < 13: ");    //con 13 supera gli 8 byte della codifica degli int
        scanf("%d", &n);
    } while (n<0);
    printf("Fattoriale di tutti i numeri naturali da 0 a n:\n");
    for(int i = 0; i<=n; i++) {
        fat = 1;
        for(int j = 0; j < i-1; j++) {
            //printf("%d = %d*%d\n", fat, fat, i-j);
            fat *= i-j;
        }
        printf("%d! = %d\n", i, fat);
    }
}