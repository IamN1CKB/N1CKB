package programmazione_ad_oggetti.esercizi.esami.dicembre19_2023;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class App {
    public static void main(String[] args) {
        try {
            ArchivioDigitale archivio = new ArchivioDigitale();
            BufferedReader br = new BufferedReader(
                    new FileReader("Java\\programmazione_ad_oggetti\\esercizi\\esami\\dicembre19_2023\\input.csv"));
            String riga;
            br.readLine(); // salta intestazione
            while ((riga = br.readLine()) != null) {
                String[] campi = riga.replaceAll(" ", "").split(",");
                if (campi[0].equals("Documento")) {
                    archivio.aggiungiElemento(new Documento(campi[1], campi[2], campi[3].replace("Formato", ""),
                            Integer.parseInt(campi[4].replace("pagine", ""))));
                } else if (campi[0].equals("Immagine")) {
                    archivio.aggiungiElemento(new Immagine(campi[1], campi[2], Risoluzione.valueOf(campi[3]),
                            campi[4].replace("Formato", "")));
                } else if (campi[0].equals("Audio")) {
                    archivio.aggiungiElemento(new Audio(campi[1], campi[2],
                            Integer.parseInt(campi[3].replace("Durata", "").replace("min", "")),
                            campi[4].replace("Formato", "")));
                }
            }
            br.close();

            // scrittura su file csv

            BufferedWriter bw = new BufferedWriter(
                    new FileWriter("Java\\programmazione_ad_oggetti\\esercizi\\esami\\dicembre19_2023\\output.csv"));
            bw.write("Tipo, Nome, DataCreazione, AltroAttributo1, AltroAttributo2\n");
            for (ElementoArchivio elemento : archivio.elementiArchivio) {
                if (elemento instanceof Documento) {
                    bw.write("Documento, " + elemento.nome + ", " + elemento.dataCreazione + ", ");
                    bw.write("Formato" + ((Documento) elemento).formato + ", " + ((Documento) elemento).pagine
                            + " pagine");
                    bw.newLine();
                } else if (elemento instanceof Immagine) {
                    bw.write("Immagine, " + elemento.nome + ", " + elemento.dataCreazione + ", ");
                    bw.write(((Immagine) elemento).risoluzione + ", Formato" + ((Immagine) elemento).formato);
                    bw.newLine();
                } else if (elemento instanceof Audio) {
                    bw.write("Audio, " + elemento.nome + ", " + elemento.dataCreazione + ", ");
                    bw.write("Durata" + ((Audio) elemento).durataMin + "min, Formato" + ((Audio) elemento).formato);
                    bw.newLine();
                }
            }

            bw.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
