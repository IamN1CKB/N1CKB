//leggiamo il vettore e la matrice cha abbiamo salvato precedentemente
#include <stdio.h>
#define N 100
int leggiB(char* file, int vet[], int *l_v, int mat[][N], int *l_m, int *h_m);
void stampaMat(int mat[][N], int l, int h);
void stampaVet(int vet[], int l);

int main() {
    int mat[N][N], vet[N], l_vet, l_mat, h_mat;
    if (leggiB("array.bin", vet, &l_vet, mat, &l_mat, &h_mat) == -1) {
        perror("ERR file");
        return 0;
    }
    printf("la lunghezza del vet: %d\n", l_vet);
    stampaVet(vet, l_vet);
    printf("la lunghezza della mat: %d\n", l_mat);
    printf("l'altezza della mat: %d\n", h_mat);
    stampaMat(mat, l_mat, h_mat);
}

int leggiB(char* file, int vet[], int *l_v, int mat[][N], int *l_m, int *h_m) {
    FILE *fp = fopen(file, "r");
    if (fp == NULL) return -1;
    else {
        //abbiamo salvato nel file binario il tutto in questo ordine: lunghezza vet, vet, lunghezza mat, altezza mat, mat
        fread(l_v, sizeof(int), 1, fp);
        fread(vet, sizeof(int), *l_v, fp);

        fread(l_m, sizeof(int), 1, fp);
        fread(h_m, sizeof(int), 1, fp);
        for (int i = 0; i < *h_m; i++)
            for (int j = 0; j < *l_m; j++)
                fread(&mat[i][j], sizeof(int), 1, fp);    
        fclose(fp);
        return 0;
    }
}


void stampaMat(int mat[][N], int l, int h) {
    printf("mat:\n");
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < l; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}
void stampaVet(int vet[], int l) {
    printf("vet:\n");
    for (int i = 0; i < l; i++)
        printf("%d ", vet[i]);
    printf("\n");
}