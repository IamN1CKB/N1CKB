package strutture_dati.esame;
import strutture_dati.Position;

import strutture_dati.VisitGenTree;

public class provaSettembre2025 {
    public static void main(String[] args) {
        VisitGenTree<Float> tree = new VisitGenTree<Float>();
        
        tree.addRoot(5.6f);
        Position<Float> primoFiglio = tree.addChild(tree.root(), 3.2f);
        Position<Float> secondoFiglio = tree.addChild(tree.root(), 8.1f);
        Position<Float> terzoFiglio = tree.addChild(primoFiglio, 1.5f);
        Position<Float> quartoFiglio = tree.addChild(primoFiglio, 4.7f);


        // L'albero rappresenta la seguente struttura:
            /*
            * 5.6:
            * └── 3.2
            * │ └── 1.5
            * │ └── 4.7
            * └── 8.1
            
        */
        // h =2
        
        //for each in preorder, ossia prima padri e poi figli
        int maxH=0;
        for (Position<Float> floatPos : tree.positions()) {
            int h =0;
            if (tree.numChildren(floatPos) ==0) { //se è una foglia
                if (tree.parent(floatPos) != null) {
                    h++;
                    if (tree.parent(tree.parent(floatPos))!= null) {
                        h++;
                    }
                }
            }
            if (h>maxH) {
                maxH=h;
        }
        System.out.println(maxH);
            

    }
}