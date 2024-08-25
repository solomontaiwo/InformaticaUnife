public class Supermercato {
	protected int codice;
	protected String tipo;
	protected String indirizzo;
	protected int numeroVisite;

	public Supermercato(int codice, String tipo, String indirizzo) {
		this.codice = codice;
		this.tipo = tipo;
		this.indirizzo = indirizzo;
		numeroVisite = 0;
	}
	
}