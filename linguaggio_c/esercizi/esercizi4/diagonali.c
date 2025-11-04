#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 100
/*
stampiamo tutte le diagonali di una matrice quadrata
*/
int main() {
    int mat[N][N], l;
    srand(time(NULL));
    do {
        printf("scegli la lunghezza della matrice quadrata (<%d): ", N);
        scanf("%d", &l);
    } while (l<0 || l>N);
    
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            mat[i][j] = rand()%100;
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    //stampa solo diagonali      for (int i = 0; i < l; i++)
    //stampa diagonali
    printf("stampa diagonali: \n");
    for (int j = 0; j < l; j++) {
        for (int i = 0; i+j<l; i++) {
            printf("%d ", mat[i+j][i]);
        }
        printf("\n");
    }
    for (int j = 1; j < l; j++) {
        for (int i = 0; i+j<l; i++) {
            printf("%d ", mat[i][i+j]);
        }
        printf("\n");
    }
    
    
    
    
}