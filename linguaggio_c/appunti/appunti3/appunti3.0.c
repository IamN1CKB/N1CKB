#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int main(){
    //istruzione for
    /*per poter compiere un operazione un tot numero di volte possiamo usare il ciclo for.*/
    //ad esempio per sommare uno stesso valore a una variabile
    int somma = 0;
    for (int i = 0; i <3; i= i+1) {
        somma = somma + 7;
    }
    //L’esempio precedente è volutamente semplice per concentrare l’attenzione sulle caratteristiche del costrutto for.
    //Alla variabile somma viene dato il valore 0. L’istruzione for assegna il valore 1 alla variabile i. L’operazione "int i = 0" compresa tra la parentesi tonda aperta e il primo punto e virgola è detta dichiarazione e inizializzazione e non verrà mai più eseguita.
    /*Successivamente l’esecuzione prosegue così:
        1. se i<3 allora vai al passo 2, altrimenti termina
        2. somma=somma+7
        3. i=i+1, vai al passo 1 */

    //Il formato del costrutto for è il seguente:
    //for(esp1; esp2; esp3)
    //    istruzione
    //RICORDA: la variabile di conteggio (per convenzione chiamata spesso i) è stata dichiarata nel costrutto for ì, dunque esiste solo in questo costrutto.
    //se vogliamo che i esista fuori dal costrutto deve essere dichiarato prima di fare il costrutto for
    int i;
    for (i = 0; i < 3; i=i+1) {
        printf("stampa %d\n", i);
    }
    int a=i+5;
    printf("a = %d\n", a);    //si può chiamare perché è stata dichiarata fuori dal for

    //se l'iterazione tra le operazioni non cambiano la variabile di conteggio in modo tale da stoppare il ciclo for in un determinato istante dell'esecuzione, allora il for viene eseguito all'infinito, diventando un ciclo infinito. es:
    //for(i=5; i>0; i = i + 1) {...}   //verrebbe eseguito all'infinito mandando in crash l'esecuzione del file.exe


    //per incrementare la variabile di conteggio e decrementarla possiamo usare delle scorciatoie, tramite operatori specifici.
    //per incrementare di 1 la variabile di conteggio si usa ++
    somma = 5;
    ++somma;   //equivalente di scrivere somma = somma + 1
    printf("somma = %d\n", somma);
    //per decrementare di 1 possiamo usare l'operatore --
    somma = 5;
    --somma;   //equivalente di scrivere somma = somma - 1
    printf("somma = %d\n", somma);
    //questi operatori possono essere inseriti in cicli for (i=0; i<5; ++i)
    //Gli operatori di incremento e decremento possono sia precedere sia seguire una variabile:
    //++somma;
    //somma++;
    //Le due istruzioni precedenti hanno lo stesso effetto, ma se gli operatori vengono utilizzati all’interno di espressioni che coinvolgono più elementi valgono le seguenti regole:
    /*
    • se l’operatore ++ (--) precede la variabile, prima il valore della variabile viene incrementato (decrementato) e poi viene valutata l’intera espressione;
    • se l’operatore ++ (--) segue la variabile, prima viene valutata l’intera espressione e poi il valore della variabile viene incrementato (decrementato).
    */
    int j = 0;
    printf("j = %d\n", ++j); //viene prima incrementata e poi restituisce il valore già incrementato
    j = 0; 
    printf("j = %d\n", j++); //restituisce prima il valore non incrementato e poi lo incrementa.
    //ad esempio i 2 cicli for di seguito svolgono un diverso numero di iterazioni:
    j=0;
    for(i=1; ++i<=3;)
        printf("Ciclo: %d\ti: %d\n", ++j, i);
    printf("Cicli tot: %d\ti: %d\n", j, i);
    printf("\n");

    j=0;
    for(i=1; i++<=3;)
        printf("Ciclo: %d\ti: %d\n", ++j, i);
    printf("Cicli tot: %d\ti: %d\n", j, i);
    

    //altro operatore utile per incrementare una variabile di un numero è +=
    somma = 1;
    somma += 2; //diventa somma = somma +2;      somma = 3; 
    //La forma generalizzata è
    //variabile [operatore]= espressione
    //Dove [operatore] può essere + - * / % ed espressione una qualsiasi espressione lecita. 
    //questi operatori sono l'equivalente di scrivere
    //variabile = variabile[operatore]espressione
    /*
    Forma compatta                  Forma Classica
    a *= 5;                         a = a*5;
    a -= b;                         a = a-b;
    a *= 4+b;                       a = a*(4+b);
    */
    


    //WHILE
    //anche l'istruzione while come la for permetti di ripetere ciclicamente un blocco di istruzioni.
    /*
    while(esp)
          istruzione
    */
    //Viene verificato che esp sia vera, nel qual caso viene eseguita istruzione. Il ciclo si ripete fintantoché esp risulta essere vera.
    int n;
    i = 0;
    somma = 0; 
    while (i<5) {
        printf("Inserisci %d-esimo intero da sommare: \n", i+1);
        n = 5;  //valore predefinito
        scanf("%d", &n);  //mi scoccio di interagire con io terminale 
        printf("somma = %d + %d = ", somma, n);
        somma += n;
        printf("%d\n", somma);
        i++;
    }
    //sommiamo 5 numeri diversi inseriti dall'utente
    printf("somma totale= %d\n", somma);

    //se non vogliamo decidere noi quando terminare le somme, possiamo fare in modo che terminano quando l'utente ha inserito il numero 0
    somma = 0;
    
    n=1; //inizializzo n a un qualsiasi valore diverso da 0
    //mi scoccio di interagire con la tastiera, e non posso settare n su uno stesso numero altrimenti diventerebbe un ciclo infinito. Per cui commento tutto il ciclo

    while (n!=0) {
        //sommiamo numeri diversi inseriti dall'utente fino a quando non inserisce 0
        printf("Inserisci intero da sommare (0 per smettere di sommare): ");
        n = 0;
        //scanf("%d", &n);     //mi scoccio di interagire con il terminale: farà solo un interazione
        printf("somma = %d + %d = ", somma, n);
        somma += n;
        printf("%d\n", somma);
    }
    printf("somma totale = %d\n", somma);


    //vediamo una variante più compatta del while che somma tot numero diversi
    i = 0;
    somma = 0; 
    while (i++<5) { //viene prima valutato i e poi incrementato (si risparmia una linea di codice)
        printf("inserisci 5 numeri da sommare: ");
        n = 5; //valore predefinito
        //scanf("%d", &n);   //mi scoccio di interagire con il terminale
        printf("somma = %d + %d = ", somma, n);
        somma += n;
        printf("%d\n", somma);
    }
    printf("la somma dei numeri e' %d\n", somma);
    

    //possiamo siccome 0 rappresenta il valore booleano false possiamo usarlo per compattare il codice
    i = 5;
    while (i--) //quando i = 0 il ciclo si ferma
        printf("stampa i = %d\n", i);
    

    /*Ogni istruzione for può essere sostituita da un’istruzione while se si ha cura di aggiungere le opportune inizializzazioni prima del ciclo e gli opportuni incrementi all’interno dello stesso. In C è vero anche l’inverso. Ogni istruzione while ha un suo corrispondente for, anche quando il numero d’iterazione non è noto a priori. Per esempio, la parte centrale del programma precedente può essere realizzata con un ciclo for:*/
    somma = 0;
    //la prima espressione nell'argomento del for è i = 2, ma può essere qualsiasi valore diverso da zero
    for (n = 2; n != 0; /*qui è inutile scrivere la terza espressione*/) {
        printf("inserisci numero da sommare (fino a quando non inserisci 0): \n");
        //scanf("%d", &n);    //mi scoccio di interagire con il terminale: farà solo un interazione
        printf("somma = %d + %d = ", somma, n);
        somma += n--; //n-- per far fermare il ciclo nel caso in cui non interagisco con il terminale
        printf("%d\n", somma);
    }


    //scriviamo un ciclo while che oltre a sommare dei valori dati dall'utente, di questi valori ne determini il massimo
    somma = 0;
    n = 1;
    int max = 0;  //il massimo lo inizializziamo a 0, dato che è sempre presente per terminare le somme
    while (n != 0) {
        printf("inserisci numero da sommare (0 per terminare): ");
        scanf("%d", &n);
        somma += n;
        printf("somma = %d + %d = %d\n", somma-n, n, somma);
        if (n>max)
            max = n;
    }
    printf("la somma totale è %d\n", somma);
    printf("il massimo dei valori inseriti è %d\n", max);


    //se volessimo che i valori da sommare non siano maggiori di un certo numero, possiamo aggiungere una condizione al while
    i = 0; //numero di numeri sommati
    int x;
    printf("inserisci quanti numeri vuoi sommare: ");
    scanf("%d", &x);
    somma = 0;
    n = 1;
    //in questo caso non siamo sicuri se ci sarà 0 (siccome non è indispensabile per terminare le somme)
    //infatti il massimo potrebbe essere un numero negativo. Per questo motivo inizializziamo max al valore minimo che può essere rappresentato da una variabile di tipo int. Per restituire questo valore che cambia a seconda dell'implementazione usiamo la costante INT_MIN presente nella libreria limits.h (che va inclusa) 
    max = INT_MIN;
    while (n != 0 && i++<x) {
        printf("inserisci il numero da sommare (0 per terminare): ");
        scanf("%d", &n);
        printf("somma = %d + %d = %d\n", somma, n, somma+n);
        somma += n;
        if (n>max)
            max = n;
    }
    if (x>0) {
        printf("la somma totale è %d\n", somma);
        printf("il massimo dei valori inseriti è %d\n", max);
    }
    else
        puts("nessuno elemento sommato");
    


    //se non vogliamo includere questa libreria possiamo inizializzare max al primo valore di n inserito, grazie a un costrutto if
    i = 0;
    printf("inserisci quanti numeri vuoi sommare: ");
    scanf("%d", &x);
    somma = 0;
    n = 1;
    while (n != 0 && i++<x) {
        printf("inserisci il numero da sommare (0 per terminare): ");
        scanf("%d", &n);
        printf("somma = %d + %d = %d\n", somma, n, somma+n);
        somma += n;
        if (n>max || i == 1)
            max = n;        //darà a max il valore del primo n inserito da input
    }
    
    if (x>0) {
        printf("la somma totale è %d\n", somma);
        printf("il massimo dei valori inseriti è %d\n", max);
    }
    else
        puts("nessuno elemento sommato");




    //do while
    //quando l'espressione compresa nel ciclo deve essere eseguita almeno una volta risulta più comodo usare il costrutto do-while
    /*
    do
        istruzione
    while(esp);
    */
   //viene eseguita istruzione per una volta, poi se esp risulta vero il ciclo viene ripetuto
   //ricostruiamo di nuovo il ciclo che somma vari numeri presi dall'utente e che ne determini il maggiore
   //inizialmente non c'è bisogno che n sia inizializzato a un numero diverso da zero, siccome si esegue lo stesso il ciclo almeno una volta
   somma = 0;
   //inizializza x come numero di elementi da sommare (è gia inizializzato)
   //inizializza anche max
   printf("Decidi quanti numeri vuoi sommare (almeno 1 verrà sommato): ");
   scanf("%d", &x);
   i = 1;   //numero di volte in cui viene eseguito il ciclo (1 perché la prima volta gia viene sommato di default)

   do {
        printf("inserisci un numero n da sommare (0 per terminare): ");
        scanf("%d", &n);
        printf("somma = %d + %d = %d\n", somma, n, somma+n);
        somma += n;
        if (n>max || i == 1)
            max = n;
   } while (i++<x && n!=0);
   printf("la somma finale di %d numeri e' %d\n", x, somma);
   printf("il massimo è %d\n", max);




   //OPERATORE VIRGOLA
   //L’operatore virgola, che ha priorità più bassa di tutti gli altri, permette di inserire all’interno delle espressioni più istruzioni. Per esempio, un for può includere le inizializzazioni all’interno di esp1:
        //for(numero=1, somma=0; numero!=0;) 
    //In questo caso esp3 non è presente, ma se necessario anch'essa potrebbe contenere più di un istruzione:
        for(i=1, j=5; i<10 && j<100; i++, j=i*j);   //se mettiamo il ; dopo il for non esegue altro che esp3 ciclicamente
        printf("i = %d, j = %d\n", i, j);    //se veniva mancato ; dopo il for, questa istruzione sarebbe stata eseguita ciclicamente, invece adesso con ; dopo il for, viene eseguita dopo il ciclo for
    //Nell’esempio, i viene inizializzato a 1 e j a 5. Il ciclo si ripete finché i è minore di 10 e contemporaneamente j è minore di 100. A ogni ciclo i viene incrementato di 1 e a j viene assegnato il prodotto di i per j. Al limite si potrebbe scrivere:
        for(n=1, somma=0; n!=0; printf("Inserisci intero (0 per terminare):\t"), scanf("%d",&n), somma += n);
        printf("somma totale = %d\n", somma);
        //in questo caso
            //esp1 = n=1, somma=0
            //esp2 = n!=0
            //esp3 = printf("Inserisci intero:\t"), scanf("%d", &n), somma += n
    //cosi facendo non c'è bisogno di scrivere nulla nel blocco di codice perché tutte le istruzioni da eseguire sono già nell'intestazione del for comprendendo tutte le istruzioni che costituiscono il calcolo della somma dei numeri introdotti dall’utente all’interno di esp3. Vale la pena sottolineare che le istruzioni in esp3 sono inframmezzate dalla virgola e non devono essere presenti punti e virgola.
 
    //NOTA
    //Questo modo di operare porta a istruzioni lunghissime, difficilmente leggibili; consigliamo pertanto di usare l’operatore virgola essenzialmente là dove ci siano da inizializzare o incrementare più variabili che controllano il ciclo.


    //cicli annidati
    //possiamo fare cicli annidati per ripetere certe istruzioni un numero n*m volte, con n e m 2 variabili
    //Se prima dell’inizio del ciclo n ha valore 2 e m ha valore 3 l’esecuzione provocherà la seguente visualizzazione:
    /*
        i: 0 j: 0
        i: 0 j: 1
        i: 0 j: 2
        i: 1 j: 0
        i: 1 j: 1
        i: 1 j: 2
    */
    int m;
    n = 0;
    printf("Inserire il numero di linee: \t");
    scanf("%d", &n);
    printf("Inserire il numero di colonne: \t");
    scanf("%d", &m);
    for(i=0; i<n; i++) { /* inizio blocco ciclo esterno */
        for(j=0; j<m; j++)
            printf("+ ");
        printf("\n");
    } /* fine blocco ciclo esterno */
    


    //salti condizionati e incondizionati
    /*ci sono istruzioni che ci consentono di modificare l'esecuzione di un ciclo. abbiamo già incontrato l'istruzione break nello switch-case, che fa uscire di case di uno switch case, ma in un interazione for, while o do-while termina tutte le successive iterazioni, saltando alla prima istruzione successiva al ciclo.
    */
    for (i = 0; i < 5; i++) {
        printf("stampa %d\n", i);
        if(i==3) break;
    }
    //ovviamente sarebbe meglio evitare quest'istruzione siccome peggiora la leggibilità, e si dovrebbe scrivere invece
    for (i = 0; i <= 3; i++)
        printf("stampa %d\n", i);
    //precisiamo inoltre l'istruzione break provoca l'uscita dal ciclo più esterno
    for  (i = 1; i <= 5; i++) {
        printf("ciclo esterno: %d iterazione: ", i);
        for (j = 0; j < 12; j++) {
            printf("%d ", j);     //ciclo interno
            if (j>=9) break;
        }
        printf("\n");
    }

    //istruzione continue è simile all'istruzione break ma con la differenza che non provoca l'uscita dal ciclo ma solo dalla propria iterazione, saltando le istruzioni successivi del ciclo e andando all'iterazione successiva
    for (i = 0; i < 10; i++) {
        printf("numero : ");
        if (i == 7) {
            printf("\n");
            continue;
        }
        printf("%d\n", i);
    }
    //possiamo ad esempio sommare solo numeri positivi e mandando alla prossima iterazione se viene inserito dall'utente un numero negativo, e infine far stoppare sempre al numero 0
    n = 1;
    somma = 0;
    printf("Inserisci i numeri positivi da sommare (0 per terminare)\n");
    for (i = 1; n!=0; i++) {
        printf("%d numero da sommare: ", i);
        scanf("%d", &n);
        if (n<0) {
            printf("no numeri negativi\n");
            i--;
            continue;
        }
        printf("somma = %d + %d = %d\n", somma, n, somma+n);
        somma += n;
    }
    printf("somma finale: %d\n", somma);

    //adesso presentiamo la funzione exit() che si trova nella libreria stdlib.h e fa terminare l'esecuzione di un intero programma (lo inseriremo alla fine altrimenti le istruzioni successive non verranno mai eseguite)
    //come argomento possiamo passare un numero che sarà riportato come valore di quel programma (non è obbligatorio)
    //di solito si passa 0 per indicare che l'esecuzione non ha avuto errori, e altri valori per indicare errori

    exit(-1);  //in questo caso il programma dovrebbe essere segnato come programma con errori (non ci sono davvero)
    printf("questo non verrà eseguito");
    //Le ragioni della programmazione strutturata, tra cui pulizia ed eleganza del codice, sconsigliano l’uso generalizzato di break, continue ed exit
    //ora vedi la prossima lezione "appunti3.1.c"
}