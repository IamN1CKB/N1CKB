#include <stdio.h>
int main() {
    int i;
    printf("inserisci un numero i: ");
    i = 7;     //valore inserire da me
    //scanf("%d", &i);   //mi scoccio di interagire con il terminale direttamente e quindi ho messo io il valore
    //Quando si desidera eseguire un’istruzione al verificarsi di una certa condizione, si utilizza l’istruzione if. Per esempio, se si vuole visualizzare il messaggio minore di 100 solamente nel caso in cui il valore della variabile intera i è minore di 100, si scrive
    if(i<10) printf("minore di 100\n");
    //La sintassi dell’istruzione if è
    // if(espressione) istruzione
    //l'espressione all'interno delle parentesi restituisce il valore di uno se è vera, 0 se è falsa
    //l'espressione se è indicata da un confronto da sempre il valore di 0 e 1, ma se indicata da una variabile intera (o char che come vedremo non cambia molto), dà false solo nel caso della variabile=0, nel resto dei casi (anche per i numeri negativi) la variabile viene considerata come una condizione true
    //es
    if (1) printf("1 questo viene eseguito\n");
    if (4) printf("2 questo viene eseguito\n");
    if (0) printf("3 questo non viene eseguito\n");
    if (-3) printf("4 questo viene eseguito\n");
    
    printf("vero = 1; falso = 0;  %d\n", i<10);
    //possiamo anche scrivere quindi:
    int a = i<10;
    if (a==1) {
        //ci mettiamo le parentesi per un migliore ordine. Nel caso in cui nelle code block da eseguire ci fossero più di una istruzione, le parentesi sono d'obbligo, altrimenti esegue solo la prima istruzione. 
        puts("i<10");
    }
    //se ci chiediamo se a è uguale a 1, possiamo anche usare direttamente il valore di a come condizione per l'if, siccome 1 vale true e 0 vale false. Inoltre possiamo aggiungere il ramo else, che svolge n operazione nel caso in cui la condizione dell'if sia falsa.
    if (a) {
        puts("i<10");
    }
    else { //vuol dire che a è uguale a 0, e quindi i≥10
        puts("i>=10");
    }

    //se vogliamo usare una variabile all'interno del code block e in futuro non ci servirà, allora la dichiariamo all'interno del code block. Ma se la utilizziamo al di fuori di essa, ci risulterà un errore siccome non risulta dichiarata
    if(1) {
        int variabile_no_fuori_code_block;
        variabile_no_fuori_code_block = 10;
    }
    //printf("%d", variabile_no_fuori_code_block);      questo ci risulterà come errore
    //quindi se vogliamo usare una variabile in un code block e poi usarla nuovamente fuori dal code block, bisogna inizializzarla fuori dal code block
    int b;
    if (1) {
        b = 20;
    }
    printf("b = %d\n", b); 
    //in questo modo non avremo errori



    //il costrutto if è un istruzione e può apparire all'interno di altri costrutti if
    int x = 20; //mi scoccio sempre di interagire col terminale e non metto gli scanf
    //printf("inserisci un numero x: ");   scanf("%d", &x);
    printf("Imponiamo x = %d => ", x);
    if (x<30) 
        if (x>10)
            puts("10<x<30");
        else
            puts("x<=10");
    else
        if (x==30)
            puts("x = 30");
        else
            puts("x>30");
    //in questo specifico caso non servono le parentesi che racchiudono i vari code block, ma attenzione che in molti altri casi sono necessari. Infatti gli else si riferiscono all'ultimo if prima di loro. Ad esempio in questo caso
    x = 30; //mi scoccio sempre di interagire col terminale e non metto gli scanf
    //printf("inserisci un numero x: ");   scanf("%d", &x);
    printf("Imponiamo x = %d => ", x);
    if (x<30) {
        if (x>10)
            puts("10<x<30");
    }
    else  //senza le parentesi questo else avrebbe fatto riferimento all'else con condizione x>10
        if (x==30)
            puts("x = 30");
        else
            puts("x>30");

    //per non sbagliare mai, metti sempre le parentesi.

    //altro costrutto utile è else if che si aggiunge a un costrutto if, ed esegue un code block se sono vere le sue condizioni e false le condizioni dell'if principale
    if (1) {  //questo viene eseguito
        puts("primo costrutto");
    }
    else if (0) { //questo non viene eseguito perché ha la condizione falsa
        puts("secondo costrutto");
    }
    else if (1) { //questo non viene eseguito perché l'if principale ha la condizione vera
        puts("terzo costrutto");
    }
    else { //questo viene eseguito nel caso in cui tutte le condizioni degli if e else if sono false 
        puts("quarto costrutto");
    }
    //esempio pratico
    x = 31; //mi scoccio sempre di interagire col terminale e non metto gli scanf
    //printf("inserisci un numero x: ");   scanf("%d", &x);
    printf("Imponiamo x = %d => ", x);
    if (x>30)
        puts("x>30");
    else if (x==30)
        puts("x = 30");
    else
        puts("x<30");






    //vediamo le espressioni aritmetiche.
        //1)unico operatore unario, ossia che si usa con un solo elemento, è l'elemento di negazione, che restituisce l'opposto di un numero
        printf("%d\n", -x);

        //gli altri operatori sono tutti binari, ossia hanno bisogno di 2 elementi
        //2) moltiplicazione (*)
        //3) divisione (/)
        //4) modulo (%) => fa ottenere il resto di una divisione. es: 10%3 = 1 perché 10/3 = 9 con resto 1
        //5) somma (+)
        //6) sottrazione (-), con lo stesso operatore della negazione
        //7) assegnazione (=)
        //il valore che viene assegnato è sempre l'ultimo a destra
        int var, var1, var2, var3;
        var1 = 7;    //var1 prende il valore di 7
        var2 = var1+3; //var 2 prende il valore di 7 + 3 = 10
        var = var3 = var2/2; //var e var3 prendono il valore di 10/2 = 5
        printf("%d\n", var);
        //attenzione, il valore di assegnazione riporta anche il valore che viene assegnato alla variabile
        printf("la variabile x ora prende il valore di %d\n", x=5);  //x=5 riporta 5
    //ci sono priorità di operazioni su altre operazioni, per questo motivo usa sempre le partentesi tonde

    //poi ci sono gli operatori di confronto che riportano un valore booleano che in C viene segnato come 1 per vero e 0 per falso. Inoltre qualsiasi valore diverso da vero in una condizione (di un if ad esempio) risulta sempre vero, e solo se vale 0 risulta falso.
        // < minore
        // > maggiore
        // <= minore o uguale
        // >= maggiore o uguale
        // == uguaglianza
        // != disuguaglianza
    //inoltre ci sono operatori logici consentono ci concatenare più espressioni logiche, (stessi operatori di reti logiche)
        // ! not logico (unico operatore logico unario)
        // && and logico
        // || or logico


    //facciamo degli esempi
        //1)
        if(5 && -6) //5 e -6 sono diversi da zero, quindi risultano vere
            puts("questo viene stampato sicuro");

        //2)
        x = 4;
        if(a = x)  //assegna ad a il valore di x e riporta il suo valore; dato che è diverso da zero la condizione è vera
            printf("a vale quanto x, ossia %d\n", a);
            //solo se x vale 0 non veniva eseguito il costrutto if


    //espressioni condizionali
    //le espressioni condizionali si ottengono con l'operatore ternario ?: che segue la sintassi:
    //espr1 ? espr2 : espr3
    //se l'espressione 1 è vera, questa espressione finale restituisce il valore dell'espressione 2, se è falsa il valore dell'espressione 3
    int y;
    x=y=5;
    int boolean;
    boolean = x==y? 1 : 0;  
    printf("1 se x = y, 0 se sono diversi => %d\n", boolean);
    //quest'espressione è identica a :
    y = 6;
    if(x==y)
        boolean = 1;
    else
        boolean = 0;
    printf("1 se x = y, 0 se sono diversi => %d\n", boolean);

    //facciamo altri esempi
    int v, c, d;
    x = y = 4;
    a = 3;
    b = 7;
    c = 8;
    d = 2;
    v = x==y ? a*c+5 : b-d;  // 4==4 ? 3*8+5 : 7-2 => 1 ? 29 : 5
    printf("v = %d\n", v);

    a = 5;
    b = 4;
    printf("%d maggiore o uguale di %d\n", (a>b ? a : b), (b<=a ? b : a));

    //queste espressioni condizionali possono essere inserite nelle condizioni if
    a = 1;
    b = 0;
    c = 4;
    if ((a==c ? a : b) >= 7) //(1==4 ? 1 : 0) >= 7       (0 ? 1 : 0) >= 7       0 >= 7       0
        puts("Non verrà stampato\n");
    //altro esempio
    x = 5;
    y = 1;
    var = x > y ? (a>b ? a : b) : y; //5 > 1 ? (1>0 ? 1 : 0) : 1     1 ? (1 ? 1 : 0) : 0     1 ? 1 : 0     1
    printf("var = %d\n", var);


    //VARIABILI CARATTERI char
    //finora abbiamo lavorato con variabili di tipo intero (numeri interi negativi e positivi), ma ora introduciamo le variabili carattere (di qualsiasi tipi: alfabeto, numeri, simboli, punteggiatura, ecc che siano nella tabella ASCII) che memorizzano un solo carattere dalla tabella ASCII
    char lettera, numero, simbolo;    //dichiarazione
    lettera = 'A';   //inizializzazione: RICORDA CHE VANNO SEMPRE USATE LE SINGOLE VIRGOLETTE (ossia l'apostrofo)
    numero = '3';
    simbolo = '+';
    //char alfa1 = "4";     //questo produce un warning perché i doppi apici si usano per gli array di carattere (poi vedrai)
    //la dimensione di questo tipo può variare dall'implementazione ma di solito viene riservato uno spazio di byte (8 bit)
    /*A ogni carattere presente nel codice corrisponde una rappresentazione numerica univoca, per cui è possibile
    confrontare due simboli non solamente con uguaglianze e diseguaglianze, ma anche per mezzo di tutti gli altri operatori
    relazionali. Ogni carattere char corrisponde a un valore della tabella ASCII, ad esempio "A" corrisponde al valore decimale "65" della tabella ASCII siccome è il 65esimo valore.
    “A” (65) è maggiore di “;” (59) che a sua volta è maggiore di “&” (38). Osservando il codice ASCII possiamo
    vedere che le lettere alfabetiche maiuscole sono in ordine crescente da A (65) a Z (90), le minuscole vanno da a (98) a z
    (122) e le cifre decimali da 0 (48) a 9 (57) . Dunque hanno perfettamente senso le istruzioni condizionali*/
    char z = 'A';
    if (z=='A')
        puts("z = A");

    z='G';
    if (z>='A' && z<='Z')
        puts("si tratta di una lettera maiuscola");
    //per poter stampare una variabile carattere:
    printf("%c\n", z);
    //per poter usare scanf con le variabili carattere:
    printf("Inserisci un solo carattere:\n");
    z = 'H';    //inserito a caso da me
    //scanf("%c", &z);   //mi scoccio sempre di interagire con il terminale
    printf("La lettera da te inserita = %c\n", z);
    
    //esistono altri 2 tipi di funzioni di input/output che presente nella libreria <stdio.h>
    //getchar che è riporta il valore che l'utente dà nel terminale
    printf("Inserisci di nuovo un solo carattere: ");
    z = 's';
    printf("%c\n", z);      //mi scoccio di interagire sempre
    //z = getchar();   //non necessita argomenti questa funzione (niente nelle parentesi)
    //questa funzione è simile dunque a scanf()

    //poi c'è la funzione putchar() che è l'equivalente di printf se dobbiamo stampare solo la variabile char
    printf("La lettera da te inserita tramite getchar = ");
    putchar(z);
    printf("\n");

    //ATTENZIONE A USARE scanf("%c", &x) di seguito
    /*Quando richiedi all'utente di seguito più volte un carattere, e lui preme sempre invio, il carattere di nuova riga ('\n') viene lasciato nel buffer. Successivamente, quando usi scanf("%c", &esterno) per le volte successive alla prima; per leggere il carattere, scanf acquisisce il carattere di nuova riga rimasto dal precedente scanf anziché attendere un nuovo input.

    Per risolvere questo problema, puoi aggiungere uno spazio prima della specifica di conversione %c nelle chiamate successive di scanf. In questo modo, lo spazio consuma eventuali caratteri di nuova riga rimasti nel buffer. Inoltre, è una buona pratica includere una chiamata a getchar() per consumare il carattere di nuova riga residuo.
    scanf("%c", &x);
    scanf(" %c", &y);
    */

    
    
    //SWITCH-CASE
    /*Le decisioni a più vie possono essere risolte utilizzando più if-else in cascata:
    if(espressione1)
        istruzione1
    else
        if(espressione2)
            istruzione2
        else
            if(espressione3)
                istruzione3
            ...
                else
                    istruzioneN
                    
                    
    Un’altra soluzione è data dal costrutto switch-case, che consente di implementare decisioni multiple basandosi sul confronto fra il risultato di un’espressione (int o char) e un insieme di valori costanti*/

    /*
    switch(espressione) {
        case costante1:
            istruzione
            ...
        case costante2:
            istruzione
            ...
        case costante3:
            istruzione
            ...
        [default:
            istruzione
            ... ]
    }
    */
    //In fase di esecuzione, viene valutata espressione e il risultato viene confrontato con costante1: se i due valori sono uguali il controllo passa alla prima istruzione che segue i due punti corrispondenti, altrimenti si prosegue confrontando il risultato dell’espressione con costante2, e così di seguito.
    //RICORDA: dopo il case deve esserci una costante e non una variabile 
    //il codice di seguito non è per nulla ottimizzato ma serve solo a far vedere come funziona lo switch-case
    x= 16;
    switch (x) {
        case 14:    //primo paragone
            puts("numero = 14");    //il codice viene eseguito se x==14
            break;    //quest'istruzione fa uscire immediatamente fuori dallo switch-case
            //se non ci fosse l'istruzione break, verrebbero eseguite anche tutte le istruzioni di tutti i case successivi
        case 5:
            puts("numero = 5");
            break;
        case (4+11):
            puts("numero = 15");
            break;
        case 1:
            puts("numero = 1");
            break;
        case 6:
            puts("numero = 6");
            break;
        default:     //nel caso in cui nessun case è giusto viene eseguito questo
            puts("non lo so");
            break;
   }
}
//vedi esercizi di questa lezione
//vedi la prossima lezione ad appunti3.0.c 