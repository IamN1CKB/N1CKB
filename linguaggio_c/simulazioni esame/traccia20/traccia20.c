//settima "traccia esame" su parsec
#include <stdio.h>
#include <string.h>
#define N 100
struct myStruct {
    int n_val_sinistra;
    int n_val_destra;
    int somma;
};
typedef struct myStruct MyStruct;

void checkRiga(char buf[], MyStruct s[], int *n);
void ordina(MyStruct s[], int n);
int salvaB(char* file, MyStruct s[], int n);
int main(){
    char input[] = "input.txt";
    MyStruct vetStr[N];
    memset(vetStr, 0, sizeof(MyStruct)*N);
    char buf[N];
    int n_giuste = 0;
    FILE *fp = fopen(input, "r");
    if (fp == NULL) {
        perror("ERR file input");
        return 0;
    }
    while (fgets(buf, N, fp) != NULL)
        checkRiga(buf, vetStr, &n_giuste);
    fclose(fp);

    ordina(vetStr, n_giuste);

    if (salvaB("output.bin", vetStr, n_giuste)==-1)
        perror("ERR output");
}

void checkRiga(char buf[], MyStruct s[], int *n) {
    int espr = 1;   //indica se ti trovi al primo membro (1) o al secondo (2)
    int somma1 = 0, somma2 = 0;   //somma dei valori al primo e secondo membro
    int numero = 0;
    s[*n].n_val_destra = s[*n].n_val_sinistra = 0;
    for (int i = 0; buf[i] != '\n'; i++) {
        if (espr == 1) {
            if (buf[i]>='0'&&buf[i]<='9')
                numero = numero*10 + buf[i] - '0';
            else {  //diverso da un numero
                (s[*n].n_val_sinistra)++;
                somma1 += numero;
                numero = 0;
                if (buf[i] == '=')
                    espr = 2;
            }
        }
        else { //se stiamo al secondo membro (espr = 2)
            if (buf[i]>='0'&&buf[i]<='9')
                numero = numero*10 + buf[i] - '0';
            else {  //diverso da un numero
                (s[*n].n_val_destra)++;
                somma2 += numero;
                numero = 0;
            }
        }
    }
    if (somma1 == somma2) {
        s[*n].somma = somma1;
        (*n)++;
    }
}

void ordina(MyStruct s[], int n) {
    int condizione, p;
    MyStruct temp;
    do {
        condizione = 0;
        for (int i = 0; i < n-1; i++)
            if (s[i].somma<s[i+1].somma) {
                temp = s[i];
                s[i] = s[i+1];
                s[i+1] = temp;
                condizione = 1;
                p = i+1;
            }
        n = p;
    } while (condizione);
}

int salvaB(char* file, MyStruct s[], int n) {
    FILE *fp = fopen(file, "w");
    if (fp == NULL) return -1;
    else {
        fwrite(s, sizeof(MyStruct), n, fp);
        fclose(fp);
        return 0;
    }
}