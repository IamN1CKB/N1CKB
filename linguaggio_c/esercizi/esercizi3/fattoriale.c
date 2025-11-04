#include <stdio.h>
#include <limits.h>
int main() {
    //Calcolo del fattoriale
    //possiamo anche calcolare il fattoriale di un numero tramite il ciclo for; in cui un numero naturale n > 1 ha come fattoriale
    //n! = n*(n-1)*(n-2)*(n-3)...*2*1
    // e dove 1! = 0! = 1
 
    int n;
    printf("Calcolo del fattoriale di n. Inserisci il valore di n:\n");
    scanf("%d", &n);    //mi scoccio di interagire
    if (n>=0) {
        printf("n = %d\n", n);
        int fattoriale = 1; //inizializziamo a 1 in modo che 1! e 0! risulti 1
        //ricorda che fattoriale è una variabile di tipo int, codificata in 32 bit per l'implementazione di Nicola e se n > 13 il numero che viene calcolato è errato perché non rappresentabile con 32 bit (il valore massimo di n cambia con l'implementazione)
        for (int i = 0; i < n; i++)
            //i<n, in modo che se è n=0, il ciclo non venga eseguito; invece se è 1, viene eseguito una sola volta facendo praticamente: 1 * (1-0) = 1
            fattoriale *= n-i;
        printf("%d! = %d\n", n, fattoriale);
    }
    else
        printf("impossibile calcolare il fattoriale di un numero negativo");
}