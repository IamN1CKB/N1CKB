/*
data una stringa dobbiamo verificare se un carattere si trova dentro
*/
#include <stdio.h>
#include <stdlib.h>
#define N 100
void strEChar(char str[], char* x);
int cercaChar(char str[], char x);

void main(){
    char str[N], x;
    strEChar(str, &x);

    int j = cercaChar(str, x);
    if (j == -1)
        printf("l'elemento %c non e' presente nella stringa\n", x);
    else
        printf("l'elemento %c e' presente nella stringa nella posizione %d\n", x, j);
    

}

void strEChar(char str[], char* x) {
    int i;
    printf("inserisci stringa: ");
    fgets(str, N, stdin);
    printf("inserisci carattere da cercare: ");
    scanf("%c", x);
    for (i = 0; str[i]!='\n'; i++);
    str[i] = '\0';
    
}

int cercaChar(char str[], char x) {
    int i;
    for (i = 0; (str[i]!='\0') && (str[i]!=x); i++);
    if (str[i]=='\0') return -1;
    else return i;
}