#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    //vediamo come generare valori numerici casuali
    //un metodo molto efficace è usare la funzione time, dalla libreria time.h.
    //se a questa funzione passiamo il valore di NULL, essa ci darà il numero di secondi che sono passati 
    //dal 1° gennaio 1970, a mezzanotte (00:00:00 UTC). questo giorno è detto giorno di Epoch ed è utilizzato
    //dai sistemi informatici UNIX (come lo è il linguaggio c) come riferimento temporale per definire il tempo.
    //in questo modo ad ogni esecuzione del programma abbiamo la possibilità di avere un valore diverso, ma non 
    //è questo il numero casuale perché in 2 esecuzioni ravvicinate i numeri che ci escono sono simili.
    //Precisazione:  la funzione time restituisce il valore dei secondi come numero di tipo long int, quindi un
    //intero con una codifica con più bit di un intero semplice (occupa più memoria ma può essere più grande)
    long secondi = time(NULL);
    //si potrebbe salvare anche in un valore unsigned ma poi vedremo
    printf("secondi dal 1 gennaio 1970: %ld\n", secondi);

    //oppure direttamente
    /*
    printf("secondi dal 1 gennaio 1970: %ld\n", time(NULL));
    */

    //questo numero di secondi adesso lo usiamo in una funzione detta srand(), che inizializza la funzione rand(),
    //ossia il generatore di numeri casuali tramite il seme del tempo in secondi, dunque ad ogni esecuzione il seme sarà diverso,
    //e verranno generati diversi numeri
    //se invece si utilizza sempre lo stesso seme, la funzione rand() genera sempre gli stessi numeri
    srand(time(NULL));
	int a = rand();
	printf("primo valore di a: %d\n",a);
    //la variabile a assume un valore randomico
    //se riutilizziamo la funzione rand, otteniamo un altro valore sempre randomico e (quasi sicuramente) diverso
	a = rand();
	printf("secondo valore di a: %d\n", a);

    //se non vogliamo salvare il valore in una variabile ma solo stamparla possiamo fare cosi (visualizziamo un long int)
	printf("valore randomico stampato: %ld\n", rand());
    //però c'è sempre un limite di valori generabili. il valore massimo che la funzione rand() può generare, è dato dalla
    //costante RAND_MAX presente nella libreria stdlib.h. Questo valore rappresenta il massimo numero casuale che può essere generato.
	printf("valore massimo ottenibile dalla rand(): %d\n", RAND_MAX);

    //se vogliamo generare dei valori randomici in un intervallo di interi, possiamo usare il modulo %
	a = rand()%10;
    //Questo permette di ottenere un numero casuale compreso tra 0 e 9 (inclusi).
	printf("numero random da 0 a 9: %d\n",a);

    //ricordiamo che se non è inizializzato srand a nessun seme allora è di default inizializzato al seme 1
    //ci sta la prova al prossimo file
}