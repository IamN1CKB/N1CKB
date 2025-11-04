package strutture_dati;

public class Pair<A,B> {
    A first;
    B second;
    public Pair(A a,B b){
        first=a;
        second = b;
    }
    public A getFirst() {return first;}
    public B getSecond() {return second;}
    public static void main(String[] args) {
        Pair<Integer, Double> generics = new Pair<Integer, Double>(4,4.5);
        System.err.println(generics.first);
    }
}