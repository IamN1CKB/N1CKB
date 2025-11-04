#include <stdio.h>
#define N_MAX 100
/*
stampare a console un istogramma a colonne i cui valori sono contenuti in un vettore di interi
*/
int main() {
    int vet[N_MAX], l, max;
    printf("decidi lunghezza del vettore (<%d): ", N_MAX);
    scanf("%d", &l);
    printf("inserisci gli elementi del vettore:\n");
    for (int i = 0; i < l; i++) {
        printf("vet[%d]: ", i);
        scanf("%d", &vet[i]);
    }

    //dobbiamo trovare il massimo del vettore per capire l'altezza dell'istogramma
    max = vet[0];
    for (int i = 1; i < l; i++)
        if (max<vet[i]) max = vet[i];

    for (int i = max; i > 0; i--) {
        for (int j = 0; j < l; j++)
            if (vet[j]>=i) printf("*\t");
            else printf(" \t");
        printf("\n");
    }
    for (int i = 0; i < l; i++) printf("%d\t", vet[i]);
    
    

}