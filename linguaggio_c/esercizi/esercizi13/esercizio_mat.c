/*abbiamo un file (matrice.txt) con tanti interi:
    i primi 2 numeri rappresentano le dimensioni di una matrice
    gli altri numeri, presi a coppie rappresentano le coordinate della stessa matrice
dobbiamo stampare a video la matrice con tutti spazi vuoti tranne nelle coordinate specificate, dove mettiamo un '*'
*/
#include <stdio.h>
#define  N 100
void stampaMat(char mat[][N], int l, int h);
int main() {
    char mat[N][N];
    int l, h, n_let, x, y;
    FILE *fp = fopen("file1/matrice.txt", "r");
    if (fp == NULL) {
        perror("ERR file");
        return 0;
    }
    fscanf(fp, "%d", &h);
    fscanf(fp, "%d", &l);

    for (int i = 0; i < h; i++)
        for (int j = 0; j < l; j++)
            mat[i][j] = ' ';
    

    do {
        for (int i = 0; i < 2; i++) {
            n_let = fscanf(fp, "%d", &x);
            n_let = fscanf(fp, "%d", &y);
            mat[x][y] = '*';
        }
    } while (n_let>0);

    stampaMat(mat, l, h);  
}

void stampaMat(char mat[][N], int l, int h) {
    printf("mat:\n");
    for (int i = 0; i < h; i++) {
        printf("|");
        for (int j = 0; j < l; j++)
            printf("%c  ", mat[i][j]);
        printf("|\n");
    }
    printf("\n");
}