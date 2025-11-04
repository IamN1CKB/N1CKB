#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//merge sort
/*
IDEA BASE
L'ordinamento per fusione o Merge Sort riconduce il problema dell'ordinamento al problema della fusione di array ordinati.
Fusione di array ordinati: Dati due array ordinati, generare un array compost dagli elementi di entrambi, anch'esso ordinato.
*/
void creaVet(int *arr, int n);
void stampaVet(int *arr, int n);
void merge(int a1[], int n1, int a2[], int n2, int dest[]);
void merge_sort(int a[], int n, int temp[]);

int main () {
    //creiamo una array dinamico con valori random
    int *vet, *temp, n;
    printf("decidi il numero di elementi del vettore: ");
    scanf("%d", &n);
    vet = (int*) calloc(n, sizeof(int));
    temp = (int*) calloc(n, sizeof(int));
    creaVet(vet, n);
    stampaVet(vet, n);
    merge_sort(vet, n, temp);
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
/*
IDEA BASE – Fusione ordinata 
    1. L'array risultato c viene costruito iterativamente, partendo da un array vuoto e aggiungendo ad ogni passo un nuovo elemento
    2. Affinché l'array c risulti ordinato possiamo aggiungere a ogni passo il più piccolo degli elementi di a e di b che non sono 
        stati ancora usati
    3. Il più piccolo tra gli elementi di a e di b è semplicemente il più piccolo tra il primo elemento di a ed il primo elemento
        di b non ancora inseriti
*/

void merge (int a1[], int n1, int a2[], int n2, int dest[]) {
    int pos1=0, pos2=0, k=0;
    while (pos1<n1 && pos2<n2) {
        if (a2[pos2] < a1[pos1])
            dest[k++] = a2[pos2++];
        else
            dest[k++] = a1[pos1++];
    }
    while (pos1 <n1)
        dest[k++] = a1[pos1++];
    while (pos2 <n2)
        dest[k++] = a2[pos2++];
}
/*
Caso base: se n= 1 allora l'array è ordinato
• Divide: dividiamo a in due parti, a’ e a’’ rispettivamente di m = n/2 elementi e di n-m;
• Impera: Applica l’algoritmo ad a’ ed a’’
• Combina: utilizzando l'algoritmo di fusione, fondiamo gli array ordinati a’ e a’’ producendo un nuovo array ordinato
*/

void merge_sort (int a[], int n, int temp[]) {
    int i, m=n/2;
    if (n <2)
        return ;
    merge_sort (a, m, temp );
    merge_sort (a+m, n-m, temp );
    merge (a, m, a+m, n-m, temp );
    for (i =0; i<n; i ++)
        a[i]= temp [i];
}
//la complessità computazionale del merge sort é sempre di O(n*log(n)) con n la grandezza del vettore.Q
//Quindi non dipende dal fatto che il vettore sia già leggermente ordinato
//essendo una funzione ricorsiva non è molto ottimizzata nell'ambito della memoria