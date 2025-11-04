#include <stdio.h>
#include <string.h>
#define N_MAX 100
/*
Scrivere un programma che, richieste all’utente le stringhe frase, parola1 e parola2, controlli se in frase è 
contenuta parola1, e in tal caso sostituisca tutte le sue occorrenze con parola2
*/
int main() {
    char frase[N_MAX], parola1[N_MAX], parola2[N_MAX];
    int i, j = 0, trovato = 0;
    printf("inserisci frase (< di %d caratteri): ", N_MAX);
    for (i = 0; ((frase[i] = getchar()) != '\n') && (i<N_MAX); i++);
    frase[i] = '\0';
    
    printf("inserisci parola1 (< di %d caratteri): ", N_MAX);
    scanf("%s", &parola1); //dobbiamo inserire solo una parola e quindi va bene scanf

    printf("inserisci parola2 (< di %d caratteri): ", N_MAX);
    scanf("%s", &parola2); //dobbiamo inserire solo una parola e quindi va bene scanf
    
    
    for (i = 0; frase[i]!='\0'; i++) {
        if (frase[i] == parola1[j]) {
            if (parola1[j+1]!=frase[i+1] || frase[i+1] == '\0') {
                trovato++;
                j = 0;
            }
            else j++;
        }
    }
    printf("ci sono %d occorrenze della parola '%s' nella frase ('%s')", trovato, parola1, frase);

   
    //VEDIIIIIIII
    

    
    
}