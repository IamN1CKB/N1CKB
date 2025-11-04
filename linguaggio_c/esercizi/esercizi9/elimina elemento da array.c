/*eliminiamo o inseriamo un elemento da un vettore*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100


void inserimentoArray(int vet[], int* n);
void stampaVet(int vet[], int n);
void inserisciElemento(int vet[], int *pn, int pos);
void eliminaElemento(int vet[], int *pn, int pos);

void main(){
    int vet[N], l, decisione, pos;
    char continua = 's';
    inserimentoArray(vet, &l);
    stampaVet(vet, l);
    do {
        printf("\nscegli cosa far fare al vettore:\n");
        printf("1 per inserire un elemento a una determinata posizione\n");
        printf("2 per eliminare un elemento a una determinata posizione\n");
        printf("inserisci opzione: ");
        scanf("%d", &decisione);
        switch (decisione) {
        case 1:
            printf("a che posizione vuoi inserire l'elemento? ");
            scanf("%d", &pos);
            inserisciElemento(vet, &l, pos);
            stampaVet(vet, l);
            break;
        case 2:
            printf("a che posizione vuoi eliminare l'elemento? ");
            scanf("%d", &pos);
            eliminaElemento(vet, &l, pos);
            stampaVet(vet, l);
            break;
        default:
            printf("opzione sbagliata\n");
            break;
        }
        printf("\nvuoi continuare? scrivi s per continuare, e qualsiasi altra cosa per non continuare: ");
        scanf(" %c", &continua);
    } while (continua == 's');
    
}

void inserimentoArray(int vet[], int* n) {
    srand(time(NULL));
    printf("inserisci lunghezza vet: ");
    scanf("%d", n);
    for (int i = 0; i<*n; i++)
        vet[i] = rand()%100;
}
void stampaVet(int vet[], int n) {
    printf("vet:   ");
    for (int i = 0; i < n; i++)
        printf("%d\t", vet[i]);
    printf("\n");
}

void inserisciElemento(int vet[], int *pn, int pos) {
    int i = *pn+1;
    int x;
    while (i-->pos)
        vet[i] = vet[i-1];
    *pn= *pn + 1;
    printf("decidi l'elemento da inserire: ");
    scanf("%d", &x);
    vet[pos] = x;
}

void eliminaElemento(int vet[], int *pn, int pos) {
    int i = pos;
    while (i<*pn) {
        vet[i] = vet[i+1];
        i++;
    }
    *pn = *pn - 1;
}