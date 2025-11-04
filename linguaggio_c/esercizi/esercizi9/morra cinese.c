#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int convertiScelta(char);
char CPU();
int vincitore(char, char);

void main() {
    int modalità, vittoria;
    char scelta1, scelta2;
    char* opzioni[3] = {"carta", "forbici", "sasso"};
    printf("MORRA CINESE\n");
    printf("decidi che modalita' usare per giocare:\n1 per modalita' single player\n2 per modalita' multi-giocatore\n");
    printf("inserisci la modalita': ");
    scanf("%d", &modalità);


    switch (modalità) {
    case 1:
        printf("modalita' single player attivata\n");
        printf("cosa scegli (inserisci le iniziali)? carta (c), forbice (f) o sasso (s)? ");
        scanf(" %c", &scelta1);
        if (convertiScelta(scelta1) != -1) {
            scelta2 = CPU();
            printf("Utente:  \t%s\n\n", opzioni[convertiScelta(scelta1)]);
            printf("Computer:\t%s\n\n", opzioni[convertiScelta(scelta2)]);
            vittoria = vincitore(scelta1, scelta2);
            if (vittoria) {
                if (vittoria == 1) printf("il vincitore e' l'utente\n");
                else printf("il vincitore e' il computer");
            }   
            else
                printf("pareggio\n");
        }
        else printf("input errato\n");
        break;
    case 2:
        printf("modalita' multi-giocatore attivata\n");
        printf("cosa sceglie il giocatore 1 (inserisci le iniziali)? carta (c), forbice (f) o sasso (s)? ");
        scanf(" %c", &scelta1);
        if (convertiScelta(scelta1) != -1) {
            printf("cosa sceglie il giocatore 1 (inserisci le iniziali)? carta (c), forbice (f) o sasso (s)? ");
            scanf(" %c", &scelta2);
            if (convertiScelta(scelta2) != -1){
                printf("giocatore 1: %s\n\n", opzioni[convertiScelta(scelta1)]);
                printf("giocatore 2: %s\n\n", opzioni[convertiScelta(scelta2)]);
                vittoria = vincitore(scelta1, scelta2);
                if (vittoria) {
                    if (vittoria == 1) printf("il vincitore e' il giocatore 1\n");
                    else printf("il vincitore e' il giocatore 2\n");
                }
                else
                    printf("pareggio\n");
                
            }
            else printf("input giocatore 2 non valido\n");
        }
        else printf("input giocatore 1 non valido\n");
        
        break;
    default:
        printf("input sbagliato\n");
        break;
    }
}

char CPU() {
    srand(time(NULL));
    char CPU;
    //valori randomici tra 0 1 e 2
    switch (rand()%3) {
    case 0:
        CPU = 'c';
        break;
    case 1:
        CPU = 'f';
        break;
    case 2:
        CPU = 's';
        break;
    }
    return CPU;
}

int convertiScelta(char scelta) {
    switch (scelta) {
    case 'c':
        return 0;   //se lo consideriamo come indice del puntatore a char ci prende la stringa carta
        break;
    case 'f':
        return 1;   //se lo consideriamo come indice del puntatore a char ci prende la stringa forbici
        break;
    case 's':
        return 2;   //se lo consideriamo come indice del puntatore a char ci prende la stringa sasso
        break;
    default:
        return -1;  //con questo controlliamo anche se l'input è valido
        break;
    }
}

int vincitore(char scelta1, char scelta2) {
    if (scelta1 == scelta2) return 0; //pareggio
    else {
        if ((scelta1 == 's' && scelta2 == 'f') || (scelta1 == 'c' && scelta2 == 's') || (scelta1 == 'f' && scelta2 == 'c'))
            return 1;  //scelta1 vince
        else
            return 2;   //scelta2 vince
    }
}