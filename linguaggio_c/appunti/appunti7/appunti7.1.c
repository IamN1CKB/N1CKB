#include <stdio.h>

int x=3; 
//questa è detta funzione globale siccome è definita fuori da una funzione (come funzione intendiamo anche il main), e ha visibilità dalla sua definizione fino alla fine del file

int g(int, char);
int main() {
    printf("variabile globale x = %d\n", x);
    int y = 4;
    //la visibilità della variabile y si estende dal punto di definizione sino alla fine del blocco di appartenenza.
    printf("variabile locale y = %d\n", y);
    char z = 'A';
    g(y, z);
    
}
int g(int a, char z) {
    /*
    Anche i parametri formali di una funzione hanno un campo di visibilità che si estende dall’inizio alla fine del blocco 
    istruzioni della funzione; sono quindi considerati a tutti gli effetti variabili locali alla funzione.

    Le variabili y e z sono locali alla funzione g e hanno una visibilità che si estende dalla parentesi graffa aperta { alla 
    corrispondente parentesi graffa chiusa }. Quindi la definizione di y e z precede all’interno del blocco la definizione 
    delle altre variabili locali k e l aventi anch’esse una visibilità che va dal punto di definizione alla fine del blocco . Per 
    questo motivo la funzione:
    f(int x) {
        int x;
    }
    sarebbe sbagliata perché cerca di dichiarare 2 volte la stessa variabile nello stesso blocco
    */

    int k;
    int l;
}