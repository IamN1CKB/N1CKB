package programmazione_ad_oggetti.esercizi.esami.marzo17_2025;

public class ConcessionarioTest {
    public static void main(String[] args) {
        String path = "Java\\programmazione_ad_oggetti\\esercizi\\esami\\marzo17_2025\\veicoli.csv";
        ParcoAuto parcoAuto = new ParcoAuto();
        parcoAuto.leggiDaFile(path);
        parcoAuto.aggiungiVeicolo(new VeicoloVendita("BZ750ZL", "Ford", "Focus", 2002, 30000, 10, true, false));

    }
}
