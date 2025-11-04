/*se vogliamo allocare dinamicamente una stringa inserita da console, dobbiamo usare ciclicamente realloc
in modo da aumentare lo spazio allocato ogni volta che si inserisce un nuovo carattere
per fare ciò abbiamo bisogno di usare l'inserimento in input ciclico con getchar
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    int i;
    char *str = malloc(2*sizeof(char));  //allochiamo lo spazio solo per un carattere e lo \0
    if (str == NULL) {
        perror("allocazione fallita");
        return -1;
    }
    for (i = 0; (str[i] = getchar())!='\n'; i++) {
        str = realloc(str, (i+2)*sizeof(char));   //allochiamo uno spazio in modo da contenere i+2 caratteri
        //i+2 perché all'inizio i vale 0, e se ci fermiamo a un solo carattere, dobbiamo salvare il carattere scritto e lo \0
        if (str == NULL) {
            perror("allocazione fallita");
            return -1;
        }
    }
    str[i] = '\0';
}