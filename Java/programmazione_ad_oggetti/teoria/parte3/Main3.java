package programmazione_ad_oggetti.teoria.parte3;

public class Main3 {
    public static void main(String[] args) {
        // in questo file spieghiamo le interfacce
        // sono simili a una classe astratta. infatti hanno dei metodi a cui non
        // aggiungeremo il body e verranno
        // sovra-scritte nelle classe che le implementeranno
        // la differenza è che mentre una classe può estendere solo un altra classe,
        // ossia solo una classe genitore, ma può implementare
        // più interfacce
        // inoltre di solito c'è una relazione ereditaria tra classe astratta e classe
        // che la estende, come veicolo e macchina, ma
        // non ci deve essere per forza correlata, siccome può essere implementata su
        // varie classi diverse, che condividono alcune caratteristiche

        // per spiegare tutto creiamo i file Leone Pesce Gazzella Preda Predatore.java
        Leone leone = new Leone();
        Gazzella gazzella = new Gazzella();
        Pesce pesce = new Pesce();

        leone.caccia();
        gazzella.scappa();
        pesce.caccia();
        pesce.scappa();
        // pesce ha implementato 2 interfacce

        /*
         * ## 🎯 In un'interfaccia:
         * Gli **attributi** (cioè le variabili dichiarate) sono **sempre**:
         * - `public`
         * - `static`
         * - `final`
         ** automaticamente**, anche se non li scrivi esplicitamente.
         * 
         * 👉 Significa che sono **costanti** (non modificabili) e **appartengono
         * all'interfaccia**,
         * non alle istanze degli oggetti.
         * 
         * 
         * ## 🔥 Esempio:
         * 
         * public interface Costanti {
         * int NUMERO_MAX = 100; // è automaticamente public static final
         * }
         * 
         * È **equivalente** a scrivere:
         * 
         * public interface Costanti {
         * public static final int NUMERO_MAX = 100;
         * }
         * 
         * 
         * ## 🚫 Cosa NON puoi fare:
         * - **Non puoi avere variabili normali** (non `static` o non `final`).
         * - **Non puoi modificare il valore** delle variabili dentro l'interfaccia.
         * 
         * ## 🧠 In breve:
         * | Può avere attributi? | Sì |
         * | Sono modificabili? | No (sono finali) |
         * | Sono statici? | Sì |
         * | Sono pubblici? | Sì |
         */

    }
}
