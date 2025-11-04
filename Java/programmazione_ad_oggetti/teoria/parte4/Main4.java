package programmazione_ad_oggetti.teoria.parte4;

import java.util.ArrayList;
import java.util.Iterator;

public class Main4 {
    public static void main(String[] args) {
        // un interatore è un oggetto che è usato per iterare un collezione dati (come
        // ArrayList o HashSet).
        // la documentazione di java sconsiglia di rimuovere elementi di un array list o
        // hashSet con un loop o foreach loop siccome
        // la struttura dati cambia dimensione durante il loop
        ArrayList<String> persone = new ArrayList<String>();
        persone.add("Luca");
        persone.add("Marco");
        persone.add("Anna");
        persone.add("Paolo");

        // adesso creiamo l'oggetto iterator, che deve iterare una collezione di String
        Iterator<String> iterator = persone.iterator();
        // il metodo next() ci permette di spostarci in avanti nell'iterator
        System.out.println(iterator.next()); // Luca
        System.out.println(iterator.next()); // Marco
        System.out.println(iterator.next()); // Anna
        System.out.println(iterator.next()); // Paolo

        // il metodo hasNext() ci restituisce un boolean che dice se siamo all'ultimo
        // elemento della collezione dati
        System.out.println(iterator.hasNext());
        // per riportare l'iterator a inizio collezione dati, riassegniamo all'iterator
        // il valore precedente
        iterator = persone.iterator();

        while (iterator.hasNext()) {
            String persona = iterator.next();
            if (persona == "Anna") {
                iterator.remove();
            }
        }
        System.out.println(persone);

    }
}
