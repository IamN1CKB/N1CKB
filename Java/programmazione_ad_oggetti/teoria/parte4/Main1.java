package programmazione_ad_oggetti.teoria.parte4;

//classi per i file
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Main1 {
    public static void main(String[] args) {
        // lavorare con i file
        File file = new File("Java\\programmazione_ad_oggetti\\teoria\\parte4\\file.txt");

        if (file.exists()) {
            System.out.println("il file esiste");
            System.out.println(file.getPath());
            System.out.println(file.getAbsolutePath());
            System.out.println(file.isFile()); // potrebbe indicare anche un cartella (in quel caso sarebbe false)
            file.delete();
        } else {
            System.out.println("il file non esiste");
            try {
                // dato che questa classe può facilmente creare eccezioni, va impostato con un
                // try catch
                FileWriter writer = new FileWriter("Java\\programmazione_ad_oggetti\\teoria\\parte4\\prova.txt");
                // se il file non esiste, viene creato, altrimenti viene indicato quello
                // esistente
                writer.write("Giada è un idiota\nma almeno è carina");

                writer.close();
                System.out.println("file creato");

                FileReader reader = new FileReader("Java\\programmazione_ad_oggetti\\teoria\\parte4\\prova.txt");
                // oppure possiamo mettere come parametro l'oggetto File (c'è infatti l'override
                // del costruttore)
                int data = reader.read(); // restituisce il valore decimale del carattere ASCII a cui stiamo puntando
                                          // nel file
                // restituisce -1 se il file è finito
                while (data != -1) {
                    System.out.print((char) data); // conversione da numero a char
                    data = reader.read();
                }
                reader.close();
            } catch (IOException e) {
                e.printStackTrace(); // serve a stampare l'errore
                System.out.println("File non creato o trovato");
            }
        }
    }
}
