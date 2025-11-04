#include <stdio.h>
void main() {
    /*
    I valori di una variabile possono essere convertiti da un tipo a un altro. Questa conversione può avvenire implicitamente 
    o può essere comandata esplicitamente. In ogni caso il programmatore deve sempre tener conto degli eventuali effetti 
    delle conversioni implicite di tipo; quelle ammesse sono le seguenti:
        1) il tipo char è implicitamente convertibile in int, short int e long int. La conversione di un carattere 
        in un valore più lungo può riguardare o meno l’estensione del segno, a seconda del tipo di macchina;
        */
            char var = '0';
            long var2 = var;  //var2 = 48 ossia la codifica di '0' in ASCII
            printf("var2 = %ld\n", var2);
        /*
        2) il tipo int è implicitamente convertibile in char, short int, long int. La conversione a un intero più 
        lungo produce l’estensione del segno; la conversione a un intero più corto provoca il troncamento dei bit più 
        significativi. Il tipo int è implicitamente convertibile anche in float, double e unsigned int. Per 
        quest’ultimo caso la sequenza dei bit dell’int è interpretata come unsigned;
        */
            int var3 = 72;
            /*char*/ var = var3;  //'H' la cui codifica in ASCII è 72
            printf("var = %c\n", var);
        /*
        3) i tipi short int e long int possono essere convertiti implicitamente come int (punto 2);
        */
        short var4 = 14;
        /*int*/ var3 = var4;
        printf("var3 = %d\n", var3);
        /*
        4) il tipo float può essere convertito in double senza alcun problema. Il tipo float può essere anche 
        convertito in int, short int e long int, e ciò comporta il troncamento delle cifre dopo la virgola.
        Il risultato non è definito quando il valore float da convertire è troppo grande, perché cambia da macchina a macchina;
        */
        float var5 = 5.5;
        /*int*/ var3 = var5;    //5
        printf("var3 = %d\n", var3);
        /*
        5) il tipo double può essere convertito in float, potendo provocare troncamento nell’arrotondamento. Inoltre, 
        per il double vale quanto detto per il float a proposito di int, short int e long int
        */
        double var6 = 7.9;
        /*float*/ var5 = var6;
        printf("var5 = %f\n", var5);
        /*
    NOTA
    Le conversioni implicite di tipo vengono effettuate per rendere conformi, se possibile, i tipi di due operandi in 
    un’espressione e i tipi dei parametri attuali e formali nel passaggio dei parametri di una funzione. In C sono 
    possibili molte conversioni implicite di tipo, ma ci limiteremo a considerare solo quelle che il programmatore 
    può ragionevolmente ammettere. Per tutte le altre conversioni, non è saggio affidarsi al compilatore, soprattutto 
    per motivi di leggibilità e portabilità delle applicazioni, e, pertanto, si raccomanda di usare la conversione 
    esplicita di tipo




    In C l’esecuzione degli operatori aritmetici effettua la conversione implicita degli operandi se questi non sono 
    omogenei. il tutto accade in vari step:
    -si controlla se gli operandi sono omogenei
    -se non sono omogenei si convertono le variabile in modo da diventare omogenei
    -si salva il risultato dell'operazione in una variabile temporanea
    -si converte il valore nel tipo della variabile a cui stiamo assegnando il valore

    Ecco come avviene la conversione implicita:
        1. Se entrambi gli operandi sono dello stesso tipo, il risultato dell'operazione sarà dello stesso tipo.
        2. Se gli operandi sono di tipi diversi, l'operando di tipo inferiore viene convertito al tipo superiore.
        3. La priorità dei tipi è la seguente (dal più basso al più alto): `char`, `short int`, `int`, `unsigned int`,
        `long int`, `unsigned long int`, `float`, `double`, `long double`.
            -Se un operando è `long double`, l'altro viene convertito in `long double`.
            -Se un operando è `double`, l'altro viene convertito in `double`.
            -Se un operando è `float`, l'altro viene convertito in `float`.
            -Se un operando è `unsigned long int`, l'altro viene convertito in `unsigned long int`.
            -Se un operando è `long int`, l'altro viene convertito in `long int`.
            -Se un operando è `unsigned int`, l'altro viene convertito in `unsigned int`.
            -Altrimenti, entrambi gli operandi sono `int` e il risultato è `int`.

    Ad esempio, se hai un'operazione tra un int e un float, il int viene convertito in float prima dell'operazione.
    Se hai un'operazione tra un int e un double, il int viene convertito in double.
    */
    //Nel frammento di codice
    short i=5;
    i = i + 4;
    //si ha che la variabile i di tipo short è convertita in int e sommata alla costante intera 4. Il risultato della somma è 
    //convertito in short, prima dell’assegnazione. In quest’altro esempio:
    double dd = 5.6;
    int intero = 3;
    intero = intero + dd;
    //la variabile intera i è convertita in double, sommata alla variabile double dd e il risultato della somma, prima 
    //dell’assegnazione, è convertito in int, con eventuale perdita di precisione.
    //facciamo una altro esempio
    int k = 5, m = 4, n;
    double x = 1.5, y = 2.1, z;
    //la somma k+x darebbe 6.5 siccome k è convertito in double prima dell'operazione (poi dopo l'operazione
    //ci potrebbe essere un ulteriore cast per salvare la variabile)
    n = k+x;   //il valore dell'espressione è 6.5 ma viene salvato 6 perché n è un int
    printf("n = %d\n", n);
    
    z = k/m; //k/m è una divisione tra interi e dà quindi un numero intero, e anche se z è un numero reale non lo si ottiene
    printf("z = %f\n", z);  //divisione intera tra k e m => 5/4 = 1 (divisione reale 1.25)

    n = x*y; //prima viene effettuata l'operazione tra double, poi viene salvato il numero troncando la parte decimale
    printf("n = %d\n", n);   //x*y => 1.5*2.1 = 3.15 => troncato 3


    
    /*Un’espressione di un certo tipo può essere esplicitamente convertita in un altro tipo per mezzo dell’operazione detta di 
    cast.
    La sintassi generale del cast 
    è:
    (nome_tipo) espressione
    In pratica nome_tipo è lo stesso che si usa nella dichiarazione delle variabili. Si consideri il semplice esempio:
    */
    int *p_int, num;
    p_int = &num;
    char *p_char;
    p_char = (char*) p_int; 
    /*
    Alla variabile a di tipo char* viene assegnato l'indirizzo di p_int ma considerandolo come puntatore a int. Si 
    faccia bene attenzione: il tipo della variabile p_int, e così il suo contenuto, rimane int* anche dopo il cast.
    Semplicemente il compilatore valuta l’espressione p_int, e il risultato di tale espressione è
    temporaneamente convertito in char*, e così convertito è assegnato alla variabile p_char. 
    I cast sono principalmente usati per:
        1. convertire puntatori di tipo diverso;
        2. eseguire calcoli con la precisione desiderata senza dover introdurre una variabile temporanea.
    Finora abbiamo sempre usato il cast per operare conversioni tra puntatori che puntano a tipi diversi, ma può essere utile 
    usarlo anche nelle espressioni aritmetiche:
    */
    /*int*/ i = ((long)i * 10) /9;
    //Trasformare la variabile int i in long, prima della moltiplicazione, garantisce che le operazioni di moltiplicazione e 
    //divisione vengano eseguite con una precisione maggiore. Nell’esempio:
    //int i, k;

    k = (i+7)*3 + (double)(k+2*i);
    //la moltiplicazione tra (i+7)*3 è una moltiplicazione tra int ed è eseguita per prima, mentre il risultato 
    //dell’espressione (k+2*i) è convertito in double, e la somma tra le due espressioni (i+7)*3 e (k+2*i) è di 
    //tipo double. Il risultato della somma è poi implicitamente convertito in int, con eventuale perdita di precisione.
}