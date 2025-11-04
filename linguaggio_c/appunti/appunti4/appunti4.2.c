#include <stdio.h>
#define N 100
int main() {
    //inoltre possiamo inizializzare tutti gli elementi di un array (con anche più dimensioni) a 0, e a 0 solo, durante la dichiarazione
    //dobbiamo usare questa sintassi:
    int array0[N] = {0};  //tutti gli elementi hanno valore 0
    //funziona solo con il valore 0, e si può fare solo durante la dichiarazione
    //per fare la stessa cosa con altri valori e in un momento successivo alla dichiarazione, possiamo usare memset, che vedremo molto in futuro
    
    //settare tutto a 0 è possibile farlo anche con gli altri tipi di array, come double, float e anche char
    char array_c[N] = {0};  //la codifica 0 nei char corrisponde allo \0 che sarebbe un carattere speciale, e settare tutti i caratteri di
    //array di caratteri a questo valore ha poco senso, e vedrai tra poco il motivo.
}