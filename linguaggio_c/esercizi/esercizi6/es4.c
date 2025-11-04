#include <stdio.h>
#include <string.h>
#define N_MAX 100
/*
Scrivere un programma che confronti due stringhe, limitatamente ai primi cinque caratteri, e successivamente 
visualizzi il risultato del confronto.
*/
int main() {
    char str1[N_MAX], str2[N_MAX];
    int i;
    printf("str1: ");
    for (i = 0; ((str1[i] = getchar()) != '\n') && (i<N_MAX); i++);
    str1[i] = '\0';
    printf("str2: ");
    for (i = 0; ((str2[i] = getchar()) != '\n') && (i<N_MAX); i++);
    str2[i] = '\0';
    
    i = strncmp(str1, str2, 5);
    if (i ==0) printf("i primi 5 caratteri delle 2 stringhe sono uguali");
    else
        if (i>0) printf("str1 va dopo str2");
        else printf("str1 va prima str2");
    
}