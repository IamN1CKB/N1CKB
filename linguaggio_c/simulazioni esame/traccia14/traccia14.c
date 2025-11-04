//traccia del 10 gennaio 2024 a13_t11.pdf
#include <stdio.h>
#include <string.h>
#define  N 6
struct myStruct {
    int indice;
    int n; 
    int valori[N];
    float nmass; 
};
typedef struct myStruct MyStruct;
int leggiMat(char *file, int mat[][N], int *h, int *l);
void stampaMat(int mat[][N], int h, int l);
void trovaPalin(int mat[N][N], int *l, int h);
void eliminaColonna(int mat[N][N], int *l, int h, int col);
void creaStruct(MyStruct vet[N], int mat[N][N], int l, int h);
void ordinaStruct(MyStruct vet[N], int n);

int salvaB(MyStruct s[], int n);
int main(){
    int mat[N][N], l, h;
    MyStruct vetStr[N];
    memset(vetStr, 0, sizeof(MyStruct)*N);
    if (leggiMat("input.txt", mat, &h, &l) == -1){
        printf("ERR file input");
        return 0;
    }
    stampaMat(mat, h, l);
    trovaPalin(mat, &l, h);
    stampaMat(mat, h, l);
    creaStruct(vetStr, mat, l, h);
    ordinaStruct(vetStr, h);

    if (salvaB(vetStr, l) == -1) printf("ERR file output");
}

void trovaPalin(int mat[N][N], int *l, int h) {
    int cond;
    for (int i = 0; i<*l; i++) {
        cond = 1;
        for (int j = 0; (j<(h/2)) && (cond == 1); j++) {
            if (mat[j][i] == mat[h-1-j][i])
                cond = 1;
            else cond = 0;
        }
        if (cond == 1) {
            eliminaColonna(mat, l, h, i);
            i--;
        }
    }
}

void eliminaColonna(int mat[N][N], int *l, int h, int col) {
    (*l)--;
    for (int i = col; i<*l; i++)
        for (int j = 0; j<h; j++)
            mat[j][i] = mat[j][i+1];
}

void creaStruct(MyStruct vet[N], int mat[N][N], int l, int h) {
    float massimoMat = mat[0][0], massimoRiga;
    //troviamo prima il massimo della matrice
    for (int i = 0; i < h; i++)
        for (int j = 0; j < l; j++)
            if (massimoMat<mat[i][j])
                massimoMat = mat[i][j];
    
    for (int i = 0; i < h; i++) {
        vet[i].indice = i;
        vet[i].n = l;
        massimoRiga = mat[i][0];
        for (int j = 0; j < l; j++){
            vet[i].valori[j] = mat[i][j];
            if (massimoRiga < mat[i][j])
                massimoRiga = mat[i][j];
        }
        vet[i].nmass = massimoRiga/massimoMat;
    }
}

void ordinaStruct(MyStruct vet[N], int n) {
    int condizione, p;
    MyStruct temp;
    do{
        condizione = 0;
        for (int i = 0; i < n-1; i++)
            if (vet[i].nmass>vet[i+1].nmass) {
                temp = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = temp;
                condizione = 1;
                p =i+1;
            }
        n = p;
    } while (condizione);
}

int leggiMat(char *file, int mat[][N], int *h, int *l) {
    FILE *fp = fopen(file, "r");
    if (fp == NULL) return -1;
    else {
        fscanf(fp, "%d", h);
        fscanf(fp, "%d", l);
        for (int i = 0; i < (*h)*(*l); i++)
            fscanf(fp, "%d", &mat[i/(*l)][i%(*l)]);
        fclose(fp);
        return 0;
    }
}

void stampaMat(int mat[][N], int h, int l) {
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