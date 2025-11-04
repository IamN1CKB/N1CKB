#include <stdio.h>
//vediamo i sottoprogrammi, ossia parti del programma che possono essere richiamate nel main per poter essere eseguite
//vanno dichiarate fuori dal main (preferibilmente prima del main per comodità),
int somma(int, int);
//nella dichiarazione si devono precisare gli argomenti che devono essere passati alla funzione. in questo caso 2 numeri interi
//dopo il main di solito viene poi definita la funzione
int main(){
    int a, b;
    printf("inserisci valore a: ");
    scanf("%d", &a);
    printf("inserisci valore b: ");
    scanf("%d", &b);
    somma(a, b);     //Il programma chiamante non ha da fare altro che passare alla funzione somma dei valori, ed eseguire la funzione

    
}
int somma(int a, int b) {
    printf("a+b = %d", a+b);
    //Oltre al nome della funzione viene definito il numero, il tipo e il nome dei suoi parametri, cioè le variabili su cui essa agisce.
}
/*in sintesi ci sono:
la dichiarazione di una funzione: double cubo(float);
• la definizione di una funzione: double cubo(float c) {...};
• il ritorno di un valore: return(c*c*c);
• l’invocazione di funzione: b = cubo(a).

DICHIARAZIONE DI UNA FUNZIONE
In termini generali una funzione viene dichiarata con la sintassi detta prototyping:
tipo_ritorno nome_funzione (tipo_parametro1, tipo_parametro2, ..., tipo_parametroN);
La dichiarazione introduce il nome della funzione, che in questo modo può essere utilizzato dal programma, ma 
presuppone che da qualche altra parte ne esista la definizione, altrimenti quel nome resterebbe privo di significato e il 
compilatore segnalerebbe un errore.

Il programmatore potrebbe anche scegliere di definire una funzione in un file e invocarla in un altro. In tal caso, nel file 
in cui viene utilizzata la funzione senza che essa vi sia definita l’invocazione della funzione deve essere preceduta da 
una sua dichiarazione (ossia #include file_in_cui_si_trova_la_funzione).
Per il momento consideriamo solo programmi interamente contenuti in un file; la dichiarazione 
di una funzione serve per poter separare il punto in cui una funzione è invocata dal punto in cui essa è definita. Avremo 
modo più avanti di approfondire l’argomento parlando di programmi su più file.
Nella dichiarazione di una funzione si potrebbero specificare anche i nomi dei parametri formali. Per esempio
    int somma(int a, int b);
è una dichiarazione valida. Il nome del parametro formale, però, è assolutamente superfluo. Ciò che conta in una 
dichiarazione è il tipo, o meglio la lista dei tipi dei parametri formali. Se in una dichiarazione di una funzione si 
specificano anche i nomi dei parametri formali il compilatore semplicemente li ignora.

DEFINIZIONE DI UNA FUNZIONE
La definizione stabilisce il nome della funzione, i valori in ingresso su cui agisce − detti parametri formali −, il blocco 
di istruzioni che ne costituiscono il contenuto, e l’eventuale valore di ritorno. Per i nomi delle funzioni valgono le 
consuete regole in uso per gli identificatori. Nelle parentesi tonde che seguono il nome della funzione sono definiti i 
parametri formali specificandone il tipo e il nome.
Per ogni funzione introdotta nel programma occorre una definizione, ma si ricordi che in C non è ammesso che più 
funzioni abbiano lo stesso nome.
Nel blocco istruzioni delimitato da parentesi graffe può essere inserita qualunque istruzione, compresa una chiamata di 
funzione.

NOTA: in C, main non è una parola chiave del linguaggio ma il nome della funzione principale, cioè la funzione che, 
fra tutte quelle definite nel programma, viene eseguita per prima. La funzione main non è sintatticamente 
diversa dalle altre funzioni. La sua struttura:
main()
{
... 
}
rispetta la sintassi generale di definizione delle funzioni. Alla funzione main possono essere anche passati dei 
parametri attraverso la linea di comando. Ritorneremo sull’argomento dopo aver trattato i puntatori

i parametri formali sono i parametri che stanno nel codice della funzione, invece i parametri effettivi sono
i parametri che sono situati nella chiamata della funzione

questo metodo di programmare in C tramite le funzioni, si chiama approccio (paradigma) procedurale
*/