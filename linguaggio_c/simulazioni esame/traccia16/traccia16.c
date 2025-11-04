//seconda "traccia esame" su parsec
#include <stdio.h>
#include <string.h>
#define N 100
struct myStruct{
    char tipo;
    int indice;
    int confronto;
    int n;
    float vet[N];
};
typedef struct myStruct MyStruct;

int leggi(float mat[][N], int *l, float vet[], char *file);
void stampaMat(float mat[][N], int l);
void stampaVet(float vet[], int l);
void confronto(float vet[], float mat[][N], int l, MyStruct s[]);
void stampaStruct(MyStruct s[], int l);
int salvaB(MyStruct s[], int n, float mat[][N], float vet[]);

int main(){
    float mat[N][N], vet[N];
    int l;
    MyStruct vetStr[N];
    memset(vetStr, 0, sizeof(MyStruct)*N);
    leggi(mat, &l, vet, "input.txt");
    stampaMat(mat, l);
    stampaVet(vet, l);
    confronto(vet, mat, l, vetStr);
    stampaStruct(vetStr, l);

    if (salvaB(vetStr, 2*l, mat, vet) == -1) printf("ERR file output");
    
}

int salvaB(MyStruct s[], int n, float mat[][N], float vet[]) {
    FILE *fp = fopen("output.bin", "w");
    if (fp == NULL) return -1;
    else {
        fwrite(s, sizeof(MyStruct), n, fp);
        fclose(fp);
        return 0;
    }
}

void stampaStruct(MyStruct s[], int l) {
    for (int i = 0; i < 2*l; i++){
        if (s[i].tipo == 'r') printf("stiamo controllando una riga\n");
        else printf("stiamo controllando una colonna\n");
        printf("indice %d\n", s[i].indice);
        printf("confronto = %d\n", s[i].confronto);
        printf("n confronti = %d\n", s[i].n);
        printf("i valori confrontati sono:\t");
        for (int j = 0; j < l; j++)
            printf("%.2f\t", s[i].vet[j]);
        printf("\n\n");
    }
}

void confronto(float vet[], float mat[][N], int l, MyStruct s[]) {
    //confrontiamo prima le righe
    int n;
    for (int i = 0; i < l; i++) {
        s[i].tipo = 'r';
        s[i].indice = i;
        s[i].n = l;
        n = 0;
        for (int j = 0; j < l; j++) {
            s[i].vet[j] = mat[i][j];
            if (mat[i][j] == vet[j]) n++;   //vediamo se sono uguali (anche nella posizione)
        }
        if (n == 4) s[i].confronto = -1;    
        else {   //se non sono uguali e nella stessa posizione
            n = 0;
            for (int j = 0; j < l; j++) {
                for (int k = 0; k < l; k++) {
                    if (mat[i][k] == vet[j]) {  //verifichiamo se ogni elemento della riga della matrice è presente almeno una volta nel vettore
                        n++;
                        k = l;
                    }
                }
            }
            s[i].confronto = n;
        }
    }

    //confrontiamo ora le colonne (stesso algoritmo ma con gli indici invertiti)
    for (int i = 0; i < l; i++) {
        s[i+l].tipo = 'c';
        s[i+l].indice = i;
        s[i+l].n = l;
        n = 0;
        for (int j = 0; j < l; j++) {
            s[i+l].vet[j] = mat[j][i];
            if (mat[j][i] == vet[j]) n++;
        }
        if (n == 4) s[i+l].confronto = -1;    
        else {
            n = 0;
            for (int j = 0; j < l; j++) {
                for (int k = 0; k < l; k++) {
                    if (mat[k][i] == vet[j]) {
                        n++;
                        k = l;
                    }
                }
            }
            s[i+l].confronto = n;
        }
    }
}

int leggi(float mat[][N], int *l, float vet[], char* file) {
    FILE *fp = fopen(file, "r");
    if (fp == NULL) return -1;
    else {
        fscanf(fp, "%d", l);
        for (int i = 0; i < *l; i++)
            for (int j = 0; j < *l; j++)
                fscanf(fp, "%f", &mat[i][j]);
        for (int i = 0; i < *l; i++)
            fscanf(fp, "%f", &vet[i]);
        fclose(fp);
        return 0;
    }  
}

void stampaMat(float mat[][N], int l) {
    printf("mat:\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++)
            printf("%.2f\t", mat[i][j]);
        printf("\n");
    }
    printf("\n\n");
}

void stampaVet(float vet[], int l){
    printf("vet:\n");
    for (int i = 0; i < l; i++)
        printf("%.2f\t", vet[i]);
    printf("\n");
}

