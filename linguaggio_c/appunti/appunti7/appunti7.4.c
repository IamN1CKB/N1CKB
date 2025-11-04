/*
Abbiamo trattato il passaggio di parametri e la restituzione di un valore da parte di una funzione. Prendiamo ora in 
esame funzioni che non restituiscono alcun valore, e funzioni che non hanno parametri. In entrambi i casi il C mette a 
disposizione un “tipo” speciale detto void.
*/


//facciamo un esempio con un programma per la conversione di un numero da decimale a binario (solo stampandolo ma non salvandolo)
#include <stdio.h>
#define DIM_INT 16
void stampa_bin (int num);
int main() {
    char resp[2];
    int num;
    resp[0] = 's';
    while( resp[0] == 's' ) {
        printf("Inserisci un intero positivo: ");
        scanf("%d", &num);
        printf("La sua rappresentazione binaria è: ");
        stampa_bin(num);
        printf("\nVuoi continuare? (s/n): ");
        scanf("%s", resp);
    }
}

void stampa_bin (int num) {
    int array_num[DIM_INT], i = 0;
    while (num!=0) {
        array_num[i] = num % 2;
        num = num/2;
        i++;
    }
    
    for (int j = i-1; j >= 0; j--) //dobbiamo stamparlo al contrario
        printf("%d ", array_num[j]);  //non abbiamo nessun return siccome dobbiamo solo stampare a video
    
}

//il void si usa per indicare quindi che la funzione stampa_bin non ha un valore di ritorno, ma potrebbe anche essere omesso, scrivendo solo stampa_bin
//si può usare il void per specificare che una funzione non ha argomenti da passare, ma anche questo void può essere omesso. infatti sono dichiarazioni valide tutte queste:
/*
void funzione(void);
void funzione();
funzione(void);
funzione();
*/
//però negli ultimi 2 casi la funzione viene indicata dal compilatore come di tipo int, e se non ha nessun valore di ritorno viene considerata come void
//dunque la funzione principale di un programma, ossia main(), può essere meglio definita come:
// void main(void) {...}
/*
Il fatto è che prima dello standard ANSI il C non prevedeva la parola chiave void, e oggi, per motivi di compatibilità, 
sono ammesse le due notazioni, con e senza void. Attualmente lo standard stabilisce che main sia implicitamente 
definita come funzione void, mentre in passato veniva comunemente definita di tipo int. Per evidenti motivi di 
leggibilità si consiglia caldamente di far uso di void tutte le volte che è necessario, soprattutto al fine di indicare che la 
funzione non ritorna nessun valore 
*/

/*
cerchiamo di comprendere come elabora una funzione. come prima cosa si deve scegliere un nome descrittivo, e che non è troppo generico

inoltre si ricorda che non si devono inserire troppi parametri siccome essi vengono definiti dinamicamente e ciò comporta un maggior tempo di elaborazione e un maggior consumo di memoria.

La zona di memoria riservata alle chiamate di funzione viene gestita con la logica di una pila (stack), di cui parleremo diffusamente nel Capitolo 14. Cerchiamo comunque di rappresentare quello che accade in memoria durante il ciclo di vita di una funzione. 
Quando viene invocata una funzione il sistema alloca uno spazio di memoria libero in testa alla pila, spazio riservato ai parametri formali e alle variabili locali.
Per esempio, nel programma che calcola le somme, dopo che il main ha chiamato la funzione somma il sistema alloca spazio per i suoi dati...

Quindi, per esempio, definire una funzione come:
int f(void) {
    char a[1000000];
    ...
}
potrebbe creare qualche problema! Ecco dunque una possibile eccezione alla sacre regole della programmazione strutturata: nei casi in cui una funzione debba lavorare su strutture di memoria costose in termini di occupazione è preferibile usare variabili globali.

L’ultima osservazione riguarda le uscite di una funzione. Abbiamo visto che in C una funzione ritorna al più un valore. 
Come ci si deve comportare allora quando è necessario che ci sia più di un valore di ritorno? Esistono due soluzioni:
    1. usare delle variabili globali;
    2. rendere note alla funzione delle locazioni in cui andare a depositare le uscite.
Per saperne di più su questo secondo tipo di soluzione, si rimanda al Capitolo 9 sui puntatori
*/