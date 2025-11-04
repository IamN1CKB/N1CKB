#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 100
/*
algoritmo di ordinamento in senso decrescente
*/
int main(){
    int vet[N];
    srand(time(NULL));
    
    int l;   //lunghezza del vettore
    l=10;   //valore preimpostato
    printf("inserisci lunghezza del vettore: ");
    scanf("%d", &l);

    //inizializzazione e stampa del vettore
    printf("vet:\n");
    for (int i = 0; i < l; i++){
        vet[i] = rand()%100;
        printf("%d ", vet[i]);
    }
    
    int condizione;  //condizione che verifica se il vettore è gia completamente ordinato
    int aux; //variabile di appoggio per scambiare i valori
    do {
        condizione=0;
        for (int i = 1; i < l; i++) {
            //ragioniamo sugli ultimi elementi, quindi dal l-1
            if (vet[l-i]>vet[l-i-1]) {
                aux = vet[l-i];
                vet[l-i] = vet[l-i-1];
                vet[l-i-1] = aux;
                condizione = 1;
            }
        }
    } while (condizione);

    //stampa ordinata del vettore
    printf("\nvet in ordine decrescente:\n");
    for (int i = 0; i < l; i++)
        printf("%d ", vet[i]);
    
    
}