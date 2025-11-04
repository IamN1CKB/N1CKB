#include <stdio.h>
struct studente {
    char nome[50];
    char cognome[50];
    float media_esami;
    int data_nascita[3];
};
typedef struct studente Studente;

void stampa_studente(Studente s);
int main(){
    //leggiamo il file elenco.bin che abbiamo creato nel programma precedente
    FILE *fp = fopen("file1/elenco.bin", "r");
    int l;
    Studente elenco_ricavato[50];
    if (fp == NULL) printf("ERR file");
    else {
        fread(&l, sizeof(int), 1, fp);
        fread(elenco_ricavato, sizeof(Studente), l, fp);
    }

    for (int i = 0; i < l; i++){
        printf("stampa studente %d\n", i+1);
        stampa_studente(elenco_ricavato[i]);
        printf("\n\n");
    }
    
}

void stampa_studente(Studente s) {
    printf("nome studente: %s\n", s.nome);
    printf("cognome studente: %s\n", s.cognome);
    printf("media studente: %f\n", s.media_esami);
    printf("data di nascita studente: ");
    for (int i = 0; i < 3; i++){
        printf("%d", s.data_nascita[i]);
        if (i!=2) printf("/");
    }
    printf("\n");
}