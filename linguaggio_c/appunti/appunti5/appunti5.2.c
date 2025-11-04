#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 30
int main(){
    //LA RICERCA BINARIA
    //la ricerca binaria consiste nel ricercare in un array ordinato un elemento, dividendo l'intervallo degli elementi a metà, escludendo metà dei dati ad ogni passaggio (necessita di un array ordinato)
    srand(time(NULL));
    int vet[N];
    int i;     //dichiaro i qui perché mi può servire fuori dai cicli
    //inizializzazione vettore con rand() con stampa
    printf("vet non ordinato:\n");
    for (i = 0; i < N; i++) {
        vet[i] = rand()%(127-33) + 33;  //lettere, punteggiatura e numeri dalla tabella ASCII (da 33 a 126)
        printf("%d\t", vet[i]);
    }
    //ordiniamo l'array secondo il bubble sort ottimizzato
    int aux, p;    //p = elemento da cui non bisogna più controllare
    int condizione = 1, n = N;
    do {
        condizione = 0;
        for (i = 0; i < n-1; i++) {
            if (vet[i]>vet[i+1]) {
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
                condizione = 1;
                p = i + 1;   //dal valore dopo sono già ordinati
            }   
        }
        n = p;
    } while (condizione);
    printf("\nvet ordinato:\n");
    for (int i = 0; i < N; i++) printf("%d\t", vet[i]);

    int x;      //elemento da cercare
    printf("\ninserisci numero da cercare: ");
    scanf("%d", &x);


    //ricerca binaria
    /*per poter eseguire una ricerca binaria, dobbiamo usare 3 variabili:
        pos: ci dice se abbiamo trovato il valore e nel caso affermativo riporta l'indice del valore
        inf: ci dice il valore più inf da confrontare e lo cambia con il tempo
        sup: ci dice il valore più sup da confrontare e lo cambia con il tempo
    */
    //sup e inf cambiano restringendo man mano l'intervallo di valori in cui cercare
    //inizializziamo sup e inf all'indice più alto e l'indice più basso a cui cercare
    int sup = N-1;
    int inf = 0;
    int pos = -1;     //-1 indica che ancora non ho trovato il valore
  //int i;   //indice del valore medio già inizializzato
    do
    {
        i = (sup + inf)/2;    //indice del valore medio
        if (x == vet[i]) pos = i;   //abbiamo trovato il valore
        else {  //se non l'abbiamo trovato
            if (x<vet[i])
                sup = i-1;     //siccome i l'abbiamo già controllato, lo escludiamo
            else 
                inf = i+1;    //stessa cosa per inf
        }
        
    } while (sup >= inf && pos == -1);
    //c'è la condizione sup >= inf perché dopo varie iterazioni (se il valore non è stato ancora trovato) sup e inf si avvicinano sempre di più fino a coincidere o il sup diventa minore dell'inf siccome diminuisce di un i-1 e inf aumenta sempre di i+1



    //conferma se il vettore è trovato
    if (pos == -1)
        printf("non abbiamo trovato %d\n", x);
    else
        printf("abbiamo trovato %d all'indice %d\n", x, pos);
    
    
    
    

    
    

}