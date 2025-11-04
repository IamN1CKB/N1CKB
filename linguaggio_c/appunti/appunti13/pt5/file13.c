#include <stdio.h>
int main(){
    //le funzioni di scrittura formattata possono essere usate per l'input e l'output da tastiera
    /*
    Quando un programma va in esecuzione il sistema apre automaticamente tre file pointer, mediante i quali è possibile 
    scrivere messaggi a video e acquisire dati dalla tastiera. Questi tre file pointer prendono il nome di Standard Input 
    (stdin), Standard Output (stdout) e Standard Error (stderr) e possono essere utilizzati dalle funzioni di accesso 
    ai file descritte nei precedenti paragrafi.
    Il file pointer stdin è associato dal sistema alla tastiera, i due file pointer stdout e stderr sono entrambi 
    assegnati al video. Per scrivere un messaggio a video si può allora utilizzare, per esempio, la funzione fprintf:
    */
    fprintf(stdout,"Ciao lettore\n");
    /*
    Dunque le funzioni che abbiamo utilizzato per accettare valori da tastiera e mandare uscite al video corrispondono a usi 
    particolari delle funzioni di uso generale esaminate in questo capitolo. Si hanno le seguenti equivalenze:
        printf(...) -> fprintf(stdout,...)
        scanf(...) -> fscanf(stdin,...) 
        getchar() -> fgetc(stdin)
        putchar(c) -> fputc(c, stdout)
        eof() -> feof(stdin)
    La sintassi delle funzioni a sinistra è più sintetica, perché quelle sulla destra devono specificare che desiderano operare 
    sullo standard input o sullo standard output.
    Il programmatore deve prestare molta attenzione all’utilizzo delle due funzioni con sintassi abbreviata gets e puts, il 
    cui comportamento è simile ma non uguale a quello delle funzioni fgets e fputs. Infatti gets legge una riga da 
    tastiera ma elimina il carattere di newline (inoltre non specifica nemmeno la dimensione massima della stringa, quindi si possono avere
    problemi di overflow) e puts scrive una riga a video aggiungendo automaticamente un carattere di newline. Ne consegue che :
    gets(buf) non equivale a fgets(buf, n_max, stdin)
    puts(buf) non equivale a fputs(buf, stdout)

    al posto di gets() che non specifica la dimensione massima è consigliato usare o fgets() o gets_s()
    char *gets_s(char *, rsize_t)
    */
    char buf[50];
    gets_s(buf, 50);
    printf("buf = %s\n", buf);
}