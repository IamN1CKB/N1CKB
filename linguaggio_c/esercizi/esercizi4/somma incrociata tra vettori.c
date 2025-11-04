#include <stdio.h>
#define N 100
/*
Scrivere un programma che, inizializzati in due vettori a e b della stessa lunghezza n valori interi, calcoli la
somma incrociata degli elementi: a[1] + b[n], a[2] + b[n−1], ... la memorizzi nel vettore c e visualizzi quindi
a, b e c.
*/
int main(){
    int a[N], b[N], c[N], n;
    printf("scegli la lunghezza del vettore: ");
    scanf("%d", &n);

    //inizializza vettore
    for (int i = 0; i < n; i++) {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("b[%d]: ", i);
        scanf("%d", &b[i]);
    }
    
    for (int i = 0; i < n; i++)
        c[i] = a[i] + b[n-1-i];
    
    for (int i = 0; i < n; i++)
        printf("a[%d]= %d\t", i, a[i]);
    printf("\n");
    for (int i = n-1; i >= 0; i--)
        printf("b[%d]= %d\t", i, b[i]);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("c[%d]= %d\t", i, c[i]);
    
    
}