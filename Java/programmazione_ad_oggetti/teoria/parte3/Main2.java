package programmazione_ad_oggetti.teoria.parte3;

public class Main2 {
    public static void main(String[] args) {
        // vediamo come copiare gli oggetti
        Persona persona1 = new Persona("Luca", "Rossi");
        Persona persona2 = new Persona("Marco", "Verdi");
        // vediamo cosa stampa di default il metodo toString
        System.out.println(persona1);
        System.out.println(persona2);
        // come notiamo, viene stampato il pacchetto, il nome dell'istanza dell'oggetto
        // (la classe a cui appartiene) e l'indirizzo esadecimale

        System.out.println(persona1.getNome() + " " + persona1.getCognome());
        System.out.println(persona2.getNome() + " " + persona2.getCognome());

        System.out.println();

        // se vogliamo copiare persona1 in persona2 ci viene naturale pensare di fare
        // questo
        persona2 = persona1;
        // questo passaggio però fa indirizzare entrambi gli oggetti alla stessa memoria
        // di persona1. lo si può vedere dal metodo toString
        System.out.println(persona1);
        System.out.println(persona2);

        // quindi modificare uno dei 2 oggetti modifica pure l'altro, siccome la cella
        // di memoria è la stessa
        persona1.setNome("Nicola");
        System.out.println(persona1.getNome() + " " + persona1.getCognome());
        System.out.println(persona2.getNome() + " " + persona2.getCognome());

        System.out.println();

        // un modo migliore per copiare un oggetto è tramite il metodo copy, dichiarato
        // nella classe Persona
        Persona persona3 = new Persona("Nicola", "Belardo");
        // vogliamo copiare persona1 in persona3
        persona3.copy(persona1);

        System.out.println(persona1);
        System.out.println(persona3);
        // in questo caso i 2 oggetti hanno una cella di memoria diversa cambiare uno,
        // non influenza l'altro
        persona1.setNome("William");
        System.out.println(persona1.getNome() + " " + persona1.getCognome());
        System.out.println(persona3.getNome() + " " + persona2.getCognome());

        System.out.println();

        // possiamo copiare anche con i constructor, quando dichiariamo l'oggetto.
        // ci basta fare un override del constructor dove usiamo il parametro Persona
        Persona persona4 = new Persona(persona1);

        System.out.println(persona1);
        System.out.println(persona4);
        persona1.setNome("Giuseppe");
        System.out.println(persona1.getNome() + " " + persona1.getCognome());
        System.out.println(persona3.getNome() + " " + persona2.getCognome());

        /*
         * Se vuoi controllare se **due oggetti appartengono alla *stessa classe*** (non
         * necessariamente alla stessa *istanza*),
         * puoi usare **il metodo `.getClass()`** oppure l’operatore `instanceof` in
         * certi casi.
         * 
         * ## ✅ Metodo 1: `.getClass()` per confrontare le classi esatte
         * 
         */
        Persona obj1 = new Persona("Gianni", "Morandi");
        Insegnante obj2 = new Insegnante("Anna", "Setola");
        if (obj1.getClass() == obj2.getClass()) {
            System.out.println("Stessa classe!");
        } else {
            System.out.println("Classi diverse.");
        }
        /*
         * > Questo controlla se **entrambe le istanze sono della *stessa classe
         * concreta** (esattamente la stessa,
         * niente sottoclassi!).
         * 
         * ## ✅ Metodo 2: `instanceof` (più generico)
         * Se invece vuoi controllare **se un oggetto è di un certo tipo o sottotipo**,
         * puoi usare:
         */
        if (obj1 instanceof Persona && obj2 instanceof Persona) {
            System.out.println("Entrambi sono Persone (o sottoclassi).");
        }
        /*
         * 
         * Ma attenzione:
         * - `instanceof` → **sì alla gerarchia** (Auto è anche Veicolo)
         * - `.getClass()` → **solo classe esatta** (Auto ≠ Moto)
         * 
         * 
         * ### 🔍 Esempio completo:
         * 
         * //class Veicolo {}
         * //class Auto extends Veicolo {}
         * //class Moto extends Veicolo {}
         * 
         * Veicolo v1 = new Auto();
         * Veicolo v2 = new Moto();
         * Veicolo v3 = new Auto();
         * 
         * // Confronto 1
         * System.out.println(v1.getClass() == v3.getClass()); // true
         * System.out.println(v1.getClass() == v2.getClass()); // false
         * 
         * // Confronto 2
         * System.out.println(v1 instanceof Veicolo); // true
         * System.out.println(v2 instanceof Veicolo); // true
         * 
         * 
         * ## 🧠 Riassunto:
         * 
         * | Cosa vuoi sapere? | Usi... |
         * | **Stessa classe esatta?** | `obj1.getClass() == obj2.getClass()` |
         * | **Appartiene a una classe o gerarchia?** | `obj instanceof Classe` |
         * 
         */
    }
}
