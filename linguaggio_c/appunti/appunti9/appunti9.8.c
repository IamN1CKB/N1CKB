#include <stdio.h>
#include <string.h>

int main() {
    //i puntatori vengono usati sempre per passare i parametri alle funzioni, e grazie a quest'ultimi ora possiamo capire ulteriori funzioni di string.h

    /*la funzione strstr della libreria string.h in C viene utilizzata per trovare la prima occorrenza di una sotto-stringa all'interno di una 
    stringa principale. Ecco la sua firma:

    char *strstr(const char *_Str, const char *_SubStr);
    _Str: La stringa in cui cercare la sotto-stringa.
    _SubStr: La sotto-stringa da cercare all'interno della stringa principale.
    
    La funzione restituisce un puntatore al primo carattere della prima occorrenza di _SubStr all'interno di _Str. Se la sotto-stringa non
    viene trovata, la funzione restituisce NULL.
    Il valore di ritorno non include un carattere di terminazione alla fine dell'occorrenza.

    Ecco un esempio di utilizzo di strstr:
    */
        
    char *str = "Questo e' un esempio di utilizzo di strstr";   //ricorda che in questo modo sono stringhe che possiamo vedere solo in lettura
    char *sottoStr = "esempio";

    char *result = strstr(str, sottoStr);
    printf("str = %s\n", str);
    printf("sottoStr = %s\n", sottoStr);
    printf("result = %s\n", result);    //dato che result dà il puntatore al primo carattere della prima occorrenza della sotto-stringa (senza 
                                        //aggiungere nessun carattere di terminazione), questa istruzione stampa dalla prima occorrenza della 
                                        //sotto-stringa fino alla fine della stringa

    if (result != NULL)
        printf("La sotto-stringa \"%s\" è stata trovata in posizione %d nella stringa \"%s\"\n", sottoStr, result - str, str);
        //result - str è una sottrazione tra puntatori, e ci indica così in che posizione nell'array di caratteri si trova il primo carattere 
        //della prima occorrenza
    else
        printf("La sotto-stringa \"%s\" non è stata trovata\n", sottoStr);
    /*
    In questo esempio, strstr viene utilizzata per cercare la sotto-stringa "esempio" all'interno della stringa "Questo è un esempio di utilizzo 
    di strstr". Se la sotto-stringa viene trovata, viene stampata la posizione della sua prima occorrenza all'interno della stringa principale.
    Ricorda che strstr cerca una corrispondenza esatta della sotto-stringa. Se desideri cercare una sotto-stringa considerando maiuscole e 
    minuscole, potresti voler utilizzare altre funzioni come strcasestr (se supportato dal tuo compilatore) o convertire entrambe le stringhe in 
    minuscolo o maiuscolo prima di chiamare strstr.


    inoltre result è un puntatore a una parte dell'array, quindi nel caso in cui modifichiamo result, si modifica anche la stringa (nel caso in 
    cui è dichiarata come array di caratteri e non come puntatore: non è il nostro caso)
    */

    char stringa[] ="This is a simple string";
    result = strstr (stringa, "simple");
    printf("result = %s\n", result);
    if (result != NULL)
        strncpy (result,"sample",6);
    puts(stringa);
    //in questo modo abbiamo modificato anche la stringa iniziale




    //FUNZIONE STRTOK
    /*
    La funzione `strtok` (string token) in C è utilizzata per suddividere una stringa in sottostringhe (token) basandosi su un set di 
    delimitatori specificato. La firma della funzione è la seguente:
        char *strtok(char *str, const char *delimiters);
    - str: La stringa da suddividere. Per la prima chiamata, passa la stringa originale. Per le chiamate successive, passa `NULL` per 
    continuare a suddividere la stessa stringa.
    - delimiters: Una stringa contenente tutti i caratteri che devono essere considerati delimitatori. I caratteri inclusi in questa stringa 
    verranno utilizzati per separare la stringa in token.

    La funzione restituisce un puntatore alla prima parte del token trovato. Quando tutti i token sono stati estratti, la funzione restituisce 
    NULL.

    Ecco un esempio di utilizzo di `strtok`:
    */

    char stringa2[] = "Questo è un esempio, di utilizzo di strtok";
    char delimiters[] = " ,"; // Delimitatori: spazio e virgola

    // Prima chiamata
    char *token = strtok(stringa2, delimiters);

    // Continua a chiamare finché ci sono token
    while (token != NULL) {
        printf("Token: %s\n", token);
        printf("puntatore del Token: %p\n\n", token);
        token = strtok(NULL, delimiters); // Passa NULL per continuare con la stessa stringa
    }
    /*

    In questo esempio, la stringa "Questo è un esempio, di utilizzo di strtok" viene suddivisa in token basati su spazi e virgole come delimitatori. Ogni token viene stampato a schermo. Nota che `strtok` modifica la stringa originale inserendo caratteri null ('\0') per terminare ciascun token.

    Attenzione: `strtok` è una funzione non thread-safe e può causare problemi in un ambiente multithreading. In alternativa, puoi considerare l'utilizzo di `strtok_r` (se disponibile), che è una versione thread-safe di `strtok`.

    se volessimo salvare tutti i token in memoria, potremmo usare un array di puntatori a char (detto anche array di stringhe)
    */
    char str1[] = "parole completamente a caso, e non so che dire";   //attenzione a usare più di una volta strtok con la stessa stringa, siccome si bugga (ne crea un altra per questo motivo)
    int cont = 0; 
    char *tokens[100];
    tokens[cont] = strtok(str1, " ,");
    while (tokens[cont] != NULL)
        tokens[++cont] = strtok(NULL, " ,");

    for (int i = 0; i < cont; i++)
        printf("token %d: %s\n", i, tokens[i]);

    //ora possiamo anche rispondere a un altra domanda, il valore di ritorno di strtok è un puntatore a altro array di caratteri
    //oppure coincide con i puntatori ai caratteri della stringa originale?
    printf("puntatore del primo token (parola: %s): %p\n", tokens[0], tokens[0]);
    printf("puntatore della stringa (%s): %p\n", str1, str1);
    if (tokens[0] == str1)
        printf("sono gli stessi\n");
    //da qui abbiamo capito che strtok modifica direttamente la stringa originale e posiziona \0 al posto dei delimitatori
    //se vogliamo riusare la stringa originale, dopo l'uso di strtok, essa si è limitata al primo token (prima parola)
    //quindi se la stringa è importante anche per il futuro, dobbiamo copiarla in un altra stringa per salvarcela.

    
    
}
