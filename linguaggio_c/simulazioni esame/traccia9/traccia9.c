//settima traccia su parsec: prodotto matrici
//traccia incompleta: non la fare, devi saper fare il prodotto tra matrici
#include <stdio.h>
#include <string.h>
#define N 100
struct myStruct {
    int val;
    int i;
    int j;
};
typedef struct myStruct myStruct;

int leggiMat(int mat[][N], int *l, int *h, char *file);
void stampaMat(int mat[][N], int l, int h);
void trasporta(int mat[][N], int l, int h, int trasporta[][N]);
void prodottoMat(int mat[][N], int l, int h, int mat2[][N]);

int main(){
    int mat[N][N], trasporta[N][N];
    int l, h;
    if (leggiMat(mat, &l, &h, "input.txt") == -1) {
        printf("ERR file input\n");
        return 0;
    }
    stampaMat(mat, l, h);
}

void trasporta(int mat[][N], int l, int h, int trasporta[][N]) {

}

int leggiMat(int mat[][N], int *l, int *h, char *file) {
    FILE *fp = fopen(file, "r");
    if (fp == NULL) return -1;
    else {
        fscanf(fp, "%d", h);
        fscanf(fp, "%d", l);
        for (int i = 0; i < *h; i++)
            for (int j = 0; j < *l; j++)
                fscanf(fp, "%d", &mat[i][j]);
        fclose(fp);
        return 0;
    }
}

void stampaMat(int mat[][N], int l, int h) {
    printf("mat:\n");
    for (int i = 0; i < h; i++) {
        for (int  j = 0; j < l; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");    
    }
    printf("\n\n");
}