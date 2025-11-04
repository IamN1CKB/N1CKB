#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
Il Selection Sort è un algoritmo di ordinamento che opera in place, in modo simile all'ordinamento per inserzione¹. L'algoritmo è
di tipo non adattivo, il che significa che il suo tempo di esecuzione non dipende dall'input ma dalla dimensione dell'array.

Ecco come funziona l'algoritmo:
1. L'algoritmo seleziona di volta in volta il numero minore nella sequenza di partenza e lo sposta nella sequenza ordinata.
2. Di fatto la sequenza viene suddivisa in due parti: la sotto-sequenza ordinata, che occupa le prime posizioni dell'array, e
    la sotto-sequenza da ordinare, che costituisce la parte restante dell'array.
3. Dovendo ordinare un array A di lunghezza n, si fa scorrere l'indice i da 1 a n-1 ripetendo i seguenti passi:
    - si cerca il più piccolo elemento della sotto-sequenza A [ i .. n ];
    - si scambia questo elemento con l'elemento i -esimo.
*/
void stampaVet(int *arr, int n);
void selectionSort(int *arr, int n);
void scambia(int *a, int *b);
int main () {
    //creiamo una array dinamico con valori random
    int *vet, n;
    printf("decidi il numero di elementi del vettore: ");
    scanf("%d", &n);
    vet = (int*) calloc(n, sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        vet[i] = rand()%100;
    stampaVet(vet, n);
    selectionSort(vet, n);
    stampaVet(vet, n);
}

void stampaVet(int *arr, int n) {
    printf("vet: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void scambia(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *arr, int n) {
    int iMin;  //indice del minimo
    for (int i = 0; i < n-1; i++) {
        iMin = i;
        for (int j = i+1; j < n; j++)  //dobbiamo trovare il minimo nel vettore da posizione i+1 a n-1
        //i+1 perché abbiamo inizializzato il minimo già all'indice i
            if (arr[iMin] > arr[j]) iMin = j;


        scambia(&arr[iMin], &arr[i]); //lo sostituiamo alla i-esima posizione
    }
}

//La complessità temporale del Selection Sort è O(n²) nel caso peggiore, nel caso migliore e nel caso medio. Questo significa che
//il tempo di esecuzione aumenta quadraticamente con la dimensione dell'input, rendendo l'algoritmo inefficiente per grandi quantità di dati..