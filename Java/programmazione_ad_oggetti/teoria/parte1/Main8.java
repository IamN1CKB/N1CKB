package programmazione_ad_oggetti.teoria.parte1;

public class Main8 {
    public static void main(String[] args) {
        // questa lezione spiega la programmazione ad oggetti, detta OOP (object
        // orienting programming)
        // è un metodo di fare programmazione ragionando con gli oggetti che adesso
        // vediamo tramite le classi
        // possiamo vedere il file Persona in questa directory, dove abbiamo definito la
        // classe Persona

        // possiamo creare così un nuovo tipo di dato, detto oggetto, basato sulle
        // classi della stessa directory o stesso file
        /*
         * Persona Marco = new Persona();
         * Marco.nome = "Marco";
         * Marco.saluta();
         * Persona Luca = new Persona();
         * Luca.cammina();
         */
        // abbiamo commentato perché adesso useremo il costruttore che è più comodo

        // entrambi gli oggetti Luca e Marco sono istanze del tipo persona, ovvero che
        // sono derivate dalla classe persona,
        // ma sono oggetti completamente diversi
        // con la notazione puntuale possiamo accedere ai metodi e alle
        Persona Marco = new Persona("Marco", "Rossi", 23, "blu");
        Marco.saluta();
        Persona Luca = new Persona("Luca", "Rossi", 23, "blu");
        Luca.saluta();

        // possiamo usare anche overloaded constructors (nello stesso modo delle
        // overloaded methods)
        // vedi il file Pizza.java in questa directory
        Pizza margherita = new Pizza("integrale", "pomodoro", "caciocavallo", "basilico");
        Pizza mortadella = new Pizza("normale", "pistacchio", "mortadella");
        System.out.println("mi piace il " + margherita.formaggio + " e l'impasto " + mortadella.impasto);

    }
}
