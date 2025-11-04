//ottava traccia su parsec: "traccia" subito dopo "prodotto matrici"
#include <stdio.h>
#include <string.h>
#define N 100
struct myStruct {
    int riga[50];
    int lriga;
    int index;
    float media;
    int diff;
};
typedef struct myStruct MyStruct;
int leggiMat(int mat[][N], int *l, int *h, char *file);
void stampaMat(int mat[][N], int l, int h);
int checkDifferenza(int mat[][N], int *h, int l, MyStruct s[]);
void eliminaRiga(int mat[][N], int *h, int l, int riga);
int salvaB(MyStruct s[], int n);

int main() {
    int mat[N][N], l, h, n_eliminazioni;
    MyStruct vetStr[N];
    if (leggiMat(mat, &l, &h, "input.txt")==-1) {
        printf("ERR file input");
        return 0;
    }
    stampaMat(mat, l, h);
    n_eliminazioni = checkDifferenza(mat, &h, l, vetStr);

    if (salvaB(vetStr, n_eliminazioni) == -1) printf("ERR file output");
}

int checkDifferenza(int mat[][N], int *h, int l, MyStruct s[]) {
    int max, min, cont = 0;;
    float media;
    for (int i = 0; i < *h; i++){
        min = max = mat[i][0];
        media = 0;
        for (int j = 0; j < l; j++){
            media += mat[i][j];
            s[cont].riga[j] = mat[i][j];
            if (max<mat[i][j]) max = mat[i][j];
            if (min>mat[i][j]) min = mat[i][j];
        }
        media /= l;
        if ((max - min)>media) {
            s[cont].index = i + cont;
            s[cont].lriga = l;
            s[cont].media = media;
            s[cont++].diff = max-min;
            eliminaRiga(mat, h, l, i);
            i--;
            stampaMat(mat, l, *h);
        }
    }
    return cont;
}

void eliminaRiga(int mat[][N], int *h, int l, int riga) {
    (*h)--;
    for (int i = riga; i < *h; i++)
        for (int j = 0; j < l; j++)
            mat[i][j] = mat[i+1][j];
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
        for (int j = 0; j < l; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
    printf("\n\n");
}

int salvaB(MyStruct s[], int n) {
    FILE *fp = fopen("output.bin", "w");
    if (fp == NULL) return -1;
    else {
        fwrite(s, sizeof(MyStruct), n, fp);
        fclose(fp);
        return 0;
    }
}