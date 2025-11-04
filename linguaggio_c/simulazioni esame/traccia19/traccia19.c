//quarta "traccia esame" su parsec
#include <stdio.h>
#include <string.h>
#define N 100
struct myStruct {
    char parola[N];
    int num_occorrenze;
    int indice_parola;
};
typedef struct myStruct MyStruct;


int leggiStr(char *file, char *str);
int dividiStr(char str[], MyStruct s[]);
void trovaOccorrenze(MyStruct s[], int parole, char *file);
void ordina(MyStruct s[], int n);
int salvaB(MyStruct s[], int n);
int main() {
    char str_main[N];
    int parole;
    MyStruct vetStr[N];
    memset(vetStr, 0, sizeof(MyStruct)*N);
    if (leggiStr("input.txt", str_main)==-1) {   //legge solo la prima riga
        perror("ERR input");
        return 0;
    }
    parole = dividiStr(str_main, vetStr);
    trovaOccorrenze(vetStr, parole, "input.txt");
    ordina(vetStr, parole);

    if (salvaB(vetStr, parole)==-1) perror("ERR output");
}

void trovaOccorrenze(MyStruct s[], int parole, char *file) {
    char buf[N], *trovato;
    FILE *fp = fopen(file, "r");
    for (int i = 0; i < parole; i++) {
        fgets(buf, N, fp); //leggiamo la prima riga che non ci serve
        while (fgets(buf, N, fp) != NULL) {
            trovato = buf;
            printf("%s", trovato);
            trovato = strstr(trovato, s[i].parola);
            if (trovato != NULL)
                s[i].num_occorrenze++;
        }
        fseek(fp, 0, 0);
    }
    fclose(fp);    
}

void ordina(MyStruct s[], int n) {
    int condizione, p;
    MyStruct temp;
    do {
        condizione = 0;
        for (int i = 0; i < n-1; i++)
            if ((s[i].num_occorrenze>s[i+1].num_occorrenze) || (s[i].num_occorrenze == s[i+1].num_occorrenze && s[i].indice_parola>s[i+1].indice_parola)){
                temp = s[i];
                s[i] = s[i+1];
                s[i+1] = temp;
                condizione = 1;
                p = i+1;
            }
        n = p;
    } while (condizione);
}

int dividiStr(char str[], MyStruct s[]) {
    int cont = 0;
    char *token;
    token = strtok(str, " ");
    while (token != NULL) {
        s[cont].indice_parola = cont;
        strcpy(s[cont++].parola, token);
        token = strtok(NULL, " ");
    }
    return cont;
}

int leggiStr(char *file, char *str) {
    FILE *fp =fopen(file, "r");
    if (fp == NULL) return -1;
    else {
        fgets(str, N, fp);
        fclose(fp);
        return 0;
    }
}

int salvaB(MyStruct s[], int n) {
    FILE *fp = fopen("output.bin", "wb");
    if (fp == NULL) return -1;
    else {
        fwrite(s, sizeof(MyStruct), n, fp);
        fclose(fp);
        return 0;
    }
}