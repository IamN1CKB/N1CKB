#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

int strLen(char str[]);
void leggiVet(int vet[], int l);
void ordinamento(int vet[], int l);
void stampaVet(int vet[], int l);
void main() {
    //per poter scrivere in un file, dobbiamo usare funzioni diverse a seconda che il file sia di testo o binario
    //adesso vediamo come scrivere e come leggere in un file binario
    char str[N] = "cose da inserire nel vettore";   //vettore di partenza
    FILE *fp;
    int n;
    fp = fopen("nome_file.bin", "w");
    if (fp!=NULL) {
        //per scrivere su un file binario dobbiamo usare la funzione fwrite
        n = fwrite(&str[0], sizeof(char), strLen(str), fp);    //scrivere &str[0] = str 
        printf("il numero di elementi salvati e' %d\n", n);
        fclose(fp);
    }
    else printf("errore con l'apertura del file\n");
    //dato che è un file che contiene una stringa, può essere letta come un file di testo, ma la stessa cosa non vale per gli interi o per altre variabili


    //facciamo un esempio inserendo nel file un array di interi
    int vet[N], l;
    //generiamo vettore casualmente e ordiniamolo
    printf("inserisci grandezza vet: ");
    scanf("%d", &l);
    leggiVet(vet, l);
    stampaVet(vet, l);  //stampiamo il vettore non ordinato
    ordinamento(vet, l);  //lo ordiniamo e poi lo salviamo nel file
    fp = fopen("file_vet.bin", "w");
    if (fp == NULL) printf("errore file_vet.bin\n");
    else {
        n = fwrite(vet, sizeof(int), l, fp);
        if (n == l) printf("vettore caricato con successo nel file\n");
        else printf("vettore non caricato con successo\n");
        fclose(fp);
    }
    
    //non riusciamo a leggere il file come un file di testo, perché quando leggiamo un file binario come file di testo tutta la sequenza di byte viene considerata come caratteri, anche se sono interi, e per questo riporta valori errati
    //per poter vedere l'interno del file dobbiamo leggere il file tramite fread
    fp = fopen("file_vet.bin", "r");  //apriamo stavolta in lettura
    if (fp == NULL) printf("errore file_vet.bin\n");
    else {
        n = fread(vet, sizeof(int), l, fp);
        if (n == l) printf("vettore letto con successo nel file\n");
        else printf("vettore non letto con successo\n");
        fclose(fp);
    }


    stampaVet(vet,l);  //stampiamo il vettore ordinato che abbiamo ricevuto nel file


    
}


int strLen(char str[]) {
    int i;
    for (i = 0; str[i]; i++);
    return i+1;  //vogliamo considerare come lunghezza anche \0
}

void leggiVet(int vet[], int l) {
    //genera un vettore ordinato
    srand(time(NULL));
    for (int i = 0; i < l; i++)
        vet[i] = rand()%100;
}
void ordinamento(int vet[], int l) {
    //ordiniamo pure
    int condizione, temp, p;
    do {
        condizione = 0;
        for (int i = 0; i < l; i++) {
            if (vet[i]>vet[i+1]) {
                temp = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = temp;
                condizione = 1;
                p =i +1;
            }
        }
        l = p;
    } while (condizione);
}

void stampaVet(int vet[], int l) {
    printf("vet: ");
    for (int i = 0; i < l; i++)
        printf("%d ", vet[i]);
    printf("\n");
}