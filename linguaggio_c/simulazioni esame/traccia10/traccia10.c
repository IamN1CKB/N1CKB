//traccia del 10 gennaio 2024 a13_t12.pdf
#include <stdio.h>
#include <string.h>
#define N 100
#define N_MAX 100
struct myStruct {
    int indice;
    int n; 
    int valori[N_MAX];
    float media; 
};
typedef struct myStruct MyStruct;

int leggiMat(char *file, int mat[N][N], int *l, int *h);
void stampaMat(int mat[N][N], int l, int h);
void trovaPalin(int mat[N][N], int l, int *h);
void eliminaRiga(int mat[N][N], int l, int *h, int riga);
void creaStruct(MyStruct vet[N], int mat[N][N], int l, int h);
void ordinaStruct(MyStruct vet[N], int n);
void salvaB(MyStruct vet[], int n);
int main() {
    int mat[N][N], l, h;
    MyStruct vetStr[N];
    memset(vetStr, 0, sizeof(MyStruct)*N);
    if (leggiMat("input.txt", mat, &l, &h) == -1) {
        printf("err input file\n");
        return 0;
    }
    stampaMat(mat, l, h);
    trovaPalin(mat, l, &h);
    stampaMat(mat, l, h);
    creaStruct(vetStr, mat, l, h);
    ordinaStruct(vetStr, h);
    
    salvaB(vetStr, h);
    
}

void salvaB(MyStruct vet[], int n) {
    FILE *fp = fopen("output.bin", "w");
    if (fp == NULL) printf("ERR file output\n");
    else {
        fwrite(vet, sizeof(MyStruct), n, fp);
        fclose(fp);
    }  
}

void ordinaStruct(MyStruct vet[N], int n) {
    int condizione, p;
    MyStruct temp;
    do{
        condizione = 0;
        for (int i = 0; i < n-1; i++)
            if (vet[i].media<vet[i+1].media) {
                temp = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = temp;
                condizione = 1;
                p =i+1;
            }
        n = p;
    } while (condizione);
}

int leggiMat(char *file, int mat[N][N], int *l, int *h) {
    FILE *fp = fopen(file,"r");
    if (fp == NULL) return -1;
    else {
        fscanf(fp, "%d", h);
        fscanf(fp, "%d", l);
        for (int i = 0; i<*h; i++)
            for (int j = 0; j<*l; j++)
                fscanf(fp, "%d", &mat[i][j]);
        fclose(fp);
        return 0;
    }
}

void creaStruct(MyStruct vet[N], int mat[N][N], int l, int h) {
    float somma;
    for (int i = 0; i < l; i++) {
        somma = 0;
        vet[i].indice = i;
        vet[i].n = h;
        for (int j = 0; j < h; j++){
            somma+= mat[j][i];
            vet[i].valori[j] = mat[j][i];
        }
        vet[i].media = somma/h;
    }
    
}

void stampaMat(int mat[N][N], int l, int h) {
    printf("mat:\n");
    for (int i = 0; i<h; i++) {
        for (int j = 0; j<l; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
    printf("\n\n");
}

void trovaPalin(int mat[N][N], int l, int *h) {
    int cond;
    for (int i = 0; i<*h; i++) {
        cond = 1;
        for (int j = 0; (j<(l/2)) && (cond == 1); j++) {
            if (mat[i][j] == mat[i][l-1-j])
                cond = 1;
            else cond = 0;
        }
        if (cond == 1) {
            eliminaRiga(mat, l, h, i);
            i--;
        }
    }

}

void eliminaRiga(int mat[N][N], int l, int *h, int riga) {
    (*h)--;
    for (int i = riga; i<*h; i++) {
        for (int j = 0; j<l; j++)
            mat[i][j] = mat[i+1][j];
    }
}

