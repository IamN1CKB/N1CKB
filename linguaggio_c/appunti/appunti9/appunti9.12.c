#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//allochiamo dinamicamente una array in un sottoprogramma

float *allocaVet_noParametri(int l);
int allocaVet_conParametri(int l, float **vet);
void stampaVet(float *vet, int l);


int main(){
    int l;
    //allochiamo un vettore senza passarlo per parametri
    printf("decidi lunghezza del vet: ");
    scanf("%d", &l);
    float *vet;
    if ((vet = allocaVet_noParametri(l)) == NULL) {
        perror("allocazione non riuscita");
        return -1;
    }
    stampaVet(vet, l);
    free(vet);

    //usiamo il metodo passando per parametri
    printf("decidi lunghezza del vet: ");
    scanf("%d", &l);
    if (allocaVet_conParametri(l, &vet) == -1) {
        perror("ERR allocazione");
        return -1;
    }
    stampaVet(vet, l);
    free(vet);

   
}

float *allocaVet_noParametri(int l) {
    srand(time(NULL));
    float *vet = (float*) calloc(l, sizeof(float));      //dichiariamo l'array dinamico nel sottoprogramma e nel main
    if (vet == NULL) return NULL;
    for (int i = 0; i < l; i++)
        vet[i] = rand()%100;
    return vet;
}

int allocaVet_conParametri(int l, float **vet) {
    srand(time(NULL));
    *vet = (float*) calloc(l, sizeof(float));
    if (*vet == NULL) return -1;
    for (int i = 0; i < l; i++)
        (*vet)[i] = rand()%100;
    return 0;
}

void stampaVet(float *vet, int l) {
    printf("vet:\n");
    for (int i = 0; i < l; i++)
        printf("%.0f\t", vet[i]);
    printf("\n");
}
