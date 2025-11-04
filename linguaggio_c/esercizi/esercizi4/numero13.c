#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N_ROW 10
#define N_COL 15
/*
Scrivere un programma che, letta una matrice di interi o reali, individui la colonna con somma degli elementi
massima
*/
int main() {
    int mat[N_ROW][N_COL], somma_colonna[N_COL], massimo_somma = 0, w;
    srand(time(NULL));
    for (int i = 0; i < N_ROW; i++)
        for (int j = 0; j < N_COL; j++)
            mat[i][j] = rand()%101 -50;  //valori da -50 a 50
    
    printf("\t\tmat[%d][%d]\n", N_ROW, N_COL);
    for (int i = 0; i < N_ROW; i++) {
        for (int j = 0; j < N_COL; j++) printf("%d\t", mat[i][j]);
        printf("\n");
    }

    for (int i = 0; i < N_COL; i++) {
        somma_colonna[i] = 0;
        for (int j = 0; j < N_ROW; j++)
            somma_colonna[i] += mat[j][i];
        if (i==0) massimo_somma = somma_colonna[0];  //inizializziamo il massimo al primo valore da comparare
        else if (massimo_somma<somma_colonna[i]) {
            massimo_somma = somma_colonna[i];
            w = i;
        }
    }

    printf("somma delle colonne:\n");
    for (int i = 0; i < N_COL; i++) printf("%d\t", somma_colonna[i]);
    
    printf("\nla colonna che ha la somma più grande è la %d colonna: %d", w, somma_colonna[w]);   
}