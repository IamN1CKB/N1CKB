#include <stdio.h>
#include <string.h>
//il main può avere dei parametri che di solito vengono chiamati argc e argv
void main(int argc, char* argv[]) {
    //queste variabili vengono passate dalla linea di comando quando viene eseguito il file eseguibile
    //int argc è il numero di parametri passati dalla linea di comando sul terminale
    printf("hai inserito %d parametro/i da linea di comando sul terminale\n", argc);
    //già solo scrivere '.\eseguibile' è considerato un parametro
    
    //invece argv è un array di stringhe, sempre fatto tramite i puntatori, e sarebbero i parametri che passi
    //da notare che non specifichiamo la dimensione dell'array di caratteri siccome viene ricavata sul momento dell'esecuzione su linea di comando
    //in base ai parametri che uno dà, possiamo personalizzare il nostro programma
    for (int i = 0; i < argc; i++) {
        printf("parametro %d: %s\n", i+1, argv[i]);
        if (strcmp (argv[i], "N1CKB") == 0)
            printf("INGEGNERE\n");
    }
    printf("\n");
    //avvia questo programma da terminale e dopo aver scritto il nome del programma scrivi altre parole: verranno stampate anch'esse a console.
    //fatto carino: se scrivi N1CKB stampa anche INGEGNERE
    /*
    inoltre le virgole (,) non vengono considerate nel terminale se a fine o inizio parole
    il punto e virgola (;) invece è considerato come un mezzo che separa due istruzioni in console. quindi se messo a fine istruzione viene
    ignorato, invece se messo in mezzo divide le due istruzioni, quindi deve essere richiamato il programma

    es: scriviamo su linea di comando (nella directory dell'eseguibile):
        .\appunti9.2 parola a caso, N1CKB ,caso a parola boh,virgola; .\appunti9.2 N1CKB altra esecuzione
    l'output che ci esce sarà:
        parametro 1: tutto il percorso\...\appunti9.2.exe
        parametro 2: parola
        parametro 3: a
        parametro 4: caso
        parametro 5: N1CKB
        INGEGNERE
        parametro 6: caso
        parametro 7: a
        parametro 8: parola
        parametro 9: boh,virgola

        hai inserito 4 parametro/i da linea di comando sul terminale
        parametro 1: tutto il percorso\...\appunti9.2.exe
        parametro 2: N1CKB
        INGEGNERE
        parametro 3: altra
        parametro 4: esecuzione

    */
}