#include <stdio.h>
#define N_MAX 100
int main() {
    //adesso confrontiamo 2 stringhe e vediamo quale delle 2 è maggiore (quale viene scritta dopo in ordine dei caratteri ASCII)
    char frase1[N_MAX] = "caccia";
    char frase2[N_MAX];
    int i, j = 0;
    printf("prima frase: %s\n", frase1);
    printf("Inserisci la seconda frase (manda a capo per concludere): ");
    for (i=0; ((frase2[i]=getchar())!='\n') && (i<N_MAX); i++);
    frase2[i] = '\0';
    for (i = 0; (frase1[i] == frase2[i]) && (frase2[i]!= '\0') && (frase1[i] != '\0'); i++);
    //questo codice ti confronta le due stringhe fin quando: le due stringhe sono uguali, le 2 stringhe non finiscono
    //ora ci sono vari casi:
   
    
    if (frase1[i] == frase2[i]) {
        printf("caso 1: le due stringhe sono uguali");
        j = 1;
    }
    else {
        if (frase1[i]>frase2[i]) {
            printf("la prima frase viene dopo della seconda frase\n");
            if (frase2[i] != '\0')
                printf("caso 2: le due frasi sono diverse gia' dalle prime lettere");   //es frase2 = arco
            else
                printf("caso 3: la seconda frase e' più piccola della prima e hanno le prime lettere uguali fino alla fine della seconda frase");  //es frase2 = cacci
            j = 1;
        }
        if (frase1[i]<frase2[i]) {
            printf("la prima frase viene dopo della seconda frase\n");
            if (frase1[i] != '\0')
                printf("caso 4: le due frasi sono diverse gia' dalle prime lettere");    //es frase2: zebra
            else
                printf ("caso 5: la seconda frase e' più lunga della prima e hanno le prime lettere uguali fino alla fine della prima frase");    //es frase2: cacciatore
        }
    }


    
    if (j) {
        printf("\nfrase2 = %s\n", frase2);
        printf("frase1 = %s\n", frase1);
    }
    else {
        printf("\nfrase1 = %s\n", frase1);
        printf("frase2  = %s\n", frase2);
    }
    //NOTA: non è in ordine alfabetico perché considera l'ordine della tabella ASCII in cui le lettere maiuscole vengono prima delle minuscole
    //ad esempio con questo ordine le parole caccia e Zebra le ordinerebbe come
    // Zebra - caccia
    //invece caccia e zebra
    // caccia - zebra

}