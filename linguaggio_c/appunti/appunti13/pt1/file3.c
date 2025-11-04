#include <stdio.h>
#define N 100
void main() {
    //vediamo precisamente come leggere da un file binario con la funzione fread()
    int elementi, dimensione, n;
    char buf[N];
    FILE *fp;
    fp = fopen("nome_file.bin", "r");
    if (fp == NULL) printf("impossibile leggere il file nome_file.bin\n");
    else {
        //con fread possiamo leggere il contenuto del file copiando le informazioni in un vettore buf
        //dobbiamo definire i parametri
        dimensione = sizeof(char);   //la dimensione di un solo elemento del vettore in cui trasferire tutto
        elementi = N; //numero di elementi del vettore

        n = fread(buf, dimensione, N, fp);
        //il valore di ritorno della funzione fread (salvato in n) indica al programmatore il numero di elementi letti dal file, che nel migliore dei casi dovrebbe essere N, ma nel caso in cui il vettore è vuoto o ha un numero di elementi inferiore a N, n assume un valore più basso di N
        /*
        Se il valore di ritorno assume valore negativo significa che è stato commesso 
        qualche errore, per esempio il file non è stato aperto.
        */
        printf("sono stati copiati %d elementi nel vettore\n", n);
        if (n>0) {
            //proviamo a stampare con il ciclo, per far vedere che sono davvero n elementi
            for (int i = 0; i < n; i++)
                printf("%c", buf[i]);
            //poi stampiamo la stringa con la scorciatoia di printf, che fa vedere che l'ultimo elemento è anche \0
            printf("\nbuf = '%s'\n", buf);
        }
        else printf("nel file non c'è nulla oppure non è accessibile");
        fclose(fp);
    }
    printf("\n\n\n");
    //facciamo un esempio con un esempio cercando di leggere elementi da un file vuoto
    fp = fopen("file vuoto", "r");
    if (fp == NULL) printf("errore file");
    else {
        n = fread(buf, sizeof(char), N, fp);
        if (n>0)
            printf("contenuto del file: %s\n", buf);
        else printf("il file è vuoto o non accessibile (potrebbe non essere stato aperto, o aperto non in lettura)\n");
    }
    printf("\n\n\n\n\n");



    /*
    La operazioni di lettura accedono al file in maniera sequenziale e mantengono traccia del punto in cui si è arrivati nella 
    lettura. Dopo l’apertura in lettura il puntatore si trova posizionato all’inizio del file; a ogni chiamata a fread il puntatore si sposta in avanti di un numero di byte pari a quelli che sono stati letti e trasferiti nella memoria centrale.

    Poiché in generale un file può avere notevoli dimensioni, sarebbe impensabile poterlo leggere con una sola chiamata a fread: quest’ultima può essere ripetuta più di una volta, leggendo così a ogni chiamata soltanto una limitata porzione del file.

    Siccome non conosciamo la lunghezza del file, iterare quest'operazione è utile per prendere le informazioni dal file senza dover settare l'argomento del numero di elementi da copiare con fread con dimensioni precise o altro.
    
    Quando tutto il contenuto del file è stato letto la funzione fread ritorna il valore 0 per indicare che il puntatore è ormai posizionato a fine file; ogni ulteriore tentativo di lettura fallirà e fread continuerà a restituire il valore di ritorno 0.
    */
    //prossime lezione nella sottocartella 'continuo'
}