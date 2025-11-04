#include <stdio.h>
#define N 10
/*
gli array e i puntatori in C sono strettamente correlati. Il nome di un array può essere usato come un puntatore al suo 
primo elemento. Considerando, per esempio:
*/
void main() {
    char buf[100];
    char* s;
    s = &buf[0];
    s = buf;
    /*
    si ha che le due assegnazioni s=&buf[0] e s=buf sono perfettamente equivalenti. Infatti in C il nome di un array, 
    come nel nostro caso buf, è una costante − si noti bene: una costante, non una variabile! − il cui valore è l’indirizzo 
    del primo elemento dell’array. Allora, come gli elementi di un array vengono scanditi per mezzo dell’indice, 
    equivalentemente si può avere accesso agli stessi elementi per mezzo di un puntatore. Per esempio consideriamo il 
    seguente codice:
    */
    char buf2[100];
    buf2[7] = 'a';
    printf("buf2[7] = %c\n", buf2[7]);
    *(buf2 + 7) = 'b';
    printf("buf2[7] = %c\n", buf2[7]);

    //ora notiamo che questi 2 codici sono equivalenti:
    //parte di dichiarazione identica
    char buf3[2];
    char* s3;

    //caso 1
    for (int i = 0; i < 2; i++)
        buf3[i] = 'K';
    
    //caso 2
    s3 = buf3;   //dobbiamo salvare il valore della costante buf2 perché non possiamo incrementare buf, siccome è una costante
    for (int i = 0; i < 2; i++)
        *s3++ = 'K';

    /*
    Il valore del puntatore s3 è incrementato di 7 unità, cioè di 7 volte la dimensione dell’oggetto corrispondente al tipo base del puntatore
    */

    //ATTENZIONE: anche con i puntatori devi stare attento a non sfondare le dimensioni massime di un array


    /*
    con i puntatori sono disponibili solo le operazioni di incremento e decremento.
    Nell’aritmetica dei puntatori quello che conta è il tipo base. Incrementare di 1 un puntatore significa far saltare il 
    puntatore alla prossima locazione corrispondente a un elemento di memoria il cui tipo coincide con quello base. Per 
    esempio, in:
    */
    int a[10];
    char b[10];
    int* pi;
    char* pc;
    pi = a;
    pc = b;
    pi = pi + 3;
    pc = pc + 3;
    //le ultime due istruzioni che incrementano di 3 i puntatori pi e pc debbono essere interpretate in modo diverso. La prima,
    pi = pi + 3;
    //significa spostare in avanti pi di tre posizioni, dove ogni posizione occupa lo spazio di un int. La seconda,
    pc = pc + 3;
    //significa spostare in avanti pc di tre posizioni, dove ogni posizione occupa lo spazio di un char

    
    //Più in generale si ha che, quando un operatore aritmetico è applicato a un puntatore p di un certo tipo e p punta a un elemento
    // di un array di oggetti di quel tipo, p+1 significa “prossimo elemento del vettore” mentre p-1 significa “elemento precedente”.
    
    
    
    int v1[10];
    int v2[10];
    int i;
    int* p;

    i = &v1[5] - &v1[3]; /* 1 ESEMPIO */
    printf("\ni = &v1[5] - &v1[3]\ni = 5-3 = %d\n\n", i); /* i vale 2 */


    i = &v1[5] - &v2[3]; /* 2 ESEMPIO */
    printf("i = &v1[5] - &v2[3]\ni = sottrazione tra puntatori di array diversi = risultato imprevedibile =  %d\n\n", i); /* il risultato è indefinito */ 
    
    /* 3 ESEMPIO */
    p = v2 - 2; /* dove va a puntare p ? */
    //sottrazione di una costante da un indirizzo ma nella direzione sbagliata:
    
    //il puntatore p va a puntare due interi prima dell’inizio del vettore v2 (per come sono avvenute le definizioni probabilmente si sconfina nello spazio riservato a v1, ma non è detto !)
    
    //dato che il nome di una array è un puntatore possiamo dichiarare una stringa anche in questo modo (attenzione solo le stringhe)
    char *stringa = "stringa da puntatore";
    printf("stringa: %s\n", stringa);
    /*
    In questo caso, stai dichiarando un puntatore a carattere (char *) e lo stai inizializzando con l'indirizzo della stringa letterale 
    "stringa a caso" in memoria.
    Tuttavia, è importante notare che le stringhe letterali in C sono immutabili, quindi il contenuto della stringa non può essere modificato 
    tramite il puntatore str. In altre parole, str punta a una porzione di memoria in sola lettura che contiene la sequenza di caratteri della 
    stringa letterale.

    Se intendi creare una stringa modificabile, dovresti invece utilizzare un array di caratteri in maniera tipica:
    */
    printf("stringa[0] = %c\n\n\n", stringa[0]);   //possiamo considerarlo come un array in lettura, ma non in scrittura
    //stringa[0] = 'b';     //darebbe un errore di segmentation fault
    


    //inoltre possiamo anche dichiarare array di puntatori a un certo tipo
    int* pVet[N];     //array di puntatori a interi
    int vet[N];     //array di interi
    int vet1[N];
    //possiamo scrivere
    pVet[0] = vet;   //perché vet è l'indirizzo del primo elemento di vet[N]
    pVet[1] = vet1;  //inizializziamo ogni elemento dell'array di puntatori all'indirizzo del primo elemento di un array
    //...

    //in questo modo stiamo avendo una matrice, ma molto particolare siccome non è d'obbligo che tutti gli array riga debbano avere la stessa lunghezze (numero di colonne).
    //inoltre sono allocate in modo diverso in memoria, ossia non riga dopo riga ma puntatore dopo puntatore, i quali possono puntare a spazi di memoria distanti tra loro
    //vediamo invece la matrice propria come possiamo definirla in termini di puntatori


    int mat[N][N];
    mat[0][0] = 7;
    //in questo caso mat[N] è un array di puntatori a interi, che puntano al primo elemento di ogni riga
    //invece solo mat è un puntatore al primo elemento dell'array di prima, ma in aritmetica dei puntatori mat+1 è &mat[1][0]
    //si potrebbero definire in questo modo
    //int* mat[N] array di puntatori alle righe
    //int** mat   puntatore al primo puntatore
    printf("indirizzo della prima riga della matrice =                    %p\n", mat[0]);
    printf("primo elemento della matrice = %d\n", *mat[0]); //è la stessa cosa di scrivere mat[0][0]
    printf("indirizzo del puntatore al primo elemento della matrice =     %p\n", mat);
    printf("indirizzo della prima riga (uguale al primo elemento) =       %p\n", (*mat));
    

    //grazie ai puntatori abbiamo la possibilità di costruire un array di stringhe, simile alla matrice impropria che abbiamo fatto, dove ogni riga ha una lunghezza diversa
    //il linguaggio c dà anche la possibilità di compattare l'inizializzazione in questo modo
    char* str[3] = {"cos", "ma che cazzo", "ah, va bene"};
    for (int i = 0; i < 3; i++)
        printf("str[%d]: %s\n", i, str[i]);
    //dato che sono puntatori possiamo anche stamparli e capire come sono posizionati in memoria, e vediamo che sono posizionati come matrici ma con righe di diversa lunghezza
    printf("0) %ld\n", str[0]);  //stampiamo gli indirizzi come interi (int long che poi vedrai) perché ci è più facile fare le operazioni
    printf("1) %ld\n", str[1]);
    printf("2) %ld\n", str[2]);
    printf("str[0] ha un numero di caratteri pari alla differenza tra i puntatori str[1] - str[0]: %d\n", str[1]- str[0]);
    printf("infatti '%s' ha %d caratteri incluso lo \\0\n", str[0], str[1]-str[0]);
    printf("str[1] ha un numero di caratteri pari alla differenza tra i puntatori str[2] - str[1]: %d\n", str[2]- str[1]);
    printf("infatti '%s' ha %d caratteri incluso lo \\0\n", str[1], str[2]-str[1]);
    printf("per calcolare il numero di caratteri di str[2] dovremmo sapere cosa si trova subito dopo in memoria dopo str[2] (non lo sappiamo)\n");
}