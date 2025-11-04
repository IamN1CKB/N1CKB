#include <stdio.h>
#include <string.h>
#define N 100
struct myStruct{
    float colonna[N];
    int indice;
    int numero_righe;
};
typedef struct myStruct MyStruct;

void leggiMat(float m[N][N], int *l, char *nomeFile);

void stampaMat(float m[N][N], int l);

void scambioFloat(float *a, float *b);

void ordina(float m[N][N], int l, int r);

void definizioneStruct(MyStruct s[], float mat[N][N], int l);

void salvaB(MyStruct s[], int l);

int main() {
    float mat[N][N];
    int l;  //lunghezza di un lato della matrice
    MyStruct s[N];
    memset(s, 0, sizeof(MyStruct)*N);

    leggiMat(mat, &l, "input.txt");
    stampaMat(mat, l);
    //dobbiamo scambiare gli elementi della diagonale principale con gli elementi della prima colonna
    for (int i = 0; i < l; i++)
        scambioFloat(&mat[i][i], &mat[i][0]);

    stampaMat(mat, l);

    //dobbiamo scambiare gli elementi della diagonale secondaria con gli elementi dell'ultima colonna
    for (int i = 0; i < l; i++)
        scambioFloat(&mat[i][l-i-1], &mat[i][l-1]);
    
    stampaMat(mat, l);

    ordina(mat, l, l-1);
    stampaMat(mat, l);

    definizioneStruct(s, mat, l);

    salvaB(s,l);
}


void scambioFloat(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void leggiMat(float m[N][N], int *l, char *nomeFile) {
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) printf("ERR file input\n");
    else {
        fscanf(fp, "%d", l);
        for (int i = 0; i < *l; i++)
            for (int j = 0; j < *l; j++) 
                fscanf(fp, "%f", &m[i][j]);
        fclose(fp);
    }
    
}

void stampaMat(float m[N][N], int l) {
    printf("mat:\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++)
            printf("%.1f\t", m[i][j]);
        printf("\n");
    }
    printf("\n\n");
}

void ordina(float m[N][N], int l, int r) {
    //dobbiamo scambiare le colonne in modo che gli elementi dell'ultima riga si trova in ordinati in senso decrescente
    int condizione, p;
    do {
        condizione = 0;
        for (int i = 0; i<l-1; i++) {
            if (m[r][i]<m[r][i+1]) {
                for (int j = 0; j < l; j++)
                    scambioFloat(&m[j][i],&m[j][i+1]);
                condizione = 1;
            }
        }
    } while (condizione);
    
}

void definizioneStruct(MyStruct s[], float mat[N][N], int l) {
    /*
    vettore di struct il cui i-esimo elemento contiene:
        -Gli elementi della colonna
        -L'indice di colonna
        -Il numero di elementi della colonna
    */

    for (int i = 0; i < l; i++) {
        s[i].indice = i;
        s[i].numero_righe = l;
        for (int j = 0; j < l; j++)
            s[i].colonna[j] = mat[j][i];
    }

}

void salvaB(MyStruct s[], int l) {
    FILE *fp = fopen("output.bin", "w");
    if (fp == NULL) printf("ERR file output\n");
    else {
        fwrite(s,sizeof(MyStruct), l, fp);
        fclose(fp);
    }
}
