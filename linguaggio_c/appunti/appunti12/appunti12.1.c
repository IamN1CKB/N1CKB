#include <stdio.h>
struct data {
    int giorno;
    char* mese;
    int anno;
};
int intMese(struct data *p);
void main() {
    struct esempio {
        int campo1;
        char* campo2;
        float campo3;
        struct dentro_struct{
            int campoInside[100];
            double** puntatore;
        };
    };
    //possiamo salvare qualsiasi cosa noi vogliamo in una struct, anche altre struct
    struct esempio x, a;
    x.campo1 = 1;
    //inoltre quando creiamo una variabile di struct possiamo creare anche array di struct
    struct esempio array[10];
    array[5].campo3 = 2.5;
    //possiamo creare anche un puntatore a tipo di struct che abbiamo creato
    struct esempio *p, *m;  //questo è un puntatore a struct esempio
    p = &x;
    m = array;
    //possiamo usare l'operatore di dereferenziazione con le parentesi per capire il valore di un campo di una variabile di tipo struct puntata da p
    printf("x.campo1 = (*p).campo1 = %d\n", (*p).campo1);   //è obbligatoria la coppia di parentesi altrimenti l'operatore di dereferenziazione non funzionerebbe solo su p, ma su tutto il campo1
    printf("array[%d].campo3 = %f\n", 5, (*(m+5)).campo3);
    /*
    Poiché in C si accede frequentemente a una variabile struttura tramite puntatore per evitare costrutti sintattici laboriosi, 
    è stato introdotto l’operatore freccia -> per accedere direttamente ai membri di una variabile strutturata puntata da un puntatore
    */
    printf("altro modo per dire x.campo1 = (*p).campo1 = p -> campo1 = %d\n", p->campo1);
    /*
    I puntatori a struttura sono molto usati specialmente per passare una struttura a una funzione, e per far sì che una 
    funzione ritorni un risultato di tipo struttura:
    per poter passare tutto ciò a un sottoprogramma solo la definizione del nuovo tipo di struct deve essere globale, altrimenti la funzione non riconosce la variabile
    */
    
    struct data oggi = {11, "febbraio", 2024};   //questa è una forma contratta per inizializzare la variabile di tipo struct 
    
    printf("%s = %d\n", oggi.mese, intMese(&oggi));
}
int intMese(struct data *p) {
    if (p->mese == "gennaio") return 1;
    if (p->mese == "febbraio") return 2;
    if (p->mese == "marzo") return 3;
    if (p->mese == "aprile") return 4;
    if (p->mese == "maggio") return 5;
    if (p->mese == "giugno") return 6;
    if (p->mese == "luglio") return 7;
    if (p->mese == "agosto") return 8;
    if (p->mese == "settembre") return 9;
    if (p->mese == "ottobre") return 10;
    if (p->mese == "novembre") return 11;
    if (p->mese == "dicembre") return 12;
}