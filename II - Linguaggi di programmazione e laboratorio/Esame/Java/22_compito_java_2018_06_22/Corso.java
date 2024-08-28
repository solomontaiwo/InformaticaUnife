public class Corso {
	protected int codiceCorso;
	protected String tipo, nomeCorso;
	protected String nomeCognomeDocente;
	
	public Corso(int codiceCorso, String tipo, String nomeCorso, String nomeCognomeDocente) {
		this.codiceCorso = codiceCorso;
		this.tipo = tipo;
		this.nomeCorso = nomeCorso;
		this.nomeCognomeDocente = nomeCognomeDocente;
	}
}