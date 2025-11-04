#include <stdio.h>
#include <stdlib.h>
//facciamo l'allocazione dinamica di una struct
typedef struct {
    int campo1;
    float campo2;
    char campo3[50];
} struttura;

int main(){
    struttura *varStruct;
    varStruct = malloc(sizeof(struttura));
    if (varStruct == NULL) {
        perror("allocazione varStruct fallita");
        return -1;
    }
    
    varStruct->campo1 = 10;

    printf("campo1 = %d\n", varStruct->campo1);
    printf("scrivi qualcosa: ");
    fgets(varStruct->campo3, sizeof(varStruct->campo3), stdin);
    printf("campo3 = %s", varStruct->campo3);


    free(varStruct);

    //allochiamo dinamicamente un vettore di struct
    varStruct = calloc(10, sizeof(struttura));
    if (varStruct == NULL) {
        perror("allocazione varStruct fallita");
        return -1;
    }
    varStruct[1].campo1 = 2;
}