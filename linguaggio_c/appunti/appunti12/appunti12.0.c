#include <stdio.h>
void main() {
    /*
    Per mezzo di un array è possibile individuare mediante un nome e un indice un insieme di elementi dello stesso tipo.
    Ci sono però problemi in cui è necessario aggregare elementi di tipo diverso per formare una struttura. Per esempio, 
    se si vuol rappresentare il concetto di data basta definire una struttura siffatta:
    */
    struct data {
        int giorno;
        char *mese;
        int anno;
    };
    //Si osservi come per effetto di questa dichiarazione si sia introdotto nel programma un nuovo tipo, il tipo data. D’ora in 
    //poi sarà possibile definire variabili in cui tipo è data.
    struct data oggi;
    /*
    Come deve essere interpretata la variabile oggi di tipo data? Semplicemente come una variabile strutturata, 
    composta di tre parti: due di tipo int − giorno e anno − e una di tipo stringa − mese −. La sintassi generale 
    per la definizione di una struttura è:
        struct nome_struttura {
            tipo_membro nome_membro1;
            tipo_membro nome_membro2;
            ...
            tipo_membro nome_membroN;
        };
    Gli elementi della struttura sono detti membri; essi sono identificati da un nome, nome_membro, e da un tipo, 
    tipo_membro, che può essere sia fondamentale sia derivato.
    Nell’esempio della struttura data si ha che giorno e 
    anno sono di tipo int, cioè un tipo fondamentale, mentre mese è di tipo char *, cioè di tipo derivato. Si osservi il 
    punto e virgola posto in coda alla definizione di una struttura: è questo uno dei rari casi in cui in C occorre mettere un 
    “;” dopo una parentesi graffa; il lettore presti la dovuta attenzione a questo particolare, spesso trascurato.

    Una volta definita una struttura, nome_struttura diviene un nuovo tipo a tutti gli effetti. Si possono allora definire 
    variabili il cui tipo è nome_struttura:
    struct nome_struttura nome_variabile;
    Per esempio si può scrivere:
        struct data oggi, ieri, compleanno;
    */

    //Esiste anche un’altra sintassi per la definizione di variabili di tipo struttura. Per esempio:
    struct automobile {
        char *marca;
        char *modello;
        int venduto;
    } a1, a2;
    /*
    introduce la struttura automobile, e al contempo, anche due variabili di tipo automobile, a1 e a2. In luogo di 
    questa definizione di struttura e di variabili insieme, avremmo potuto usare la forma equivalente:
        struct automobile {
             char *marca;
             char *modello;
             int venduto;
        };
        struct automobile a1, a2;
    È lasciato alla sensibilità del lettore stabilire quale delle due convenzioni usare per definire una variabile struttura. 
    Per poter accedere ai campi di una variabile di tipo struttura si fa uso dell’operatore punto (.):
    */
    oggi.giorno = 11;
    oggi. mese = "Gennaio";
    oggi. anno = 2024;
    struct data ieri;
    ieri.giorno = oggi.giorno -1;
    ieri.mese = oggi.mese;
    ieri.anno = oggi.anno;
    printf("il mese di oggi è %s\n", oggi.mese);
    
    struct {
        int campo1;
        float campo2;
    } punto;
    punto.campo1 = 3;
    /*In questo esempio, la struttura anonima viene dichiarata insieme alla dichiarazione della variabile punto. Puoi quindi utilizzare 
    immediatamente la variabile punto per memorizzare i dati della struttura.

    La cosa importante da notare è che, se non assegni un nome alla struttura, non sarai in grado di dichiarare altre variabili dello stesso 
    tipo in un secondo momento nel tuo codice. La struttura anonima è utile quando hai bisogno solo di una variabile di quel tipo in un 
    contesto specifico e non prevedi di dichiararne altre. Se hai bisogno di utilizzare la stessa struttura in più parti del codice, può 
    essere preferibile dare un nome alla struttura.
    
    
    Talvolta ci si può riferire a una variabile di tipo struttura nel suo insieme, attraverso il nome, senza dover far riferimento 
    ai singoli membri. Per esempio, in C è possibile effettuare assegnazioni tra variabili struttura dello stesso tipo:
        struct data compleanno, oggi;
        compleanno = oggi;
    è una assegnazione consentita che effettua una copia di tutti i valori dei membri di oggi nei corrispondenti valori dei 
    membri di compleanno.
    
    Due strutture corrispondono a due tipi differenti anche se hanno gli stessi membri. Per esempio:
        struct sl {
            int a;
        };
        struct s2 {
            int a;
        };
    sono due tipi struttura differenti:
    inoltre l'assegnazione di una variabile di tipo struct ad un altra variabile di tipo struct ma differente darebbe errore
        struct s1 bob;
        struct s2 alex;
        ...
        alex = bob; //errore: tipi dati discordi
    Quest’ultima assegnazione darebbe luogo a un errore, poiché si è tentato di assegnare una variabile di tipo s1 a una di 
    tipo s2. Inoltre si ricordi che i tipi struttura sono diversi anche dai tipi fondamentali. Per esempio, in
        struct s1 bobo;
        int i;
        ...
        bobo = i; // errore: tipi dati discordi
    l’ultima assegnazione provocherebbe un errore a causa della disomogeneità di tipo.
    */
    
    
}