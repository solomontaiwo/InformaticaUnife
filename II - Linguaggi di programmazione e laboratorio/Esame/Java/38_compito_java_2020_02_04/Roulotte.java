public class Roulotte extends Veicolo {

	private int peso;
	private String veranda;

	public Roulotte(int c, String m, float larghezza, float lunghezza, float costo, int posti, int peso,
			String veranda) {
		super(c, m, larghezza, lunghezza, costo, posti);
		this.peso = peso;
		this.veranda = veranda;
	}

	public String toString() {
		return "roulotte\t" + super.toString() + peso + "\t" + veranda + "\t-\t" + costo;
	}

}