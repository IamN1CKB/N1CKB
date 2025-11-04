#include <stdio.h>
#define N 10
/*
Scrivere un programma di inizializzazione che richiesto un elemento controlli, prima di inserirlo nel vettore, se è
già presente, nel qual caso chieda che l’elemento sia digitato di nuovo. 
*/
int main() {
    int vet[N], condizione;
    printf("inserisci 10 numeri diversi\n");
    for (int i = 0; i < N; i++) {
        do {
            printf("inserisci un numero che non hai mai inserito: ");
            scanf("%d", &vet[i]);
            for (int j = 0; j < i; j++)
                if (vet[i] == vet[j]) {
                    printf("coglione, inserisci un numero del cazzo che non hai mai inserito\n");
                    condizione = 1;
                }
                else condizione = 0;
        } while (condizione);
        
    }
    
    return 0;
}