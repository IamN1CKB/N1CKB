#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//quick sort
/*
Come ulteriore e più complesso esempio di procedura ricorsiva 
consideriamo ora il principe degli algoritmi di ordinamento, quicksort (letteralmente: “ordinamento veloce”). Con 
metodi matematici è possibile dimostrare che quicksort è in media il più veloce metodo di ordinamento a uso generale.
L’algoritmo di quicksort inizia determinando un ipotetico valore medio del vettore, detto pivot (“pernio”), quindi 
suddivide gli elementi in due parti: quella degli elementi più piccoli e quella degli elementi più grandi del pivot. Non è 
indispensabile che la suddivisione sia esattamente in parti uguali: l’algoritmo funziona con qualunque approssimazione. 
Tuttavia, quanto più la suddivisione è esatta, tanto più l’ordinamento risulta veloce.
*/
void creaVet(int *arr, int n);
void stampaVet(int *arr, int n);
void quickSort(int*, int, int);
void scambia(int *, int *);

int main () {
    //creiamo una array dinamico con valori random
    int *vet, n;
    printf("decidi il numero di elementi del vettore: ");
    scanf("%d", &n);
    vet = (int*) calloc(n, sizeof(int));
    creaVet(vet, n);
    stampaVet(vet, n);
    quickSort(vet, 0, n-1);
    stampaVet(vet, n);
}

void creaVet(int *arr, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand()%100;
}

void stampaVet(int *arr, int n) {
    printf("vet:\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

void scambia(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Procedura ricorsiva "quick sort" */
void quickSort(int *vet, int sin, int des) {
    int i, j, media;
    media = (vet[sin]+vet[des]) / 2;
    i = sin;
    j = des;
    do {
        while(vet[i]<media) i++;
        while(media<vet[j]) j--;
        if(i<=j) {
            scambia(&vet[i], &vet[j]);
            i++;
            j--;
        }
    } while (j>=i); 
    if(sin<j) quickSort(vet, sin, j); /* Invocazione ricorsiva */
    if(i<des) quickSort(vet, i, des); /* Invocazione ricorsiva */
}

//la complessità del quick sort è O(n*log(n)) nel caso migliore e O(n^2) nel caso peggiore