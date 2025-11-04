#include <stdio.h>
#include <string.h>
#define N_MAX 100
/*
Scrivere un programma che concateni a una stringa i primi cinque caratteri di una seconda stringa.
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
    
    strncat(str1, str2, 5);
    printf("str1 concatenata: %s", str1);
}