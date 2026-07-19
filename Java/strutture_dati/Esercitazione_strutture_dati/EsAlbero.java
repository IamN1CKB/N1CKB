package strutture_dati.Esercitazione_strutture_dati;

import strutture_dati.Position;
import strutture_dati.VisitGenTree;

public class EsAlbero {
    public static void main(String[] args) {
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
