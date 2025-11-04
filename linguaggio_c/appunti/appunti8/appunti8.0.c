/*
Un compilatore traduce le istruzioni di un programma sorgente in linguaggio macchina. Generalmente il programmatore 
non è consapevole del lavoro del compilatore: usa delle istruzioni in linguaggio di alto livello per evitare le idiosincrasie 
del linguaggio macchina. Talvolta però è conveniente prendere coscienza dell’esistenza del compilatore per impartirgli 
delle direttive. 
In C è possibile inserire in un codice sorgente tali direttive, dette più propriamente direttive del preprocessore. Il 
preprocessore è il modulo del compilatore che scandisce per primo il codice sorgente e interpreta le direttive prima della 
traduzione in codice macchina. Le direttive del preprocessore non fanno realmente parte della grammatica del 
linguaggio, ma estendono l’ambiente di programmazione del C includendo il compilatore. Tra esse troviamo define 
e include , che abbiamo introdotto già dal Capitolo 1. Secondo lo Standard ANSI l’elenco delle direttive del 
preprocessore C è il seguente:
#define #error #include
#elif #if #line
#else #ifdef #pragma
#endif #ifndef #undef
Tutte iniziano con il simbolo # e una linea di codice non ne deve contenere più di una. La linea
#include "stdio.h" #include "stdlib.h"
produrrebbe perciò un messaggio di errore da parte del preprocessore.

il define l'abbiamo già incontrato e sappiamo che sostituisce tutte le occorrenza dell'identificatore la stringa di caratteri che vi è stata associata. possiamo anche usare una costante definita prima per una altra costante. es:
#define UNO 1
#define DUE UNO+UNO


La sostituzione di macro è un processo vantaggioso che risparmia al programmatore un lavoro ripetitivo e tedioso. Se 
per esempio si volesse definire un messaggio di errore standard si potrebbe usare una soluzione del tipo:
#define MYERR "standard error on input\n"
...
printf(MYERR);

NOTA
Non si ha sostituzione di macro se il nome di macro è usato all’interno di una stringa:
#define XYZ Buona Lettura
...
printf("XYZ");
L’ultima istruzione non visualizzerà la scritta Buona Lettura ma la stringa XYZ.

Nel caso in cui la sequenza di caratteri da associare a un nome-macro sia più lunga di una linea si può continuare su 
quella successiva terminando la linea con il carattere \. Per esempio:
*/
#define STRINGONA "questa linea e' molto molto molto \
molto molto molto lunga"

/*
La direttiva #define possiede un’ulteriore caratteristica: una macro può avere argomenti. Una macro con 
argomenti è per molti aspetti simile a una funzione. Ogni qualvolta si incontra una macro nel codice gli argomenti 
dell’occorrenza sono sostituiti al posto di quelli della definizione:
*/
#define ABS(a) (a)<0 ? -(a) : (a)


#include <stdio.h>
int main(){
    int n;
    printf(STRINGONA);
    printf("\n\nscegli un numero di cui calcolare il valore assoluto: ");
    scanf("%d", &n);
    printf("\nvalore assoluto di:\n|%d| = %d", n, ABS(n));
    
}