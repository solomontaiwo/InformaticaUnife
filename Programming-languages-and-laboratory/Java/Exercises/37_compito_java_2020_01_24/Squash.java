public class Squash extends Campo {
	private float altezza;
	private int piano;
	private float costo;

	public Squash(int codice, String sport, String nome, float larghezza, float lunghezza, float altezza, int piano, float costo) {
		super(codice, sport, nome, larghezza, lunghezza, costo);
		this.altezza = altezza;
		this.piano = piano;
	}

	public String toString() {
		return sport + "\t" + nome + "\t" + codice + "\t" + larghezza + "\t" + lunghezza + "\t-\t-\t" + altezza + "\t"
				+ piano + "\t" + costo;
	}
}