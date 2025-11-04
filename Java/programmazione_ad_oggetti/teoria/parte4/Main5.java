package programmazione_ad_oggetti.teoria.parte4;

import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;

public class Main5 {
    public static void main(String[] args) {
        // in questa lezione vedremo come vengono gestiti i file CSV in java
        // abbiamo scaricato da internet un file CSV
        /*
         * Un file CSV (Comma-Separated Values) è un tipo di file di testo utilizzato
         * per memorizzare dati tabulari in formato semplice e leggibile. Ogni riga
         * rappresenta un record, e i valori all'interno di una riga sono separati da
         * una virgola (,), un punto e virgola (;) o un altro delimitatore.
         * 📌 Caratteristiche principali
         * 📂 Formato leggibile: Può essere aperto con un editor di testo, Excel, Google
         * Sheets o programmi di database.
         * 🔄 Facile da importare/esportare: Usato per trasferire dati tra programmi
         * diversi (database, fogli di calcolo, sistemi di gestione dati).
         * ⚠️ Semplice ma limitato: Non supporta tipi di dati avanzati o strutture
         * complesse.
         * vediamo un esempio
         * 
         * Nome,Età,Città
         * Alice,25,Roma
         * Bob,30,Milano
         * Carlo,28,Napoli
         * In questo esempio:
         * 
         * La prima riga contiene i nomi delle colonne (intestazione).
         * Le righe successive contengono i dati veri e propri.
         * Le virgole (,) separano i valori (ma può essere anche ; o | in alcuni casi).
         * 
         */
        // apriamo il file. come prima cosa salviamo il path (percorso) relativo
        String path = "Java\\programmazione_ad_oggetti\\teoria\\parte4\\SacramentoRealeStateTransactions.csv";
        // ora apriamo il file, per controllare se è esiste
        File CVSfile = new File(path);
        if (CVSfile.exists()) {
            System.out.println("il file esiste");
            try {
                // per gestire un file CSV possiamo usare un oggetto detto BufferedReader che
                // legge da un FileReader (ha solo il costruttore con un FileReader)
                // apriamo un lettore del file
                FileReader reader = new FileReader(CVSfile); // possiamo inserire anche direttamente il path
                BufferedReader br = new BufferedReader(reader);
                // adesso abbiamo aperto il file, ed è leggibile. Usiamo una variabile String in
                // modo da conservare una riga alla volta
                String riga = "";
                // ora possiamo iniziare a copiare nella variabile riga, ogni riga del file CSV
                // la prima riga del file CSV è l'intestazione che saltiamo facendo:
                br.readLine();
                while ((riga = br.readLine()) != null) {// fin quando non è finito il file
                    // per prendere i diversi dati da una riga usiamo il separatore "," con il
                    // metodo split
                    String[] values = riga.split(",");
                    System.out.println("strada: " + values[0] + "; citta': " + values[1] + "; zip: " + values[2]
                            + "; stato: " + values[3] + "; letto: " + values[4] + "; bagno: " + values[5] + "; sq__ft: "
                            + values[6] + "; type: " + values[7] + "; sale_date: " + values[8] + "; price: " + values[9]
                            + "; latitude: " + values[10] + "; longitude: " + values[11] + "\n\n");
                }
                br.close();
                reader.close();
            } catch (Exception e) {
                e.printStackTrace(); // stampiamo l'errore
            } finally {

            }
        } else {
            System.out.println("il file non esiste");
        }
    }
}
