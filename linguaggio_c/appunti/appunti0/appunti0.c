//per fare commenti monoriga in c si usa il doppio slash
/*per
fare
commenti a più righe invece lo slash e asterisco*/
#include <stdio.h>
//Questa riga dice al compilatore (o meglio al linker) di includere nel programma il contenuto del file di intestazione della libreria standard stdio.h (standard input output).
int main(void) {

    //Adesso vediamo le vari fasi del lavoro di un programmatore
    /*le fasi del lavoro del programmatore sono costituite da:
        • editing del programma;
        • precompilazione;
        • compilazione;
        • traduzione in codice oggetto;
        • link;
        • esecuzione.
    La prima fase sarebbe dunque la scrittura del codice da parte del programmatore in un editor da lui scelto.

    La fase di precompilazione viene eseguita dal preprocessore C, che ha il compito di espandere alcune forme abbreviate. È, per esempio, il preprocessore che si preoccupa di sostituire nel programma ai nomi delle costanti i loro valori, specificati con la macro-istruzione define che abbiamo introdotto in questo capitolo. il precompilatore dunque crea il codice sorgente espanso.
    
    Quest'ultimo viene elaborata dal compilatore C vero e proprio, che ricerca gli errori eventualmente presenti e traduce tale codice in istruzioni scritte nel linguaggio assemblatore (fase di compilazione). 
    
    Questa versione del programma originario in linguaggio assemblatore viene passata all’assembler, che effettua la traduzione in una forma chiamata codice oggetto rilocabile (fase di traduzione in file di tipo .o). Questa forma non è ancora eseguibile dal sistema di elaborazione, perché deve essere collegata alle librerie alle quali si fa riferimento negli include. Infatti il compilatore lascia in sospeso tutte le funzioni che vengono invocate nel programma ma che non vi sono definite; è il caso di printf() e scanf() che abbiamo già utilizzato.
    
    Il linker ricerca tali funzioni nelle librerie indicate: se le trova le collega, altrimenti restituisce dei messaggi di errore. In questo modo il linker genera il file eseguibile (.exe)

    Dopo tutto questo si può procedere con l'esecuzione del file .exe, controllando che sia tutto nella norma.
    */

    //adesso vediamo come compiere tutte queste azioni


    //EDITING DI UN PROGRAMMA
    /*Per modificare un programma ci sono Semplici editor di testo includono vim o gedit su Linux, o Notepad su Windows. Gli editor multi-piattaforma includono anche Visual Studio Code o Sublime Text.
    L'editor deve creare file di testo semplici, non in formato RTF o in qualsiasi altro formato.*/
    
    //COMPILAZIONE ED ESECUZIONE DEL PROGRAMMA
    /*Per la precompilazione, la compilazione, l'assemblaggio e il linker dobbiamo avere un compilatore C installato nel nostro sistema operativo.
    Si possono usare diversi tipi di compilatori:
    1)  Compila usando GCC (USATO ATTUALMENTE DA N1CKB)
        GCC (GNU Compiler Collection) è un compilatore C ampiamente utilizzato. Per utilizzarlo, apri un terminale, utilizza la riga di comando per navigare nella posizione del file sorgente e quindi esegui:
            gcc appunti.c -o appunti
        Se non vengono trovati errori nel codice sorgente (appunti.c), il compilatore creerà un file binario, il cui nome è dato dall'argomento dell'opzione della riga di comando -o (appunti in questo caso). Questo è il file eseguibile finale.
        Se non viene specificata l'istruzione -o nome_del_eseguibile in questo caso viene creato l'eseguibile con (di solito) il nome a.exe

        Possiamo anche utilizzare le opzioni di avviso -Wall -Wextra -Werror, che aiutano a individuare problemi che possono causare il fallimento del programma o produrre risultati inaspettati. Non sono necessari per questo semplice programma, ma puoi aggiungerli in questo modo:
            gcc -Wall -Wextra -Werror -o appunti appunti.c

    2)  Utilizzando il compilatore clang
        Per compilare il programma con clang, puoi usare:
            clang -Wall -Wextra -Werror -o appunti appunti.c
        Per progettazione, le opzioni della riga di comando di clang sono simili a quelle di GCC.
    
    3)  Utilizzo del compilatore Microsoft C dalla riga di comando
        Se si utilizza il compilatore Microsoft cl.exe su un sistema Windows che supporta Visual Studio e se tutte le variabili d'ambiente sono impostate correttamente, è possibile compilare questo esempio C utilizzando il seguente comando, che produrrà un file eseguibile hello.exe nella directory in cui viene eseguito il comando (Esistono opzioni di avviso come /W3 per cl, approssimativamente analoghe a -Wall, ecc., per GCC o clang).
            cl hello.c

    Esecuzione del programma:
    Una volta compilato, il file binario eseguibile può essere eseguito digitando `.\appunti` nel terminale nella stessa cartella dell'eseguibile. (il comando di default di visual studio code scrive & .\'appunti.exe', in cui & serve ad eseguire il programma in modo asincrono e in background)
    */

    //Vari editor danno la possibilità di eseguire in modo automatico tutti i passaggi dalla precompilazione all'esecuzione tramite comandi integrati nell'editor stesso, dunque senza interagire nel terminale direttamente.


    //ora che sappia compilare il file e lo sappiamo eseguire, scriviamo delle semplici istruzioni per iniziare:
    //Per poter stampare qualcosa in console usiamo varie funzioni da varie libreria, un esempio è la funzione puts();
    puts("Hello, World!"); //Questa riga chiama la funzione puts() per stampare del testo sull'output standard (che di solito corrisponde al display).
    //Dopo il testo, viene aggiunta una nuova riga. La stringa da stampare è inclusa tra le parentesi.
    puts("Una riga nel terminale");
    puts("Un'altra riga nel terminale");
    /*In C, ogni valore letterale di stringa deve essere racchiuso tra doppi apici "…".

    Nei programmi C, ogni istruzione deve essere terminata da un punto e virgola (cioè ";").
    */
    return 0;
    //La riga "return 0;" indica che, quando abbiamo definito la funzione main(), l'abbiamo dichiarata come una funzione che restituisce un valore di tipo int, il che significa che deve restituire un numero intero. In questo esempio, stiamo restituendo il valore intero 0, che viene utilizzato per indicare che il programma è uscito con successo. Dopo l'istruzione "return 0;", il processo di esecuzione terminerà.
    //adesso passa al prossimo file (appunti1.c) per le prossime lezioni
} 