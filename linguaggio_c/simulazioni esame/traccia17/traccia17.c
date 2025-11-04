//quinta "traccia esame" su parsec
#include <stdio.h>
#include <string.h>
#define N 100
struct myStruct {
    int nCount;
    float median;
    char overMedian;
    int value;
};
typedef struct myStruct MyStruct;
int leggiMat(int mat[][N], int *l, char file[]);
void stampaMat(int mat[][N], int l);
void scambiaRighe(int mat[][N], int r1, int r2, int l);
void ordinaRighe(int mat[][N], int l);
void creaStruct(int mat[][N], int l, MyStruct s[]);
int salvaB(MyStruct s[], int n);
int main(){
    int mat[N][N], l;
    MyStruct vetStr[N];
    memset(vetStr, 0, sizeof(MyStruct)*N);
    if (leggiMat(mat, &l, "input.txt")==-1) {
        printf("ERR input");
        return -1;
    }
    stampaMat(mat, l);
    ordinaRighe(mat, l);
    stampaMat(mat, l);
    creaStruct(mat, l, vetStr);





    if (salvaB(vetStr, l)==-1) printf("ERR output");
    memset(vetStr, 0, sizeof(MyStruct)*N);
    FILE *fp =fopen("output.bin", "r");
    if (fp == NULL){
        printf("cazzo");
        return 0;
    }
    fread(vetStr, sizeof(MyStruct), l, fp);
    fclose(fp);
    
}

void creaStruct(int mat[][N], int l, MyStruct s[]){
    int somma, cont;
    for (int i = 0; i < l; i++) {
        s[i].value = mat[i][l-1];
        somma = cont = 0;
        for (int j = 0; j < l; j++) {
            if (s[i].value == mat[i][j])
                cont++;
            somma += mat[i][j];
        }
        s[i].nCount = cont-1;
        s[i].median = (float)somma/(float)l;
        if (s[i].median<s[i].value)
            s[i].overMedian = 'y';
        else
            s[i].overMedian = 'n';
    }
}

void scambiaRighe(int mat[][N], int r1, int r2, int l) {
    int temp;
    for (int i = 0; i < l; i++){
        temp = mat[r1][i];
        mat[r1][i] = mat[r2][i];
        mat[r2][i] = temp;
    }
}

void ordinaRighe(int mat[][N], int l) {
    int condizione, p, n = l;
    do {
        condizione = 0;
        for (int i = 0; i < n-1; i++)
            if (mat[i][l-1]>mat[i+1][l-1]) {
                scambiaRighe(mat, i, i+1, l);
                condizione = 1;
                p = i+1;
                stampaMat(mat, l);
            }
        n = p;
    } while (condizione);
}

int leggiMat(int mat[][N], int *l, char file[]){
    FILE *fp = fopen(file, "r");
    if (fp == NULL) return -1;
    else {
        fscanf(fp, "%d", l);
        for (int i = 0; i < *l; i++)
            for (int j = 0; j < *l; j++)
                fscanf(fp, "%d", &mat[i][j]);
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
    FILE *fp =fopen("output.bin", "w");
    if (fp == NULL) return -1;
    else {
        fwrite(s, sizeof(MyStruct), n, fp);
        fclose(fp);
        return 0;
    }
}