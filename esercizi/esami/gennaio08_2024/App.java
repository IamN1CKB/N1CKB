package programmazione_ad_oggetti.esercizi.esami.gennaio08_2024;

public class App {
    public static void main(String[] args) {
        GestioneLibreria libreria = new GestioneLibreria();
        String path = "Java\\programmazione_ad_oggetti\\esercizi\\esami\\gennaio08_2024\\libreria.csv";
        String path2 = "Java\\programmazione_ad_oggetti\\esercizi\\esami\\gennaio08_2024\\libreria2.csv";
        libreria.leggiDaFile(path);

        libreria.aggiungiRisorsa(new Libro("Il Trono di Spade", "George R.R. Martin", 1996, 694));
        libreria.aggiungiRisorsa(new Audiolibro("Il Trono di Spade", "George R.R. Martin", 1996, 600));
        libreria.aggiungiRisorsa(new Libro("Il Conte di Montecristo", "Alexandre Dumas", 1844, 1276));
        libreria.aggiungiRisorsa(new Audiolibro("Il Conte di Montecristo", "Alexandre Dumas", 1844, 1200));
        libreria.mostraElencoRisorse();
        libreria.scriviSuFile(path2);
        libreria.leggiDaFile(path2);
        libreria.modificaRisorsa("1984", new Libro("1984", "George Orwell", 1949, 338));
        libreria.mostraElencoRisorse();
        libreria.scriviSuFile(path2);

    }
}
