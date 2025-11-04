#include <stdio.h>
#define N_MAX 100
/*
Scrivere un programma che, senza utilizzare la libreria string.h, concateni a una stringa i primi cinque caratteri di 
una seconda stringa.
*/
int main() {
    char str1[N_MAX], str2[N_MAX];
    int i, j = 0, l;
    //inizializzazione stringhe
    printf("inserisci str1 (< di %d caratteri): ", N_MAX);
    for (i = 0; ((str1[i] = getchar()) != '\n') && (i<N_MAX); i++);
    str1[i] = '\0';
    printf("str1: %s\n", str1);
    printf("inserisci str2 (< di %d caratteri): ", N_MAX);
    l = i; //salviamo la lunghezza di str1
    for (i = 0; ((str2[i] = getchar()) != '\n') && (i<N_MAX); i++);
    str2[i] = '\0';
    printf("str2: %s\n", str2);

    //concateniamo i primi 5 caratteri di str2 a str1
    //es: str1 = ciao     str2 = , mi chiamo nick
    //str1 (dopo la concatenazione) = ciao, mi 
    for (i = 0; ((str1[l] = str2[i]) != '\0') && (i<5); i++, l++);
    str1[l] = '\0';
    printf("str1 concatenati: %s", str1);
    

    
}