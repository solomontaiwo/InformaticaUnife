public class Visita {
	protected int codiceSupermercato;
	protected float importoSpeso;
	
	public Visita(int codiceSupermercato, float importoSpeso) {
		this.codiceSupermercato = codiceSupermercato;
		this.importoSpeso = importoSpeso;
	}
	
	public int getCodiceSupermercato() {
		return codiceSupermercato;
	}
}