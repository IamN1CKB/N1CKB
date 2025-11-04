#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
Il Bubble Sort è un algoritmo di ordinamento semplice che funziona confrontando ripetutamente gli elementi adiacenti in un array e
scambiandoli se non sono nell’ordine corretto1. Questo processo viene ripetuto fino a quando l’array non è completamente ordinato.

noi forniamo la versione più ottimizzata in cui c'è n variabile cond che ci controlla se l'array è già ordinato, e poi una variabile p,
che modifica la grandezza dell'array da controllare, siccome gli ultimi elementi dell'array sono già ordinati
*/


void stampaVet(int *arr, int n);
void bubbleSort(int *arr, int n);
void scambia(int *a, int *b);
int main () {
    //creiamo una array dinamico con valori random
    int *vet, n;
    printf("decidi il numero di elementi del vettore: ");
    scanf("%d", &n);
    vet = (int*) calloc(n, sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        vet[i] = rand()%100;
    stampaVet(vet, n);
    bubbleSort(vet, n);
    stampaVet(vet, n);
}

void stampaVet(int *arr, int n) {
    printf("vet: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void scambia(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *arr, int n) {
    int cond, p;
    do {
        cond = 0;
        for (int i = 0; i < n-1; i++)
            if (arr[i]>arr[i+1]){
                scambia(&arr[i], &arr[i+1]);
                cond = 1;
                p = i+1;
            }
        n = p;
    } while (cond);
}
