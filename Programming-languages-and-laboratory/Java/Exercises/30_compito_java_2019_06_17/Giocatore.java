public class Giocatore {
	protected int codiceSquadra;
	protected String cognome, nome;
	protected boolean titolare;
	protected int eta, numeroMaglia;
	protected String ruolo;
	
	public Giocatore(int codiceSquadra, String cognome, String nome, boolean titolare, int eta, int numeroMaglia, String ruolo) {
		this.codiceSquadra = codiceSquadra;
		this.cognome = cognome;
		this.nome = nome;
		this.titolare = titolare;
		this.eta = eta;
		this.numeroMaglia = numeroMaglia;
		this.ruolo = ruolo;
	}
	
	public String toString() {
		return nome + "\t" + cognome + "\t" + eta + "\t" + numeroMaglia + "\t" + ruolo + "\t";
	}
}