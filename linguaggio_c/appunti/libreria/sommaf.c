//qui includiamo i prototipi dal file definizioni.h
#include "sommaf.h"    //usiamo i doppi apici per incldere file fatti da te e non dal compilatore" "
//mettiamo solo il corpo delle funzioni

int somma(int a, int b) {
    return a+b;
}
//dopodiché dobbiamo compilare questo file con il comando da terminale 
//gcc -c vettori.c
//e con questo verrà creato un file .o

/*dunque in sintesi abbiamo:
    il file ide solo con i prototipi (sommaf.h)
    il file sorgente con il codice dei sottoprogrammi (sommaf.c)
    il file compilato (stavolta non .exe, ma .o) che è la traduzione del file .c
*/
//abbiamo fatto questa libreria e possiamo usarla e darla agli altri in modo da poterla usare.
/*possiamo fare in 2 modi:
    diamo il file .h e .o ma non il file sorgente: non vogliamo farvi vedere come è il nostro codice perché siamo gelosi

    diamo il file .h e .c, così prima da compilare e poi da usare (possono vedere il tuo codice)
*/

//ATTENZIONE: il file .o è stato compilato su un compilatore windows e funziona solo su windows. se si vuole il file per linux o mac si deve compilare il file sorgente in quell'ambiente