#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
L'Insertion Sort è un algoritmo di ordinamento semplice che funziona in modo simile a come le persone ordinano le carte in mano
durante un gioco di poker. Ecco come funziona:
    1. Si parte dal secondo elemento dell'array (indice 1). Questo elemento viene considerato come una nuova "carta in mano", e
        viene confrontato con gli elementi (o "carte") a sinistra.
    2. Se l'elemento a sinistra è maggiore dell'elemento considerato, si sposta l'elemento a sinistra di una posizione verso destra.
    3. Si continua a spostare gli elementi finché non si trova un elemento a sinistra che è minore dell'elemento considerato,
        o finché non si raggiunge l'inizio dell'array. A questo punto, si può inserire l'elemento considerato.
    4. Si ripete il processo per ogni elemento nell'array.

Ecco un esempio passo-passo dell'Insertion Sort su un array di 5 elementi `{12, 11, 13, 5, 6}`:
    1. `{12, 11, 13, 5, 6}` - Inizia dal secondo elemento "11". È minore di "12", quindi scambia i due.
    2. `{11, 12, 13, 5, 6}` - Passa al prossimo elemento "13". È maggiore di "12", quindi non fa nulla.
    3. `{11, 12, 13, 5, 6}` - Passa al prossimo elemento "5". È minore di tutti gli elementi a sinistra, quindi sposta "5" all'inizio dell'array.
    4. `{5, 11, 12, 13, 6}` - Passa all'ultimo elemento "6". È maggiore di "5" ma minore degli altri, quindi sposta "6" alla seconda posizione.
    5. `{5, 6, 11, 12, 13}` - Ora l'array è ordinato.

La complessità temporale dell'Insertion Sort è O(n²) nel caso peggiore, ma è più efficiente quando l'array è quasi ordinato, rendendolo utile per gli array di piccole dimensioni o quasi ordinati. Tuttavia, per gli array di grandi dimensioni o molto disordinati, ci sono algoritmi di ordinamento più efficienti disponibili, come Quicksort o Mergesort.
*/

void creaVet(int *arr, int n);
void stampaVet(int *arr, int n);
void insert_in_order(int *arr, int n, int x);
void insertionSort(int *arr, int n);
void insertionSortSmall(int *arr, int n);
int main () {
    //creiamo una array dinamico con valori random
    int *vet, n;
    printf("decidi il numero di elementi del vettore: ");
    scanf("%d", &n);
    vet = (int*) calloc(n, sizeof(int));
    creaVet(vet, n);
    stampaVet(vet, n);
    insertionSort(vet, n);

    //riproviamo con la versione più compatta
    creaVet(vet, n);
    stampaVet(vet, n);
    insertionSortSmall(vet, n);
    stampaVet(vet, n);

}

void creaVet(int *arr, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand()%100;
}

void stampaVet(int *arr, int n) {
    printf("vet:\t");
    for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

//creiamo prima un sottoprogramma che inserisce un elemento in modo ordinato in un array, poi lo usiamo per ogni elemento dell'array
void insert_in_order(int *arr, int n, int x) {
    int pos;
    /*Cerca la posizione di inserimento*/
    for (pos=n; (pos>0)&&(arr[pos-1]>x); pos--);
    /*Sposta in avanti gli elementi successivi*/
    for (int i=n-1; i>=pos; i--)
        arr[i+1] = arr[i];
    arr[pos] = x;
    //stampiamo per vedere le modifiche
    printf("%d)", n);
    stampaVet(arr, n+1);
}

void insertionSort(int *arr, int n) {
    for (int i = 0; i < n; i++)
        insert_in_order(arr, i, arr[i]);
}

//creiamo una versione più compatta, con un solo sottoprogramma per l'ordinamento, e un solo for che sposta gli elementi e trova il posto giusto
void insertionSortSmall(int *arr, int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];

        // Sposta gli elementi di arr[0..i-1], che sono maggiori di key, alla posizione successiva di dove erano.
        for (j = i-1; j>=0 && arr[j]>key; j--)
            arr[j+1] = arr[j];
        arr[j+1] = key;
    }
}