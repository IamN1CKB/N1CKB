package algoritmi_e_strutture_dati.Prove_d_esame;
/*
Scrivere un metodo che costruisce un albero binario completo e simmetrico di altezza h,
 passata come parametro di ingresso, e contenente gli interi successivi a partire dalla
 radice di valore 1 (vedi figura: albero di altezza pari a 2).
N.B. E' possibile utilizzare come supporto una struttura dati Coda.

**Rappresentazione dell'albero binario:**


          ( 1 )
         /     \
      ( 2 )   ( 3 )
      /   \   /   \
    [ 4 ][ 5 ][ 6 ][ 7 ]



(Nota: i nodi 1, 2 e 3 sono rappresentati con forma circolare nell'immagine,
 mentre le foglie 4, 5, 6 e 7 hanno forma quadrata/rettangolare).
  */
import algoritmi_e_strutture_dati.Strutture_dati.Position;
import algoritmi_e_strutture_dati.Strutture_dati.LinkedQueue;
import algoritmi_e_strutture_dati.Strutture_dati.VisitBinTree;

public class ProvaGiugno2026 {

    public VisitBinTree<Integer> createTree(int h) {

        if (h < 0) return null;

        // Creazione di un albero binario vuoto
        LinkedQueue<Position<Integer>> queue = new LinkedQueue<>();
        VisitBinTree<Integer> tree = new VisitBinTree<>();

        // Calcolo del numero massimo di nodi in un albero binario completo di altezza h,
        // ossia N=2^(h+1)-1
        int N = (int) Math.pow(2, h + 1) - 1;

        int value = 1;

        tree.addRoot(value);
        queue.enqueue(tree.root());
        
        // Costruzione dell'albero in ampiezza fino a raggiungere N nodi
        while (value < N) {
            // Dequeue del nodo corrente
            Position<Integer> p = queue.dequeue();
            value++;
            // Aggiunta del figlio sinistro
            tree.addLeft(p, value);
            // Richiamiamo left(p) sull'oggetto tree per ottenere la posizione del figlio 
            // sinistro appena aggiunto e lo mettiamo in coda per la successiva elaborazione
            queue.enqueue(tree.left(p));

            value++;
            // Aggiunta del figlio destro
            tree.addRight(p, value);
            // Richiamiamo right(p) sull'oggetto tree
            queue.enqueue(tree.right(p));
        }
        
        // Restituiamo l'albero costruito
        return tree;
    }

    public static void main(String[] args) {
        System.out.println("Prova Giugno 2026");
        ProvaGiugno2026 prova = new ProvaGiugno2026();
        VisitBinTree<Integer> tree = prova.createTree(3);
        tree.breadthfirst();
    }
}
