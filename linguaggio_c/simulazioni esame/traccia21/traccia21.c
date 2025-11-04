//traccia fatta ad esercitazione
#include <stdio.h>
#include <string.h>
#define N 100

int leggiMat(float mat[][N], int *l, char *file);
void stampaMat(float mat[][N], int l);
void media_min(float mat[][N], int l);
void scambiaRiga(float mat[][N], int r1, int r2, int l);
void ordinamento(float mat[][N], int l);
int main() {
    float mat[N][N];
    int l = -1;
    if (leggiMat(mat, &l, "input.txt")==-1) {
        perror("ERR input");
        return 1;
    }
    printf("matrice letta da file:\n");
    stampaMat(mat, l);

    
    media_min(mat,l);
    printf("matrice modificata con sottrazioni e addizioni:\n");
    stampaMat(mat, l);


    ordinamento(mat, l);
    printf("matrice in ordine decrescente secondo la prima colonna:\n");
    stampaMat(mat, l);
}

void media_min(float mat[][N], int l) {
    float cont = 0;
    float min = mat[0][0];
    for (int i = 0; i < l; i++) {
        cont += mat[i][i];
        if (min>mat[i][i]) min = mat[i][i];
    }
    cont /= l;
    for (int i = 0; i < l-1; i++) {
        for (int j = 0; j < l-1-i; j++) {
            mat[i][j] -= cont;
            mat[l-1-i][l-1-j] += min;
        }
    }
}

void scambiaRiga(float mat[][N], int r1, int r2, int l) {
    float temp;
    for (int i = 0; i < l; i++){
        temp = mat[r1][i];
        mat[r1][i] = mat[r2][i];
        mat[r2][i] = temp;
    }
}

void ordinamento(float mat[][N], int l) {
    int condizione, p, l1 =l;
    do {
        condizione = 0;
        for (int i = 0; i < l1-1; i++)
            if (mat[i][0]<mat[i+1][0]) {
                condizione = 1;
                p = i+1;
                scambiaRiga(mat, i, i+1, l);
            }
        l1 = p;
    } while (condizione);
}

int leggiMat(float mat[][N], int *l, char *file) {
    FILE *fp = fopen(file, "r");
    char buf[2*N], *p;
    if (fp == NULL) return -1;
    else {
        do {
            p = fgets(buf, N, fp);
            (*l)++;
        } while (p != NULL);
        fseek(fp, 0, 0);
        for (int i = 0; i < (*l)*(*l); i++)
            fscanf(fp, "%f", &mat[i/(*l)][i%(*l)]);
        fclose(fp);
        return 0;
    }
}

void stampaMat(float mat[][N], int l) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++)
            printf("%.2f\t", mat[i][j]);
        printf("\n");
    }
    printf("\n\n");
}