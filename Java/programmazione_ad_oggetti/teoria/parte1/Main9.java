package programmazione_ad_oggetti.teoria.parte1;

public class Main9 {
    public static void main(String[] args) {
        // in questo file vedremo il metodo toString. come prima cosa vediamo come si
        // comporta la stampa di un oggetto
        Persona Nicola = new Persona("Nicola", "Belardo", 20, "rosso");
        // per stampare le info dell'oggetto possiamo usare il metodo toString, che è un
        // metodo di java presente in
        // qualsiasi oggetto che creiamo. Per poter definire bene la stringa da voler
        // stampare, possiamo fare l'override
        // del metodo nella nostra classe

        // se non definiamo il metodo nella classe allora stamperà le stesse cose di un
        // semplice print senza toString
        // System.out.println(Nicola); //stampa parte1.Persona@372f7a8d
        // stampa infatti il nome dell'istanza, e l'indirizzo in cui è salvato l'oggetto
        // però possiamo sovrascrivere nella classe il metodo toString (ossia fare
        // l'override), come abbiamo
        // già fatto e avremo in console
        System.out.println(Nicola.toString());
        // viene stampata la stessa cosa se omettiamo toString
        System.out.println(Nicola);

        // vediamo come creare array di oggetti
        // prima rivediamo un array di una primitiva
        int[] arrayInt = new int[3];
        arrayInt[0] = 1;

        // creiamo dei nuovi oggetti
        Persona persona0 = new Persona("Marco", "Verdi", 25, "giallo");
        Persona persona1 = new Persona("Giada", "Verdi", 22, "rosso");
        Persona persona2 = new Persona("Anna", "Verdi", 20, "nero");

        // possiamo creare array in 2 modi. creando prima l'array vuoto
        Persona[] personeArray = new Persona[3];
        personeArray[0] = persona0;
        personeArray[1] = persona1;
        personeArray[2] = persona2;

        System.out.println(personeArray[1]);

        Persona[] arrayPersone = { persona0, persona1, persona2 };
        System.out.println(arrayPersone[2]);

        // adesso vediamo come passare oggetti come parametri di metodi
        Persona Gabriele = new Persona("Gabriele", "Bagnato", 18, "bianco");
        Persona Sabrina = new Persona("Sabrina", "Bagnato", 15, "verde");

        // usiamo il metodo saluta definito in Persona, e vogliamo far salutare Sabrina
        // tramite Gabriele
        Gabriele.saluta(Sabrina);
        Sabrina.saluta(Gabriele);

        // vediamo anche l'uso di final e static
        // final indica una variabile che non può essere modificata durante l'esecuzione
        final float variabileFinal = 3.14f;
        System.out.println(variabileFinal);
        // variabileFinal =+ 1; //error: The final local variable variabileFinal cannot
        // be assigned. It must be blank and not using a compound assignment
        // variabileFinal = 4f; //stesso errore di prima

        // la keyword static riferita a un'attributo della classe vuol dire che
        // quell'attributo è univoco per tutte le istanze
        // della classe
        // ad esempio immaginiamo di voler contare il numero di oggetti persona creati.
        // possiamo creare un attributo static numeroPersone, che viene modificato ogni
        // volta che viene definito un
        // nuovo oggetto persona (quindi nel costruttore)
        // quindi usiamo l'attributo static numeroPersone (che è di default a zero
        // all'inizio)
        // siccome in questo file abbiamo già creato
        // per poter accedere a una variabile static, dobbiamo usare il nome della
        // classe e non di uno oggetto della classe
        System.out.println("sono state definite " + Persona.numeroPersone + " oggetti di tipo Persona");
        // allo stesso modo possiamo fare anche metodi static
        Persona.mostraNumeroPersone();

    }
}
