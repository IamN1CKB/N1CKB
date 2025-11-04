package programmazione_ad_oggetti.esercizi.esami.febbraio24_2025;

public class App {
    public static void main(String[] args) {
        Partita partita = new Partita(new Allenatore(), new Allenatore());
        partita.iniziaPartita();
    }
}
