#include <stdio.h>
#define N 100
/*
Scrivere un programma che, letta una stringa composta da sole lettere dell’alfabeto, visualizzi il numero delle 
vocali, quello delle consonanti e la lettera più frequente.
*/
int main() {
    char str[N], a;
    printf("inserisci stringa con sole lettere dell'alfabeto (nemmeno spazi): ");
    int i;
    for (i = 0; ((str[i]=getchar())!='\n') && ((str[i]>='a'&& str[i]<='z')||(str[i]>='A'&&str[i]<='z')); i++);
    str[i]='\0';
    printf("la stringa con solo lettere dell'alfabeto è: %s\n", str);

    int vocali=0, consonanti=0, cont=0, max=0;
    char frequente;
    for (i = 0; str[i]!='\0'; i++) {
        //controllo vocali e consonanti
        if ((str[i] == 'a')||(str[i] == 'e')||(str[i] == 'i')||(str[i] == 'o')||(str[i] == 'u')||(str[i] == 'A')||(str[i] == 'E')||(str[i] == 'I')||(str[i] == 'O')||(str[i] == 'U'))
            vocali++;
        else consonanti++;


        //controllo lettera più frequente
        cont = 0;
        for (int j = 0; str[j] != '\0'; j++)
            if (str[j] == str[i]) cont++;
        if (cont>max) {
            max = cont;
            frequente = str[i];
        }
    }
    
    printf("ci sono %d vocali e %d consonanti\n", vocali, consonanti);
    printf("la lettera più frequente è '%c', apparsa %d volte", frequente, max);
    
    
}