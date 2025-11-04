/*
Scrivere un programma che, letti gli elementi di due vettori v1 e v2 di lunghezza 5, determini il vettore w di
lunghezza 10 ottenuto alternando gli elementi di v1 e v2. Visualizzare v1, v2 e w.
Per esempio: se v1 e v2 sono i vettori di caratteri
v1 = B N S I O
v2 = E I S M !
W = B E N I S S I M O !
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
int main(){
    char v1[N], v2[N], w[2*N]; 
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        v1[i] = rand()%(128 - 33) + 33;   //in questo modo scegli un numero tra 0 e 94, e poi lo addiziona per 33
        v2[i] = rand()%(128 - 33) + 33;   //quindi sceglie un numero tra 33 e 127, che sono i caratteri visibili della tabella ASCII
    }
    printf("v1[%d]: '", N);
    for (int i = 0; i < N; i++) printf("%c", v1[i]);
    printf("'\nv2[%d]: '", N);
    for (int i = 0; i < N; i++) printf("%c", v2[i]);
    printf("'\n");

    for (int i = 0; i < 2*N; i++) {
        if (i%2==0) w[i] = v1[i/2];
        else w[i] = v2[(i-1)/2];  //siccome in questo caso i è dispari, sottraggo uno e lo diviso per 2 per ottenere l'indice di v2[]
    }

    printf("\nw[%d]: '", 2*N);
    for (int i = 0; i < 2*N; i++) printf("%c", w[i]);
    printf("'\n");

    return 0;
}