#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define N_MAX 100
/*
scrivere una funzione righeConsecutive che, data in ingresso una matrice di interi m, verifichi che non esistano due righe consecutive con somma pari a un numero primo
*/

int inizializzazione(int mat[N_MAX][N_MAX], int* lunghezza, int* altezza);

void somme(int somme[N_MAX], int mat[N_MAX][N_MAX], int lunghezza, int altezza);

void stampa(int somme[N_MAX], int mat[N_MAX][N_MAX], int lunghezza, int altezza);

int verifica(int somme[], int altezza);

int main() {
    int mat[N_MAX][N_MAX], l, a;
    
    inizializzazione(mat, &l, &a);

    int somma[N_MAX];
    somme(somma, mat, l, a);


    //stampiamo la matrice con le somme vicino
    stampa(somma, mat, l, a);
    
    if (!verifica(somma, a)) printf("non"); 

    printf("ci sono 2 righe consecutive la cui somma e' un numero primo");

}


int inizializzazione(int mat[N_MAX][N_MAX], int* lunghezza, int* altezza) {
    srand(time(NULL));   //genero numeri casuali nella matrice perché mi scoccio di metterli io da console
    printf("inserimento lunghezza e altezza della matrice\n");
    printf("lunghezza: ");
    scanf("%d", lunghezza);
    printf("altezza: ");
    scanf("%d", altezza);
    for (int i = 0; i < *altezza; i++)
        for (int j = 0; j < *lunghezza; j++)
            mat[i][j] = rand()%20;
}

void somme(int somme[N_MAX], int mat[N_MAX][N_MAX], int lunghezza, int altezza) {
    for (int i = 0; i < altezza; i++) {
        somme[i] = 0;
        for (int j = 0; j < lunghezza; j++)
            somme[i] += mat[i][j];
    }
    //in questo modo abbiamo un array delle somme delle righe

}

void stampa(int somme[N_MAX], int mat[N_MAX][N_MAX], int lunghezza, int altezza) {
    printf("colonne:\t|");
    for (int i = 0; i < lunghezza; i++) printf("%d\t", i);
    printf("|somma\n");
    for (int i = 0; i < 10*lunghezza; i++) printf("_", i);
    for (int i = 0; i < altezza; i++) {
        printf("\nriga %d: \t|", i);
        for (int j = 0; j < lunghezza+1; j++) {
            if (j!=lunghezza) printf("%d\t", mat[i][j]);
            else printf("|%d", somme[i]);
        }
    }
    printf("\n");
}

int verifica(int somme[], int altezza) {
    int condizione = 0, temp;
    for (int i = 0; i < altezza; i++) {
        temp = condizione;
        for (int j = 2; j < somme[i]/2; j++) {
            if (somme[i]%j != 0) condizione = temp + 1; //è primo
            else {
                condizione=0; //non è primo
                break;
            }
        }
        if(condizione == 2) 
            break;
    }
    return condizione == 2? 1 : 0;
}