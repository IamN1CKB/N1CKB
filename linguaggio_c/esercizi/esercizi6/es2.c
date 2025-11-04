#include <stdio.h>
#define N_MAX 100
/*
Scrivere un programma che confronti due stringhe, limitatamente ai primi cinque caratteri, e successivamente 
visualizzi il risultato del confronto. Il programma non deve utilizzare la libreria string.h
*/
int main() {
    char str1[N_MAX], str2[N_MAX];
    int i;
    //inizializzazione
    printf("inserisci str1 (< di %d caratteri): ", N_MAX);
    for (i = 0; ((str1[i] = getchar()) != '\n') && (i<N_MAX); i++);
    str1[i] = '\0';
    printf("inserisci str2 (< di %d caratteri): ", N_MAX);
    for (i = 0; ((str2[i] = getchar()) != '\n') && (i<N_MAX); i++);
    str2[i] = '\0';

    //confronto
    for (i = 0; (str1[i]==str2[i]) && (i<5) && (str1[i] != '\0') && (str2[i] != '\0'); i++);
    if (str1[i] == str2[i]) printf("i primi 5 caratteri delle stringhe sono identiche");
    else
        if (str1[i]>str2[i]) printf("la str1 viene dopo la str2");
        else printf("la str1 viene prima la str2");
        
    
    

}