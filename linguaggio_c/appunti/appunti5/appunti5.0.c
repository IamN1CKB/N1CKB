#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_ELE 1000
int main(){
    /*esistono 2 tipi di ricerca di un elemento in C: la ricerca completa e la ricerca binaria
    La ricerca completa e la ricerca binaria sono due approcci diversi per trovare un elemento all'interno di una struttura dati (come un array) in base a un valore di ricerca. Le differenze principali tra le due riguardano l'efficienza e la strategia di ricerca.

    Ricerca completa (o sequenziale):
        Metodo: La ricerca completa procede sequenzialmente attraverso tutti gli elementi della struttura dati, partendo dall'inizio e procedendo fino alla fine.
        Efficienza: È un metodo semplice, ma può diventare inefficiente su grandi quantità di dati, specialmente se l'elemento desiderato si trova verso la fine o non è presente.
        Complessità temporale: La complessità temporale è lineare e dipende dalla lunghezza della struttura dati. Se la lunghezza dell'array è "n", la ricerca completa richiede in media n/2 operazioni per trovare un elemento o determinare che non è presente.

    Ricerca binaria:
        Metodo: La ricerca binaria opera su un insieme ordinato di dati e divide ricorsivamente l'intervallo di ricerca a metà, escludendo metà degli dati ad ogni passaggio, fino a trovare l'elemento desiderato o concludere che non è presente.
        Efficienza: È un metodo efficiente in quanto riduce il numero di confronti richiesti. È particolarmente utile su grandi insiemi di dati ordinati.
        Complessità temporale: La complessità temporale è logaritmica. Se la lunghezza dell'array è "n", la ricerca binaria richiede log2(n) passaggi per trovare l'elemento desiderato. Questo significa che in un array di 1024 elementi, la ricerca binaria impiega al massimo 10 passaggi per trovare un elemento.
    */
    //facciamo un programma di ricerca completo di un elemento in un vettore
    int vet[MAX_ELE], l, n, i;
    //immissione lunghezza del vettore
    do {
        printf("inserisci la lunghezza l del vettore (l>=1): ");
        scanf("%d", &l);
        if (l<1) printf("l errato\n");
    } while (l<1);
    
    //generiamo valori casuali da 0 a 100 e nel mentre li stampiamo
    printf("vet[%d]: ", l);
    srand(time(NULL));
    for (i = 0; i < l; i++) {
        vet[i] = rand()%101;
        printf("%d\t", vet[i]);
    }
    

    //elemento da trovare n
    printf("\nscegli un elemento n da trovare: ");
    scanf("%d", &n);
    for (i = 0; i < l && vet[i] != n; i++);
    if (i==l) printf("elemento n non trovato\n");
    else printf("elemento n trovato => v[%d]\n", i);
    
    //vedi appunti 5.2 per ricerca binaria
    
}