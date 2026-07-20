package algoritmi_e_strutture_dati.Esercitazione_strutture_dati;

import algoritmi_e_strutture_dati.Strutture_dati.ArrayStack;
import algoritmi_e_strutture_dati.Strutture_dati.LinkedStack;

public class EsStack {
    public static void main(String[] args) {
        ArrayStack<Integer> stack = new ArrayStack<Integer>(20);
        System.out.println("lo stack e' vuoto? " + stack.isEmpty());

        stack.push(12);
        stack.push(23);
        stack.push(34);
        stack.push(113);
        stack.push(11);
        System.out.println("il primo elemento dello stack e' " + stack.top());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println("lo stack e' vuoto? " + stack.isEmpty());

        LinkedStack<String> stackLista = new LinkedStack<String>();
        System.out.println("lo stackLista e' vuoto? " + stackLista.isEmpty());
        stackLista.push("Ciao");
        stackLista.push("A");
        stackLista.push("B");
        System.out.println("il primo elemento dello stackLista e' " + stackLista.top());
        stackLista.pop();
        System.out.println("il primo elemento dello stackLista e' " + stackLista.top());

        
    
    }
}
