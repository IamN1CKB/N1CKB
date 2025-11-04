#include <stdio.h>
#define N 100
/*
Scrivere un programma che controlli se una stringa richiesta all’utente è palindroma. (Una stringa si dice palindroma 
se si legge nello stesso modo da sinistra verso destra e da destra verso sinistra. Sono esempi di stringhe palindrome: 
ANNA, radar, anilina.)
*/
int main() {
    char str[N];
    int i;
    //richiedi stringa
    printf("inserisci stringa: ");
    for (i = 0; (str[i]=getchar()) != '\n'; i++);
    str[i] = '\0';

    //calcoliamo la lunghezza della str
    int len = 0;
    i = 0;
    while (str[i++]!='\0') len++;
    
    //len è la lunghezza della parola ma io voglio l'indice dell'ultimo carattere, quindi vogliamo len - 1
    len--;
    int cond = 1;
    for (i = 0; i<len/2 && cond; i++)
        if (str[i] == str[len-i])
            cond = 1;
        else cond = 0;


        
    printf("'%s' ", str);
    if (!cond) printf("non ");
    printf("e' palindroma");
    
    
}