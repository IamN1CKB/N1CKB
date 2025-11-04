//terza "traccia esame" su parsec
#include <stdio.h>
#include <string.h>
#define N 100
struct myStruct {
    int position[2];
    int value;
    int sdiag;
};
typedef struct myStruct MyStruct;
int leggiMat(int mat[][N], int *l, char *file);
void stampaMat(int mat[][N], int l);
void checkMat(int mat[][N], int *l);
void elimina(int mat[][N], int *l, int iRiga, int iCol);
void creaStruct(int mat[][N], int l, MyStruct s[]);
int salvaB(MyStruct s[], int n);
int main() {
    int mat[N][N], l;
    MyStruct vetStr[N];
    memset(vetStr, 0, sizeof(MyStruct)*N);
    if (leggiMat(mat, &l, "input.txt")==-1){
        printf("ERR file input");
        return 0;
    }
    stampaMat(mat, l);
    checkMat(mat, &l);
    creaStruct(mat, l, vetStr);
    stampaMat(mat, l);
    

    if (salvaB(vetStr, l)==-1)
        printf("ERR file output");
}

void creaStruct(int mat[][N], int l, MyStruct s[]) {
    int cont = 0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            s[cont].position[0] = i;
            s[cont].position[1] = j;
            if (j == l-1-i) s[cont].sdiag = 1;
            else s[cont].sdiag = 0;
            s[cont++].value = mat[i][j];
        }
    }
}

void checkMat(int mat[][N], int *l) {
    int somma, cont = 0;
    for (int i = 0; i < *l; i++){
        somma = 1;
        for (int j = 2; j <= (mat[i][*l-1-i])/2; j++)
            if ((mat[i][*l-1-i])%j == 0)
                somma += j;
        if (somma == mat[i][*l-1-i] && mat[i][*l-1-i] != 1) {
            elimina(mat, l, i, *l-1-i);
            i--;
        }
    }
}

void elimina(int mat[][N], int *l, int iRiga, int iCol) {
    (*l)--;
    for (int i = iRiga; i < *l; i++)
        for (int j = 0; j < *l+1; j++)  //usiamo *l+1 perché la lunghezza della riga ancora non l'abbiamo modificata
            mat[i][j] = mat[i+1][j];
    stampaMat(mat, *l+1);
    for (int i = iCol; i < *l; i++)
        for (int j = 0; j < *l; j++)
            mat[j][i] = mat[j][i+1];
    stampaMat(mat, *l);
}

int leggiMat(int mat[][N], int *l, char *file) {
    FILE *fp = fopen(file, "r");
    if (fp == NULL) return -1;
    else {
        fscanf(fp, "%d", l);
        for (int i = 0; i < (*l)*(*l); i++)
            fscanf(fp, "%d", &mat[i/(*l)][i%(*l)]);
        fclose(fp);
        return 0;
    }
}

void stampaMat(int mat[][N], int l) {
    printf("mat:\n");
    for (int i = 0; i < l; i++) {
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
