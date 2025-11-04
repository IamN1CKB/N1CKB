package programmazione_ad_oggetti.teoria.parte3;

public class Persona {
    private String nome;
    private String cognome;

    Persona(String nome, String cognome) {
        this.nome = nome;
        this.cognome = cognome;
    }

    public String getNome() {
        return nome;
    }

    public String getCognome() {
        return cognome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setCognome(String cognome) {
        this.cognome = cognome;
    }

    public void copy(Persona persona) {
        this.nome = persona.getNome();
        this.cognome = persona.getCognome();
    }

    Persona(Persona persona) {
        this.copy(persona);// fa le stesse cose di copy
    }

    public void saluta() {
        System.out.println("Ciao, sono " + this.nome);
    }

}
