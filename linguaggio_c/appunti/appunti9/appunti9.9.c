#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
I puntatori sono usati nella creazione e manipolazione di oggetti dinamici. Mentre gli oggetti statici vengono creati specificandoli in 
una definizione, gli oggetti dinamici sono creati durante l’esecuzione del programma. Il numero degli oggetti dinamici non è definito 
dal testo del programma, come per gli oggetti creati attraverso una definizione: essi vengono creati o distrutti durante l’esecuzione 
del programma, non durante la compilazione. Gli oggetti dinamici, inoltre, non hanno un nome esplicito, ma occorre fare riferimento a 
essi per mezzo di puntatori.
Il valore NULL, che può essere assegnato a qualsiasi tipo di puntatore, indica che nessun oggetto è puntato da quel puntatore. È un 
errore usare questo valore in riferimento a un oggetto dinamico. 
Il puntatore NULL è un indirizzo di memoria che corrisponde al valore convenzionale di puntatore che non punta a nulla e la sua 
definizione può essere diversa da macchina a macchina.
*/
int main() {
    char a[10] = "buon anno";
    int i;
    i = sizeof(a);
    printf("L'array %s ha dimensione = %d char\n", a, i);
    i = sizeof(int);
    printf("Gli interi hanno dimensione %d char\n", i);
    /*
    L’operatore sizeof ritorna un intero maggiore di zero corrispondente al numero di char che formano l’espressione o il tipo.
    Si ricordi che l’unità di misura di sizeof è il char e non il byte, come potrebbe venire naturale pensare, ma in quasi tutti
    le architetture il char ha la dimensione di un byte, per questo nel futuro indicheremo il valore di ritorno di sizeof() misurato in byte.
    
    
    la dichiarazione di variabili corrispondenti a tipi semplici e strutturati non possono mutare le loro caratteristiche
    in fase di esecuzione e pertanto sono dette statiche.
    nel caso di array per allocare staticamente memoria dobbiamo usare una dimensione massima chiamata comunemente N_MAX ma questo utilizzo
    comporta 2 problematiche:
        -spreco di memoria se il riempimento è molto minore di N_MAX
        -limiti di utilizzo se il riempimento è > N 
    
    con invece l'allocazione dinamica si risolvono i problemi

    prima di tutto vediamo come è strutturata la memoria in C

    In linguaggio C, la memoria è strutturata in diverse sezioni, ognuna con un ruolo specifico. Le principali sezioni di memoria includono:
    1. **Text Section (o Code Section):**
       - Contiene il codice eseguibile del programma.
       - La sezione di testo è di sola lettura e condivisa, il che significa che più istanze dello stesso programma in esecuzione 
       condivideranno la stessa area di memoria per il codice.
    2. **Data Section:**  Questa regione di memoria contiene le variabili globali e statiche.
       - Divisa in due sottosezioni: data inizializzata e data non inizializzata (o bss).
       - La data inizializzata contiene variabili globali e statiche inizializzate con valori specifici.
       - La data non inizializzata contiene variabili globali e statiche che vengono inizializzate a zero o a valori predefiniti.
    // Data section
    int global_variable_initialized = 42; // data inizializzata
    int global_variable_uninitialized;    // data non inizializzata
    3. **Heap:**
       - Utilizzato per la gestione dinamica della memoria.
       - È possibile allocare e deallocare la memoria nel heap durante l'esecuzione del programma, ad esempio utilizzando le funzioni `malloc`, `calloc`, `realloc` e `free`.
       - la dimensione può cambiare a runtime, ovvero durante l'esecuzione del programma
    tra poco li vediamo bene
    int *dynamic_array = (int *)malloc(5 * sizeof(int)); // allocazione di memoria nel heap
    free(dynamic_array); // deallocazione di memoria nel heap
    4. **Stack:**
       - Utilizzato per la gestione automatica della memoria.
       - Contiene le variabili locali e i record di attivazione delle funzioni.
       - L'allocazione e la deallocazione della memoria nello stack avvengono automaticamente durante l'entrata e l'uscita dalle funzioni.
    void exampleFunction() {
        int local_variable; // variabile locale nello stack
    }
    Queste sono le principali sezioni di memoria in un programma C. La gestione della memoria è cruciale per evitare problemi come memory leaks o accessi illegali alla memoria.     
    
    L'allocazione dinamica è particolarmente utile quindi se si vuole dichiarare una array (di qualsiasi dimensione) ma non
    si vuole limitare la dimensione massima
    L'allocazione dinamica della memoria in C avviene tramite un insieme di funzioni nell'header `stdlib.h`:
        1. `malloc()`: Questa funzione assegna un blocco di memoria di una certa dimensione e restituisce un puntatore a quel blocco.
        ha un solo parametro, che è la dimensione dello spazio da allocare, che quindi la moltiplicazione tra il numero di elementi
        da allocare e la dimensione di un singolo elemento 
        Ecco un esempio:
        */
        int *punt = malloc(10 * sizeof(int));  // Alloca spazio per 10 interi
        if (punt == NULL) {
            // La malloc non è riuscita, gestisci l'errore
        }
        /*

        2. `calloc()`: Questa funzione funziona come `malloc()`, ma inizializza anche la memoria a zero. essa richiede 2 argomenti  
        che sono il numero di elementi da allocare, e la dimensione di un singolo elemento 
        Ecco un esempio:
        */
        punt = calloc(10, sizeof(int));  // Alloca spazio per 10 interi e li inizializza a zero
        if (punt == NULL) {
            // La calloc non è riuscita, gestisci l'errore
        }
        

        /*
        3. `realloc()`: Questa funzione cambia la dimensione di un blocco di memoria già allocato. vuole 2 parametri che sono il
        puntatore su cui devi cambiare la dimensione, e la nuova dimensione
        Ecco un esempio:
        */
        punt = realloc(punt, 20 * sizeof(int));  // Raddoppia la dimensione dell'array
        if (punt == NULL) {
            // La realloc non è riuscita, gestisci l'errore
        }
        /*

        4. `free()`: Questa funzione libera un blocco di memoria precedentemente allocato con `malloc()`, `calloc()` o `realloc()`.
        Se non si effettua questa operazione lo spazio di memoria verrà perso, cioè non sarà possibile riutilizzarlo.
        Ecco un esempio:
        */
        free(punt);  // Libera la memoria e non ha un tipo di ritorno
        punt = NULL;  // Imposta il puntatore a NULL
        //attenzione se non si impostava alla fine punt a NULL, essa per il sistema operativo era ancora un puntatore valido ma 
        //potrebbe dare errori insoliti se si continua a usare punt dopo il free.
        //Il puntatore dopo l'istruzione free è considerato un dangling pointer (puntatore cigolanti)
        /*

    Ricorda che è responsabilità del programmatore gestire correttamente la memoria in C. Dovresti sempre liberare qualsiasi memoria che
    hai allocato quando hai finito di usarla, altrimenti il tuo programma potrebbe causare una perdita di memoria.
    
    L'allocazione della memoria potrebbe non sempre riuscire, ad esempio quando non è disponibile più memoria. in tal caso le 
    funzioni qui sopra restituiscono NULL, e dobbiamo gestire questo errore altrimenti il programma lavora con un puntatore NULL
    
    Gli allocatori malloc e calloc ritornano un puntatore all’oggetto dinamico creato. In realtà, gli allocatori ritornano 
    dei puntatori a void, cioè a tipo generico, e perciò devono essere esplicitamente convertiti in un tipo specifico. Il 
    valore che ritorna dagli allocatori di memoria è molto importante perché è solo attraverso di esso che si può far 
    riferimento agli oggetti dinamici. 
    Consideriamo per esempio l’istruzione:
    */
    int *pi;
    pi = (int *) malloc (sizeof(int));
    /*
    che alloca una quantità di memoria sufficiente per accogliere un intero. Questo intero, allocato dinamicamente e di 
    cui non si conosce il nome, può essere raggiunto per mezzo del puntatore pi. L’indirizzo dell’intero è assegnato a pi
    dopo aver esplicitamente convertito il tipo void * (ritornato da malloc), nel tipo int *, il tipo della variabile pi, 
    mediante la semplice espressione (int *) detta cast.
    */
    int *array;
    array = (int*) calloc(5, sizeof(int));
    if (array == NULL) {
        perror("ERR allocazione array");
        return -1;
    }
    //abbiamo allocato dinamicamente un array di 10 elementi, e possiamo aumentare questa "dimensione massima" tramite realloc 
    array[0] = 10;
    printf("primo elemento dell'array = %d\n", array[0]);
    *array = 10;
    printf("primo elemento dell'array = %d\n", array[0]);

    for (int i = 1; i < 5; i++) {
        printf("inserisci array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    printf("array: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", array[i]);
    printf("\n\n");
    free(array);


    //con questa allocazione possiamo chiedere all'utente a runtime la dimensione del vettore
    int *l, *vet;
    l = (int*) malloc(sizeof(int));
    if (l == NULL){
        perror("ERR allocazione l");
        return -1;
    }
    
    printf("decidi quanto grande deve essere il prossimo vettore: ");
    scanf("%d", l);
    vet = (int*) calloc(*l, sizeof(int));
    if (vet == NULL) {
        perror("ERR allocazione vet");
        return -1;
    }
    srand(time(NULL));
    printf("vet:\n");
    for (int i = 0; i < *l; i++) {
        vet[i] = rand()%20;
        printf("%d ", vet[i]);
    }
    printf("\n");

    //l'allocazione dinamica quindi preserva la memoria in RAM, ma in termini di prestazioni di velocità è più lenta rispetto all'allocazione
    //statica, siccome dobbiamo chiedere a runtime al sistema operativo di allocare spazio in in RAM
}