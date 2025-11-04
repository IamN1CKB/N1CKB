#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

//facciamo un esempio di sottoprogrammi con array
int inizializzazione(int array[]);  //array[] è un puntatore di default
void stampa(int array[], int l);
//è indifferente se al sottoprogramma passi 'int array[]' o 'int array[N]'
//In realtà, quando dichiari un parametro come arr[], il compilatore lo tratta internamente come un puntatore.
//l'importante che alla chiamata della funzione passi il puntatore al primo elemento, ossia solo 'array'

void main(){
    int array[N];
    int l = inizializzazione(array);   //dobbiamo dare il puntatore al primo elemento (ossia solo il nome dell'array)
    stampa(array, l);

}


int inizializzazione(int array[]) {
    int l;
    printf("scegli lunghezza array (<%d): ", N);
    scanf("%d", &l);
    srand(time(NULL));
    for (int i = 0; i < l; i++) array[i] = rand()%100;
    return l; //ritorniamo la lunghezza
}

void stampa(int array[], int l) {
    printf("array: ");
    for (int i = 0; i < l; i++) printf("%d ", array[i]);
}