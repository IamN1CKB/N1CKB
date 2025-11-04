package programmazione_ad_oggetti.esercizi.esami.aprile17_2023;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.File;

public class Main {
    public static void main(String[] args) {

        // DistributoreImpl Distr();
        String pathInput = "Java\\programmazione_ad_oggetti\\esercizi\\esami\\aprile17_2023\\input.csv";
        String pathStock = "Java\\programmazione_ad_oggetti\\esercizi\\esami\\aprile17_2023\\stock.csv";
        File FileInput = new File(pathInput);
        if (FileInput.exists()) {
            try {
                BufferedReader br_input = new BufferedReader(new FileReader(pathInput));
                String riga;
                boolean scelta = true;
                DistributoreImpl distributore = new DistributoreImpl(pathStock);
                do {
                    // stampa menu principale
                    System.out.println("Benvenuto nel distributore automatico\nScegli una delle opzioni:");
                    System.out.println("1. Acquista un prodotto");
                    System.out.println("2. Aggiungi un prodotto");
                    System.out.println("3. Carica il distributore");
                    System.out.println("0. Esci");
                    // leggiamo le righe del file input.csv
                    while ((riga = br_input.readLine()) != null) {
                        // salvo la riga tra le informazione tra le ,
                        String[] campi = riga.replaceAll("\"", "").split(",");

                        // in base al primo elemento della riga, capiamo qual è l'operazione da svolgere
                        switch (campi[0]) {
                            case "1": // acquista un prodotto. es riga: 1,"CENT50 CENT50 CENT50 0","A6"
                                // dividiamo i valori "CENT50 CENT50 CENT50 0" (sostituiamo prima le virgolette
                                // di troppo)
                                String[] moneteInserite = campi[1].split(" ");
                                int i = 0;
                                do {
                                    System.out.println("Inserisci le moneta o 0 per terminare");
                                    distributore.aggiungiMoneta(moneteInserite[i]);
                                    i++;
                                } while (!moneteInserite[i].equals("0"));
                                distributore.stampaCredito();
                                distributore.acquistaProdotto(campi[2]);
                                distributore.stampaStock();
                                break;

                            case "2": // aggiungi un prodotto
                                String[] attributiProdotto = campi[1].split(" ");
                                // se è precisato il numero dei prodotti, abbiamo 4 elementi di
                                // attributiProdotto
                                if (attributiProdotto.length < 4)
                                    distributore.modificaProdotto(new Prodotto(attributiProdotto[0],
                                            attributiProdotto[1], Float.parseFloat(attributiProdotto[2])), true);
                                else
                                    distributore.modificaProdotto(new Prodotto(attributiProdotto[0],
                                            attributiProdotto[1], Float.parseFloat(attributiProdotto[2]),
                                            Integer.parseInt(attributiProdotto[3])), true);

                                break;

                            case "3": // stampare il distributore
                                System.out.println("Inserisci il nome del file");
                                distributore.stampaStock();
                                break;

                            case "0":
                                scelta = false;
                                break;

                            default:
                                System.out.println("scelta non valida");
                                break;
                        }
                    }

                } while (scelta);
                br_input.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
        } else
            System.out.println("errore con i file");
    }

}