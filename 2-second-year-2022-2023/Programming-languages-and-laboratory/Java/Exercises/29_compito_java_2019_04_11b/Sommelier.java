public class Sommelier extends Impiegato {

	private int ore;
	private String spec;

	public Sommelier(int codice, String nome, int ore, String spec, double costo) {
		super(codice, nome, "sommelier", costo);
		this.ore = ore;
		this.spec = spec;
	}

	public String toString() {
		return super.toString() + "\t" + ore + "\t" + spec + "\t-\t-\t-\t" + getCosto();
	}

}