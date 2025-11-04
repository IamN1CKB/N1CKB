#include <stdio.h>
#define N 100
/*
scrittura di una stringa in un file
*/
int leggiStrLen(char str[]);
void main(){
    char buf[N];
    FILE *fp;
    int len;
    //scriviamo la stringa da console
    printf("inserisci cio' da inserire nel file (_ e invio per concludere): \n");
    len = leggiStrLen(buf);


    fp = fopen("file in cui scrivere", "w");
    if (fp == NULL) printf("il file \"file in cui scrivere\" non e' stato aperto correttamente\n");
    else {
        fwrite(buf, sizeof(char), len, fp);
        fclose(fp);
    }
    /*se inseriamo anche lo \0 nel file, gli editor di testo non riescono a rappresentarlo, ma in un file binario andrebbe messo*/
}

int leggiStrLen(char str[]) {
    int i;
    for (i = 0; ((str[i]=getchar())!='_') && (i<N); i++);
    str[i] = '\0';  //non includiamo il valore \0 nella lunghezza
    return i;
}