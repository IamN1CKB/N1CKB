package programmazione_ad_oggetti.esercizi.esami.gennaio08_2024;

public class Audiolibro extends RisorsaDigitale {
    int durataMin;

    Audiolibro(String titolo, String autore, int annoPubblicazione, int durataMin) {
        super(titolo, autore, annoPubblicazione);
        this.durataMin = durataMin;
    }

    @Override
    void mostraDettagli() {
        System.out.println("titolo: " + this.titolo);
        System.out.println("anno di pubblicazione: " + this.annoPubblicazione);
        System.out.println("autore: " + this.autore);
        System.out.println("durata: " + this.durataMin);
    }
}
