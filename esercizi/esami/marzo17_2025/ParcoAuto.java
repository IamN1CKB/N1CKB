package programmazione_ad_oggetti.esercizi.esami.marzo17_2025;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;

/*
 * Implementare una classe ParcoAuto che gestisca l’elenco dei veicoli disponibili nel concessionario.
 * Questa classe deve contenere un elenco di veicoli, consentire l’aggiunta e la rimozione di veicoli,
 * aggiornare le informazioni e fornire metodi per visualizzare i veicoli disponibili per vendita o noleggio.
 */
public class ParcoAuto implements GestioneDati {
    ArrayList<Veicolo> lista = new ArrayList<Veicolo>();

    @Override
    public void leggiDaFile(String path) {
        try (BufferedReader br = new BufferedReader(new FileReader(path))) {
            // eliminiamo la lista attuale
            this.lista.clear();
            br.readLine(); // salta intestazione
            String riga;
            while ((riga = br.readLine()) != null) {
                String[] campi = riga.split(",");
                if (campi[0].equals("VeicoloVendita")) {
                    this.lista.add(new VeicoloVendita(campi[1], campi[2], campi[3], Integer.parseInt(campi[4]),
                            Double.parseDouble(campi[5]), Integer.parseInt(campi[6]), Boolean.parseBoolean(campi[7]),
                            Boolean.parseBoolean(campi[8])));

                } else if (campi[0].equals("VeicoloNoleggio")) {
                    this.lista.add(new VeicoloNoleggio(campi[1], campi[2], campi[3], Integer.parseInt(campi[4]),
                            Double.parseDouble(campi[9]), Double.parseDouble(campi[10]),
                            Boolean.parseBoolean(campi[11])));
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public void scriviSuFile(String path) {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(path))) {
            bw.write(
                    "tipo,targa,marca,modello,anno,prezzo,garanzia,finanziamento,nuovo,giornaliera,cauzione,assicurazione\n");

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void aggiungiVeicolo(Veicolo veicolo) {
        lista.add(veicolo);
    }

    public void rimuoviVeicolo(Veicolo veicolo) {
        for (int i = 0; i < lista.size(); i++) {
            if (lista.get(i).targa.equals(veicolo.targa)) {
                lista.remove(i);
                return;
            }
        }
    }

    public void modificaVeicolo(Veicolo veicolo) {
        for (int i = 0; i < lista.size(); i++) {
            if (lista.get(i).targa.equals(veicolo.targa)) {
                lista.set(i, veicolo);
            }
        }
    }

    public void stampaVeicoli() {
        for (Veicolo veicolo : lista) {
            if (veicolo instanceof VeicoloVendita) {
                System.out.println("descrizione veicolo in vendita:");
                System.out.println("targa: " + veicolo.targa);
                System.out.println("marca: " + veicolo.marca);
                System.out.println("modello: " + veicolo.modello);
                System.out.println("anno di immatricolazione: " + veicolo.annoImmatricolazione);
                System.out.println("prezzo: " + veicolo.prezzo);
                System.out.println("anni di garanzia: " + ((VeicoloVendita) veicolo).anniGaranzia);
                System.out.println("possibilità di finanziamento: " + ((VeicoloVendita) veicolo).possFinanziamento);
                if (((VeicoloVendita) veicolo).nuovo)
                    System.out.println("veicolo nuovo");
                else
                    System.out.println("veicolo usato");
            } else if (veicolo instanceof VeicoloNoleggio) {
                System.out.println("descrizione veicolo da noleggiare:");
                System.out.println("targa: " + veicolo.targa);
                System.out.println("marca: " + veicolo.marca);
                System.out.println("modello: " + veicolo.modello);
                System.out.println("anno di immatricolazione: " + veicolo.annoImmatricolazione);
                System.out.println("tariffa giornaliera: " + veicolo.prezzo);
                System.out.println("prezzo della cauzione : " + ((VeicoloNoleggio) veicolo).cauzione);
                System.out.println("assicurazione: " + ((VeicoloNoleggio) veicolo).assicurazioneInclusa);
            } else
                System.err.println("veicolo non trovato");
        }
    }

}
