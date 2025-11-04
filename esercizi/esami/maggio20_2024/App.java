package programmazione_ad_oggetti.esercizi.esami.maggio20_2024;

import java.io.BufferedReader;
import java.io.FileReader;

public class App {
    public static void main(String[] args) {
        Magazzino magazzino = new Magazzino();
        String path = "Java\\programmazione_ad_oggetti\\esercizi\\esami\\maggio20_2024\\magazzino.csv";
        try (BufferedReader br = new BufferedReader(new FileReader(path))) {
            br.readLine();
            String riga;
            while ((riga = br.readLine()) != null) {
                String[] campi = riga.split(",");
                if (campi[0].charAt(0) == 'A') {
                    magazzino.aggiungiProdotto(new Alimentare(campi[0], campi[1], Float.parseFloat(campi[2]),
                            Integer.parseInt(campi[3]), campi[4]));
                } else if (campi[0].charAt(0) == 'E') {
                    magazzino.aggiungiProdotto(new Elettrodomestico(campi[0], campi[1], Float.parseFloat(campi[2]),
                            Integer.parseInt(campi[3]), Integer.parseInt(campi[5])));
                } else {
                    throw new Exception("Prodotto non identificato");
                }
            }
            magazzino.stampaScontrino();

            System.out.println("Prodotto da eliminare una quantità: " + magazzino.ricercaProdotto("A002").getNome());
            magazzino.rimuoviProdotto(magazzino.ricercaProdotto("A002"));

            magazzino.stampaScontrino();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
