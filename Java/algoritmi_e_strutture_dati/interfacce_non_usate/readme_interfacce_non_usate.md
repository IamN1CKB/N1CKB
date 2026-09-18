# Interfacce e Implementazioni (A Scopo Didattico)

Questa cartella raccoglie le implementazioni di strutture dati e interfacce che sono state studiate teoricamente durante il corso, ma che **non vengono utilizzate attivamente** negli esercizi principali o nelle prove d'esame.

Il motivo principale è l'adozione delle implementazioni predefinite della libreria standard `java.util.*`, che risultano nettamente superiori, complete e integrate nel linguaggio.

## Contenuto e Motivazioni

Di seguito le classi presenti e il motivo per cui preferiamo le controparti standard:

* 📝 **ArrayList** (`ArrayList.java`)
  Implementazione didattica di una lista basata su array. Nei nostri esercizi utilizziamo la `java.util.ArrayList` standard perché gestisce nativamente e in automatico il ridimensionamento dinamico della struttura (una funzionalità avanzata non implementata nella nostra versione).

* 🔄 **Iteratori** (`Iterable.java` e `Iterator.java`)
  Versioni didattiche del pattern iteratore. Preferiamo utilizzare gli iteratori di libreria standard (`java.util.Iterator` e `java.lang.Iterable`) perché sono gli unici che permettono al compilatore Java di utilizzare nativamente il costrutto del *for-each loop*, semplificando enormemente la scrittura del codice.

* 🔗 **DoublyLinkedList Modificata** (`DoublyLinkedList.java`)
  *Caso speciale:* Questa è una rielaborazione della lista doppiamente concatenata classica. Abbiamo modificato la visibilità dei metodi e dei nodi interni da `private` a `protected`. È stata inserita in questa cartella per uno scopo ben preciso: funge da base necessaria per risolvere una specifica **traccia d'esame di Marzo 2026**.