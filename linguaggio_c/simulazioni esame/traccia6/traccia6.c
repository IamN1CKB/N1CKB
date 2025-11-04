//è la 5 traccia su parsec
#include <stdio.h>
#include <string.h>
#define N 100
struct Mystruct {
    int valore;
    int occorrenze;
    int indiciriga[N];
    int indicicolonna[N];
};
typedef struct Mystruct MyStruct;

int leggiMat(int mat[N][N], int *l, int *h, char *file);
void stampaMat(int mat[N][N], int l, int h);
int mat_in_vet(int mat[N][N], int vet[], int l, int h);
void stampaVet(int vet[], int l);
void creaStruct(int mat[N][N], int vet[], int l, int h, MyStruct s[], int l_array);
void ordinaStruct(MyStruct s[], int n);
int salvaB(MyStruct s[], int n);

int main() {
    int mat[N][N], l, h, array[N], l_array;
    MyStruct structVet[N];
    memset(structVet, 0, sizeof(MyStruct)*N);
    if (leggiMat(mat, &l, &h, "input.txt")==-1){
        printf("ERR input\n");
        return 0;
    }
    stampaMat(mat, l, h);
    l_array = mat_in_vet(mat, array, l, h);
    
    stampaVet(array, l_array);

    creaStruct(mat, array, l, h, structVet, l_array);

    ordinaStruct(structVet, l_array);
    if (salvaB(structVet, l_array) == -1) {
        printf("ERR output.bin");
        return 0;
    }
}
void ordinaStruct(MyStruct s[N], int n) {
    MyStruct temp;
    int condizione, p;
    do {
        condizione = 0;
        for (int i = 0; i < n-1; i++) {
            if (s[i].occorrenze>s[i+1].occorrenze) {
                temp = s[i];
                s[i] = s[i+1];
                s[i+1] = temp;
                condizione = 1;
                p = i+1;
            }  
        }
        n = p;
    } while (condizione);
}

void creaStruct(int mat[N][N], int vet[N], int l, int h, MyStruct s[N], int l_array) {
    int cont;
    for (int i = 0; i < l_array; i++) {
        s[i].valore = vet[i];
        cont = 0;
        for (int j = 0; j < h; j++)
            for (int k = 0; k < l; k++)
                if (mat[j][k] == vet[i]){
                    s[i].indiciriga[cont] = j+1;   //l'algortimo di 25 vuole che si parta a contare dalla riga 1
                    s[i].indicicolonna[cont] = k+1;                    
                    cont++;
                }
        s[i].occorrenze = cont;
    }
}

void stampaVet(int vet[N], int l) {
    printf("vet:\n");
    for (int i = 0; i < l; i++)
        printf("%d\t", vet[i]);
    printf("\n");   
}

int mat_in_vet(int mat[N][N], int vet[N], int l, int h) {
    int cont = 0, condizione=1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < l; j++){
            condizione = 1;
            for (int k = 0; (k < cont) && (condizione == 1); k++)
                if (mat[i][j] != vet[k]) condizione = 1;
                else condizione = 0;
            if (condizione==1)
                vet[cont++] = mat[i][j];
        }
    }
    return cont;
}

int leggiMat(int mat[N][N], int *l, int *h, char *file) {
    FILE *fp = fopen(file, "r");
    if (fp == NULL) return -1;
    else {
        fscanf(fp, "%d", h);
        fscanf(fp, "%d", l);
        for (int i = 0; i < *h; i++)
            for (int j = 0; j < *l; j++)
                fscanf(fp, "%d", &mat[i][j]);
        fclose(fp);
        return 1;
    }
}

void stampaMat(int mat[N][N], int l, int h) {
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
        return 1;
    }
}