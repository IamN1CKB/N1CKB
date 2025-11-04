package programmazione_ad_oggetti.esercizi.es_vari;

/*programma che legge un intero di 4 cifre e lo visualizzi una cifra per riga.
il programma deve esplicitamente richiedere all'utente che il numero sia di 4 cifre,
deve aspettarsi che l'utente rispetti le indicazioni
*/
import java.util.Scanner;

public class es4 {
    public static void main(String[] args) {
        Scanner tastiera = new Scanner(System.in);
        System.out.println("inserisci un intero: ");
        int numero = tastiera.nextInt();
        int cifre = 1;
        int potenza = 10;
        while (numero / potenza != 0) {
            cifre++;
            potenza *= 10;
        }
        System.out.println("numero per righe:");
        potenza /= 10;
        for (int i = 0; i < cifre; i++) {
            System.out.println(numero % (10 * potenza) / potenza);
            potenza /= 10;
        }
        tastiera.close();
    }
}