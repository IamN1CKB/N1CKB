#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N_MAX 11
/*
Scrivere un programma che, richiesti all’utente i primi n−1 elementi già ordinati di un vettore di dimensione n e un 
ulteriore elemento finale, inserisca quest’ultimo nella posizione corretta facendo scivolare verso il basso tutti gli 
elementi più grandi
*/
int main(){
    int vet[N_MAX];
    int l = 10;
    //printf("scegli una lunghezza del vettore (<%d): ", N_MAX);
    //scanf("%d", &l);
    int n = l;
    srand(time(NULL));
    for (int i = 0; i < l; i++)
        vet[i] = rand()%100;
    int condizione, p, temp;
    do {
        condizione = 0;
        for (int i = 0; i < n-1; i++) {
            if (vet[i] > vet[i+1]) {
                temp = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = temp;
                condizione = 1;
                p = i +1;
            }
        }
        n = p;
    } while (condizione);

    printf("vet: ");
    for (int i = 0; i < l; i++)
        printf("%d ", vet[i]);
    
    //adesso richiediamo all'utente un altro numero da inserire nel vettore.
    int x;
    printf("\ninserisci un numero: ");
    scanf("%d", &x);

    //capiamo prima in che indice dobbiamo inserire il valore x
    int indice = l;
    for (int i = 0; i < l; i++)
        if (x<vet[i]) {
            indice = i;
            break;
        }
    printf("indice: %d\n", indice);

    //ora inseriamo x nel vettore spostando gli elementi successivi
    
    for (int i = l; i > indice; i--) vet[i] = vet[i-1];
    //questo ciclo for parte dall'ultimo elemento e lo impone uguale al precedente, e poi col penultimo e così via
    //non possiamo fare lo stesso ragionamento partendo dal primo perché poi viene copiato sempre lo stesso valore
    vet[indice] = x;    //ci resta solo da copiare l'elemento nel suo indice giusto
    
   
    
    //stampa vettore
    printf("vet: ");
    for (int i = 0; i < l+1; i++)
        printf("%d ", vet[i]);
}