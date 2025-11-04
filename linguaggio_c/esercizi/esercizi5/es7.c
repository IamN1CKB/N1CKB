#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 100
/*
Scrivere un programma che, richiesti i valori di un vettore ordinato in modo crescente, li inverta ottenendo un vettore 
decrescente. Si chiede di risolvere il problema utilizzando un solo ciclo
*/
int main() {
    srand(time(NULL));
    int vet[N];
    int n = 10;
    //printf("inserisci lunghezza del vettore (<=%d)", N);
    //scanf("%d", &n);
    for (int i = 0; i < n; i++) vet[i] = rand()%100;

    int condizione, aux, p, n1 = n;
    do {
        condizione = 0;
        for (int i = 0; i < n1; i++)
            if (vet[i]>vet[i+1]) {
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
                condizione = 1;
                p = i+1;
            }
        n1 = p; 
    } while (condizione);
    
    
    //dobbiamo invertire il vettore
    for (int i = 0; i < n/2; i++) {
        aux = vet[i];
        vet[i] = vet[n-1-i];
        vet[n-1-i] = aux;
    }

    //stampa vettore
    printf("vet in ordine decrescente: ");
    for (int i = 0; i < n; i++)
        printf("%d ", vet[i]);
    
}