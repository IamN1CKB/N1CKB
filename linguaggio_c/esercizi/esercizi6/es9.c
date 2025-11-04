#include <stdio.h>
#define N 100
/*
Scrivere un programma che richieda all’utente un carattere e una stringa e calcoli quindi il numero di occorrenze del carattere nella stringa.
*/
int main() {
    char str[N], a;
    printf("inserisci stringa: ");
    fgets(str, N, stdin);
    //dobbiamo settare l'ultimo carattere da \n a \0
    int i;
    while (str[i] != '\n') i++;
    str[i] = '\0';
    
    printf("inserisci carattere da cercare nella stringa: ");
    a = getchar();
    int cont = 0;
    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == a) cont++;

    if (cont) printf("ci sono state %d occorrenze di '%c' in '%s'", cont, a, str);
    else printf("non ci sono state occorrenze di '%c' in '%s'", a, str);
    
}