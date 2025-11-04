#include <stdio.h>
/*
Utilizzando l’espressione condizionale ?: scrivere un programma che, dati tre valori interi memorizzati nelle
variabili a, b e c, assegna a d:
• il volume del parallelepipedo di lati a, b e c se il valore di a al quadrato sommato a b è diverso da c;
• la somma di a, b e c, altrimenti.
*/
int main(void) {
    int a, b, c, d;
    printf("scegli in seguito i valori di 'a' 'b' e 'c':\n");
    scanf("%d %d %d", &a, &b, &c);
    if (a*a +b != c) {
        d = a*b*c;
    }
    else {    //ad esempio a=5; b=3; c=5*5+3=28
        d = a+b+c;
    }
    printf("d = %d", d);
     
}