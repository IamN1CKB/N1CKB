package algoritmi_e_strutture_dati.Esercitazione_strutture_dati;
import algoritmi_e_strutture_dati.Strutture_dati.VisitBinTree;
import algoritmi_e_strutture_dati.Strutture_dati.Position;


public class EsVisitBinTree {

    // Metodo helper per aggiungere contemporaneamente due figli sinistro/destro
    public static void addSons(VisitBinTree<Integer> btree, Position<Integer> parent, int k) {
        btree.addLeft(parent, k);
        btree.addRight(parent, k + 1);
    }

    public static void main(String[] args) {
        VisitBinTree<Integer> btree = new VisitBinTree<>();
        System.out.println("Avvio riempimento albero");

        // Radice
        Position<Integer> root = btree.addRoot(0);

        // Costruzione del livello 1
        addSons(btree, root, 1); // Aggiunge 1 a sinistra e 2 a destra di 0

        // Costruzione del livello 2
        addSons(btree, btree.left(root), 3);  // Aggiunge 3 a sinistra e 4 a destra di 1
        addSons(btree, btree.right(root), 5); // Aggiunge 5 a sinistra e 6 a destra di 2

        System.out.println("Dimensione btree = " + btree.size());

        // 1. Stampa in ordine Simmetrico (Inorder)
        System.out.println("Stampa nodi albero in ordine (In-order):");
        for (Position<Integer> p : btree.inOrder()) {
            System.out.println(p.getElement());
        }

        // 2. Stampa in Pre-ordine
        System.out.println("Stampa nodi albero in preordine (Pre-order):");
        btree.preorder(root);

        // 3. Stampa in Post-ordine
        System.out.println("Stampa nodi albero in postordine (Post-order):");
        btree.postorder(root);

        // 4. Stampa in Ampiezza
        System.out.println("Stampa nodi albero in ampiezza (Breadth-first):");
        btree.breadthfirst();
    }
}