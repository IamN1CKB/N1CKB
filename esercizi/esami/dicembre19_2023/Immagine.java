package programmazione_ad_oggetti.esercizi.esami.dicembre19_2023;

public class Immagine extends ElementoArchivio {
    Risoluzione risoluzione;
    String formato;

    Immagine(String nome, String data, Risoluzione risoluzione, String formato) {
        this.nome = nome;
        this.dataCreazione = data;
        this.risoluzione = risoluzione;
        this.formato = formato;
    }

    @Override
    void visualizzaDettagli() {
        System.out.println("Tipo: documento");
        System.out.println("Nome: " + nome);
        System.out.println("data: " + nome);
        System.out.println("risoluzione: " + risoluzione);
        System.out.println("formato: " + formato);
    }
}
