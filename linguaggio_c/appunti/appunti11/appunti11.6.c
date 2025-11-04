#include <stdio.h>
#include <stdlib.h>
int main() {
    /*
    Esistono altre due funzioni, sscanf e sprintf, che eseguono le medesime conversioni di scanf e printf, ma 
    operando su stringa invece che su standard input e standard output. Il prototype di queste due funzioni è:
        int sprintf(char *s, char *format, arg1, arg2, ...)
        int sscanf(char *s, char *format, punt1, punt2, ...)
    La funzione sprintf è comunemente usata per scrivere in un determinato formato variabili C dentro una stringa
    la usiamo con una stringa statica, poi vediamo per una dinamica
    */
    char stringa[50];
    int len, n;
    printf("inserisci un numero: ");
    scanf("%d", &n);
    
    len = sprintf(stringa, "Il valore di n = %d", n);
    //dobbiamo stare attenti che ciò che sta nel sprintf non superi la dimensione massima della stringa
    printf("sprintf() ha scritto %d caratteri e il buffer contiene: %s\n", len, stringa);


    //invece se dobbiamo allocare dinamicamente dobbiamo fare operazioni in più che risultano inutili, ma almeno risparmiamo memoria
    char *str, let;
    //int len;        //già dichiarato
    printf("scegli una lettera: ");
    scanf(" %c", &let);
    len = printf("la lettera da te scelta e' '%c'", let);
    str = (char*) calloc(len+1, sizeof(char));
    //allochiamo dinamicamente per tutta la stringa e il +1 indica che si deve aggiungere il carattere \0
    len = sprintf(str, "la lettera da te scelta e' '%c'", let);



    //adesso però abbiamo stampato delle cose inutile su standard output, quindi torniamo indietro con \b
    for (int i = 0; i<len; i++) printf("\b");  //torniamo indietro con il puntatore alla stampa su console
    printf("str = %s\n", str);  //ristampiamo in modo da sovrascrivere la stampa precedente
    free(str);





    /*
    La funzione sscanf ha lo scopo di leggere dei caratteri da una stringa, s, che possiamo chiamare buffer di caratteri, 
    convertirli e memorizzarli nelle locazioni puntate da punt1, punt2, ... secondo il formato specificato dalla stringa 
    format. Per ciò che riguarda la specifica di formato valgono le medesime convenzioni di scanf.
    
    La funzione sscanf restituisce il numero di campi che sono stati letti, convertiti e assegnati a variabili con successo. 
    Se la stringa dovesse finire prima della fine dell’operazione di lettura, sscanf ritornerebbe il valore costante EOF, 
    definito in stdio.h.
    */
    char str1[] = "66 - 60 = 6";     //modifica la stringa se vuoi (in modo sensato, altrimenti c'è l'errore che abbiamo segnalato dopo)
    int operando1, operando2, risultato, n_immissioni;
    n_immissioni = sscanf(str1, "%d - %d = %d", &operando1, &operando2, &risultato);
    if (n_immissioni<= 0) {
        printf("ERR sscanf()");
        return -1;
    }
    printf("%s\n", str1);
    printf("immissioni = %d\n", n_immissioni);
    printf("operando1 = %d\n", operando1);
    printf("operando2 = %d\n", operando2);
    printf("risultato = %d\n", risultato);
}