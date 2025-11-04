#include <stdio.h>
#include <string.h>
#define N 100
/*
Scrivere un programma che richiesta all’utente una stringa controlli se vi compaiono almeno tre caratteri uguali consecutivi
*/
int main() {
    char str[N];
    printf("inserisci la stringa di almeno 3 caratteri: ");
    fgets(str, N, stdin);
    if (strlen(str)>3) { //3 sarebbe una stringa da 2 caratteri con in più \0
        int i, cond = 0;
        for (i = 0; str[i+2] != '\0'; i++)
            if (str[i] == str[i+1] && str[i+1] == str[i+2]) {
                cond = 1;
                break;
            }
        if (cond) printf("ci sono 3 lettere consecutive uguali (%c)", str[i]);
        else printf("Buon Natale");
    }
    else printf("str troppo corta");
    
    
    
}