#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //se usiamo la funzione rand ma non inizializziamo la funzione srand a nessun seme, allora è come se avessimo
    //inizializzato la funzione srand al seme 1
    printf("numero casuale generato con il seme = 1:   %d\n", rand());
    printf("la sequenza di valori iniziali è sempre la stessa: %d %d %d %d %d\n", rand(), rand(), rand(), rand(), rand());
    //i caratteri generati sono sempre gli stessi, ossia per il computer di N1CKB: 41 15724 19169 26500 6334 18467


    srand(time(NULL));
    printf("valore sempre diverso:   %d\n", rand());
    //nell'ultimo caso il seme è sempre diverso quindi la sequenza di numeri generata è sempre diversa

    //se vogliamo generare gli stessi numeri di prima dobbiamo inizializzare di nuovo srand, ma stavolta ad 1
    srand(1);
    printf("stessi numeri iniziali: %d %d %d %d\n", rand(), rand(), rand(), rand());
    //piccolo accorgimento: la funzione rand non mostra sempre nello stesso ordine i numeri anche se si ha lo stesso seme
}