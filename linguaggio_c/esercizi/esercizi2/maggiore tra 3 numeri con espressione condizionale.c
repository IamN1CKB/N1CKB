#include <stdio.h>
/*
Scrivere un programma che richieda in ingresso tre valori interi distinti e ne determini il maggiore con :?
*/
int main() {
    int a, b, c, max;
    printf("Inserisci 3 numeri separati da uno spazio: ");
    scanf("%d %d %d", &a, &b, &c);
    b = b>c ? b : c; //se b è più grande di c, b prende il valore di c, altrimenti nulla
    max = a>b ? a : b; //se a è più grande di b, a è il massimo, altrimenti b 
    printf("max = %d", max);
}