package algoritmi_e_strutture_dati.Prove_d_esame;
import algoritmi_e_strutture_dati.Strutture_dati.PositionalList;
import algoritmi_e_strutture_dati.Strutture_dati.Position;
import algoritmi_e_strutture_dati.Strutture_dati.LinkedPositionalList;
/*
* Scrivere un metodo che a partire da una stringa **Testo** passata come parametro, utilizzando i soli metodi 
  pubblici dell'interfaccia, crei una lista posizionale di caratteri che contiene tutti i caratteri di **Testo**. 
  Successivamente, modificare la lista (senza creare una nuova lista posizionale) inserendo al posto di ogni 
  carattere '*' eventualmente presente la sequenza di caratteri "123". 
*/

public class ProvaLuglio2026 {

    public static void elaboraTesto(String testo) {
        // Ipotizziamo l'esistenza di una classe concreta (es. LinkedPositionalList) 
        // che implementa la nostra interfaccia PositionalList
        PositionalList<Character> lista = new LinkedPositionalList<>();
        
        // 1. Creiamo la lista posizionale aggiungendo tutti i caratteri della stringa
        for (int i = 0; i < testo.length(); i++) {
            lista.addLast(testo.charAt(i));
        }
        
        // 2. Modifichiamo la lista cercando eventuali caratteri '*'
        Position<Character> cursore = lista.first();
        
        while (cursore != null) {
            // Salviamo il prossimo elemento PRIMA di un'eventuale rimozione
            // in modo da non "rompere" l'iterazione
            Position<Character> prossimo = lista.after(cursore);
            
            if (cursore.getElement() == '*') {
                // Inseriamo la sequenza '1', '2', '3' prima dell'asterisco
                lista.addBefore(cursore, '1');
                lista.addBefore(cursore, '2');
                lista.addBefore(cursore, '3');
                
                // Rimuoviamo l'asterisco dalla lista
                lista.remove(cursore);
            }
            
            // Avanziamo al prossimo nodo originale
            cursore = prossimo;
        }
    }
}