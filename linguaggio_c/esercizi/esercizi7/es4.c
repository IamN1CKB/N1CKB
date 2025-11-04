#include <stdio.h>
/*
Scrivere una funzione che calcoli il numero di caratteri e cifre presenti in una stringa passata come variabile globale
*/
#define N 100
char str[N];

int conta_caratteri();

void main() {
    printf("inserisci stringa: ");
    fgets(str, N, stdin);
    printf("in '%s' ci sono %d caratteri", str, conta_caratteri());
}

int conta_caratteri() {
    int i;
    for (i = 0; str[i]!='\n'; i++);
    str[i] = '\0';
    return i;
}
