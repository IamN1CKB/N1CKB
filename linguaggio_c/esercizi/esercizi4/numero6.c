#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20
/*
Scrivere un programma che, letti gli elementi di due vettori v1 e v2 di lunghezza n, inizializzi un terzo vettore w
di lunghezza n con i valori
w(i) = 1    se v1(i) > v2(i)
w(i) = 0    se v1(i) = v2(i)
w(i) = -1   se v1(i) < v2(i)
*/
int main() {
    int v1[N], v2[N], w[N];
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        v1[i] = rand()%199 - 99;   //sceglie il numero da -99 a 99
        v2[i] = rand()%199 - 99;   //sceglie il numero da -99 a 99
    }
    printf("v1[%d]: ", N);
    for (int i = 0; i < N; i++) printf("%d\t", v1[i]);
    printf("\nv2[%d]: ", N);
    for (int i = 0; i < N; i++) printf("%d\t", v2[i]);

    //inizializzazione w[N]
    for (int i = 0; i < N; i++) {
        if      (v1[i] > v2[i]) w[i] = 1;
        else if (v1[i] == v2[i]) w[i] = 0;
        else if (v1[i] < v2[i]) w[i] = -1;
    }
    printf("\nw[%d]:  ", N);
    for (int i = 0; i < N; i++) printf("%d\t", w[i]);
    
    
    




    return 0;
}