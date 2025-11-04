//traccia del 10 gennaio 2024 a13_t21.pdf
#include <stdio.h>
#include <string.h>
#define N 100
struct myStruct {
    int inizio[2];
    int fine[2];
    char parola[N];
};
typedef struct myStruct MyStruct;

int leggiMat(char mat[N][N], char* file, int *l);
void stampaMat(char mat[N][N], int l);
int cercaParoleOrizzontale(char mat[N][N], int l, MyStruct s[], int cont_parole);
void stampaStruct(MyStruct s[], int n);
int cercaParoleVerticale(char mat[N][N], int l, MyStruct s[], int cont_parole);
void ordinaParole(MyStruct s[], int cont_parole);
int main() {
    char mat[N][N];
    int l, n_parole = 0;
    MyStruct s[N/2];

    leggiMat(mat, "input.txt", &l);
    stampaMat(mat, l);
    n_parole = cercaParoleOrizzontale(mat, l, s, n_parole);
    n_parole = cercaParoleVerticale(mat, l, s, n_parole);
    stampaStruct(s, n_parole);
    ordinaParole(s, n_parole);
    stampaStruct(s, n_parole);

}

void ordinaParole(MyStruct s[], int cont_parole) {
    MyStruct temp;
    int condizione, p;
    do {
        condizione = 0;
        for (int i = 0; i < cont_parole-1; i++)
            if (strcmp(s[i].parola, s[i+1].parola)>0){
                temp = s[i];
                s[i] = s[i+1];
                s[i+1] = temp;
                condizione = 1;
                p=i+1;
            }
        cont_parole = p;
    } while (condizione); 
}

void stampaStruct(MyStruct s[], int n) {
    for (int i = 0; i < n; i++) {
        printf("la %d parola = %s\n", i+1, s[i].parola);
        printf("inizio = (%d, %d)\n", s[i].inizio[0], s[i].inizio[1]);
        printf("fine = (%d, %d)\n", s[i].fine[0], s[i].fine[1]);
        printf("\n");
    }
    printf("\n\n");
}

int cercaParoleOrizzontale(char mat[N][N], int l, MyStruct s[], int cont_parole) {
    int parola;    //variabile che indica se stiamo leggendo una parola
    int n_caratteri;  //numero di caratteri della parola che stiamo leggendo
    for (int i = 0; i < l; i++) {
        parola = 0;
        n_caratteri = 0;
        for (int j = 0; j < l; j++) {
            if ((mat[i][j] != ' ' )) {    //stiamo leggendo una lettera
                if ((mat[i][j+1] != ' ') && (j+1!=l)) { //non è l'ultima lettera della parola
                    s[cont_parole].parola[n_caratteri++] = mat[i][j];   //ci salviamo il carattere nella Struct e incrementiamo gli n_caratteri
                    if (parola == 0) { //la parola non c'era già e l'abbiamo appena trovata
                        parola = 1;    //segniamo l'inizio della parola
                        s[cont_parole].inizio[0] = i;  //salviamo anche lo coordinate delle parole
                        s[cont_parole].inizio[1] = j;
                    }
                }
                else if (parola) {         //è l'ultima lettera della parola
                    s[cont_parole].parola[n_caratteri++] = mat[i][j];  //salviamo l'ultima lettera
                    s[cont_parole].parola[n_caratteri] = '\0';         //aggiungiamo il carattere di terminazione
                    s[cont_parole].fine[0] = i;    //salviamo le coordinate di fine parola
                    s[cont_parole++].fine[1] = j;
                    parola = 0;   //segniamo che non stiamo leggendo più una parola
                    n_caratteri = 0;  //azzeriamo n_caratteri per la parola successiva
                }
            }
        }
    }
    return cont_parole;
}

int cercaParoleVerticale(char mat[N][N], int l, MyStruct s[], int cont_parole) {
    int parola;
    int n_caratteri;
    for (int i = 0; i < l; i++) {
        parola = n_caratteri = 0;
        for (int j = 0; j < l; j++) {
            if ((mat[j][i] != ' ' )) {
                if ((mat[j+1][i] != ' ') && (j+1<l)) {
                    s[cont_parole].parola[n_caratteri++] = mat[j][i];
                    if (parola == 0) { //la parola non c'era già e l'abbiamo appena trovata
                        parola = 1;
                        s[cont_parole].inizio[0] = j;
                        s[cont_parole].inizio[1] = i;
                    }
                }
                else if (parola) {
                    s[cont_parole].parola[n_caratteri++] = mat[j][i];
                    s[cont_parole].parola[n_caratteri] = '\0';
                    s[cont_parole].fine[0] = j;
                    s[cont_parole++].fine[1] = i;
                    parola = n_caratteri = 0;
                }
            }
        }
    }
    return cont_parole;
}

int leggiMat(char mat[N][N], char* file, int *l) {
    FILE *fp = fopen(file, "r");
    if (fp == NULL) return -1;
    else {
        fscanf(fp, "%d ", l);
        for (int i = 0; i < *l; i++)
            for (int j = 0; j < *l; j++)
                mat[i][j] = fgetc(fp);
        fclose(fp);
        return 1;
    }
}

void stampaMat(char mat[N][N], int l) {
    printf("mat:\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++)
            printf("%c ", mat[i][j]);
        printf("\n");
    }   
    printf("\n");
}