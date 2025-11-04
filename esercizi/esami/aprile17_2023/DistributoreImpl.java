package programmazione_ad_oggetti.esercizi.esami.aprile17_2023;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;

public class DistributoreImpl implements Distributore {
    float credito;
    String pathStock;
    ArrayList<String> stock = new ArrayList<>();

    DistributoreImpl(String pathStock) {
        this.pathStock = pathStock;

        // salvo lo stock per comodità in un ArrayList
        try (BufferedReader br_stock = new BufferedReader(new FileReader(pathStock))) {
            String riga;
            while ((riga = br_stock.readLine()) != null)
                this.stock.add(riga);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public void aggiungiMoneta(String moneta) {
        Moneta mon = Moneta.valueOf(moneta);
        switch (mon) {
            case CENT1:
                credito += 0.01;
                break;
            case CENT2:
                credito += 0.02;
                break;
            case CENT5:
                credito += 0.05;
                break;
            case CENT10:
                credito += 0.10;
                break;
            case CENT20:
                credito += 0.20;
                break;
            case CENT50:
                credito += 0.50;
                break;
            case EURO1:
                credito += 1;
                break;
            case EURO2:
                credito += 2;
                break;
            default:
                break;
        }
    }

    @Override
    public void stampaCredito() {
        System.out.println("il credito inserito e' " + this.credito + " euro" + "\n");
    }

    @Override
    public void acquistaProdotto(String codice) {
        // leggiamo l'ArrayList fin quando non troviamo il prodotto con il codice
        // identificativo giusto
        Prodotto prodotto;
        for (String riga : this.stock) {
            String[] colonne = riga.split(",");
            if (colonne[0].equals(codice)) { // abbiamo trovato il prodotto
                // creiamo un oggetto Prodotto con il codice e le info identificate
                // nell'ArrayList
                prodotto = new Prodotto(codice, colonne[1], Float.parseFloat(colonne[2]));
                if (credito < prodotto.prezzo) {
                    System.err.println("soldi non sufficienti");
                    this.credito = 0;
                    return;
                }
                if (Integer.parseInt(colonne[3]) < prodotto.quantita) {
                    System.err.println("pezzi non sufficienti");
                    return;
                }
                restituisciResto(credito - prodotto.prezzo);
                // togliamo un pezzo del prodotto dallo stock
                modificaProdotto(prodotto, false);
                return;
            }
        }
    }

    @Override
    public void restituisciResto(float resto) {
        System.out.println("il resto da erogare è di " + resto + " euro");
        credito = 0;
    }

    @Override
    public void stampaStock() {
        System.out.println("STOCK DEL DISTRiBUTORE:" + "\n");
        for (int i = 1; i < stock.size(); i++) {
            String[] colonne = stock.get(i).split(",");
            System.out.println("codice identificativo: " + colonne[0]);
            System.out.println("nome: " + colonne[1]);
            System.out.println("prezzo: " + colonne[2] + " euro");
            System.out.println("pezzi rimanenti: " + colonne[3] + "\n");
        }
    }

    @Override
    public void modificaProdotto(Prodotto prodotto, boolean aggiungi) {
        // leggiamo l'ArrayList fin quando non troviamo il prodotto con il codice
        // identificativo giusto
        for (int i = 1; i < this.stock.size(); i++) {
            String[] colonne = this.stock.get(i).split(",");
            if (colonne[0].equals(prodotto.codice)) {// abbiamo trovato il prodotto giusto
                // vediamo se dobbiamo aggiungere o sottrarre pezzi in base alla variabile
                // aggiungi
                if (aggiungi) {
                    // si devono aggiungere dei pezzi pari ai prodotto.quantita
                    colonne[3] = String.valueOf(Integer.parseInt(colonne[3]) + prodotto.quantita);
                } else {
                    // si deve sottrarre un solo pezzo
                    colonne[3] = String.valueOf(Integer.parseInt(colonne[3]) - 1);
                }
                // modifichiamo riga nell'ArrayList, in modo da poterla caricare poi nello stock
                this.stock.set(i, colonne[0] + "," + colonne[1] + "," + colonne[2] + "," + colonne[3]);
                caricaStock();
                return;
            }
        }
    }

    public void caricaStock() {
        try (BufferedWriter bw_stock = new BufferedWriter(new FileWriter(this.pathStock))) {
            for (String riga : stock)
                bw_stock.write(riga + "\n");
            bw_stock.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
