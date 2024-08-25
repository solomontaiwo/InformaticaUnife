public class Dipendente {
	protected int codice;
	protected String tipo;
	protected String nomeDipendente;
	protected float costoOrario;
	protected int numeroServiziSvolti;

	public Dipendente(int codice, String tipo, String nomeDipendente, float costoOrario) {
		this.codice = codice;
		this.tipo = tipo;
		this.nomeDipendente = nomeDipendente;
		this.costoOrario = costoOrario;
		this.numeroServiziSvolti = 0;		
	}
	
	public void incrementaNumeroServiziSvolti() {
		numeroServiziSvolti++;
	}

	public String toString() {
		return nomeDipendente + "\t" + codice;
	}
}