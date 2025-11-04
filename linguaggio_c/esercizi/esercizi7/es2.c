#include <stdio.h>
/*
Scrivere una funzione che visualizzi un messaggio a una generica coordinata x, y dello schermo. Si consideri uno 
schermo con 25 righe e 80 colonne
*/
#define R 25
#define C 80
#define N 100

void messaggio(int, int);

void main() {
    int x, y;
    printf("decidi coordinata x (0<x<%d): ", C);
    scanf("%d", &x);
    printf("decidi coordinata y (0<y<%d): ", R);
    scanf("%d", &y);
    messaggio(x, y);
}

void messaggio(int x, int y) {
    char str[N];
    printf("decidi messaggio da scrivere: ");
    getchar();
    fgets(str, N, stdin);
    for (int i = 0; i < y; i++) printf("\n");
    for (int i = 0; i < x; i++) printf(" ");
    printf("%s", str);
}