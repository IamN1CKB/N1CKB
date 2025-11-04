#include <stdio.h>
#include <string.h>
#define N_MAX 100
int main() {
    char str[N_MAX];
    printf("inserisci stringa: ");
    fgets(str, N_MAX, stdin);
    int conta = 0;
    for (int i = 0; str[i] !='\0'; i++)
        if ((str[i] != ' ')  && ((str[i+1] == ' ') || (str[i+1] == '\0')))
            conta++;

    printf("ci sono %d parole\n", conta);
    //c'è un problema: nel caso in cui la stringa finisce con uno spazio gli ultimi 2 caratteri della stringa sono \n\0, e siccome \n è diverso da uno spazio lo conta come una parola in più. ad esempio "ciao " lo conterebbe come 2 parole
    //per evitare ciò ci sono varie strade:
    //1) usare il ciclo di getchar invece di fgets (soluzione intuitiva che non faccio vedere)
    //2) aggiungere una condizione in più all'if in modo che str[i] sia diverso da \n
    conta = 0;
    for (int i = 0; str[i] !='\0'; i++)
        if (((str[i] != ' ') && (str[i]!= '\n'))  && ((str[i+1] == ' ') || (str[i+1] == '\0')))
            conta++;
    printf("ci sono %d parole\n", conta);
    //3) sovrascrivere lo \n con \0 
    str[strcspn(str, "\n")] = '\0'; // Rimuove il carattere newline da fgets

    //5) altre soluzioni che non mi vengono in mente


}