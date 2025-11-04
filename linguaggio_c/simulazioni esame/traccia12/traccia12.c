//traccia di una videolezione del prof: lezione del gennaio 2021 (non so quale precisa)
#include <stdio.h>
#include <string.h>
#define N 100
struct myStruct {
    int n_occorrenza;
    int pos[2];
    int n_val_uguali;
    int val_uguali[N];
};
typedef struct myStruct MyStruct;

int leggiFile(char* file, int mat[N][N], int vet[N], int *l_vet, int *l_mat, int *h_mat);
void stampaMat(int mat[N][N], int l, int h);
void stampaVet(int vet[N], int l);
int controllaOccorrenze(int vet[N], int mat[N][N], int l_vet, int l_mat, int h_mat, MyStruct s[N]);
void stampaStruct(MyStruct s[], int n);

int salvaB(char* file, int n, MyStruct s[]);
int main(){
    int mat[N][N], array[N], l_vet, l_mat, h_mat, occorrenze;
    MyStruct vetStr[N];
    memset(vetStr, 0, sizeof(MyStruct)*N);
    if (leggiFile("input.txt", mat, array, &l_vet, &l_mat, &h_mat)==-1) {
        printf("Err file input\n");
        return 0;
    }
    stampaVet(array, l_vet);
    stampaMat(mat, l_mat, h_mat);
    

    occorrenze =  controllaOccorrenze(array, mat, l_vet, l_mat, h_mat, vetStr);

    stampaStruct(vetStr, occorrenze);



    if (salvaB("output.bin", occorrenze, vetStr) == -1) printf("Err file output.bin\n");
}

void stampaStruct(MyStruct s[], int n) {
    for (int i = 0; i < n; i++){
        printf("occorrenza n %d\n", i+1);
        printf("posizione occ: (%d, %d)\n", s[i].pos[0], s[i].pos[1]);
        printf("numero di valori uguali: %d\n", s[i].n_val_uguali);
        printf("valori uguali: ");
        for (int j = 0; j < s[i].n_val_uguali; j++)
            printf("%d ", s[i].val_uguali[j]);
        printf("\n\n");
    }
    
}


int controllaOccorrenze(int vet[N], int mat[N][N], int l_vet, int l_mat, int h_mat, MyStruct s[N]) {
    int occorrenza = 0, cont = 0;
    for (int i = 0; i < h_mat; i++)
        for (int j = 0; j < l_mat; j++) {
            if (mat[i][j] == vet[cont]) { 
                if (cont == 0) {
                    s[occorrenza].pos[0] = i;
                    s[occorrenza].pos[1] = j;
                }
                s[occorrenza].val_uguali[cont] = mat[i][j];
                cont++;
                if (cont == l_vet || (i==h_mat-1 && j==l_mat-1)) {
                    s[occorrenza].n_occorrenza = occorrenza + 1;
                    s[occorrenza++].n_val_uguali = cont;
                    cont = 0;
                }
            }
            else
                if (cont>0) {
                    s[occorrenza].n_occorrenza = occorrenza + 1;
                    s[occorrenza++].n_val_uguali = cont;
                    cont = 0;
                    //dobbiamo anche ricontrollare l'ultimo valore
                    if (j != 0) j--;
                    else {
                        i--;
                        j = l_mat-1;
                    }
                }
        }
    return occorrenza;
}


int leggiFile(char* file, int mat[N][N], int vet[N], int *l_vet, int *l_mat, int *h_mat) {
    FILE *fp = fopen(file, "r");
    if (fp == NULL) return -1;
    else {
        fscanf(fp, "%d", l_vet);
        for (int i = 0; i < *l_vet; i++)
            fscanf(fp, "%d", &vet[i]);
        fscanf(fp, "%d", h_mat);
        fscanf(fp, "%d", l_mat);
        for (int i = 0; i < *h_mat; i++)
            for (int j = 0; j < *l_mat; j++)
                fscanf(fp, "%d", &mat[i][j]);
        fclose(fp);
        return 0;
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
void stampaVet(int vet[N], int l) {
    printf("vet:\n");
    for (int i = 0; i < l; i++)
        printf("%d\t", vet[i]);
    printf("\n\n");
}
int salvaB(char* file, int n, MyStruct s[]) {
    FILE *fp =fopen(file, "w");
    if (fp == NULL) return -1;
    else {
        fwrite(s, sizeof(MyStruct), n, fp);
        fclose(fp);
        return 0;
    }
}