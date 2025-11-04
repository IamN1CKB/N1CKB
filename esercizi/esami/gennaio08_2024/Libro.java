package programmazione_ad_oggetti.esercizi.esami.gennaio08_2024;

public class Libro extends RisorsaDigitale {
    int numeroPagine;

    Libro(String titolo, String autore, int annoPubblicazione, int numeroPagine) {
        super(titolo, autore, annoPubblicazione);
        this.numeroPagine = numeroPagine;
    }

    @Override
    void mostraDettagli() {
        System.out.println("titolo: " + this.titolo);
        System.out.println("anno di pubblicazione: " + this.annoPubblicazione);
        System.out.println("autore: " + this.autore);
        System.out.println("numero delle pagine: " + this.numeroPagine);
    }
}
