#include <stdio.h>
/*
Scrivere un programma che, richiesti in input tre numeri interi, a seconda dei casi visualizzi una delle seguenti
risposte:
*/
int main() {
    int a, b, c;
    printf("Inserisci 3 numeri separati da uno spazio: ");
    scanf("%d %d %d", &a, &b, &c);
    if (a == b || b == c || c == a)
    { //almeno 2 sono uguali
        if ((a==b && b==c))    
            puts("Tutti uguali");
        else
            puts("Due uguali e uno diverso");
    }
    else
        puts("Tutti diversi");
}