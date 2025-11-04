#include <stdio.h>
//nel caso del passaggio dei parametri in una funzione, ci può essere sia cast esplicito, sia implicito

float sommaFloat(float, float);

int main() {
    int a = 5;
    int b = 4;
    int c = sommaFloat(a,b);
    //nonostante la funzione richieda dei float, viene effettuato il cast implicito sui parametri effettivi della funzione
    //inoltre il valore di ritorno è un float, ma viene effettuato nuovamente il cast implicito per salvare il valore nella
    //variabile c
    printf("c = %d\n", c);
}


float sommaFloat(float x, float y) {
    return x+y;
}