package programmazione_ad_oggetti.teoria.parte1;

public class Main4 {
    public static void main(String[] args) {
        // gli array sono collezioni di dati (già visti in C)
        // gli array sono di lunghezza fissa, quindi non è possibile aggiungere e
        // togliere elementi
        // con gli array list che vedremo in futuro sarà possibile

        // gli array possiamo dichiararli vuoti in questo modo e poi inizializzare gli
        // elementi successivamente
        int[] numeri = new int[3];
        numeri[0] = 1;
        numeri[1] = 4;
        numeri[2] = 6;
        // numeri[3] = 6; //errore: java.lang.ArrayIndexOutOfBoundsException: Index 3
        // out of bounds for length 3
        System.out.println(numeri[2]);

        // possiamo dichiarare e inizializzare l'array nello stesso momento, senza
        // creare l'array vuoto
        char[] caratteri = { 'a', 'b', 'c', 'd' };
        caratteri[3] = 'h';
        System.out.println("" + caratteri[0] + caratteri[3]); // "" + serve a far capire che vogliamo concatenare i
                                                              // caratteri

        // possiamo prendere la lunghezza dell'array con il metodo .length
        System.out.println("i carattere nell'array sono " + caratteri.length);

        // possiamo ciclare gli array con i for
        for (int i = 0; i < caratteri.length; i++) {
            System.out.println("Lettera numero " + (i + 1) + ": " + caratteri[i]);
        }

        for (char lettera : caratteri) {
            System.out.println("lettera dell'array: " + lettera);
        }

        // vediamo le matrici. possiamo prima inizializzare la matrice vuota e poi
        // inizializzare gli elementi
        int[][] n = new int[3][5];

        n[0][0] = 1;
        n[2][4] = 3;

        System.out.println(n[0][0] + n[2][4]);

        // possiamo poi dichiarare una matrice inizializzandola pure
        String classi[][] = {
                { "Nicola", "Michele", "Marco" },
                { "Franco", "Mauro", "Elisabetta" },
                { "Giada", "Amalia", "Salvatore" }
        };
        for (int i = 0; i < classi.length; i++) {
            for (int j = 0; j < classi[i].length; j++) {
                System.out.print(classi[i][j] + "\t\t");
            }
            System.out.println();
        }

        System.out.println();
        System.out.println();
        // proviamo con il for each
        for (String[] singolaClasse : classi) {
            for (String studente : singolaClasse) {
                System.out.print(studente + "\t\t");
            }
            System.out.println();
        }

    }
}
