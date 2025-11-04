#include <stdio.h>
void main() {
    //UNIONI   (non le useremo mai in esercizi)
    /*
    Le unioni (union) sono analoghe alle strutture: introducono nel programma una nuova definizione di tipo e sono 
    costituite da un insieme di membri, che possono essere − in generale − di tipo e dimensione diversa. I membri di una 
    unione, però − a differenza di una struttura −, coincidono, cioè hanno lo stesso indirizzo e vanno a occupare le 
    medesime locazioni di memoria. Questo implica che l’occupazione di memoria di una unione coincide con quella del 
    membro dell’unione di dimensione maggiore. La sintassi generale di una union è analoga a quella delle strutture:
    union nome_unione {
        tipo_membro nome_membro1;
        tipo_membro nome_membro2;
        ...
        tipo_membro nome_membroN;
    };
    Nell’esempio
    */
    union fantasma {
        int i;
        long d;
        char c;
    };
    union fantasma a;
    //la dimensione della variabile a coincide con quella della unione fantasma e corrisponde allo spazio occupato da un long

    /*
    La parola chiave typedef viene usata per assegnare un alias a un qualsiasi tipo, fondamentale e derivato. Con 
    typedef non si definisce un nuovo tipo all’interno del programma, ma più semplicemente si introduce un nome che 
    corrisponde a uno dei tipi definiti. Per esempio, con le istruzioni
    */
    typedef char * Stringa;
    Stringa s1, s2;
    /*
    dapprima il tipo char *, cioè il tipo puntatore a carattere, viene ribattezzato Stringa. Successivamente si 
    definiscono due variabili, s1 e s2. La sintassi di typedef è
    typedef nome_tipo nuovo_nome_tipo;
    dove nome_tipo è il nome simbolico del tipo che si vuol ribattezzare e nuovo_nome_tipo è il nome che si associa 
    a nome_tipo. Ribattezzare un tipo può essere molto utile soprattutto per rendere più leggibile un programma, e per 
    evitare espressioni altrimenti complesse. Per esempio con il frammento di programma


    
    L’uso di typedef può risultare utile anche quando si ha a che fare con le strutture. Per esempio 
    si potrebbe avere
    */
    struct automobile {
        char *marca;
        char *modello;
        int venduto;
    };
    typedef struct automobile Auto;
    Auto car1, car2, car3;
    /*
    In tal modo si evita di ripetere la parola chiave struct nella definizione delle variabili car1, car2 e car3 e al 
    contempo si rende molto espressivo il codice sorgente.
    Si osservi come si sia implicitamente mantenuta la convenzione di usare la prima lettera maiuscola nella ridefinizione 
    del nuovo nome di un tipo. In tal modo è possibile riconoscere immediatamente i tipi introdotti dal programmatore.
    
    c'è anche una scorciatoia che definisce la struct e aggiunge anche il sinonimo con typedef
    */

    typedef struct{
        int campo1;
        float campo2;
        char campo3;
    } STRUTTURA;
    STRUTTURA boh;

    boh.campo1 = 1;

    /*
    inoltre typedef può essere utile per accorciare anche una dichiarazione di un enum
    */
    enum enumerazione {UNO = 1, DUE, TRE};
    enum enumerazione variabile_enum = UNO;
    typedef enum enumerazione lista_n;
    lista_n var_enum = DUE;    //variabile_enum e var_enum sono dello stesso tipo
    //possiamo anche qui usare la scorciatoia
    typedef enum {COPPE, DENARI, SPADE, BASTONI} carte_nap;
    carte_nap settebello = DENARI;
   
}