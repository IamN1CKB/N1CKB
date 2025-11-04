package programmazione_ad_oggetti.esercizi.esami.dicembre19_2023;

public class Documento extends ElementoArchivio {
    // nome e data da classe madre
    String formato;
    int pagine;

    Documento(String nome, String data, String formato, int pagine) {
        this.nome = nome;
        this.dataCreazione = data;
        this.formato = formato;
        this.pagine = pagine;
    }

    @Override
    void visualizzaDettagli() {
        System.out.println("Tipo: documento");
        System.out.println("Nome: " + nome);
        System.out.println("data: " + nome);
        System.out.println("formato: " + formato);
        System.out.println("numero pagine: " + pagine);
    }

}
