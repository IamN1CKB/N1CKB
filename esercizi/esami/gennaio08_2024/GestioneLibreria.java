package programmazione_ad_oggetti.esercizi.esami.gennaio08_2024;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;

public class GestioneLibreria implements GestioneFile {
    ArrayList<RisorsaDigitale> lista = new ArrayList<RisorsaDigitale>();

    void aggiungiRisorsa(RisorsaDigitale risorsa) {
        lista.add(risorsa);
    }

    void mostraElencoRisorse() {
        for (RisorsaDigitale risorsa : lista) {
            if (risorsa instanceof Libro) {
                System.out.println("Descrizione Libro");
                System.out.println("titolo: " + risorsa.titolo);
                System.out.println("autore: " + risorsa.autore);
                System.out.println("anno di pubblicazione: " + risorsa.annoPubblicazione);
                System.out.println("numero di pagine: " + ((Libro) risorsa).numeroPagine);
            } else if (risorsa instanceof Audiolibro) {
                System.out.println("Descrizione Audiolibro");
                System.out.println("titolo: " + risorsa.titolo);
                System.out.println("autore: " + risorsa.autore);
                System.out.println("anno di pubblicazione: " + risorsa.annoPubblicazione);
                System.out.println("durata in minuti: " + ((Audiolibro) risorsa).durataMin);
            }
            System.out.println("");
        }
    }

    @Override
    public void scriviSuFile(String nomeFile) {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(nomeFile))) {
            bw.write("tipo,titolo,autore,annoPubblicazione,numeroPagine,durata\n");
            for (RisorsaDigitale risorsa : lista) {
                if (risorsa instanceof Libro) {
                    bw.write("Libro," + risorsa.titolo + "," + risorsa.autore + "," + risorsa.annoPubblicazione + ","
                            + ((Libro) risorsa).numeroPagine + ",");

                } else if (risorsa instanceof Audiolibro) {
                    bw.write("Audiolibro," + risorsa.titolo + "," + risorsa.autore + "," + risorsa.annoPubblicazione
                            + ",," + ((Audiolibro) risorsa).durataMin);
                } else
                    throw new Exception("risorsa non disponibile");
                bw.newLine();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public void leggiDaFile(String nomeFile) {
        try (BufferedReader br = new BufferedReader(new FileReader(nomeFile))) {
            this.lista.clear(); // ripuliamo la lista, altrimenti mettiamo dei doppioni
            br.readLine(); // salta intestazione
            String riga;
            while ((riga = br.readLine()) != null) {
                String[] campi = riga.split(",");
                if (campi[0].equals("Libro")) {
                    this.lista
                            .add(new Libro(campi[1], campi[2], Integer.parseInt(campi[3]), Integer.parseInt(campi[4])));
                } else if (campi[0].equals("Audiolibro")) {
                    this.lista.add(
                            new Audiolibro(campi[1], campi[2], Integer.parseInt(campi[3]), Integer.parseInt(campi[5])));
                } else {
                    throw new Exception("Risorsa digitale non disponibile");
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    void modificaRisorsa(String titolo, RisorsaDigitale nuovaRisorsa) {
        for (int i = 0; i < lista.size(); i++) {
            // non usiamo for each perché dobbiamo ricordare che indice ha l'oggetto da
            // modificare
            // inoltre nella condizione if controlliamo che abbia sia lo stesso titolo del
            // parametro,
            // sia la stessa classe esatta, per distinguere da libri e audiolibri
            if (lista.get(i).titolo.equals(titolo) && (lista.get(i).getClass() == nuovaRisorsa.getClass()))
                lista.set(i, nuovaRisorsa);
        }
    }
}
