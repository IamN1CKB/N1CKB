package strutture_dati;

import java.util.Iterator;

public class Main1 {
    public static void main(String[] args) {
        SinglyLinkedList<String> lista = new SinglyLinkedList<String>();
        // La lista è vuota, controlliamolo
        if (lista.isEmpty())
            System.out.println("la lista è vuota");

        // aggiungiamo nella lista "Ciao"
        lista.addFirst("Ciao");
        System.out.println("primo: " + lista.first());
        System.out.println("ultimo: " + lista.last());
        // La lista è "Ciao"

        // aggiungiamo nella lista "A"
        lista.addFirst("A");
        System.out.println("primo: " + lista.first());
        System.out.println("ultimo: " + lista.last());
        // La lista è "A", "Ciao"

        // aggiungiamo nella lista "B" come ultimo
        lista.addLast("B");
        System.out.println("primo: " + lista.first());
        System.out.println("ultimo: " + lista.last());
        // La lista è "A", "Ciao", "B"

        // Rimuoviamo il primo
        lista.removeFirst();
        System.out.println("primo: " + lista.first());
        System.out.println("ultimo: " + lista.last());
        // La lista è "Ciao", "B"

        System.out.println("la dimensione della lista è " + lista.size());

        DoublyLinkedList<Float> listaDoppia = new DoublyLinkedList<Float>();
        listaDoppia.addFirst(2.3f);
        listaDoppia.addFirst(3f);
        listaDoppia.addFirst(23f);
        listaDoppia.addLast(35.6f);
        System.out.println("il primo della lista doppiamente incatenata e' " + listaDoppia.first());
        listaDoppia.stampa();

        ArrayStack<Integer> stack = new ArrayStack<Integer>(20);
        System.out.println("lo stack e' vuoto? " + stack.isEmpty());

        stack.push(12);
        stack.push(23);
        stack.push(34);
        stack.push(113);
        stack.push(11);
        System.out.println("il primo elemento dello stack e' " + stack.top());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println("lo stack e' vuoto? " + stack.isEmpty());

        LinkedPositionalList<String> listaPosizioni = new LinkedPositionalList<String>();
        Position<String> MichelePosition = listaPosizioni.addFirst("Michele");
        // lista: Michele
        Position<String> LucaPosition = listaPosizioni.addFirst("Luca");
        // lista: Luca, Michele
        System.out.println("numero elementi lista posizionale: " + listaPosizioni.size());
        System.out.println("primo elemento della lista posizionala: " + listaPosizioni.first().getElement());
        System.out.println("elemento Michele della lista posizionala: " + MichelePosition.getElement());
        System.out.println("elemento Luca della lista posizionala: " + LucaPosition.getElement());
        // rimuoviamo Luca dalla lista
        listaPosizioni.remove(LucaPosition);
        // lista: Michele
        System.out.println("numero elementi lista posizionale: " + listaPosizioni.size());
        try {
            // se proviamo a stampare un elemento rimosso, ci dà IllegalStateException
            System.out.println("elemento Luca della lista posizionala: " + LucaPosition.getElement());
        } catch (Exception e) {
            System.out.println("\n");
            e.printStackTrace();
            System.out.println("\n");
        }
        System.out.println("elemento Michele della lista posizionala: " + MichelePosition.getElement());
        Position<String> MarioPosition = listaPosizioni.addAfter(MichelePosition, "Mario");
        // lista: Michele, Mario
        System.out.println("elemento Mario della lista posizionala: " + MarioPosition.getElement());
        try {
            // se proviamo ad aggiungere una posizione prima o dopo una posizione che è
            // stata rimossa dalla lista, ci darà IllegalArgumentException
            Position<String> LuigiPosition = listaPosizioni.addBefore(LucaPosition, "Luigi");
            System.out.println(LuigiPosition.getElement());
        } catch (Exception e) {
            System.out.println("\n");
            e.printStackTrace();
            System.out.println("\n");
        }

        Position<String> LuigiPosition = listaPosizioni.addBefore(MichelePosition, "Luigi");
        // lista: Luigi, Michele, Mario
        System.out.println("elemento Luigi della lista posizionala: " + LuigiPosition.getElement());

        System.out.println("stampa con iteratore esplicito della lista posizionale:");
        Iterator<String> iter = listaPosizioni.iterator();
        while (iter.hasNext()) {
            String variabile = iter.next();
            System.out.println(variabile);
        }

        // proviamo a iterare con un for each
        System.out.println("stampa con for each della lista posizionale:");
        for (String s : listaPosizioni) {
            System.out.println(s);
        }

        System.out.println(
                MarioPosition.getElement() + " e' dopo di " + listaPosizioni.before(MarioPosition).getElement());

        // usiamo un albero generico per rappresentare un sistema di cartelle e file
        // usiamo la classe VisitGenTree che estende GenTree e implementa le visite
        VisitGenTree<String> alberoFile = new VisitGenTree<String>();
        Position<String> root = alberoFile.addRoot("C:"); // radice dell'albero
        System.out.println("Aggiunto: " + root.getElement());
        Position<String> users = alberoFile.addChild(root, "Users");
        System.out.println("Aggiunto: " + users.getElement());
        Position<String> nicol = alberoFile.addChild(users, "nicol");
        System.out.println("Aggiunto: " + nicol.getElement());
        Position<String> desktop = alberoFile.addChild(nicol, "Desktop");
        System.out.println("Aggiunto: " + desktop.getElement());
        Position<String> documenti = alberoFile.addChild(nicol, "Documenti");
        System.out.println("Aggiunto: " + documenti.getElement());
        Position<String> foto = alberoFile.addChild(nicol, "Foto");
        System.out.println("Aggiunto: " + foto.getElement());
        Position<String> file1 = alberoFile.addChild(desktop, "file1.txt");
        System.out.println("Aggiunto: " + file1.getElement());
        Position<String> file2 = alberoFile.addChild(desktop, "file2.txt");
        System.out.println("Aggiunto: " + file2.getElement());
        Position<String> file3 = alberoFile.addChild(documenti, "file3.txt");
        System.out.println("Aggiunto: " + file3.getElement());
        Position<String> vacanze = alberoFile.addChild(foto, "Vacanze");
        System.out.println("Aggiunto: " + vacanze.getElement());
        Position<String> img1 = alberoFile.addChild(vacanze, "img1.jpg");
        System.out.println("Aggiunto: " + img1.getElement());
        Position<String> img2 = alberoFile.addChild(vacanze, "img2.jpg");
        System.out.println("Aggiunto: " + img2.getElement());
        Position<String> img3 = alberoFile.addChild(vacanze, "img3.jpg");
        System.out.println("Aggiunto: " + img3.getElement());
        Position<String> amici = alberoFile.addChild(foto, "Amici");
        System.out.println("Aggiunto: " + amici.getElement());
        Position<String> img4 = alberoFile.addChild(amici, "img4.jpg");
        System.out.println("Aggiunto: " + img4.getElement());
        Position<String> img5 = alberoFile.addChild(amici, "img5.jpg");
        System.out.println("Aggiunto: " + img5.getElement());
        Position<String> img6 = alberoFile.addChild(amici, "img6.jpg");
        System.out.println("Aggiunto: " + img6.getElement());
        // L'albero rappresenta la seguente struttura:
        /*
         * C:
         * └── Users
         * └── nicol
         * ├── Desktop
         * │ ├── file1.txt
         * │ └── file2.txt
         * ├── Documenti
         * │ └── file3.txt
         * └── Foto
         * ├── Vacanze
         * │ ├── img1.jpg
         * │ ├── img2.jpg
         * │ └── img3.jpg
         * └── Amici
         * ├── img4.jpg
         * ├── img5.jpg
         * └── img6.jpg
         */
        System.out.println("Visita in pre-ordine:");
        alberoFile.preOrder(alberoFile.root());
        System.out.println("\nVisita in post-ordine:");
        alberoFile.postOrder(alberoFile.root());
        System.out.println("\nVisita in ampiezza (breadth-first):");
        alberoFile.breadthFirst();

        // vediamo le funzioni di Tree
        System.out.println("\nFunzioni di Tree:");
        System.out.println("La radice dell'albero e': " + alberoFile.root().getElement());
        System.out.println("Il genitore di Vacanze e': " + alberoFile.parent(vacanze).getElement());
        System.out.println("I figli di nicol sono: ");
        for (Position<String> p : alberoFile.children(nicol)) {
            System.out.println("- " + p.getElement());
        }
        System.out.println("Il numero di figli di nicol e': " + alberoFile.numChildren(nicol));
        System.out.println("nicol e' un nodo interno? " + alberoFile.isInternal(nicol));
        System.out.println("img1.jpg e' una foglia? " + alberoFile.isExternal(img1));
        System.out.println("C: e' la radice dell'albero? " + alberoFile.isRoot(root));
        System.out.println("Il numero totale di nodi nell'albero e': " + alberoFile.size());
        System.out.println("L'albero e' vuoto? " + alberoFile.isEmpty());

    }
}
