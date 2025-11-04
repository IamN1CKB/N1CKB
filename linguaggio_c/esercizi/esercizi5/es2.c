#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 100
/*
Scrivere un programma che carichi una matrice bidimensionale di caratteri e successivamente ricerchi al suo 
interno un valore passato in ingresso dall’utente. Il programma restituisce quindi il numero di linea e di colonna relativo 
all’elemento cercato se questo è presente nella matrice, il messaggio Elemento non presente altrimenti.
*/
int main(){
    char mat[N][N];
    int lunghezza, altezza;
    srand(time(NULL));
    //lunghezza = 10;
    //altezza = 10;
    printf("inserisci la lunghezza della matrice (<=100): ");
    scanf("%d", &lunghezza);
    printf("inserisci l'altezza della matrice (<=100): ");
    scanf("%d", &altezza);

    //inizializzazione e stampa matrice
    for (int i = 0; i < altezza; i++) {
        printf("vet[%d]: ", i);
        for (int j = 0; j < lunghezza; j++) {
            mat[i][j] = rand()%(127-33) + 33;
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }

    //ricerca completa di un carattere
    char x;
    printf("inserisci un carattere: ");
    scanf(" %c", &x);
    //ci servono delle variabili in cui salviamo gli indici dell'elemento trovato
    //usiamo 2 vettori di interi nel caso in cui ci sono più occorrenze
    int i1[N], j1[N];
    //inoltre ci serve un indice per questi 2 vettori che indica quante occorrenze ci sono state
    int k = 0;
    for (int i = 0; i < altezza; i++)
        for (int j = 0; j < lunghezza; j++)
            if (mat[i][j] == x) {
                i1[k] = i;
                j1[k] = j;
                k++;
            }
    if (k!=0) {
        printf("abbiamo trovato l'elemento in %d occorrenze\\a nella matrice mat[i][j], agli indici\n", k);
        for (int w = 0; w < k; w++) {
            printf("i = %d\t", i1[w]);
            printf("j = %d\n", j1[w]);
        }
    }
    else printf("Elemento non trovato");

}