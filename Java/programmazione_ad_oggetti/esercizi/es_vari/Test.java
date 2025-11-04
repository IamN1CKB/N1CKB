package programmazione_ad_oggetti.esercizi.es_vari;

abstract class Instrument {
	private int i;

	public String what() {
		return "Instrument";
	}

	public abstract void play();

	public abstract void adjust();
}