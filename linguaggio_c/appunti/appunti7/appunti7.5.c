//facciamo un esempio di programma con le funzioni ordinando un vettore

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

int vet[N]; //definiamo questo array come variabile globale in modo da poter essere gestito da ogni funzione (vedremo con i puntatori una soluzione migliore)
int indici_x[N], ordinato = 0;

void generazione_array(int l);  //l = riempimento vet ()
void ordinamento_array(int l);
int ricerca_completa(int l);
int ricerca_binaria(int l);
void stampa_array(int l);

void main() {
    int l, decisione;
    printf("decidi la lunghezza dell'array (<%d): ", N);
    scanf("%d", &l);

    printf("decidi cosa fare:\n1 per generare valori casuali dell'array\n2 per ordinare l'array\n3 per compiere una ricerca completa\n4 per compiere una ricerca binaria (solo se il vettore è ordinato)\n5 per stampare l'array\nqualsiasi numero per terminare");
    do {
        printf("\nscegli un opzione: ");
        scanf("%d", &decisione);
        switch (decisione) {
        case 1:
            generazione_array(l);
            break;
        case 2:
            ordinamento_array(l);
            break;
        case 3:
            ricerca_completa(l);
            break;
        case 4:
            ricerca_binaria(l);
            break;
        case 5:
            stampa_array(l);
            break;
        default:
            decisione = 0;
            break;
        }
        printf("\n");
    } while (decisione);
    printf("grazie e arrivederci!");
}



void generazione_array(int l) {
    srand(time(NULL));
    for (int i = 0; i < l; i++)
        vet[i] = rand()%100;
    ordinato = 0;
}


void ordinamento_array(int l) {
    int p, condizione, temp;
    do {
        condizione = 0;
        for (int i = 0; i < l; i++) {
            if (vet[i]>vet[i+1]) {
                temp = vet[i];
                vet[i] =vet[i+1];
                vet[i+1] = temp;
                condizione = 1;
                p = i + 1;
            }
        }
        l = p;    //il valore di l cambia nella funzione, ma non nel main, siccome per cambiare un valore di una variabile ci serviranno i puntatori, che poi vedremo
    } while (condizione);
    ordinato = 1;
}


int ricerca_completa(int l) {
    int x, trovato = 0;
    printf("inserisci carattere da cercare nel vettore non ordinato: ");
    scanf("%d", &x);

    for (int i = 0; i < l; i++)
        if (vet[i]==x) indici_x[trovato++] = i;

    if (trovato) {
        printf("ci sono %d occorrenze di %d\n", trovato, x);
        printf("gli indici sono: ");
        for (int i = 0; i < trovato; i++) printf("%d ", indici_x[i]);
    }
    else printf("elemento %d non trovato nel vettore", x);
    
    printf("\n");
    return trovato;
}


int ricerca_binaria(int l) {
    if (ordinato) {
        int x, a=0, b=l-1, m;
        printf("inserisci il valore da trovare nell'array ordinato (solo la prima occorrenza): ");
        scanf("%d", &x);
        do {
            m = (a+b)/2;
            if (x == vet[m])
                indici_x[0] = m;
            else
                if (x>vet[m]) a = m+1;
                else b = m-1;
        } while (a<=b && vet[m]!=x);
        
        if (a<=b) {
            printf("valore trovato all'indice %d\n", indici_x[0]);
            return indici_x[0];
        }
        else {
            printf("valore non trovato\n");
            return -1;
        }
    }
    else {
        printf("vettore non ordinato\n");
        return -1;
    }
}


void stampa_array(int l) {
    printf("vet: ");
    for (int i = 0; i < l; i++) printf("%d ", vet[i]);
    printf("\n");
    
}