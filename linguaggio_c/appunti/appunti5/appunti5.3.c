#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 100

int main() {
    //vediamo come fare la fusione di 2 vettori di lunghezza qualsiasi 
    int vet1[N], vet2[N], n, m;
    int vet3[N]; //prodotto della fusione

    printf("inserisci la lunghezza del primo vettore (minore di %d): ", N);
    scanf("%d", &n);
    printf("inserisci la lunghezza del secondo vettore (minore di %d): ", N);
    scanf("%d", &m);

    //diamo valori casuali ai 2 vettori
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        vet1[i] = rand()%100;
    }
    for (int i = 0; i < m; i++) {
        vet2[i] = rand()%100;
    }
    
    //ordiniamo le 2 sequenza
    int condizione, aux, p=n;  //p è il valore da cui non cercare più
    int n1=n;  //nomino un altra variabile n1 per non modificare la variabile n, che deve restare fissa
    do {
        condizione = 0;
        for (int i = 0; i < n1-1; i++) {
            if (vet1[i]>vet1[i+1]) {
                aux = vet1[i];
                vet1[i] = vet1[i+1];
                vet1[i+1] = aux;
                condizione = 1;
                p = i + 1;
            }
        }
        n1 = p;
    } while (condizione);

    p=m;  //p è il valore da cui non cercare più
    int m1=m;  //nomino un altra variabile n1 per non modificare la variabile n, che deve restare fissa
    do {
        condizione = 0;
        for (int i = 0; i < m1-1; i++) {
            if (vet2[i]>vet2[i+1]) {
                aux = vet2[i];
                vet2[i] = vet2[i+1];
                vet2[i+1] = aux;
                condizione = 1;
                p = i + 1;
            }
        }
        m1 = p;
    } while (condizione);
    //stampa vettori
    printf("vet1: ");
    for (int i = 0; i < n; i++)
        printf("%d \t", vet1[i]);
    printf("\nvet2: ");
    for (int i = 0; i < m; i++)
        printf("%d \t", vet2[i]);

    //adesso facciamo la fusione ordinata delle 2 sequenze
    //paragoniamo i valori dei 2 vettori e decidendo chi è il più piccolo, per x elementi con x = min(m,n)
    int i=0, j=0, k=0;
    //i e j sono gli indici di vet1 e vet2
    do {
        if (vet1[i]<vet2[j]) //controlliamo che il valore i-esimo di vet1 sia minore del valore j-esimo di vet2, e portiamo in vet3 il valore più piccolo in modo da fondere 2 vettori in un vettore ordinato
            vet3[k++]=vet1[i++];
        else
            vet3[k++]=vet2[j++];
    } while (i<n && j<m);

    //con questo codice non si salvano gli ultimi elementi del vettore più lungo
    //dobbiamo capire quale dei 2 vettori ha i valori non memorizzati, e possiamo usare un if che compara l'indice del vet1 (i) con la lunghezza del vet1 (n), oppure l'indice del vet2 (j) con la lunghezza del vet2 (m) 
    if (j < m)
        while (j < m)
            vet3[k++] = vet2[j++];
    else //in questo caso potrebbe essere vet1 il vettore con elementi non salvati
        while (i < n)
            vet3[k++] = vet1[i++];
        
    //stampa vet3
    printf("\nvet3: ");
    for (i = 0; i < k; i++)
        printf("%d\t", vet3[i]);
    

    printf("fine");
    


}