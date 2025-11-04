#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
int main() {
    int vet[N];
    srand(time(NULL));
    for (int i = 0; i < N; i++) vet[i] = rand()%100;
    printf("vet[%d] non ordinato:\t", N);
    for (int i = 0; i < N; i++) printf("%d\t", vet[i]);
    
    //vediamo come ordinare un vettore tramite l'ordinamento detto bubble sort
    //usiamo 3 cicli annidati in cui il primo confronta gli elementi adiacenti, e verifica chi è il più grande
    //esempio di bubble in ordine crescente
    int aux; //variabile di appoggio
    for (int j = 0; j < N-1; j++)
        for (int i = 0; i < N-1; i++)
            if (vet[i]>vet[i+1]) {
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
            }

    printf("\nvet[%d] ordinato:\t", N);
    for (int i = 0; i < N; i++) printf("%d\t", vet[i]);
    printf("\n\n\n\n");

    // il ciclo interno sposta di volta in volta l’elemento più pesante verso il basso
    //guarda facendo il debug con le espressioni di controllo come cambia il vettore
    //noterai che una volta che l'array è ordinato compie molte iterazioni che sono inutili e che fanno diventare questo metodo lento su larga scala
    //per rimediare a questo questa lentezza, una volta che non riscontra più elementi da cambiare, impone una condizione che interrompe il ciclo, più comodo ancora se usiamo un do while
    //es
    for (int i = 0; i < N; i++) vet[i] = rand()%100;
    printf("vet[%d] non ordinato:\t", N);
    for (int i = 0; i < N; i++) printf("%d\t", vet[i]);

    int condizione = 1;
    do {
        for (int i = 0; i < N-1; i++)
            if (vet[i]>vet[i+1]) {
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
            }
            else ; condizione = 0; //interrompe il ciclo ma al primo non scambio e non va bene, perché deve controllare tutto il vettore, se non fa scambi per tutto il vettore allora stoppa il ciclo
    }
    while (condizione);
            
    printf("\nvet[%d] 'ordinato':\t", N);
    for (int i = 0; i < N; i++) printf("%d\t", vet[i]);
    printf("\nl'ultimo vettore dovrebbe essere ordinato ma non lo è");
    
    //l'ordinamento è scritto, quindi in questo modo che il vettore non si ordina del tutto, ma dopo il primo non cambio si fermi.
    //per farlo stoppare quando è completamente ordinato, ci deve essere una condizione impostata sull'iterazione più esterna
    do {
        condizione = 0; //se dopo non vengono effettuati scambi, si stoppa il ciclo
        for (int i = 0; i < N-1; i++)
            if (vet[i]>vet[i+1]) {
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
                condizione = 1; //questa condizione fa continuare il ciclo
            }
    } while (condizione);
    
    printf("\nvet[%d] ordinato:\t", N);
    for (int i = 0; i < N; i++) printf("%d\t", vet[i]);
    printf("\n\n\n\n");


    //in questo modo il bubble sort è più ottimizzato e più veloce, ma si può ottimizzare ulteriormente
    for (int i = 0; i < N; i++) vet[i] = rand()%100;
    printf("vet[%d] non ordinato:\t", N);
    for (int i = 0; i < N; i++) printf("%d\t", vet[i]);
    //sappiamo che ogni volta che viene eseguito un ciclo esterno del do while, gli ultimi valori vengono posizionati verso la fine dell'array, e sono per forza ordinati, quindi potremmo anche non ricontrollarli. quindi ad ogni iterazione del ciclo esterno possiamo anche non controllare più l'ultimo elemento dell'array nel ciclo interno
    int n = N;   //n dobbiamo cambiarlo, quindi non può essere una costante (di solito non è mai una costante e lo abbiamo gia dichiarato)
    condizione = 1;
    do {
        condizione = 0;
        for (int i = 0; i < n-1; i++)
            if (vet[i]>vet[i+1]) {
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
                condizione = 1;
            }
        n--;  //decrementa la condizione in modo che gli ultimi elementi non vengano ulteriormente controllati
    }
    while (condizione);
    printf("\nvet[%d] ordinato:\t", N);
    for (int i = 0; i < N; i++) printf("%d\t", vet[i]);
    printf("\n\n\n\n");


    //si può ottimizzare ancora
    for (int i = 0; i < N; i++) vet[i] = rand()%100;
    printf("vet[%d] non ordinato:\t", N);
    for (int i = 0; i < N; i++) printf("%d\t", vet[i]);
    //dato che decrementiamo un n per volta, nel caso sono già molto ordinati gli ultimi elementi (più di uno per interazione), controlliamo degli elementi di troppo
    //quindi dobbiamo cercare di far stoppare il ciclo interno all'ultimo scambio avvento nell'iterazione precedente
    //invece di decrementare n di uno per volta, usiamo un altra variabile p, che inizializziamo al valor di n

    int p; //indica la posizione del primo elemento già ordinato (da questo in poi non si deve controllare)
    n = N; //n deve avere sempre il valore iniziale giusto
    condizione = 1;
    do {
        condizione = 0;
        for (int i = 0; i < n-1; i++)
            if (vet[i]>vet[i+1]) {
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
                condizione = 1;
                p = i + 1; //se i prossimi elementi sono ordinati, p sarebbe l'indice del primo elemento da non controllare
            }
        n = p;  //decrementa la condizione in modo che gli ultimi elementi non vengano ulteriormente controllati
    }
    while (condizione);

    printf("\nvet[%d] ordinato:\t", N);
    for (int i = 0; i < N; i++) printf("%d\t", vet[i]);
    //questo è l'ordinamento in bubble sort più ottimizzato possibile


    

}