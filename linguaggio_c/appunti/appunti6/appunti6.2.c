#include <stdio.h>
#define N_MAX 100
int main() {
        /*
    In linguaggio C, la funzione `gets()` è stata utilizzata per leggere una riga di testo da stdin (standard input) e memorizzarla in una stringa. Tuttavia, è importante notare che `gets()` è considerata obsoleta e altamente insicura a causa della mancanza di controllo sulla lunghezza dell'input. Questo la rende vulnerabile agli attacchi di buffer overflow, che possono causare problemi di sicurezza gravi.

    Ecco un esempio di come funziona `gets()`:
    */
        char stringa[50]; // Dichiarazione di una stringa di lunghezza massima 50

        printf("Inserisci una stringa: ");
        gets(stringa); // Legge una riga di testo da stdin e la memorizza in 'stringa'

        printf("Hai inserito: %s\n", stringa);

    /*
    Tuttavia, l'utilizzo di `gets()` è altamente sconsigliato a causa dei potenziali problemi di sicurezza che può causare. Invece, è consigliabile utilizzare `fgets()` che offre una maggiore sicurezza gestendo il numero massimo di caratteri da leggere:

    */
    
        char stringa2[50]; // Dichiarazione di una stringa di lunghezza massima 50

        printf("Inserisci una stringa: ");
        fgets(stringa2, sizeof(stringa2), stdin); // Legge una riga di testo da stdin e la memorizza in 'stringa'

        printf("Hai inserito: %s\n", stringa);
    /*
    `fgets()` specifica la dimensione massima della stringa da leggere (in questo caso, 50 caratteri, compreso il terminatore null) per evitare il rischio di superare i limiti dello spazio allocato per la stringa.
    NOTE: fgets include nella stringa anche \n finale. ad esempio se inserisco in console "buon Natale " e poi faccio invio per salvare, nella stringa ci sarà "buon Natale \n\0". per eliminare ciò dobbiamo settare il penultimo carattere = \0, in modo che diventi "buon Natale \0\0", con l'ultimo \0 che non viene contato. per questo motivo in certi casi non è comodo usare questa soluzione

    Un altro modo per memorizzare una stringa è l’uso, all’interno di un ciclo, della funzione getchar, che cattura il carattere passatole in ingresso, che ci permette di salvare da console una stringa formata da più parole
    */
    char frase[N_MAX] = "ciao, sono Nicola Belardo";
    char parole[N_MAX];
    int i, j;
    printf("frase: %s\n", frase);
    printf("Inserisci delle parole da aggiungere alla frase (manda a capo per concludere): ");
    //adesso capiamo come ciclicizzare la funzione getchar(): fin quando l'utente non manda un invio, viene salvato ogni carattere che l'utente inserisce (anche gli spazi)
    for(i=0; (parole[i]=getchar())!='\n' && (i<N_MAX); i++);   //i<N_MAX perché altrimenti sfora la lunghezza massima dell'array
    parole[i]='\0';  //con questo metodo il fine stringa si deve per forza mettere separatamente
    //NOTA: non inserire lettere accentate nel getchar perché il compilatore impazzisce

    //da qui usiamo lo stesso algoritmo di prima
    for(i=0; frase[i]!='\0'; i++);   //calcoliamo la lunghezza
    for(j=0; (frase[i]=parole[j])!='\0' && (i<N_MAX); i++,j++);  //facciamo  l'aggiunta della stringa
    //stampa:
    printf("frase: %s\n", frase);

    /*
    È chiaro che potremmo decidere d’interrompere l’inserimento della stringa da aggiungere al verificarsi di un altro evento; per esempio, quando l’utente batte un punto esclamativo (o un qualsiasi altro carattere).
    In questo modo potremmo memorizzare più linee nello stesso array: ogni Invio dato dal terminale corrisponde infatti all’assegnamento di un \n a un elemento dell’array; evidentemente una successiva visualizzazione dell’array mostrerebbe la stringa con gli accapo inseriti dall’utente.
    */
    //facciamo un esempio di questa casistica, e aggiungiamo ulteriori parole con accapo alla stringa frase
    printf("inserisci altre parole da aggiungere (manda _  e poi accapo per concludere: puoi mettere anche gli accapo tra le parole): ");
    for (i = 0; (parole[i] = getchar())!= '_' && (i<N_MAX); i++);
    parole[i] = '\0';
    //ora inseriamo questo nella frase (prima otteniamo la lunghezza della frase)
    for (j = 0; frase[j] !='\0'; j++);
    for (i = 0; (frase[j] = parole[i])!='\0' && (j<N_MAX); j++, i++);
    //stampa:
    printf("frase: %s\n", frase);
    
    

}