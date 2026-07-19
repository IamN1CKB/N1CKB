package strutture_dati.Esercitazione_strutture_dati;

import strutture_dati.ArrayQueue;

public class EsQueue {
    public static void main(String[] args) {
        ArrayQueue<Integer> queue = new ArrayQueue<Integer>(20);
        System.out.println("la queue e' vuota? " + queue.isEmpty());
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);
        System.out.println("il primo elemento della queue e' " + queue.first());
        System.out.println("elemento rimosso dalla queue: " + queue.dequeue());
        System.out.println("il primo elemento della queue e' " + queue.first());
        System.out.println("la queue e' vuota? " + queue.isEmpty());
        queue.dequeue();
        queue.dequeue();
        System.out.println("la queue e' vuota? " + queue.isEmpty());
        System.out.println("elemento rimosso dalla queue: " + queue.dequeue());
    }
}
