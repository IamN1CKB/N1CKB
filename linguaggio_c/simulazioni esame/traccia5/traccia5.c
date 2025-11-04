//4 traccia su parsec
#include <stdio.h>
#define N 100
int leggiMat(int mat[N][N], int *l, char * file);
void stampaMat(int mat[N][N], int l);
void scambiaMassimo(int mat[N][N], int l);
void scambiaInt(int *a, int *b);
int media(int mat[N][N], int l);
int salvaB(int mat[N][N], int l);

int main() {
    int mat[N][N], l;
    if (leggiMat(mat, &l, "input.txt")==-1){
        perror("ERR file input\n");
        return 0;
    }
    stampaMat(mat, l);
    scambiaMassimo(mat, l);
    
    media(mat, l);
    stampaMat(mat, l);
    if (salvaB(mat, l)==-1)
        perror("ERR file output\n");
}

int media(int mat[][N], int l) {
    int sotto = 0, sopra = 0, med;
    for (int i = 0; i < l-1; i++)
        for (int j = i; j < l-1; j++){
            sopra += mat[i][j+1];
            sotto += mat[l-1-i][j-i];
        }
    med = (sopra+sotto)/2;
    mat[l-1][l-1] = med;
    return med;    
}

void scambiaInt(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void scambiaMassimo(int mat[N][N], int l) {
    int temp, massimo;
    int iMax, jMax;
    for (int i = 0; i < l; i++){
        massimo = mat[i][0];
        iMax = i;
        jMax = 0;
        for (int j = 0; j < l; j++)
            if (mat[j][i]>massimo) {
                massimo = mat[j][i];
                iMax = i;
                jMax = j;
            }
        scambiaInt(&mat[i][i], &mat[jMax][iMax]);
    }
}

int leggiMat(int mat[N][N], int *l, char * file) {
    FILE *fp = fopen(file, "r");
    if (fp == NULL) return -1;
    else {
        fscanf(fp, "%d", l);
        for (int i = 0; i < *l; i++)
            for (int j = 0; j < *l; j++)
                fscanf(fp, "%d", &mat[i][j]);
        fclose(fp);
        return 1;
    }
}

void stampaMat(int mat[N][N], int l) {
    printf("mat:\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
    printf("\n");
}

int salvaB(int mat[N][N], int l) {
    FILE *fp = fopen("output.bin", "w");
    if (fp == NULL) return -1;
    else {
        for (int i = 0; i < l; i++)
            fwrite(mat[i], sizeof(int), l, fp);
        fclose(fp);
        return 1;
    }
}