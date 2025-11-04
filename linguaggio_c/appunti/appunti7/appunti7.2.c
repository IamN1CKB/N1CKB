#include <stdio.h>
/*
A ogni funzione C è associato un tipo, scelto tra quelli fondamentali o derivati, che caratterizza un valore. Questo valore 
è detto valore di ritorno della funzione ed è restituito dalla funzione al programma chiamante per mezzo dell’istruzione 
return. La sintassi da usare è:
    return (espressione);
oppure:
    return espressione;

Nel caso in cui non sia esplicitamente definito un tipo di ritorno il linguaggio C assume che esso sia il tipo 
fondamentale int.
*/
double area(float, float, char);

int  main() {
    float b, h;
    double a;
    char pol;
    printf("Inserire poligono (Triangolo/Rettangolo): ");
    scanf("%c", &pol);
    printf("Inserire base: ");
    scanf("%f", &b);
    printf("Inserire altezza: ");
    scanf("%f", &h);
    a = area( b, h, pol);
    
    printf("Il poligono (b = %f, h = %f) ha area %f\n", b, h, a);
}

double area(float base, float altezza, char poligono) {
    switch (poligono) {
        case 'T': return (base * altezza/2.0);
        case 'R': return (base * altezza);
        default : return -1;
    }
}
/*
Non sono invece corrette le invocazioni:
a = area('T', b, h);
a = area( b, h);
a = area( b, h, 'T', x);
a = area( b, h, x);
dove x è una variabile int; il passaggio di parametri è errato o per ordine o per numero o per discordanza di tipo.
*/