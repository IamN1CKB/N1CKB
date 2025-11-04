#include <stdio.h>

#define N 3
/*
[Matrici simmetriche] Una matrice quadrata n×n di un tipo qualsiasi si dice simmetrica se gli elementi
simmetrici rispetto alla diagonale principale (dal vertice alto sinistro al vertice basso destro) sono due a due uguali.
Scrivere un programma che, letta una matrice quadrata di interi, controlli se è simmetrica. 
*/
int main() {
    int mat[N][N], simmetrico;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            printf("mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    //stampa matrice
    printf("\nmat[N][N]\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (mat[i][j]==mat[j][i]) simmetrico = 1;
            else {
                simmetrico = 0;
                i = j = N;  //fa finire il ciclo subito
            }
        }

    if (simmetrico) printf("la matrice e' simmetrica");
    else printf("la matrice non e' simmetrica");
    
    
    
}