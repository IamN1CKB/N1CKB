package programmazione_ad_oggetti.teoria.parte1;

public class Main1 {
    public static void main(String[] args) {
        System.out.print("Ciao,"); // istruzione per stampare in console una stringa, senza mandare a capo
        System.out.print(" sono Nicola."); // istruzione per stampare in console una stringa, senza mandare a capo
        System.out.println(" scritta con carattere finale mandato a capo (\\n)");
        System.out.println("scritta su una nuova riga");

        /*
         * commenti multiriga
         */
        int x; // dichiarazione
        x = 45; // assegnazione
        int y = 10; // inizializzazione

        System.out.println(x + y);

        // nomenclatura variabili
        int etaPersona = 10; // camel case
        int eta_cane = 4; // snake case
        // di solito per convenzione usiamo il camel case sulle variabili, e lo snake
        // case (tutto in maiuscolo) sulle costanti
        int sommaEta = etaPersona + eta_cane;
        System.out.println(sommaEta);

        // Java di dati primitive e reference
        // boolean true : false 1 bit
        boolean luce = true;
        // byte -1281 : 127 1 byte
        byte n = 60;
        // short -32768 : 32767 2 bytes
        short a = 1000;
        // int -2 miliardi : 2 miliardi 4 bytes
        int b = 1_000_000; // possiamo mettere gli underscore per comprendere meglio il numero
        // long -9 quintilioni : 9 quintilioni 8 bytes
        long c = 3_000_000_000_000l; // va inserito l o L alla fine del numero
        // float numero con 6-7 cifre decimali 5.123526f 4 bytes
        float d = 2.45234f; // dobbiamo mettere la f finale
        // double numero con 15 cifre decimali 5.123526236701522 8 bytes
        double e = 2.3456543543;
        // char singolo carattere/lettera/ASCII 'f' 2 bytes
        char carattere = 'a'; // dobbiamo usare i singoli apici (possono essere visti anche come numeri short)
        // String sequenza di caratteri "ciao dal corso java" variabile
        String stringa = "stringa a caso";

        // differenze tra primitive e reference
        // ci sono 2 tipi di variabili, primitive date da Java, e reference create da
        // noi
        // vengono identificate dall'iniziale del tipo. se è minuscola sono primitive,
        // se è maiuscola sono reference

        // le reference portano un insieme di attributi e metodi che possiamo utilizzare
        // con la notazione puntata
        System.out.println(stringa);
        System.out.println(stringa.toUpperCase());
        // le primitive non possono usare questi attributi e metodi

        // la jvm che compila il codice ci consiglia di eliminare le variabili che non
        // usiamo
        // siccome questi sono file spiegazione ci sono vari file che non usiamo, e che
        // per togliere il warning del compilatore
        // usiamo ora a caso
        System.out.println(n + a + b + c + d + e + carattere + stringa);
        System.out.println(luce);
    }
}