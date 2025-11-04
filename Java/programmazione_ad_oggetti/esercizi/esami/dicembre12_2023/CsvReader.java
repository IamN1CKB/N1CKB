package programmazione_ad_oggetti.esercizi.esami.dicembre12_2023;

import java.io.BufferedReader;
import java.io.FileReader;

public class CsvReader {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(
                new FileReader("Java\\programmazione_ad_oggetti\\esercizi\\esami\\dicembre12_2023\\inventario.csv"))) {

            Concessionario concessionario = new Concessionario();
            String riga;
            br.readLine(); // salta intestazione
            while ((riga = br.readLine()) != null) {
                String[] campi = riga.split(",");
                if (campi[2].equals("Auto"))
                    concessionario.aggiungiVeicolo(new Auto(campi[0], campi[1], Integer.parseInt(campi[3]),
                            Float.parseFloat(campi[5]), Float.parseFloat(campi[6])));
                else if (campi[2].equals("Moto"))
                    concessionario.aggiungiVeicolo(new Moto(campi[0], campi[1], Integer.parseInt(campi[4]),
                            Float.parseFloat(campi[5]), Float.parseFloat(campi[6])));
                else
                    throw new Exception("Veicolo non registrato");
            }
            br.close();
            concessionario.visualizzaInventario();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
