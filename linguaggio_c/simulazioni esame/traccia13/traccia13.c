//traccia del 10/12/2024 a13_t22.pdf
#include <stdio.h>
#include <string.h>
#define N 100
struct myStruct {
    int inizio[2];
    int fine[2];
    char parola[N];
};
typedef struct myStruct MyStruct;
int leggiMat(char mat[][N], char *file, int *l);
void stampaMat(char mat[][N], int l);
int checkParole(char mat[][N], int l, MyStruct *s);
void stampaStruct(MyStruct s[], int n);
void ordinaParole(MyStruct s[], int n);
int salvaB(MyStruct s[], int n);

int main(){
    char mat[N][N];
    int l, n_parole;
    MyStruct vetStr[N];
    printf("%d\n", strcmp("aaciao", "abc"));
    memset(vetStr, 0, sizeof(MyStruct)*N);
    if (leggiMat(mat, "input.txt", &l)==-1) {
        printf("ERR file input\n");
        return 0;
    }
    stampaMat(mat, l);
    n_parole = checkParole(mat, l, vetStr);

    stampaStruct(vetStr, n_parole);
    ordinaParole(vetStr, n_parole);
    stampaStruct(vetStr, n_parole);

    if (salvaB(vetStr, n_parole)==-1)
        printf("ERR output.bin\n");
}

void ordinaParole(MyStruct s[], int n) {
    int condizione;
    MyStruct temp;
    do {
        condizione = 0;
        for (int i = 0; i < n-1; i++){
            if (strcmp(s[i].parola, s[i+1].parola)<0){
                condizione = 1;
                temp = s[i];
                s[i] = s[i+1];
                s[i+1] = temp;
            }
        }
    } while (condizione);
}

int checkParole(char mat[][N], int l, MyStruct *s) {
    int parole = 0, isParola = 0, n_caratteri = 0;
    for (int j = 0; j < l; j++){
        for (int i = 0; i +j < l; i++) {
            if (isParola == 0) {
                if (mat[i][i+j] != ' ') {
                    isParola = 1;
                    s[parole].inizio[0] = i;
                    s[parole].inizio[1] = i + j;
                    s[parole].parola[n_caratteri++] = mat[i][i+j];
                }
            }
            else {
                if ((i==l-1) || (i+j==l-1)) {    
                    s[parole].parola[n_caratteri++] = mat[i][i+j];
                    s[parole].parola[n_caratteri] = '\0';
                    s[parole].fine[0] = i;
                    s[parole++].fine[1] = i+j;
                    isParola = n_caratteri =  0;
                }
                else {
                    if (mat[i][i+j] != ' ' && mat[i+1][i+j+1] == ' ') {
                        s[parole].parola[n_caratteri++] = mat[i][i+j];
                        s[parole].parola[n_caratteri] = '\0';
                        s[parole].fine[0] = i;
                        s[parole++].fine[1] = i+j;
                        isParola = n_caratteri = 0;
                    }
                    else {
                        s[parole].parola[n_caratteri++] = mat[i][i+j];
                    }                    
                }
            }
        }
    }
    for (int j = 1; j < l; j++){
        for (int i = 0; i+j < l; i++) {
            if (isParola == 0) {
                if (mat[i+j][i] != ' ') {
                    isParola = 1;
                    s[parole].inizio[0] = i+j;
                    s[parole].inizio[1] = i;
                    s[parole].parola[n_caratteri++] = mat[i+j][i];
                }
            }
            else {
                if ((i==l-1) || (i+j==l-1)) {    
                    s[parole].parola[n_caratteri++] = mat[i+j][i];
                    s[parole].parola[n_caratteri] = '\0';
                    s[parole].fine[0] = i+j;
                    s[parole++].fine[1] = i;
                    isParola = n_caratteri =  0;
                }
                else {
                    if (mat[i+j][i] != ' ' && mat[i+j+1][i+1] == ' ') {
                        s[parole].parola[n_caratteri++] = mat[i+j][i];
                        s[parole].parola[n_caratteri] = '\0';
                        s[parole].fine[0] = i+j;
                        s[parole++].fine[1] = i;
                        isParola = n_caratteri = 0;
                    }
                    else {
                        s[parole].parola[n_caratteri++] = mat[i+j][i];
                    }                    
                }
            }
        }
    }
    return parole;
}

void stampaStruct(MyStruct s[], int n) {
    printf("sono state trovate %d parole\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d) parola: %s\n", i+1, s[i].parola);
        printf("inizio: (%d, %d)\n", s[i].inizio[0], s[i].inizio[1]);
        printf("fine: (%d, %d)\n\n", s[i].fine[0], s[i].fine[1]);
    }
}

int leggiMat(char mat[][N], char *file, int *l) {
    FILE *fp = fopen(file, "r");
    if (fp == NULL) return -1;
    else {
        fscanf(fp, "%d ", l);
        for (int i = 0; i < (*l)*(*l); i++)
            mat[i/(*l)][i%(*l)] = fgetc(fp);
        fclose(fp);
        return 0;
    }
}

void stampaMat(char mat[][N], int l){
    printf("mat:\n");
    for (int i = 0; i < l; i++){
        for (int j = 0; j < l; j++)
            printf("%c ", mat[i][j]);
        printf("|\n");
    }
    printf("\n\n");
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