package programmazione_ad_oggetti.esercizi.esami.dicembre19_2023;

public class Audio extends ElementoArchivio {
    int durataMin;
    String formato;

    Audio(String nome, String data, int durataMin, String formato) {
        this.nome = nome;
        this.dataCreazione = data;
        this.durataMin = durataMin;
        this.formato = formato;
    }

    @Override
    void visualizzaDettagli() {
        System.out.println("Tipo: documento");
        System.out.println("Nome: " + nome);
        System.out.println("data: " + nome);
        System.out.println("durata: " + durataMin + " min");
        System.out.println("formato: " + formato);
    }

}
