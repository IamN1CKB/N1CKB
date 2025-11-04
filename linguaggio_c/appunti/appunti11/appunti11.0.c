#include <stdio.h>
 void main(){
    /*
    Un tipo rappresenta un insieme di valori e di operazioni che possono essere svolte su quei valori. Una variabile è una 
    entità che conserva un valore del corrispondente tipo; inserire un nuovo valore in una variabile significa distruggere il 
    vecchio valore presente in essa. 
    In C vi sono due categorie di tipi: fondamentali e derivati. I tipi fondamentali sono:
            char    int     enum    float   double
    Questi vengono detti anche tipi aritmetici, poiché corrispondono a valori che possono essere interpretati come numeri. I 
    tipi derivati, invece, sono costruiti a partire dai tipi fondamentali, e sono: 
            void    array   funzioni    puntatori   strutture   unioni
    
    Alcuni tra i tipi fondamentali e derivati sono già stati trattati. In questo capitolo riprenderemo le definizioni 
    precedentemente introdotte e le completeremo aggiungendo i qualificatori di tipo, definendo il tipo enum e un nuovo 
    insieme di possibili operazioni. 
    Prima di procedere alla descrizione dettagliata dei tipi fondamentali è necessario richiamare alcuni concetti di carattere 
    generale, quali la dichiarazione e la definizione di un nome. 
    In C un qualunque nome deve essere dichiarato prima di poter essere usato all’interno del programma; dichiarare un 
    nome significa specificare a quale tipo appartiene quel nome e quindi, indirettamente, quanta memoria dovrà essere 
    riservata per quel nome, e quali sono le operazioni ammesse su di esso.

    Il linguaggio C ha un insieme di tipi fondamentali associati alle principali unità di memoria di un calcolatore, e alle 
    corrispondenti modalità d’uso più comuni. Così gli interi sono rappresentati dai tipi
            char    int
    mentre i numeri in virgola mobile sono rappresentati da 
            float   double
    Il tipo char è un intero che generalmente ha una dimensione pari a un byte (8 bit). Il nome char deriva dal fatto che 
    la dimensione deve essere sufficiente a contenere un carattere. Tipicamente, allora, una variabile di tipo char contiene 
    valori positivi compresi tra 0 e 255. Questo però è solo l’uso più comune. Il C impone che un char erediti le 
    operazioni tipiche di un intero, cioè somma, sottrazione, divisione, moltiplicazione e così via. Allora, anche se 
    raramente usato, non è un errore assegnare un valore negativo a una variabile di tipo char:
    */
    char raro = -1;
    /*
    Il tipo int, invece, è un intero la cui dimensione è di solito pari alla parola (word) della macchina; dunque nella 
    maggioranza dei casi una variabile di tipo int occupa quattro byte (32 bit). La dimensione di una variabile di tipo
    int, comunque, cambia da macchina a macchina e l’unica relazione universale è:
    sizeof(char) <= sizeof(int)
    */
    if (sizeof(char)<= sizeof(int)) printf("vero 1\n");
    /*
    Ossia: la dimensione di un char è minore o uguale alla dimensione di un int.
    Il tipo float corrisponde a un dato numerico di singola precisione in virgola mobile. Anche la dimensione di un 
    float dipende dall’architettura della macchina in esame: spesso un float occupa 4 byte (32 bit). 
    Il tipo double corrisponde a un dato numerico in virgola mobile, ma in doppia precisione. Anche la dimensione del 
    double dipende dalla macchina: in molti casi un double occupa 8 byte (64 bit). L’unica relazione universale è:
    sizeof(float) <= sizeof(double)
    */
    if (sizeof(float)<= sizeof(double)) printf("vero 2\n");
    /*
    I quattro tipi fondamentali possono essere ulteriormente specificati per mezzo di due tipi di qualificatori:
        i qualificatori di dimensione    short e long
        il qualificatore aritmetico unsigned
    I qualificatori di dimensione si applicano al tipo fondamentale int:
    short int 
    definisce un dato numerico la cui dimensione è minore o uguale a quella di int:
    sizeof(short int) <= sizeof(int)
    */
    if (sizeof(short int)<= sizeof(int)) printf("vero 3\n");
    /*
    mentre
    long int 
    definisce un dato numerico la cui dimensione è maggiore o uguale a quella di int.
    sizeof(int) <= sizeof(long int)
    */
    if (sizeof(int)<= sizeof(long int)) printf("vero 4\n");
    /*

    Il C standard ANSI prevede anche un tipo long double, che definisce un dato numerico la cui dimensione è 
    maggiore o uguale a quella di double. 
    Riassumendo si ha:
    sizeof(char) <= sizeof(short int) <= sizeof(int) <= sizeof(long int)
    sizeof(float) <= sizeof(double) <= sizeof(long double)
    Il qualificatore aritmetico si applica invece ai tipi char e int:
    unsigned char
    unsigned int
    In entrambi i casi, con unsigned si fa uso dell’aritmetica senza segno. Questo significa che i valori numerici 
    contenuti nelle variabili di tipo unsigned char e unsigned int sono sempre considerati come interi positivi. 
    Nell’uso dei qualificatori la sintassi del C ammette delle abbreviazioni:
    short <----> short int
    long <----> long int
    unsigned <----> unsigned int
    unsigned short <----> unsigned short int
    unsigned long <----> unsigned long int
    Il tipo long double non può invece essere abbreviato. 
    Abbiamo visto come la dimensione dei tipi dipenda dalle caratteristiche del processore della macchina ospite.
    */
    //di seguito stampiamo le dimensioni di ogni tipo semplice di variabile presente in C
    printf("sizeof(char) = %d\n", sizeof(char));
    printf("sizeof(short) = %d\n", sizeof(short));
    printf("sizeof(int) = %d\n", sizeof(int));
    printf("sizeof(long) = %d\n", sizeof(long));
    printf("sizeof(long long) = %d\n", sizeof(long long));
    printf("sizeof(float) = %d\n", sizeof(float));
    printf("sizeof(double) = %d\n", sizeof(double));
    printf("sizeof(long double) = %d\n", sizeof(long double));

}