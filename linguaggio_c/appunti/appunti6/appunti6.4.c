#include <stdio.h>
#include <string.h>
#define N_MAX 100
int main() {
    //esistono però delle funzioni nella libreria string.h che permettono di effettuare operazioni con le stringhe
    //Come al solito, è sufficiente dichiarare il riferimento a tale libreria all’inizio del programma per poter utilizzare le funzioni in essa contenute.
    char stringa1[N_MAX], stringa2[N_MAX], n, i;
    printf("inserisci stringa1 (< di %d caratteri e manda a capo per concludere): ", N_MAX);
    for (i = 0; (stringa1[i] = getchar())!='\n' && (i<N_MAX); i++);
    stringa1[i] = '\0';
    printf("stringa1 = %s\n", stringa1);
    
    
    //La funzione strcpy consente di copiare stringa1 su stringa2:
    //strcpy(stringa_di_destinazione, stringa_di_arrivo);
    strcpy(stringa2, stringa1);
    printf("stringa2 = %s\n", stringa2);
    
    //La funzione strncpy permette invece di copiare i primi n caratteri di stringa2 in stringa1:
    printf("inserisci un altro valore di stringa1 (< di %d caratteri e manda a capo per concludere): ", N_MAX);
    for (i = 0; (stringa1[i] = getchar())!='\n' && (i<N_MAX); i++);
    stringa1[i] = '\0';
    printf("Decidi quanti caratteri copiare in stringa2 (<%d): ", i);
    scanf("%d", &n);
    strncpy(stringa2, stringa1, n);
    printf("stringa2 = %s\n", stringa2);
    printf("forse ci può essere un errore siccome aveva gia un valore precedente e il fine stringa può esserci dopo l'elemento di indice n = %d\n", n);
    stringa2[n] ='\0';
    printf("stringa2 = %s\n", stringa2);

    
    //mentre la funzione strcat consente di concatenare stringa2 a stringa1:
    //strcat(stringa1, stringa2);
    
    printf("inserisci 2 frasi da concatenare:\nfrase1: ");
    getchar();  //la prossima istruzione getchar viene consumata da un \n, per questo inseriamo questo getchar per consumare \n
    for (i = 0; (stringa1[i] = getchar())!='\n' && (i<N_MAX); i++);
    stringa1[i] = '\0';
    printf("frase2: ");
    for (i = 0; (stringa2[i] = getchar())!='\n' && (i<N_MAX); i++);
    stringa2[i] = '\0';
    strcat(stringa1, stringa2);
    printf("frase concatenata: %s\n", stringa1);



    //La funzione strcmp serve a confrontare stringa2 con stringa1 (Listato 6.6):
    //Se risultano essere uguali viene restituito zero, se stringa1 è maggiore di stringa2 viene restituito un valore 
    //positivo, altrimenti un valore negativo 
    strcmp(stringa1, stringa2);

    //vediamo un codice per confrontare le frasi
    printf("inserisci 2 frasi da confrontare:\nfrase1: ");
    //getchar();  //in questo caso non so perché non serve
    for (i = 0; (stringa1[i] = getchar())!='\n' && (i<N_MAX); i++);
    stringa1[i] = '\0';
    printf("frase2: ");
    for (i = 0; (stringa2[i] = getchar())!='\n' && (i<N_MAX); i++);
    stringa2[i] = '\0';
    int compare = strcmp(stringa1, stringa2);
    if (compare == 0)
        printf("le stringhe sono uguali");
    else
        if (compare>0)
            printf("frase1 è maggiore di stringa2");
        if (compare<0)
            printf("frase2 è maggiore di stringa1");
    //considera sempre i valori della tabella ASCII (maiuscole < minuscole)

}