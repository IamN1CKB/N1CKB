#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define P 4
#define M 5
/*
date 2 matrici mat1[N][P], mat2[P][M], inizializzare una terza matrice prodotto matp[N][M] tale che
matp[i][j] = mat1[i][0]*mat2[0][j] + mat1[i][1]*mat2[1][j] + mat1[i][2]*mat2[2][j] + mat1[i][3]*mat2[3][j] + ... + mat1[i][P]*mat2[P][j]
con i da 0 a N
con J da 0 a M
*/
int main() {
    int mat1[N][P], mat2[P][M], matp[N][M];

    //inizializzazione mat1[N][P] con valori casuali fino a 100
    srand(time(NULL));  //inizializziamo il generatore di numeri casuali
    for (int i = 0; i < N; i++)
        for (int j = 0; j < P; j++)
            mat1[i][j] = rand()%101;
    
    
    //inizializzazione mat2[P][M] con valori casuali fino a 100
    for (int i = 0; i < P; i++)
        for (int j = 0; j < M; j++)
            mat2[i][j] = rand()%101;
    

    //stampa mat1[][]
    printf("\n\tmat1[%d][%d]\n", N, P);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++)
            printf("%d\t", mat1[i][j]);
        printf("\n");
    }

    //stampa mat2[][]
    printf("\n\n\tmat2[%d][%d]\n", P, M);
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < M; j++)
            printf("%d\t", mat2[i][j]);
        printf("\n");
    }

    //inizializzazione matp[N][M]
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            //fin qui è l'inizializzazione di una qualsiasi matrice.
            matp[i][j] = 0;  //inizialmente settato a zero perché dobbiamo fare la somma dei prodotti
            for (int k = 0; k < P; k++)
                //questo ultimo for annidato somma tutti i prodotti che l'esercizio voleva
                matp[i][j] += mat1[i][k]*mat2[k][j];   
        }
    
    //stampa matp[][]
    printf("\n\n\tmatp[%d][%d]\n", N, M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            printf("%d\t", matp[i][j]);
        printf("\n");
    }
    
    
        

    return 0;
}