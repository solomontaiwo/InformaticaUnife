public class Ipermercato extends Supermercato {
	private float superficie;
	private int numeroAddetti;
	private String nomeCentroCommerciale;
	private int numeroVisite;

	public Ipermercato(int codice, String tipo, String indirizzo, float superficie, int numeroAddetti,
			String nomeCentroCommerciale) {
		super(codice, tipo, indirizzo);
		this.superficie = superficie;
		this.numeroAddetti = numeroAddetti;
		this.nomeCentroCommerciale = nomeCentroCommerciale;
		numeroVisite = 0;
	}

	public void addvisite() {
		numeroVisite++;
	}

	public int getNumeroVisite() {
		return numeroVisite;
	}

	public String toString() {
		return codice + "\t" + tipo + "\t" + indirizzo + "\t-\t-\t" + superficie + "\t" + numeroAddetti + "\t"
				+ nomeCentroCommerciale;
	}
}