package programmazione_ad_oggetti.esercizi.esami.aprile17_2023;

public class Prodotto {
    String codice;
    String nome;
    float prezzo;
    int quantita;

    Prodotto(String codice, String nome, float prezzo, int quantita) {
        this.codice = codice;
        this.nome = nome;
        this.prezzo = prezzo;
        this.quantita = quantita;
    }

    Prodotto(String codice, String nome, float prezzo) {
        this.codice = codice;
        this.nome = nome;
        this.prezzo = prezzo;
        this.quantita = 1;
    }
}
