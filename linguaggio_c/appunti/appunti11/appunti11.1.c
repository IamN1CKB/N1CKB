#include <stdio.h>
#include <limits.h>
void main() {
    //Costanti
    /*
    Si dice costante un valore che non può essere variato durante l’esecuzione di un programma. A una costante può essere 
    associato un nome simbolico come sua rappresentazione.
    Le costanti più comuni sono i dati che non sono salvati in variabili ma sono scritti direttamente in quel modo nel codice
    es:
    */
    for (int i = 0; i < 4; i++)
        printf("prova ");
    printf("\n");
    /*
    le costanti possono essere int  long    double  char    char[], ossia stringa

    l tipo di una costante decimale è int se int è sufficiente a contenerla, altrimenti è long. Il compilatore avverte se si 
    stanno trattando costanti più grandi di quelli rappresentabili sulla macchina. Per facilitare la programmazione di basso 
    livello il linguaggio consente la definizione di costanti numeriche in sintassi ottale ed esadecimale (purtroppo manca la 
    sintassi binaria):
        • ottale aggiungere una cifra 0 prima della costante
        • esadecimale aggiungere 0x o 0X prima della costante
    Per esempio: 012, 077, -05 sono costanti ottali, mentre 0xAA, 0xddL, 0xF sono costanti esadecimali.

    una costante floating point è di tipo double (le costanti non possono essere di tipo float). Il compilatore, in genere, avverte anche in questo caso se si stanno 
    trattando costanti più grandi di quelli rappresentabili sulla macchina.

    Le costanti più usate sono le costanti simboliche.
    Si ricorda che, nonostante l’apparenza, questi sono tutti caratteri singoli. 
    Le costanti cui si fa riferimento con un nome (o simbolo) sono dette costanti simboliche. Una costante simbolica è 
    quindi un nome il cui valore non può essere ridefinito nell’ambito di validità del nome stesso. In C esistono tre tipi di 
    costanti simboliche:
        1. costanti rese simboliche per mezzo della parola chiave const;
        2. una collezione di costanti elencato da una enumerazione;
        3. costanti simboliche corrispondenti ai nomi di array e funzioni.

    La parola chiave const può essere aggiunta alla dichiarazione di un oggetto in modo da rendere quell’oggetto una 
    costante invece di una variabile:
    */
    const int modello = 145;
    const int v[] = {1, 2, 3, 4};
    /*
    Il lettore osservi come, non potendosi effettuare assegnazioni a una costante nel corso di un programma, si debba 
    necessariamente procedere alla inizializzazione in fase di dichiarazione:
    */
        //modello = 165;    // darebbe errore
        //modello++;        // darebbe errore
    /*
    Dichiarando un nome const si fa in modo che il suo valore non cambi nell’ambito di validità del nome. Dunque 
    const è un modificatore di tipo, nel senso che limita i modi in cui un oggetto può essere usato, senza di per sé 
    specificare il tipo di quell’oggetto. 
    Non è richiesta alcuna memoria dati per allocare una costante, per il semplice motivo che il compilatore conosce il suo 
    valore e lo sostituisce all’interno del programma prima di generare l’eseguibile. L’inizializzatore di un nome di tipo 
    const può essere anche una espressione di tipo costante che comunque viene valutata durante la compilazione. Il tipo 
    const è utilizzato anche per ottenere costanti in virgola mobile di tipo float, non disponibili di per sé:
    const float pi8 = 3.14159265;
    La dichiarazione const int può essere abbreviata da const.

    la dichiarazione di una variabile puntatore come const è leggermente diversa
    
    */
    int g, m = 5;
    const int *punt = &g;
    punt = &m;  //cambio di variabile puntata ammesso
    //*punt = 10;      //cambio del valore della variabile puntata non ammesso: errore
    /*
    una variabile puntatore come const può cambiare il valore dell'indirizzo della variabile a cui punta (quindi cambiare variabile da puntare)
    ma non può cambiare il valore della variabile puntata
    */

    //Esiste un metodo alternativo di definire costanti intere, spesso più conveniente dell’uso di const. Per esempio:
    enum { QUI, QUO, QUA };
    //definisce tre costanti intere dette enumeratori alle quali assegna implicitamente dei valori interi sequenziali e crescenti a 
    //partire da zero; enum { QUI, QUO, QUA } è equivalente a (li scrivo in minuscolo in modo da non generare errori):
    const int qui = 0;
    const int quo = 1;
    const int qua = 2;
    printf("QUI = %d\n", QUI);
    printf("QUO = %d\n", QUO);
    printf("QUA = %d\n", QUA);
    //A una enumerazione può essere associato un nome:
    enum carte {ASSO, BASTONI, COPPE, DENARI};
    
    //che non è un nuovo tipo ma un sinonimo di int. Agli enumeratori possono essere anche assegnati esplicitamente valori:
    enum valore_simbolo {NOME, NUMERO, FINE, PIU = '+', MENO = '-', PER = '*', DIV = '/'}; 
    //La dichiarazione
    enum valore_simbolo x = DIV;   //nella dichiarazione della variabile va specificato che è di tipo enum e anche di che tipo enum
    //costituisce un utile suggerimento sia per il lettore sia per il compilatore!
    printf("x = %c", x);  //x = / 
    
}