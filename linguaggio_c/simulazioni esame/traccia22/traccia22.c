//traccia "paroliamo" su parsec
#include <stdio.h>
#include <string.h>
#define N 100
typedef enum {verticale, orizzontale, obliquo} direzione;
typedef enum {destrasinistra, sinistadestra} oriz;
typedef enum {altobasso, bassoalto} vert;
struct myStruct{
    char v[N];
    int pos[2];
    direzione direz;
    oriz d_o;
    vert d_v;
};
typedef struct myStruct MyStruct;
int leggi(char *file, int *l, char mat[][N], MyStruct s[], int *n);
void stampaMat(char mat[][N], int l);
void ricerca(char mat[][N], int l, MyStruct *s);
void ordina(MyStruct s[], int n);
void stampaStr(MyStruct s[], int n);
int salvaB(MyStruct s[], int n);

int main(){
    MyStruct vetStr[N];
    memset(vetStr, 0, sizeof(MyStruct)*N);
    int n=-1, l;
    char mat[N][N];
    if (leggi("input.txt", &l, mat, vetStr, &n) == -1) {
        perror("ERR input");
        return 0;
    }
    stampaMat(mat, l);
    ordina(vetStr, n);
    stampaStr(vetStr, n);

    if (salvaB(vetStr, n) == -1) perror("ERR file output");
}

void ricerca(char mat[][N], int l, MyStruct *s) {
    int k = 0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            if (mat[i][j] == s->v[0]) {  //primo carattere è stato trovato
                s->pos[0] = i+1;  //l'algoritmo vuole che si parta a contare da 1
                s->pos[1] = j+1;
                //dobbiamo verificare tutte le direzioni e versi (porco cane)
                //verifichiamo il caso in cui la direzione è da sinistra a destra e stiamo in orizzontale
                k++;
                while (mat[i][j+k] == s->v[k] && j+k<l) {
                    if (s->v[k+1] == '\0') {
                        s->direz = orizzontale;
                        s->d_o = sinistadestra;
                        s->d_v = -1;
                        return;
                    }
                    k++;
                }
                //caso orizzontale destra-sinistra
                k = 1;
                while (mat[i][j-k] == s->v[k] && j-k>=0) {
                    if (s->v[k+1] == '\0') {
                        s->direz = orizzontale;
                        s->d_o = destrasinistra;
                        s->d_v = -1;
                        return;
                    }
                    k++;
                }
                //caso verticale alto-basso
                k = 1;
                while (mat[i+k][j] == s->v[k] && i+k<l) {
                    if (s->v[k+1] == '\0') {
                        s->direz = verticale;
                        s->d_o = -1;
                        s->d_v = altobasso;
                        return;
                    }
                    k++;
                }
                //caso verticale basso-alto
                k = 1;
                while (mat[i-k][j] == s->v[k] && i-k>=0) {
                    if (s->v[k+1] == '\0') {
                        s->direz = verticale;
                        s->d_o = -1;
                        s->d_v = bassoalto;
                        return;
                    }
                    k++;
                }
                //caso obliquo alto-basso, sinistra-destra
                k = 1;
                while (mat[i+k][j+k] == s->v[k] && (i+k<l) && (j+k<l)) {
                    if (s->v[k+1] == '\0') {
                        s->direz = obliquo;
                        s->d_o = sinistadestra;
                        s->d_v = altobasso;
                        return;
                    }
                    k++;
                }
                //caso obliquo alto-basso, destra-sinistra
                k = 1;
                while (mat[i+k][j-k] == s->v[k] && (i+k<l) && (j-k>=0)) {
                    if (s->v[k+1] == '\0') {
                        s->direz = obliquo;
                        s->d_o = destrasinistra;
                        s->d_v = altobasso;
                        return;
                    }
                    k++;
                }
                //caso obliquo basso-alto, sinistra-destra
                k = 1;
                while (mat[i-k][j+k] == s->v[k] && (i-k>=0) && (j+k<l)) {
                    if (s->v[k+1] == '\0') {
                        s->direz = obliquo;
                        s->d_o = sinistadestra;
                        s->d_v = bassoalto;
                        return;
                    }
                    k++;
                }
                //caso obliquo basso-alto, destra-sinistra
                k = 1;
                while (mat[i-k][j-k] == s->v[k] && (i-k>=0) && (j-k>=0)) {
                    if (s->v[k+1] == '\0') {
                        s->direz = obliquo;
                        s->d_o = destrasinistra;
                        s->d_v = bassoalto;
                        return;
                    }
                    k++;
                }
            }
        }
    }
}

void stampaStr(MyStruct s[], int n) {
    for (int i = 0; i < n; i++)
        printf("{\"%s\",\t[%d, %d], %d, %d, %d}\n", s[i].v, s[i].pos[0], s[i].pos[1], s[i].direz, s[i].d_o, s[i].d_v);
    printf("\n\n");
}

int leggi(char *file, int *l, char mat[][N], MyStruct s[], int *n) {
    char *p;
    FILE *fp = fopen(file, "r");
    if (fp == NULL) return -1;
    else {
        fscanf(fp, "%d ", l);
        for (int i = 0; i < (*l)*(*l); i++)
            mat[i/(*l)][i%(*l)] = fgetc(fp);
        fgetc(fp);   //dobbiamo consumare il carattere \n
        do {
            (*n)++;
            p = fgets(s[*n].v, N, fp);
            if (s[*n].v[strlen(s[*n].v)-1] == '\n') s[*n].v[strlen(s[*n].v)-1] = '\0';
            //da qui facciamo partire già il sottoprogramma per cercare quella parola
            ricerca(mat, *l, &(s[*n]));
        } while (p != NULL);
        fclose(fp);
        return 0;
    }
}

void stampaMat(char mat[][N], int l) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++)
            printf("%c ", mat[i][j]);
        printf("\n");
    }
    printf("\n\n");
}

void ordina(MyStruct s[], int n) {
    int condizione, p;
    MyStruct temp;
    do {
        condizione = 0;
        for (int i = 0; i < n-1; i++)
            if (strcmp(s[i].v, s[i+1].v)>0) {
                temp = s[i];
                s[i] = s[i+1];
                s[i+1] = temp;
                condizione = 1;
                p = i+1;
            }
        n = p;
    } while (condizione);
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