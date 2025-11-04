package programmazione_ad_oggetti.teoria.parte1;

public class Main10 {
    public static void main(String[] args) {
        // in questo fili spiegheremo l'ereditarietà
        // inheritance in inglese
        // l'ereditarietà è il meccanismo che permette a una classe di derivare da un
        // altra classe metodi e attributi
        // creeremo le classi Studente e Insegnate che derivano da Persona
        // vedi file Studente.java e Insegnante.java
        // queste classi ereditano gli attributi e i metodi della classe persona, e
        // possono avere attributi e metodi a parte
        Persona persona1 = new Persona("Luca", "Rossi", 23, "blu");
        System.out.println(persona1);
        persona1.cammina();

        Studente studente1 = new Studente("Giovanni", "Verdi", 34, "marrone", "matematica");
        studente1.cammina();
        System.out.println(studente1.nome);

        studente1.studia();

        Insegnante insegnante1 = new Insegnante("Maria", "Bagno", 40, "bianco");
        insegnante1.insegna();

        // possiamo anche fare l'override dei metodi. vedi il metodo saluta in entrambi
        // i file
        insegnante1.saluta();
        studente1.saluta();

        // vediamo le classi astratte
        // le classi astratte sono classi molto ristrette che non possono essere usate
        // per fare oggetti, ma create
        // affinché vengano ereditate da altre classi
        // creiamo la classe astratta Veicolo in Veicolo.java
        // un veicolo è solo un idea, siccome lavoriamo sempre con un tipo specifico di
        // veicolo, come le bici, le auto, le moto
        // quindi non tratteremo mai un oggetto di tipo veicolo
        // Veicolo veicolo = new Veicolo(); //errore
        // creiamo poi una classe figlia di veicolo, ossia Macchina in Macchina.java
        Macchina macchina = new Macchina();
        macchina.muovi();

    }
}
