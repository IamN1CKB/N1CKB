package programmazione_ad_oggetti.esercizi.esami.gennaio08_2024;

public abstract class RisorsaDigitale {
    String titolo;
    int annoPubblicazione;
    String autore;

    RisorsaDigitale(String titolo, String autore, int annoPubblicazione) {
        this.titolo = titolo;
        this.autore = autore;
        this.annoPubblicazione = annoPubblicazione;
    }

    abstract void mostraDettagli();
}
