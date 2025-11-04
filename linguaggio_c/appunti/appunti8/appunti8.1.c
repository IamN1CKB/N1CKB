/*
La direttiva #include, di cui abbiamo sin qui fatto largo uso, dice al preprocessore di andare a leggere in un altro file 
sorgente oltre a quello che contiene la direttiva medesima. La sintassi generale è:
#include nome-file
 
Il qualificatore nome-file può essere indicato in due modi diversi: racchiuso da virgolette o da parentesi angolari:
#include "stdio.h"
#include <stdio.h>
Facendo precedere la parola chiave Se il nome del file è racchiuso tra parentesi angolari il preprocessore cercherà il
corrispondente file secondo un percorso stabilito da chi ha realizzato il compilatore. La ricerca, insomma, avviene in 
qualche directory speciale appositamente creata all'atto dell'installazione del compilatore per includere i file. 
Se invece il nome è racchiuso tra virgolette il file è cercato in un altro modo, dipendente dall'implementazione. In 
pratica ciò spesso vuol dire che la ricerca avviene nella directory di lavoro attuale. Se la ricerca del file dà esito 
negativo, il precompilatore la ripete come se il nome fosse stato racchiuso da parentesi angolari. 
 NOTA
Conviene sempre consultare la guida del compilatore per conoscere con precisione come sono risolte parentesi 
angolari e virgolette.
Occorre ricordare che un file di include può a sua volta contenere altre direttive #include. Si parla in questo caso di 
include annidati. Il numero di livelli di annidamento varia da compilatore a compilatore; tuttavia lo standard ANSI 
stabilisce che siano disponibili per lo meno otto livelli di inclusione.
*/

//CONTINUA TU CON QUESTO CAPITOLO INUTILE PER L'ESAME