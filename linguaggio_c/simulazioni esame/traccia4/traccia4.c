#include <stdio.h>
#include <string.h>
#define N 10 
struct myStruct {
    int lRiga;
    double eleRiga[N];
    int indiceRiga;
};
typedef struct myStruct MyStruct;

void leggiMat(char* file, int* l, int* h, double mat[N][N]);
void stampaMat(double mat[N][N], int l, int h);
int controllaRighe(double mat[N][N], int l , int *h, MyStruct righeEliminate[N]);
void stampaStruct(MyStruct s[N], int n);
void salvaB(MyStruct s[N], int n, double mat[N][N], int l, int h);
void eliminaRiga(double mat[N][N], int l, int *h, int riga);

int main() {
    int l, h, n_righeEliminate;
    double mat[N][N];
    MyStruct RigheEliminate[N];
    memset(RigheEliminate, 0, sizeof(MyStruct)*N);


    leggiMat("input.txt", &l, &h, mat);
    stampaMat(mat, l, h);

    n_righeEliminate = controllaRighe(mat, l, &h, RigheEliminate);

    stampaStruct(RigheEliminate, n_righeEliminate);


    salvaB(RigheEliminate, n_righeEliminate, mat, l, h);
    
}

void salvaB(MyStruct s[N], int n, double mat[N][N], int l, int h) {
    FILE *fp = fopen("output.bin", "w");
    if (fp == NULL) printf("ERR file output.bin");
    else {
        for (int i = 0; i < h; i++)
            fwrite(mat[i], sizeof(double), l, fp);
        fwrite(s, sizeof(MyStruct), n, fp);
        fclose(fp);
    }
}

void stampaStruct(MyStruct s[N], int n) {
    printf("ci sono %d righe eliminate di lunghezza %d\n", n, s[0].lRiga);

    for (int i = 0; i < n; i++) {
        printf("riga %d: ", s[i].indiceRiga);
        for (int j = 0; j < s[i].lRiga; j++){
            printf("%.2f\t", s[i].eleRiga[j]);
        }
        printf("\n");
    }
    printf("\n\n");
    
}

int controllaRighe(double mat[N][N], int l , int *h, MyStruct righeEliminate[N]) {
    double somma;
    int z = 0;
    for (int i = 0; i < *h; i++) {
        somma = 0;
        for (int j = 0; j < l; j++)
            somma += mat[i][j];
        if (somma == 0) {
            righeEliminate[z].indiceRiga = i+z;
            for (int w = 0; w < l; w++)
                righeEliminate[z].eleRiga[w] = mat[i][w];
            righeEliminate[z++].lRiga = l;
            eliminaRiga(mat, l, h, i);
            printf("riga eliminata %d\n", i);
            stampaMat(mat, l, *h);
            i--;
        }
    }
    return z;
}

void eliminaRiga(double mat[N][N], int l, int *h, int riga) {
    for (int i = riga; i < *h-1; i++) {
        for (int j = 0; j < l; j++) {
            mat[i][j] = mat[i+1][j];
        }
    }
    *h = *h-1;
}

void leggiMat(char* file, int* l, int* h, double mat[N][N]) {
    FILE *fp = fopen(file, "r");
    if (fp == NULL) printf("ERR file input.txt");
    else {
        fscanf(fp, "%d", h);
        fscanf(fp, "%d", l);
        for (int i = 0; i < *h; i++)
            for (int j = 0; j < *l; j++)
                fscanf(fp, "%lf", &mat[i][j]);
        fclose(fp);
    }
}

void stampaMat(double mat[N][N], int l, int h) {
    printf("mat:\n");
    for (int i = 0; i < h; i++) {
        printf("riga %d: ", i);
        for (int j = 0; j < l; j++)
            printf("%.2f\t", mat[i][j]);
        printf("\n");
    }
    printf("\n\n");
}