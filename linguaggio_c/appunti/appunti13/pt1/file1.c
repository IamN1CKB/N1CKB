#include <stdio.h>
void main() {
    //vediamo come salvare quei dati in file binari
    /*
    un file è un unità di memorizzazione dati da parte del FileSystem (ossia una componente del sistema operativo, si occupa della gestione di dati non volatili)
    
    in tutti i file i dati sono salvati come una sequenza di byte. in generale si distinguono 2 tipi di file:
        -file binario, ossia un file la cui sequenza di byte dipende dalla codifica scelta dalla particolare applicazione. Ad esempio in un file di testo non si possono codificare dati come il colore del testo, un immagine, la posizione del testo; per questo motivo abbiamo bisogno di file detti binari, che codificano queste informazioni in sequenze di byte
        -file di testo, ossia un particolare file (che sarebbe sempre binario ma non sarebbe descritto come binario) in cui, ogni byte corrisponde a una rappresentazione ASCII di un carattere

    per poter operare su un file abbiamo bisogno inizialmente di un operazione di apertura di un file che permette la creazione di un canale tra il programma e l'istanza del file nel FileSystem.

    dopodiché questo canale viene usato o per scrivere sul file o per leggere sul file (siccome è un canale con il FileSystem che è sempre una parte del sistema operativo, è il sistema operativo che svolge queste azioni, e il programma C chiede solo al sistema di svolgerle, e niente di più)

    dopo aver concluso tutte le operazioni da svolgere sul file, deve essere chiuso il canale che collega il programma con l'istanza del file, facendo in modo che tutte le operazioni vengano salvate su disco.
    
    il sistema operativo (ciò quindi vale per ogni azione senza considerare linguaggio C) non salva i dati una modifica alla volta perché le memorie di massa (come gli hard disk) sono più lenti della RAM, del processore, e di altre componenti. Quando andiamo a scrivere su un file, un byte non viene subito scritto ma il sistema operativo lo mette prima da parte e poi dopo aver raggiunto una certa quantità di byte da memorizzare li invia tutti assieme sul disco: Scrivere byte singoli comporterebbe un numero elevato di operazioni di scrittura e lettura molto piccole, rallentando notevolmente le prestazioni complessive del dispositivo di memoria.

    per svolgere le operazioni di apertura, scrittura, lettura e chiusura su un file abbiamo bisogno di varie funzioni dalla libreria stdio.h
    per poter svolgere questo operazioni abbiamo bisogno inoltre di una variabile di tipo derivata che rappresenti il file.
    questa variabile è di tipo FILE
    */
    FILE *fp;   //abbiamo dichiarato un puntatore a FILE, che servirà per le altre funzioni
    //la prima operazione da svolgere è quella di apertura tramite la funzione fopen
    fp = fopen("nome_file", "r");
    //il primo argomento di fopen è il nome del file, che non ha bisogno di un estensione perché essa è solo un suggerimento per dice al sistema operativo con che tipo di app bisogna aprire il file, ma non indica il tipo di file.
    //per capire il secondo argomento della funzione vedi più in basso

    //il file nome_file deve essere nella stessa directory dell'eseguibile siccome è scritto come un percorso assoluto (attenzione, il compilatore di visual studio divide l'eseguibile in una sottocartella della directory del codice sorgente, per questo motivo, se eseguiamo con questo compilatore il file deve essere nella directory del codice sorgente, ma se lo eseguiamo da terminale deve essere nella directory dell'eseguibile)
    //per questo motivo preferiamo eseguire da terminale
    //abbiamo assegnato al puntatore fp il risultato della funzione fopen, e ciò creerà un canale con il file attraverso questo puntatore a file
    //nel caso in cui ci sia qualche errore perché il file non è stato trovato oppure un qualsiasi altro bug (oppure i permessi mancati di amministratore, ecc..) che non fa aprire il canale con il file, il puntatore a file assume il valore di un file pointer NULL
    //per questo motivo è buona scrittura continuare il resto della operazione in un costrutto if, con un else che segnala errori
    if (fp != NULL) {
        printf("il file e' stato aperto\n");
        //varie operazioni...
        //una volta concluse le operazioni possiamo chiudere il file con fclose
        fclose(fp);
        /*
        La chiusura del file garantisce che tutti i dati scritti nel file ordini siano salvati su disco; infatti molto spesso il 
        sistema operativo, per ottimizzare le prestazioni del programma, ritarda le scritture sulla memoria di massa mantenendo 
        le informazioni temporaneamente in memoria centrale.
        */
    }
    else printf("Errore con il file 'nome_file'\n");

    /*
    Al momento dell’apertura è sempre necessario specificare, oltre al nome del file, anche il tipo di operazione che si 
    desidera eseguire. Nell’esempio precedente il parametro “r” stava a indicare che il file doveva essere aperto in lettura 
    (read). In generale, le possibili modalità di apertura di un file, specificate dal secondo parametro di fopen, sono le 
    seguenti:
        "r" sola lettura − sul file sarà possibile eseguire soltanto operazioni di lettura e quindi non sarà possibile 
        effettuarvi delle scritture. Se il file non esiste la funzione fopen ritornerà il codice di errore NULL.

        "w" sola scrittura − sul file sarà possibile eseguire solamente operazioni di scrittura, quindi non operazioni di 
        lettura. Se il file al momento dell’apertura non esiste sarà automaticamente creato, in caso contrario il 
        contenuto del file preesistente sarà perso.

        "r+" lettura e scrittura − sul file sarà possibile eseguire operazioni sia di lettura sia di scrittura. Se il file non 
        esiste la funzione fopen ritornerà il codice di errore NULL. Il puntatore al file è posizionato all'inizio del file

        "w+" scrittura e lettura − sul file sarà possibile eseguire operazioni sia di scrittura sia di lettura . Se il file non 
        esiste verrà automaticamente creato, in caso contrario il contenuto del file preesistente verrà perso.  Il puntatore al file è posizionato all'inizio del file.

        "a" append − sul file sarà possibile eseguire soltanto operazioni di scrittura a fine file: tutte le scritture 
        verranno sempre eseguite in coda al contenuto attuale del file. Se il file non esiste verrà creato 
        automaticamente, in caso contrario il contenuto del file preesistente verrà mantenuto.

        "a+" lettura e append − sul file sarà possibile eseguire operazioni sia di lettura sia di scrittura. Se il file non 
        esiste verrà automaticamente creato, in caso contrario il contenuto del file preesistente verrà mantenuto.




    */
}