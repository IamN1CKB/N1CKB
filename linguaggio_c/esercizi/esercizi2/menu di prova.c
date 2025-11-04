#include <stdio.h>
int main() {
    char scelta;
    printf("\tMENU DI PROVA\na) Per immettere i dati\nb) Per determinare il maggiore\nc) Per determinare il minore\nd) Per ordinare\ne) Per visualizzare\n");
    printf("Scelta: ");
    scelta = getchar();
    switch (scelta) {
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
        printf("In esecuzione l'opzione %c", scelta);
        break;
    default:
        printf("Opzione inesistente");
        break;
    }
}