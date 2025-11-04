//Dato un vettore di interi v[First..Last], scrivere una funzione ricorsiva lineare che inverta il vettore v. 
//La funzione non restituisce alcun valore.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void stampaVet(int v[], int n) {
    printf("vet: ");
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void invertiVet(int v[], int First, int Last);

int main(){
    int n;
    printf("quanto grande vuoi il vettore? ");
    scanf("%d", &n);
    int* vet = (int*) calloc(n, sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        vet[i] = rand()%100;
    stampaVet(vet, n);
    invertiVet(vet, 0, n-1);
    stampaVet(vet, n);
}
/*
• Divide: il vettore di ingresso v[First..Last] viene diviso in tre parti: il l'elemento di posizione First, l'elemento di
    posizione Last ed il vettore v[First+1..Last-1].
• Caso base: se il vettore ha un solo elemento, oppure nessun elemento.
• Impera: si ritiene per ipotesi induttiva che si sappia risolvere correttamente il problema dell'inversione del vettore v[First+1..Last-1].
• Combina: si scambia l'elemento di posizione First con quello di posizione Last perché la parte centrale del vettore e già invertita
    per ipotesi
*/
void invertiVet(int v[], int First, int Last) {
    if (Last<=First ) return;
    else {
        invertiVet(v, First+1, Last-1);
        int temp = v[First];
        v[First] = v[Last];
        v[Last] = temp;
    }
}