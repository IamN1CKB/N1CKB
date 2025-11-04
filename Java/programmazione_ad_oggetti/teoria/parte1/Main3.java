package programmazione_ad_oggetti.teoria.parte1;

public class Main3 {
    public static void main(String[] args) {
        /*
         * le lezioni con la stessa teoria del linguaggio C lo salteremo, ossia:
         * -le espressioni aritmetiche con + - / * % += -= *= /= ++ --
         * -operatori di comparazione (che restituiscono i boolean) < > >= <= == !=
         * (vale anche per le stringhe)
         * -operatori logici && || !
         * -gli if statement (if, if else, else)
         * -lo switch case
         * -i cicli while, do while, for
         * -il casting implicito ed esplicito dei tipi es=> int x = (int) 9.5;
         */
        // vediamo brevemente per ricordarci i ternary operator ? :
        // condizione ? risultato se vero : risultato se è falso
        int y = 10, z = 12;
        String x = (y < z) ? (y + " è minore di " + z) : (y + " non è minore di " + z);
        // stessa cosa di dire
        System.out.println(x);

        // vediamo anche un esempio di switch case
        String componenteAzienda = "Marco";
        switch (componenteAzienda) {
            case "Stefano":
                System.out.println(componenteAzienda + " e' il proprietario dell'azienda");
                break;
            case "Marco":
                System.out.println(componenteAzienda + " e' il segretario dell'azienda");
                break;
            case "Giulio":
                System.out.println(componenteAzienda + " e' l'avvocato dell'azienda");
                break;
            case "Maria":
                System.out.println(componenteAzienda + " e' la designer dell'azienda");
                break;
            case "Enza":
                System.out.println(componenteAzienda + " e' l'operaia dell'azienda");
                break;
            default:
                System.out.println(componenteAzienda + " non fa parte dell'azienda");
                break;
        }

        // vediamo anche un esempio di for enhanced (conosciuto in altri linguaggi come
        // for each)
        // si parte avendo un array di valori, e il for each prende uno ad uno tutti i
        // valori nel array, considerandoli come la variabile mesi
        String[] anno = { "gennaio", "febbraio", "marzo", "aprile", "maggio", "giugno", "luglio", "agosto", "settembre",
                "ottobre", "novembre", "dicembre" };
        for (String mese : anno) {
            System.out.println("siamo a " + mese);
        }
    }
}
