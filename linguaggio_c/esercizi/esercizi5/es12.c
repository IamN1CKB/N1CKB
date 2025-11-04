#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N_MAX 100
/*
[Insertion-sort] Utilizzare l’algoritmo del precedente esercizio per scrivere un programma che ordini il vettore 
contemporaneamente all’inserimento dei dati da parte dell’utente
*/
int main() {
    int vet[N_MAX];
    int l = 10;
    //printf("scegli una lunghezza del vettore (<%d): ", N_MAX);
    //scanf("%d", &l);
    int n = l;
    srand(time(NULL));
    for (int i = 0; i < l; i++)
        vet[i] = rand()%100;

    //VEDI
}