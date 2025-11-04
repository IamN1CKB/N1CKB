#include <stdio.h>
#define N 100
void main() {
    /*
    vediamo anche delle funzioni per file binari particolare: i file di testo
    fprintf scrive sui file in modo formattato
    scanf legge da file in modo formattato
    La funzione fprintf si usa come nell’esempio seguente:
    */
    FILE *fp;
    int i;
    char str[N];
    fp = fopen("file di testo.txt", "w");
    if(fp == NULL) printf("il file non è stato aperto correttamente\n");
    else {
        printf("inserisci un valore di i: ");
        scanf("%d", &i);
        
        fprintf(fp, "Il valore di i è %d\n", i);
        //se vedi il file è stato salvato bene

        //se vogliamo salvare una riga che già abbiamo salvato in una stringa possiamo usare fputs
        getchar();
        for (i = 0; (str[i] = getchar())!='\n'; i++);
        str[i] = '\0';
        //abbiamo scritto qualcosa nella stringa tramite console
        fseek(fp, 0, 0);  //voglio sovrascriverlo alla prima riga, quindi sposto all'inizio del file il puntatore al file
        fputs(str,fp);



        fclose(fp);
    }

    //adesso usiamo fscanf, per poter leggere qualcosa da file
    //come prima cosa dobbiamo ricreare il canale e nel caso spostiamo il puntatore all'inizio del file
    fp = fopen("file di testo.txt", "r");
    if(fp == NULL) printf("err\n");
    else {
        //salviamo solo la prima parola nella stringa
        fscanf(fp, "%s", str);
        printf("la prima parole del file è '%s'\n", str);

        //adesso salviamo tutta la prima riga tramite fgets, che ti salva le stringhe fino alla prossima newline (\n)
        //prima mettiamo il puntatore all'inizio file
        fseek(fp,0,0); //puntatore a 0 byte dal'inizio del file
        fgets(str, N, fp);    //prende la pima riga del file compreso '\n'
        printf("la prima riga del file è:\n%s", str);

        fclose(fp);
        /*
        la funzione fgets ritorna il puntatore a carattere: tale valore coincide con l’indirizzo di buf se tutto è andato a buon fine, mentre vale NULL nel caso in cui si sia verificato un errore o il file pointer si trovi posizionato a fine file.
        La funzione fgets non si limita a trasferire una riga nel vettore buf ma aggiunge automaticamente a fine riga il carattere di fine stringa “\0”.

        fgets noi già lo usavamo per ricavare stringhe dalla console, considerando la console come un file, detto stdin
        */
    }

}