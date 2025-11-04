#include <stdio.h>
//TORRE DI HANOI
/*
La Torre di Hanoi, anche conosciuta come Torre di Lucas dal nome del suo inventore, è un rompicapo matematico composto da
tre paletti e un certo numero di dischi di grandezza decrescente¹. Il gioco inizia con tutti i dischi incolonnati su
un paletto in ordine decrescente, formando un cono.

Lo scopo del gioco è spostare tutti i dischi su un paletto diverso, seguendo queste regole:
1. Si può spostare solo un disco alla volta.
2. Un disco può essere posto solo su un disco più grande, mai su uno più piccolo.

La soluzione del gioco si basa su un algoritmo ricorsivo. Supponiamo che i paletti siano etichettati con A, B e C, e i dischi
numerati da 1 (il più piccolo) a n (il più grande). L'algoritmo si esprime come segue:

1. Sposta i primi n -1 dischi da A a B. (Questo lascia il disco n da solo sul paletto A)
2. Sposta il disco n da A a C
3. Sposta n -1 dischi da B a C

Il numero minimo di mosse necessarie per completare il gioco è 2^n - 1, dove n è il numero di dischi.
Ad esempio, avendo 3 dischi, il numero di mosse minime è 7
*/
void Hanoi(int, int, int, int);
int main() {
    int n;
    printf("decidi n dischi della torre di Hanoi: ");
    scanf("%d", &n);
    Hanoi(n, 1, 2, 3);
}

/*
si riconduce il generico problema di Hanoi H(n) a problemi di Hanoi con n-1 Questa divisione permette, tra l'altro, di giungere per successive 
riduzioni al caso base rappresentato dal problema con un solo disco H(1), facilmente risolvibile in quanto prevede un'unica mossa.

• Divide: si riconduce il generico problema di Hanoi H(n) a problemi di Hanoi con n-1 Questa divisione permette, tra l'altro, di giungere
    per successive riduzioni al caso base rappresentato dal problema con un solo disco H(1), facilmente risolvibile in quanto
    prevede un'unica mossa.
• Caso base: il problema banale di Hanoi con un solo disco, tra due generici pioli X ed Y , si risolve muovendo il disco da X a Y.
• Impera: si ritiene, per ipotesi, di saper risolvere correttamente il medesimo problema H(n-1) con n-1 dischi, e di conoscere
    quindi la sequenza corretta di mosse.
• Combina: e facile verificare che nella ipotesi di saper risolvere HX;Y (n-1), la soluzione ad HO;D(n) e data dalla
    sequenza HO;I (n-1) HO;D(1), HI;D(n-1)
*/
void Hanoi(int n, int O, int D, int I) {
    if (n == 1) printf("Sposto il disco da %d a %d\n", O, D);
    else {
        Hanoi(n-1, O, I, D);
        Hanoi(1, O, D, I);
        Hanoi(n-1, I, D, O);
    }    
}