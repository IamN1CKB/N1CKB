#include <stdio.h>
#include <math.h>
#define COSTANTE 10
//possiamo definire costanti che non allocano spazio in memoria. Infatti tramite questa istruzione diciamo al compilatore (in realtà il precompilatore) di sostituire tutte le ricorrenza di COSTANTE all'interno del programma con il valore che abbiamo scelto, in questo caso 10
int main(){
    // in ogni programma che deve funzionare c'è una funzione che deve chiamarsi per forza main, ossia principale, che è il punto di inizio del nostro programma.
    // il compilatore capirà che questo è l'inizio

    
    //capiamo come si riserva spazio in memoria per le variabili di tipo int(ere)
    /*Il nome di una variabile la identifica, il suo tipo ne definisce la dimensione e l’insieme delle operazioni che si possono effettuare su di essa. La dimensione può variare rispetto all’implementazione; alcune versioni del C riservano agli int uno spazio di quattro byte. Con i 4 byte (in tutto 32 bit) possiamo lavorare con un numero di valori pari a 2^32. Per rappresentare i numeri negativi vediamo il bit più significativo (il bit più a sinistra)
        Se il bit più significativo è 0, il numero è positivo e viene interpretato come un numero intero positivo regolare.
        Se il bit più significativo è 1, il numero è negativo, e per ottenere il suo valore assoluto (valore positivo), devi eseguire il complemento a uno di tutti i bit e quindi aggiungere 1 al risultato.
    Esempio:
        Rappresenta 5 in binario (senza segno): 0000 0000 0000 0000 0000 0000 0000 0101
        Inverti tutti i bit per ottenere il complemento a uno: 1111 1111 1111 1111 1111 1111 1111 1010
        Aggiungi 1 al complemento a uno: 1111 1111 1111 1111 1111 1111 1111 1011

    Tutto ciò permette di poter lavorare su interi che vanno da –2147483648 a +2147483647; altre versioni riservano due byte (gli interi permessi vanno da –32768 a +32767) . Tra le operazioni fra int consentite vi sono: somma, sottrazione, prodotto e divisione, che corrispondono rispettivamente agli operatori +,-,*,/.
    */
    int a = 5;
    //per stampare una variabile nella console possiamo usare printf, che accetta 2 argomenti: la stringa e le variabili che sono collegate ai segnaposti %d
    printf("%d\n", a); // %d è il segnaposto per le variabili di tipo int
    //a differenza di puts, printf non manda a capo automaticamente ma bisogna specificare \n che manda a capo
    /*Esistono altre sequenze di caratteri con funzioni speciali, dette sequenze di escape. Riassumiamo quelle più usate, invitando il lettore a provarle nelle printf.
        \n va a linea nuova
        \t salta di una tabulazione
        \b ritorna un carattere indietro (backspace), ma non cancella il carattere (sarà riscritto dalle prossime stampe)
        \a suona il campanello della macchina (studia meglio perché non va)
        \\ stampa il carattere \ 
        \" stampa il carattere "
    */

    int valore_da_cambiare = 1234;
    int valore_cambiato = 9;
    //cancelliamo l'ultima cifra della prima variabile e inseriamo la seconda variabile
    printf("%d\b%d\n", valore_da_cambiare, valore_cambiato);



    /*per ricevere informazioni dal terminale dobbiamo usare funzioni di input come scanf, in cui ci sono 2 argomenti:
        un segnaposto per una variabile messo tra virgolette
        l'indirizzo della variabile a cui vogliamo assegnare il valore di input*/
    printf("Inserisci un valore: ");
    scanf("%d", &a);
    //l'indirizzo di una variabile si riceve con &variabile (si dice "e commerciale"), vedi puntatori per capire meglio
    printf("Il valore inserito = %d\n", a);

    //il segnaposto %5d indica che verrà riservato un campo di cinque caratteri per la visualizzazione del corrispondente valore, che sarà sistemato a cominciare dall’estrema destra di ogni campo:
    a = 12345;
    int b, c, d;
    b = 1234;
    c = 123;
    d = 12;
    printf("%5d %5d %5d %5d\n", a, b, c, d);
    //Inserendo poi un carattere - dopo il simbolo di percentuale e prima della lunghezza del campo il valore viene sistemato a cominciare dall’estrema sinistra della maschera.
    printf("%-5d% -5d% -5d% -5d\n", a, b, c, d);


    //vediamo cosa sono le funzioni, ossia un insieme di istruzioni che vengono eseguite quando si richiama la funzione.
    // un esempio può essere la funzione abs che sta per absolute, ossia una funzione che restituisce il valore assoluto di un intero
    //il codice di questa funzione si trova nella libreria math.h o stdlib.h, quindi non dobbiamo dimenticarci di includerla
    printf("%d", abs(-5));
    /*Dal punto di vista del programmatore, quello che interessa per ottenere un certo risultato è sapere:
        1. che esiste la funzione corrispondente;
        2. di quali informazioni essa ha bisogno;
        3. in quale librerie è contenuta.
    Le funzioni standard sono catalogate rispetto all’applicazione cui sono dedicate; per esempio:
        stdio.h funzioni di input/output
        math.h funzioni matematiche
        string.h funzioni che operano su stringhe*/
    
    //vai alla prossima lezione (appunti2.c)
}