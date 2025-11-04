#include <stdio.h>
#include <stdlib.h>

/*se vogliamo allocare qualcosa dinamicamente in un sottoprogramma e vogliamo che venga anche riportato nel main possiamo usare
2 strategie:
    1) dichiarare il puntatore nel sottoprogramma, e riportare il puntatore per ogni chiamata del main
    2) dichiarare il puntatore nel main, e passare il puntatore al puntatore come parametro
vediamo i due casi
*/
char *allocaLettera(); //restituisce il puntatore, ossia la variabile dinamica
int allocaLetParametro(char ** let);  //dato che vogliamo allocare a quel puntatore preciso, passiamo il puntatore del puntatore

int main() {
    //metodo 1
    char *lettera;
    if ((lettera = allocaLettera()) == NULL) { //diamo a lettera l'indirizzo del ritorno, se è diverso da NULL: allocazione riuscita
        perror("ERR allocazione senza parametro");
        return -1;
    }
    printf("hai scritto '%c'\n", *lettera);
    //questo metodo utilizza un'altra variabile puntatore nel sottoprogramma che è risparmiata dal prossimo metodo: questo primo metodo
    //non è molto consigliata


    //metodo 2
    char *lettera2;
    if (allocaLetParametro(&lettera2) == -1) {
        perror("ERR allocazione con parametro");
        return -1;
    }
    printf("hai scritto '%c'\n", *lettera2);
    
}

char *allocaLettera() {
    char *let = (char*) malloc(sizeof(char));  //questo metodo fa dichiarare 2 puntatori per una stessa cosa
    if (let == NULL) return NULL;               //  è scomodo
    printf("che lettera vuoi allocare?: ");
    scanf("%c", let);
    return let;
}


int allocaLetParametro(char ** let) {
    (*let) = malloc(sizeof(char));
    if (*let == NULL) return -1;
    printf("che lettera vuoi allocare?: ");
    scanf(" %c", *let);
}