#include <stdio.h>
/*
Scrivere un programma che inizializzi e quindi visualizzi un vettore con i valori alternati 0, 1, 0, 1, 0, 1, 0, 1, …
Ripetere l’esercizio con i valori 0, −3, 6, −9, 12, −15, 18, −21, ....
*/
#define N 50
int main(){
    int vettore01[N];
    for (int i = 0; i < N; i++) {
        if (i%2==0) vettore01[i] = 0;
        else vettore01[i] = 1;
    }

    for (int i = 0; i < N; i++)
        printf("%d ", vettore01[i]);
    printf("\n\n");

    for (int i = 0; i < N; i++) {
        if (i%2==0) vettore01[i] = 3*i;
        else vettore01[i] = - 3*i;
    }
    
    for (int i = 0; i < N; i++)
        printf("%d ", vettore01[i]);
    
    




    return 0;
}