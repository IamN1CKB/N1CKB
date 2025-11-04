//provo a fare la prima "traccia" su parsec, ma con allocazione dinamica
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    float avg;
    char id;
    int rc;
} Struttura;
int leggiMat(float ***mat, int *l, int *h, char *file);
//serve il puntatore al cubo di mat perché altrimenti l'allocazione avviene a una copia del puntatore al quadrato
void stampaMat(float **mat, int l, int h);
void creaStruct(Struttura * s, int l, int h, float **mat);
void ordina(Struttura *s, int n);
void stampaStruct(Struttura *s, int n);
int salvaB(Struttura *s, int n);
int main(){
    Struttura *vetStr;
    float **mat;
    int l, h;
    if (leggiMat(&mat, &l, &h, "input.txt") == -1) {
        perror("ERR file");
        return -1;
    }
    stampaMat(mat, l, h);
    vetStr = (Struttura *) calloc(l+h, sizeof(Struttura));
    creaStruct(vetStr, l, h, mat);
    for (int i = 0; i < h; i++)
        free(mat[i]);
    free(mat);
    ordina(vetStr, l+h);
    stampaStruct(vetStr, l+h);
    if (salvaB(vetStr, l+h) == -1) {
        perror("ERR salvataggio binario");
    }
    free(vetStr);
}

int leggiMat(float ***mat, int *l, int *h, char *file) {
    FILE *fp = fopen(file, "r");
    if (fp == NULL) return -1;
    fscanf(fp, "%d", h);
    fscanf(fp, "%d", l);
    *mat = (float**) calloc(*h, sizeof(float*));
    for (int i = 0; i < *h; i++) {
        (*mat)[i] = (float*) calloc(*l, sizeof(float));    //qui usiamo la dereferenziazione per avere il puntatore della matrice 
        for (int j = 0; j < *l; j++)
            fscanf(fp, "%f", &(*mat)[i][j]);  
    }
    fclose(fp);
    return 0;
}

void stampaMat(float **mat, int l, int h) {
    printf("mat:\n");
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < l; j++)
            printf("%f\t", mat[i][j]);
        printf("\n");
    }
}

void creaStruct(Struttura *s, int l, int h, float **mat) {
    float somma;
    for (int i = 0; i < h; i++) {
        somma = 0;
        for (int j = 0; j < l; j++)
            somma += mat[i][j];
        s[i].avg = somma/l;
        s[i].id = 'r';
        s[i].rc = i;
    }
    for (int i = 0; i < l; i++) {
        somma = 0;
        for (int j = 0; j < h; j++)
            somma += mat[j][i];
        s[i+h].avg = somma/h;
        s[i+h].id = 'c';
        s[i+h].rc = i;
    }
}

void ordina(Struttura *s, int n) {
    int condizione, p;
    Struttura temp;
    do {
        condizione = 0;
        for (int i = 0; i < n-1; i++)
            if (s[i].avg>s[i+1].avg) {
                condizione = 1;
                p = i+1;
                temp =s[i];
                s[i] = s[i+1];
                s[i+1] = temp;
            }
        n = p;
    } while (condizione);
}

void stampaStruct(Struttura *s, int n) {
    for (int i = 0; i < n; i++)
        printf("%.2f, '%c', %d\n", s[i].avg, s[i].id, s[i].rc);
}

int salvaB(Struttura *s, int n) {
    FILE *fp = fopen("output.bin", "w");
    if (fp == NULL) return -1;
    fwrite(s, sizeof(Struttura), n, fp);
    fclose(fp);
    return 0;
}