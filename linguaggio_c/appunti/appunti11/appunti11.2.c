#include <stdio.h>
#define N 100

int main() {
    //trattamento dei bit
    /*
    Per scrivere applicazioni che controllano dispositivi hardware è necessario disporre di operatori in grado di lavorare sui 
    singoli bit di un registro. Se per esempio si ha una centralina di controllo di un impianto di illuminazione, dove un 
    registro di 16 bit comanda lo stato di 16 lampade, mettere a 1 un bit del registro significa accendere una lampada se 
    questa è spenta, e metterlo a 0 significa spegnerla se questa è accesa. Il C fornisce un ricco insieme di operatori per il 
    trattamento dei bit:
    & AND bit a bit
    | OR bit a bit
    ^ OR esclusivo (XOR)
    << shift sinistra
    >> shift destra
    ~ complemento a 1 (NOT)
    Gli operatori per il trattamento dei bit sono gli stessi disponibili in tutti i linguaggi assembler, e rendono il C quello che alcuni hanno definito “il linguaggio di più alto 
    livello tra quelli a basso livello”.

    Analizziamo ora uno per uno gli operatori servendoci di esempi. Come premessa occorre precisare che questi 
    operatori non lavorano su variabili di tipo float o double, ma su variabili di tipo char e int. In effetti, pensando 
    agli elementi di memoria di un qualsiasi dispositivo hardware (una centralina, una scheda di rete, il controller di un 
    disco) i valori in virgola mobile non hanno alcun significato: i bit sono bit di comando e le uniche operazioni che 
    servono sono quelle di abilitazione/disabilitazione.

    Se ne deduce, allora, che le operazioni per il trattamento dei bit, con l’eccezione delle operazioni di shift e complemento, si 
    applicheranno tipicamente a variabili di tipo unsigned char e unsigned int, poiché il segno aritmetico non ha 
    significato.

    L’istruzione di AND bit a bit è usata per spegnere uno o più bit di una variabile. Infatti, nel confronto bit a bit 
    dell’operazione booleana AND basta avere uno dei due operandi a 0 per produrre 0.

        b1  b2  (b1&b2)
        0   0   0
        1   0   0
        0   1   0
        1   1   1
    se ad esempio abbiamo una variabile x che vale in binario 10101010, che sarebbe 170 in base decimale, se vogliamo spegnere gli ultimi 4 bit (meno significativi) possiamo metterlo in AND con il valore binario 11110000, che sarebbe 240 in decimale, e così otteniamo il valore binario 10100000, che sarebbe 160 in decimale
        x   = 170 = 10101010
        y   = 240 = 11110000
        x&y = 160 = 10100000

    */
    unsigned short int x = 170;  //unsigned short in modo da avere la rappresentazione in bit più facile possibile, ma potremmo anche scegliere unsigned char in modo da avere una rappresentazione in un solo byte
    unsigned short int y = 240;
    printf("dobbiamo vedere i numeri (unsigned short int) rappresentati su %d byte\n", sizeof(short int));
    printf("x & y = %u\n", x&y); 

    /*
    L’istruzione di OR bit a bit è usata per accendere uno o più bit di una variabile. Infatti, nel confronto bit a bit 
    dell’operazione booleana OR basta avere uno dei due operandi a 1 per produrre 1.
        b1  b2  b1|b2
        0   0   0
        1   0   1
        0   1   1
        1   1   1

    Se per esempio volessimo mettere a 1 i   quattro bit meno significativi di una     variabile unsigned char, e lasciare 
    inalterato la stato di quattro bit più significativi, basterebbe usare l’istruzione |
    esempio:
        x   = 170 = 10101010
        y   = 15  = 00001111
        x|y = 175 = 10101111
    */
    x= 170;
    y = 15;
    printf("x | y = %u\n", x|y);

    /*
    L’istruzione di OR esclusivo bit a bit è usata per commutare da 0 a 1 e viceversa un insieme di bit di una variabile. 
    Infatti, nel confronto bit a bit dell’operazione booleana OR esclusivo se i due bit sono uguali si produce 0, se sono 
    diversi si produce 1.
        b1  b2  b1^b2
        0   0   0
        1   0   1
        0   1   1
        1   1   0
    Se per esempio volessimo scambiare 0 con 1 e 1 con 0 nei primi quattro bit più significativi di una variabile unsigned 
    char, e lasciare inalterato lo stato dei quattro bit meno significativi, basterebbe usare l’istruzione con | 
    esempio:
        x   = 170 = 10101010
        y   = 240 = 11110000
        x|y = 90  = 01011010
    */
    x = 170;
    y = 240;
    printf("x ^ y = %u\n", x^y);
    /*
    Si osservi che effettuare l’OR esclusivo di una variabile con se stessa ha l’effetto di mettere a 0 la variabile. L’istruzione
        x = x ^ x;
    trasforma sempre x in:
        0 0 0 0 0 0 0 0
    Il lettore potrebbe obiettare che lo stesso risultato si sarebbe potuto ottenere con l’assegnazione:
        x = 0;
    */

    /*
    Se poi si vogliono scambiare tutti i bit di una variabile da 0 a 1 e viceversa, basta effettuare il complemento a 1 della variabile stessa (detto anche NOT):
    z = ~z;
        usiamo una variabile unsigned char in modo da avere un solo byte
        z  = 170 = 10101010
        ~z = 85  = 01010101

    */
    unsigned char z = 170;
    printf("dobbiamo vedere i numeri (unsigned char) rappresentati su %d byte\n", sizeof(unsigned char));
    printf("~z = %hhu\n", ~x);
    /*significato di hhu:
        hh: Indica che l'argomento successivo è un tipo di dato di dimensione di 1 byte (generalmente char).
        u: Indica che l'argomento è un numero senza segno.
    */


    /*
    Le operazioni di shift << e >> traslano il primo operando, rispettivamente a sinistra e a destra, di un numero di 
    posizioni corrispondenti al valore del secondo operando. L’effetto delle operazioni di shift cambia a seconda che le si 
    applichi a variabili senza segno o con segno; per quelle con segno il risultato può cambiare a seconda del tipo di 
    macchina. In generale valgono le seguenti regole:
        • se si esegue lo shift a destra di una variabile unsigned i bit vacanti a sinistra sono rimpiazzati con degli 0;
        • se si esegue lo shift a sinistra di una variabile unsigned, i bit vacanti a destra sono rimpiazzati con degli 0;
        • se si esegue lo shift a destra di una variabile con segno i bit vacanti a sinistra sono rimpiazzati con il bit del 
        segno su certe macchine (shift aritmetico) e con 0 su altre (shift logico);
        • se si esegue lo shift a sinistra di una variabile con segno, i bit vacanti a destra sono rimpiazzati con degli 0 e il 
        bit del segno rimane inalterato.

    siccome è complicato fare esercizi su variabili con il segno, studiamo solo quelle unsigned
    */
    //vedi lezione 01-12 da 30 minuti in poi  (anche qualche minuti più in avanti)
    



}
