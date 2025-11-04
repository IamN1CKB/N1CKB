#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 30
/*
Scrivere un programma che, inizializzato un vettore di char con una stringa di lettere dell’alfabeto e
punteggiatura, visualizzi il numero complessivo delle lettere del vettore.
*/
int main() {
    char vet[N];
    int lettere = 0;
    srand(time(NULL));
    for (int i = 0; i < N; i++)
        vet[i] = rand()%(127-33) + 33;  //troverà i valori della tabella ASCII che siano simboli di punteggiatura, numeri e lettere.
    
    printf("vet[%d]: '", N);
    for (int i = 0; i < N; i++) printf("%c", vet[i]);
    printf("'\n");
    
    //troviamo quante vocali e consonanti ci sono nel vettore
    for (int i = 0; i < N; i++)
        if (vet[i]>= 'A' && vet[i]<='z' && (vet[i] <= 'Z' || vet[i] >= 'a'))
            lettere++;
    printf("ci sono %d lettere", lettere);
    
}