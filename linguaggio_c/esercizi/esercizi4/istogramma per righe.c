#include <stdio.h>
#define N_MAX 100
/*
stampare a console un istogramma a righe i cui valori sono contenuti in un vettore di interi
*/
int main() {
    int vet[N_MAX], l;
    printf("decidi lunghezza del vettore (<%d): ", N_MAX);
    scanf("%d", &l);
    printf("inserisci gli elementi del vettore:\n");
    for (int i = 0; i < l; i++) {
        printf("vet[%d]: ", i);
        scanf("%d", &vet[i]);
    }

    for (int i = 0; i < l; i++) {
        printf("\n%d:\t", vet[i]);
        for (int j = 0; j < vet[i]; j++) printf("*");
    }
    
    
}