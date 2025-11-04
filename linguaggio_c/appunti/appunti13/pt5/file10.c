#include <stdio.h>
#define N 1000  //N deve essere abbastanza grande da contenere un intera riga
void main() {
    //facciamo un programma che conta il numero di righe che stanno in un file
    int i = 0;   //variabile di conteggio
    char buf[N];
    FILE *fp = fopen("file da contare righe.txt", "r");
    if (fp == NULL) printf("errore file\n");
    else {
        while (fgets(buf, N, fp))   //sarebbe la forma contratta di fgets(buf, N, fp) != NULL
            //fgets riporta un puntatore a carattere che dovrebbe essere il puntatore a buf, se invece dà errore oppure
            //è finito il file, dà NULL: con NULL la condizione diventa falsa
            i++;
        printf("ci sono %d righe nel file\n", i);
        fclose(fp);
    }
}