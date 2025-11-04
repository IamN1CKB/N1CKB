#include <stdio.h>
/*
Scrivere un programma che, richiesto il numero AA rappresentante un anno, verifichi se questo è bisestile.
[Suggerimento: un anno è bisestile se è divisibile per 4 ma non per 100 (cioè si escludono gli anni-secolo).]
*/
int main() {
    int AA;
    printf("Inserisci il numero di un anno: ");
    scanf("%d", &AA);
    if (AA % 4 == 0 && AA % 100 != 0) {
        puts("Anno bisestile");
    }
    else {
        puts("Anno non bisestile");
    }
}