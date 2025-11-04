#include <stdio.h>
#define N 100
void main() {
    //In C è possibile operare sui file di byte non solo in modo strettamente sequenziale ma anche con modalità random. La funzione fseek consente infatti di muovere il puntatore di lettura e/o scrittura in una qualunque posizione all’interno del file.

    //fseek si usa come illustrato nel seguente esempio:
    int err, mode;
    FILE *fp;
    long n;
    fp = fopen("file", "r");
    if (fp == NULL) printf("errore file");
    else {
        mode = 0;
        n = 100L;   //In C, quando vedi un suffisso come L attaccato a un numero, come in 100L, questo indica che il numero è di tipo long.
        err = fseek(fp, n, mode); //sposta il file pointer 100 byte dopo l'inizio del file
        fclose(fp);
    }
    /*
    in cui il file pointer fp è posizionato sul centesimo byte. I parametri della funzione fseek hanno il seguente significato:
        -fp è il file pointer;

        -n indica di quanti byte il file pointer deve essere spostato; se n è negativo significa che il file pointer deve essere spostato indietro invece che in avanti. Per calcolare n devi calcolare il numero di byte e quindi se vuoi spostare di m elementi il puntatore al file dobbiamo usare n =m*sizeof(char);

        -mode indica a partire da quale posizione muovere il file pointer; se mode vale 0 significa che lo spostamento è a partire dall’inizio, se vale 1 è dalla posizione corrente e se, infine, vale 2 è a partire dalla fine del file
    Il valore di ritorno della funzione fseek è negativo se si è verificato un errore, maggiore o uguale a 0 in caso contrario
    */

    //facciamo un esempio. vogliamo riscrivere dal 6° carattere in poi di un file già esistente con già del testo dentro
    //file iniziale: "ciao, sono Nicola"
    //stringa di modifica dal 6 carattere: "bello"
    //file finale: "ciao, bello"
    fp = fopen("file", "r+");  //r+ perché dobbiamo scriverci sopra, ma non vogliamo che tutto sia cancellato all'inizio (come fa w)
    if (fp == NULL) printf("file non aperto");
    else {
        err = fseek(fp, 6*sizeof(char), 0);
        char buf[N];
        int len;
        printf("inserisci stringa: ");
        for (len = 0; (buf[len]=getchar())!='\n'; len++);
        //non mettiamo \0 perché poi nel file lo sminchierebbe (non diventa leggibile da editor di testo), ma mettiamo len escluso \0
        buf[len] = '\0';   //solo alla stringa lo mettiamo lo \0
        
        fwrite(buf, sizeof(char), len, fp);
        //un altro metodo per portare il puntatore a inizio file è rewind
        rewind(fp);   //può portare solo a inizio file
        fread(buf, sizeof(char), len+6, fp);  //non leggiamo ulteriori caratteri che stanno dopo la stringa che abbiamo inserito

        printf("nel file finale c'e': %s\n", buf);
        fclose(fp);
    }


    

}