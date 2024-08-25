public class Cittadino extends Supermercato {
	private int orarioApertura, orarioChiusura;
	private float superficie;
	private int numeroAddetti;
	private int numeroVisite;

	public Cittadino(int codice, String tipo, String indirizzo, int orarioApertura, int orarioChiusura,
			float superficie, int numeroAddetti) {
		super(codice, tipo, indirizzo);
		this.orarioApertura = orarioApertura;
		this.superficie = superficie;
		this.numeroAddetti = numeroAddetti;
		numeroVisite = 0;
	}

	public void addvisite() {
		numeroVisite++;
	}

	public int getNumeroVisite() {
		return numeroVisite;
	}

	public String toString() {
		return codice + "\t" + tipo + "\t" + indirizzo + "\t" + orarioApertura + "\t" + orarioChiusura + "\t"
				+ superficie + "\t" + numeroAddetti + "\t-";
	}
}