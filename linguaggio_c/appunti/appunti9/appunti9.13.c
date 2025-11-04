#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//allochiamo dinamicamente una matrice in sottoprogrammi

float **allocaMat_noParametri(int l, int h);
void freeMat(int h, float*** mat);
int allocaMat_conParametri(float ***mat, int l, int h);
//nel caso della matrice dinamica quindi non abbiamo bisogno di dire nel prototipo della funzione la lunghezza delle seconda dimensione,
//siccome sono stati allocati dinamicamente riga per riga.
void raddoppiaMat(float **mat, int l, int h);

void stampaMat(float **mat, int l, int h);
int main(){
    //allochiamo una matrice senza passarlo per parametro
    float **mat;
    int l;
    int h;
    printf("decidi lunghezza della matrice: ");
    scanf("%d", &l);
    printf("decidi altezza della matrice: ");
    scanf("%d", &h);
    if ((mat = allocaMat_noParametri(l, h)) == NULL) {
        perror("Allocazione fallita");
        return -1;
    }
    stampaMat(mat, l, h);
    for (int i = 0; i < h; i++)
        free(mat[i]);
    free(mat);
    
    

    //usiamo il metodo passando per parametro
    printf("decidi lunghezza della matrice: ");
    scanf("%d", &l);
    printf("decidi altezza della matrice: ");
    scanf("%d", &h);
    if (allocaMat_conParametri(&mat, l, h) == -1) {
        perror("allocazione fallita");
        return -1;
    }
    stampaMat(mat, l, h);
    //vogliamo modificare tutti gli elementi della matrice in modo che siano il loro doppio
    raddoppiaMat(mat, l, h);
    stampaMat(mat, l, h);
    
    //per liberare la memoria allocata dinamicamente in un sottoprogramma serve sempre il puntatore della variabile dinamica
    freeMat(h, &mat);
}



float **allocaMat_noParametri(int l, int h) {
    srand(time(NULL));
    float **mat = (float **) calloc(h, sizeof(float*));
    if (mat == NULL) return NULL;
    for (int i = 0; i < h; i++) {
        mat[i] = (float *) calloc(l, sizeof(float));
        if (mat[i] == NULL) return NULL;
        for (int j = 0; j < l; j++)
            mat[i][j] = rand()%100;
    }
    return mat;
}

void stampaMat(float **mat, int l, int h) {
    printf("mat:\n");
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < l; j++)
            printf("%.0f\t", mat[i][j]);
        printf("\n");
    }
}

int allocaMat_conParametri(float ***mat, int l, int h) {
    srand(time(NULL));
    *mat = (float **) calloc(h, sizeof(float*));
    if (*mat == NULL) return -1;
    for (int i = 0; i < h; i++) {
        (*mat)[i] = (float*) calloc(l, sizeof(float));
        if((*mat)[i] == NULL) return -1;
        for (int j = 0; j < l; j++)
            (*mat)[i][j] = rand()%100;
    }   
}

void raddoppiaMat(float **mat, int l, int h) {
    for (int i = 0; i < h; i++)
        for (int j = 0; j < l; j++)
            mat[i][j] *= 2;
}

void freeMat(int h, float*** mat) {
    for (int i = 0; i < h; i++)
        free((*mat)[i]);
    free(*mat);
}