//traccia biomedici del 10 gennaio 2024 etBiom2024_01_10.pdf
#include <stdio.h>
#include <string.h>
#define N 100
struct myStruct {
    int index;
    int n;
    int elems[N];
    float media;
};
typedef struct myStruct MyStruct;
int leggiMat(int mat[N][N], int *h, int *l, char* file);
void stampaMat(int mat[N][N], int h, int l);
void trovaMin(int mat[N][N], int h, int l);
void creaStruct(MyStruct s[], int mat[N][N], int h, int l);
int salvaB(MyStruct s[], int n);

int main() {
    int mat[N][N];
    int h, l;
    MyStruct vetStr[N];
    memset(vetStr, 0, sizeof(MyStruct)*N);
    if (leggiMat(mat, &h, &l, "input.txt") == -1){
        printf("ERR file input\n");
        return 0;
    }
    stampaMat(mat, h, l);
    trovaMin(mat, h, l);
    stampaMat(mat, h, l);
    creaStruct(vetStr, mat, h, l);
    if (salvaB(vetStr, h) == -1){
        printf("ERR file input\n");
        return 0;
    }
}

void creaStruct(MyStruct s[], int mat[N][N], int h, int l) {
    float somma;
    for (int i = 0; i < h; i++) {
        somma = 0;
        s[i].index = i;
        s[i].n = l;
        for (int j = 0; j < l; j++) {
            s[i].elems[j] = mat[i][j];
            somma += mat[i][j];
        }
        s[i].media = somma/(float)l;
    }
}

void trovaMin(int mat[N][N], int h, int l) {
    int min[N], somma[N];
    for (int i = 0; i < h; i++){
        somma[i] = 0;
        min[i] = mat[i][0];
        for (int j = 0; j < l; j++)
            if (mat[i][j]<min[i]) min[i] = mat[i][j];
        printf("min riga %d = %d\n", i, min[i]);
        if (min[i]<0){
            for (int j = 0; j < l; j++)
                mat[i][j] -= min[i];
        }
    }
}
int leggiMat(int mat[N][N], int *h, int *l, char* file) {
    FILE *fp = fopen(file, "r"); 
    if (fp == NULL) return -1;
    else {
        fscanf(fp, "%d ", h);
        fscanf(fp, "%d", l);
        for (int i = 0; i < *h; i++)
            for (int j = 0; j < *l; j++)
                fscanf(fp, "%d", &mat[i][j]);
        fclose(fp);
        return 0;
    }
}

void stampaMat(int mat[N][N], int h, int l){
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
        fwrite(s,sizeof(MyStruct), n, fp);
        fclose(fp);
        return 0;
    }
}