package strutture_dati;
import java.util.Iterator;

public class Main3 {

    public static void main(String[] args) {
        // 1. Istanziazione della lista posizionale
        LinkedPositionalList<String> listapos = new LinkedPositionalList<>();

        // 2. Definizione dei dati e popolamento
        String[] testo = {"primo", "secondo", "terzo"};
        System.out.println("Avvio lista");

        for (String s : testo) {
            listapos.addLast(s);
        }

        // 3. Sostituzione dell'elemento di testa
        String s1 = "primonuovo";
        listapos.set(listapos.first(), s1);

        // 4. Stampa dei metadati di base
        System.out.println("Dimensione lista= " + listapos.size());
        System.out.println("Primo lista= " + listapos.first().getElement());

        Position<String> p = listapos.after(listapos.first());
        System.out.println("Elemento successivo al primo= " + p.getElement());
        System.out.println(); // Spaziatore logico

        // 5. ATTREVERSAMENTO 1: Iteratore classico di elementi (ElementIterator)
        Iterator<String> iter = listapos.iterator();
        while (iter.hasNext()) {
            System.out.println("Valore nella lista= " + iter.next());
        }
        System.out.println(); // Spaziatore logico

        // 6. ATTRAVERSAMENTO 2: Iteratore in avanti delle posizioni (positions())
        Iterable<Position<String>> iter2 = listapos.positions();
        for (Position<String> p1 : iter2) {
            System.out.println("Valore nella lista per posizione = " + p1.getElement());
        }
        System.out.println(); // Spaziatore logico

        // 7. ATTRAVERSAMENTO 3: Iteratore a ritroso delle posizioni (positionsB())
       // Iterable<Position<String>> iterB = listapos.positionsB();
       // for (Position<String> p1 : iterB) {
       //     System.out.println("Valore nella lista per posizione a ritroso = " + p1.getElement());
       // }
    }

}
