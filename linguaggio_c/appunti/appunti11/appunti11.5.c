#include <stdio.h>
#include <stdlib.h>

int main(){
    /*
    Abbiamo ripetutamente utilizzato negli esempi la funzione di immissione dati, scanf, e quella di visualizzazione, 
    printf. La sintassi di queste funzioni è stata usata solo sommariamente, ed è ora giunto il momento di definirla (in 
    questo paragrafo e nel prossimo) in modo più completo e generale. 
    La sintassi della funzione printf è:
        int printf(char *format, arg1, arg2, ...)
    La funzione printf converte, ordina in un formato e stampa sul video (detto standard output ) un numero variabile 
    di argomenti arg1, arg2, ... sotto il controllo della stringa format. Questa stringa dettaglia due diverse 
    informazioni: un insieme di caratteri ordinari, che vengono direttamente inviati sul video, e una specifica di conversione 
    per ognuno degli argomenti da visualizzare. Ogni specifica di conversione inizia con il carattere % e termina con il 
    carattere di conversione.
    Ecco un elenco dei caratteri di conversione più comuni utilizzati con `printf` in C:
        - `%d` o `%i`: Per numeri interi in base 10.
        - `%o`: Per numeri interi in base 8 (ottale).
        - `%x` o `%X`: Per numeri interi in base 16 (esadecimale). `x` produce lettere minuscole e `X` produce lettere maiuscole.
        - `%u`: Per numeri interi senza segno.
        - `%c`: Per un singolo carattere.
        - `%s`: Per una stringa di caratteri.
        - `%f`: Per numeri a virgola mobile.
        - `%e` o `%E`: Per numeri a virgola mobile in formato scientifico. `e` produce `e` minuscola e `E` produce `E` maiuscola.
        - `%g` o `%G`: Per numeri a virgola mobile in formato `f` o `e`.
        - `%p`: Per un puntatore.
        - `%%`: Per stampare il carattere `%`.

    la precisione è specificata dopo un punto `.` nelle specifiche di formato di `printf`. Può essere utilizzata per controllare il numero di cifre dopo il punto decimale per i numeri a virgola mobile, o il numero minimo di cifre da visualizzare per i numeri interi.

    Ecco come funziona la precisione con diversi caratteri di conversione:
        - `%d`, `%i`, `%o`, `%u`, `%x`, `%X`: La precisione specifica il numero minimo di cifre da visualizzare.
        Se il numero di cifre nel valore di output è inferiore alla precisione specificata, il valore viene riempito con zeri sulla sinistra.
        Ad esempio, `printf("%.5d", 123);` produrrà `00123`.
        - `%f`, `%F`, `%e`, `%E`: La precisione determina il numero di cifre da visualizzare dopo il punto decimale.
        Ad esempio, `printf("%.2f", 123.456);` produrrà `123.46`.
        - `%g`, `%G`: La precisione rappresenta il numero massimo di cifre significative da visualizzare.
        - `%s`: La precisione determina il numero massimo di caratteri da stampare da una stringa.
        Ad esempio, `printf("%.3s", "Hello");` produrrà `Hel`.

    I modificatori di lunghezza in C sono utilizzati nelle specifiche di formato di `printf` per indicare il tipo di dato dell'argomento    corrispondente. Ecco un elenco dei modificatori di lunghezza più comuni:
        - `hh`: L'argomento corrispondente è di tipo `signed char` o `unsigned char`.
        - `h`: L'argomento corrispondente è di tipo `short int` o `unsigned short int`.
        - `l` (elle minuscola): L'argomento corrispondente è di tipo `long int`, `unsigned long int`,
         `double` (per `%a`, `%A`, `%e`, `%E`, `%f`, `%F`, `%g`, o `%G`).
        - `ll` (elle elle): L'argomento corrispondente è di tipo `long long int` o `unsigned long long int`.
        - `L` (elle maiuscola): L'argomento corrispondente è di tipo `long double`.

    Ricorda, l'uso improprio dei modificatori di lunghezza può portare a comportamenti indefiniti. Assicurati sempre che il tipo di dato dell'argomento corrisponda al carattere di conversione utilizzato

    */
    //La printf ritorna il numero di caratteri che ha visualizzato.
    int l = printf("Nicola\n");
    printf("la stampa di prima ha %d caratteri\n", l);  //sono 7, incluso \n (unico carattere)
    
    
    
    //FUNZIONE SCANF()
    /*
    La sintassi di scanf è:
        int scanf(char *format, puntat1, puntat2, ...)
    La funzione scanf legge un insieme di caratteri da tastiera (detta standard input ), li interpreta secondo il formato 
    specificato dalla stringa format e li memorizza negli argomenti puntati da puntat1, puntat2 ecc. La stringa di 
    formato, detta anche controllo, contiene le specifiche di conversione, che sono usate da scanf per interpretare la 
    sequenza di immissione. Nel controllo possono essere presenti i simboli riportati nei punti successivi:
        • caratteri vuoti (blank, tab, newline, formfeed), che sono ignorati;
        • caratteri normali escluso %, che dovrebbero coincidere con il prossimo carattere non vuoto della sequenza di 
        ingresso;
        • le specifiche di conversione formate dal carattere %
    
    La funzione scanf ritorna il numero di immissioni che è riuscita a concludere con successo. Questo numero può anche 
    essere zero, nel caso in cui si verifichi immediatamente un conflitto tra un carattere in immissione e la stringa di 
    controllo. Se l’immissione si conclude prima del primo conflitto o della prima conversione, scanf restituisce un EOF. 
    Esempi classici di uso di scanf sono:
    */
    int n, x, y, n_numeri;
    float w;
    printf("inserisci un numero: ");
    n_numeri = scanf("%d %d %d %f", &n, &x, &y, &w);
    //se inseriamo delle lettere al posto dei numeri, non verranno salvati bene i valori, e non tutti (prova)
    if (n_numeri == 0 || n_numeri == EOF) {
        printf("ERR scanf");
        return -1;
    }
    printf("i numeri presi sono: %d\n", n_numeri);


}