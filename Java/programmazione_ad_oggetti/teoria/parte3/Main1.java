package programmazione_ad_oggetti.teoria.parte3;

public class Main1 {
    public static void main(String[] args) {
        // in questa lezione vedremo l'incapsulamento, ossia il processo in cui
        // nascondiamo attributi di una classe
        // all'esterno mettendoli private, e diventando accessibili solo tramite metodi
        // questo processo serve ad aggiungere un ulteriore livello di sicurezza e per
        // evitare errori involontari durante il codice

        Persona persona1 = new Persona("Luca", "Rossi");
        // System.out.println(persona1.nome); //non possiamo usare l'attributo nome
        // siccome è private
        // dobbiamo usare metodi particolari che chiamiamo getter e setter
        System.out.println(persona1.getNome());

        // possiamo settare il nome anche con il setter
        persona1.setNome("Marco");
        persona1.setCognome("Rossi");

        System.out.println(persona1.getNome() + " " + persona1.getCognome());

    }
}
