#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100
//in caso i puntatori sono scomodi da usare in una funzione, possiamo utilizzare un metodo per non usarli sempre nei sottoprogrammi
//facciamo un esempio con un programma per calcolare il massimo e il minimo di un vettore


int inizializzazione(int vet[]);
void stampa(int vet[], int l);
void massimoMinimo(int vet[], int* pMax, int* pMin, int l);

void main(){
    int array[N], massimo, minimo;
    int l = inizializzazione(array);   //dobbiamo dare il puntatore al primo elemento (ossia solo il nome dell'array)
    stampa(array, l);

    massimoMinimo(array, &massimo, &minimo, l);
    printf("massimo = %d\nminimo = %d", massimo, minimo);

}


int inizializzazione(int vet[]) {
    int l;
    printf("scegli lunghezza vettore (<%d): ", N);
    scanf("%d", &l);
    srand(time(NULL));
    for (int i = 0; i < l; i++) vet[i] = rand()%100;
    return l; //ritorniamo la lunghezza
}

void stampa(int vet[], int l) {
    printf("array: ");
    for (int i = 0; i < l; i++) printf("%d ", vet[i]);
    printf("\n");
}

void massimoMinimo(int vet[], int* pMax, int* pMin, int l) {
    //invece di lavorare con *max e *min lavoriamo con delle variabili che dichiariamo nel sottoprogramma e che quindi successivamente verranno cancellate
    int max = vet[0], min = vet[0];
    for (int i = 1; i < l; i++){
        if (vet[i]>max) max = vet[i];
        if (vet[i]<min) min = vet[i];
    }
    

    //solo alla fine del sottoprogramma usiamo i puntatori
    *pMax = max;
    *pMin = min;
}