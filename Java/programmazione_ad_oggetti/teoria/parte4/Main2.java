package programmazione_ad_oggetti.teoria.parte4;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;

public class Main2 {
    public static void main(String[] args) {
        // vediamo come lavorare con le date e l'ora
        // vanno importate le classi sopra
        LocalDate x = LocalDate.now();
        LocalTime y = LocalTime.now();
        System.out.println(x + "\n" + y);
        LocalDateTime z = LocalDateTime.now();
        System.out.println(z);
        // per poter formattare la data usiamo la classe DateTimeFormatter
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("EEEE, dd MMM yy"); // ci sono molti tipi di Pattern
                                                                                      // nella documentazione
        System.out.println(x.format(formatter));
    }
}
