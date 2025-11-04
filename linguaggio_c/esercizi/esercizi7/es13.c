/*
Scrivere una funzione che visualizzi la scritta:
 Premere un tasto per continuare
e interrompa quindi l’esecuzione del programma chiamante finché non viene premuto un tasto.
*/
#include <stdio.h>
void tasto();

void main() {
    printf("parte 1\n");
    tasto();
    printf("parte 2\n");
}

void tasto() {
    printf("clicca un tasto per continuare:\n");
    getchar();  
}