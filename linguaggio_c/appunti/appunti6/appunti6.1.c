#include <stdio.h>
#define N_MAX 100
int main(){
    //Gli array di char sono più comunemente chiamati stringhe
    char stringa[100] = "boh, io che cazzo ne so?";
    printf("stringa[%d]: %c\n", 5, stringa[5]);
    //NOTA: i singoli caratteri necessitano di una inizializzazione con 'carattere' (singoli apici), invece la stringa "stringa" (doppi apici)
    //si possono inizializzare (se anche dichiarati) senza specificare la lunghezza
    char alfabeto[] = "abc";
    //questa stringa è formata da 4 elementi, in cui i primi 3 sono le lettere a b c, e l'ultimo è il carattere di fine stringa, ossia \0
    //\0 nella codifica ASCII corrisponde al primo carattere, quindi in decimale è 0
    printf("%c", alfabeto[3]);    //non stamperà nulla perché il carattere di fine stringa non è rappresentabile, ma possiamo verificare che c'è con le espressioni di controllo di visual studio o oppure con un if
    if (alfabeto[3] == '\0')
        printf("il carattere di fine riga c'è\n");   //viene stampato
    
    //notiamo inoltre le due differenziazioni:
    char a = 'a';     //variabile di tipo carattere 
    char b[] = "b";   //stringa di 2 elementi (b e \0)
    //se vogliamo considerare un elemento della stringa dobbiamo sempre mettere i singoli apici
    alfabeto[1] = 'B';     //adesso alfabeto è la stringa aBc (sempre con \0)

    //per fare delle operazioni su tutti i caratteri di un stringa bisogna quindi usare un ciclo che come condizione non ha più la lunghezza del vettore, ma la comparazione con \0
    //facciamo un programma che per ogni stringa dà il corrispettivo valore ASCII (in decimale, ottale ed esadecimale) di ogni carattere
    int i = 0;
    while (stringa[i] != '\0') {
        printf("stringa[%d] = %c =\t %d (decimale) =\t %o (ottale) =\t %x (esadecimale)\n", i, stringa[i], stringa[i], stringa[i], stringa[i]);
        i++;
    }
    //per stampare tutta la stringa possiamo usare il metodo tradizionale, ossia il ciclo
    i=0;
    printf("stringa: ");
    while (stringa[i]!='\0') {
        printf("%c", stringa[i]);
        i++;
    }
    //siccome è scomodo usare tutto questo, possiamo farlo in modo più compatto con il segnaposto %s senza iterazioni
    printf("\nstringa: %s\n", stringa);     //il vettore di carattere ossia la stringa deve essere senza []
    //in questo modo possiamo usare anche scanf
    char parola[N_MAX];  //dobbiamo per forza precisare la lunghezza siccome non la conosciamo prima di eseguire il codice
    printf("inserisci una parola: ");
    scanf("%s", &parola);  //questo metodo prende solo le singole parole, separate da spazio, poi vedremo per memorizzare più parole da console 
  

    //vediamo alcuni algoritmi utili per le stringhe
    //copiare una stringa in un altra stringa
    char str[N_MAX];
    i = 0;
    while (stringa[i]!='\0') {
        str[i] = stringa[i];
        i++;
    }
    //in questo caso però str non ha il valore di fine stringa \0, quindi se andiamo a fare
    printf("str: %s\n", str);
    //stamperà anche i valori successivi che non sono stati inizializzati, fino alla prossima \0 (di solito di default molti valori sono già così, infatti qualche volta il codice potrebbe andare e altre volte no)
    //dobbiamo fare in modo da copiare anche \0
    for (i = 0; (str[i] = stringa[i])!='\0'; i++);  //usando questa notazione, viene prima eseguita l'assegnazione e poi controllato se è !='\0
    printf("str: %s\n", str);
    /*
    in poche parole abbiamo usato una forma più compatta di questo algoritmo
        for(i=0; frase[i]!='\0'; i++)
            discorso[i]=frase[i];
        discorso[i]='\0';
    */
    

    //Se si desidera copiare soltanto alcuni caratteri della prima stringa sulla seconda si deve modificare l’istruzione for
    char frase[N_MAX];
    for (i = 0; ((frase[i] = stringa[i])!='\0') && (i<10); i++);   //prendo solo i primi 9 caratteri
    frase[i] = '\0';   //il fine stringa non viene copiato, quindi lo inserisco io
    //stampa
    printf("frase spezzata: %s\n", frase);

    //se si desidera invece aggiungere a una stringa i caratteri presenti in un altra stringa:
    char frase1[N_MAX] = "Ciao, sono Nicola";
    printf("frase1: %s\n", frase1);
    //aggiungiamo i caratteri della stringa:
    char cognome[] = " Belardo";
    //vogliamo aggiungere il cognome dopo la stringa frase1, dunque dobbiamo calcolare la lunghezza di frase1
    for (i = 0; frase1[i]!='\0'; i++);
    //adesso abbiamo il valore i che è la lunghezza
    for (int j = 0; (frase1[i] = cognome[j])!='\0'; j++, i++);
    printf("frase1: %s\n", frase1);

        

    

}