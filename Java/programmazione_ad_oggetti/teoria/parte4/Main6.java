package programmazione_ad_oggetti.teoria.parte4;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;

public class Main6 {
    public static void main(String[] args) {
        // altro caso con i csv
        String path = "Java\\programmazione_ad_oggetti\\teoria\\parte4\\esempioCSV.csv";
        File file = new File(path);
        String riga;
        if (file.exists()) {
            try {
                BufferedReader br = new BufferedReader(new FileReader(path));
                br.readLine(); // salta intestazione
                while ((riga = br.readLine()) != null) {
                    String[] valori = riga.split(",");
                    System.out.println(valori[1] + ": " + valori[2] + " euro");
                }
                br.close();

            } catch (Exception e) {
                e.printStackTrace();
            }

        } else
            System.out.println("errore file");
    }
}
