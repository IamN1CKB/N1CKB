#include <stdio.h>
/*
facciamo un programma che salvi le informazioni di uno studente chiedendolo all'utente e le salvi in un file binario
*/
struct studente {
    char nome[50];
    char cognome[50];
    float media_esami;
    int data_nascita[3];
};
typedef struct studente Studente;   //creiamo un alias più veloce

void inserisci_studente(Studente *s);
void inserisci_vari_studenti(Studente s[], int* l);
void inserisci_data(Studente *s);
void stampa_studente(Studente s);
void modifica_studente(Studente *s);
void salvaB(Studente elenco[], int l);

int main(){
    Studente elencoS[50];
    int l, x;
    char continua;
    inserisci_vari_studenti(elencoS, &l);
    for (int i = 0; i < l; i++){
        printf("\n\nstampa studente %d\n", i+1);
        stampa_studente(elencoS[i]);
    }

    printf("\n\nvuoi modificare uno studente (scrivi s per continuare, altro per non continuare)? ");
    scanf(" %c", &continua);
    while (continua=='s') {
        printf("quale studente vuoi modificare? (1 2 3...) ");
        scanf("%d", &x);
        x--; //abbiamo nominato gli studenti da 1 in poi, ma gli indici ci sono da 0 in poi
        if (x<l&&x>=0) modifica_studente(&elencoS[x]);
        else printf("studente inesistente\n");

        printf("\n\n");
        printf("vuoi continuare (scrivi s per continuare, altro per non continuare)? ");
        scanf(" %c", &continua);
    }
    
    for (int i = 0; i < l; i++){
        printf("\n\nstampa studente %d\n", i+1);
        stampa_studente(elencoS[i]);
    }
    salvaB(elencoS, l);  //il file salvato lo leggiamo poi da un altro programma nella stessa directory

    
}

void inserisci_vari_studenti(Studente s[], int* l) {
    printf("quanti studenti vuoi inserire?: ");
    scanf("%d", l);
    printf("\n");
    for (int i = 0; i < *l; i++) {
        printf("dati studente %d\n", i+1);
        inserisci_studente(&s[i]);
        printf("\n");
    }
}

void inserisci_studente(Studente *s) {
    printf("inserisci nome: ");
    scanf("%s", s->nome);
    printf("inserisci cognome: ");
    scanf("%s", s->cognome);
    printf("inserisci media esami: ");
    scanf("%f", &s->media_esami);   //vanno bene le 2 scritture per ricavare l'indirizzo di un campo di una struct dato da un puntatore:
                                    // &(s->media_esami)    &s->media_esami
    inserisci_data(s);
}

void inserisci_data(Studente *s) {
    printf("inserisci giorno di nascita: ");
    scanf("%d", &(s->data_nascita[0]));
    printf("inserisci mese di nascita: ");
    scanf("%d", &(s->data_nascita[1]));
    printf("inserisci anno di nascita: ");
    scanf("%d", &(s->data_nascita[2]));
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

void modifica_studente(Studente *s) {
    int scelta;
    enum scelte {nome=1, cognome, media_esami, data_nascita};
    printf("cosa vuoi cambiare allo studente %s %s?\n", s->nome, s->cognome);
    printf("1 per nome\n2 per cognome\n3 per media esami\n4 per data di nascita\n");
    printf("inserisci un numero: ");
    scanf("%d", &scelta);
    switch (scelta) {
    case nome:
        printf("inserisci nuovo nome: ");
        scanf("%s", s->nome);
        break;
    case cognome:
        printf("inserisci nuovo cognome: ");
        scanf("%s", s->cognome);
        break;
    case media_esami:
        printf("inserisci nuova media: ");
        scanf("%s", &s->media_esami);
        break;
    case data_nascita:
        printf("inserisci nuova data di nascita:\n");
        inserisci_data(s);
        break;
    default:
        printf("Errore input\n");
        break;
    }
}

void salvaB(Studente elenco[], int l) {
    FILE *fp = fopen("file1/elenco.bin", "w");
    if (fp == NULL) printf("ERR file\n");
    else {
        //salviamo prima la dimensione dell'elenco di struct
        fwrite(&l,sizeof(int), 1, fp);
        //poi salviamo tutto l'array di struct
        fwrite(elenco ,sizeof(Studente), l, fp);
        fclose(fp);
    }
    
}