#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N_MAX 50
//cancellare un elemento da un vettore
int main() {
    int vet[N_MAX], l;
    srand(time(NULL));
    printf("scegli lunghezza vettore (<%d): ", N_MAX);
    scanf("%d", &l);
    printf("vet:\n");
    for (int i = 0; i < l; i++) {
        vet[i] = rand()%100;
        printf("%d\t", vet[i]);
    }
    
    int elemento_da_cancellare;
    int indice_da_cancellare = 0;
    printf("\n\ndecidi numero da cancellare: ");
    scanf("%d", &elemento_da_cancellare);
    //cancelliamo la prima occorrenza di elemento da cancellare
    while (vet[indice_da_cancellare] != elemento_da_cancellare) indice_da_cancellare++;
    //adesso abbiamo l'indice da cancellare
    printf("la prima occorrenza del numero da cancellare (%d) si trova all'indice %d\n", elemento_da_cancellare, indice_da_cancellare);

    for (int i = indice_da_cancellare; i < l; i++)
        vet[i] = vet[i+1];  //spostiamo tutti gli elementi che si trovano dopo l'elemento da cancellare
    
    for (int i = 0; i < l-1; i++)
        printf("%d\t", vet[i]);

    
}