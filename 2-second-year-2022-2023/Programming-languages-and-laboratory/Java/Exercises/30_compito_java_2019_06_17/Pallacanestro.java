public class Pallacanestro extends Squadra {
	private double falli;
	private int puntiSegnati;
	private int numeroGiocatori;

	public Pallacanestro(int codice, String sport, String nomeSquadra, int vinte, int perse, double falli, int puntiSegnati) {
		super(codice, sport, nomeSquadra, vinte, perse);
		this.falli = falli;
		this.puntiSegnati = puntiSegnati;
		numeroGiocatori = 0;
	}

	public String toString() {
		return nomeSquadra + "\t" + codice + "\t" + vinte + "\t" + perse + "\t" + puntiSegnati + "\t" + falli + "\t-\t" + sport;
	}
	
	public void incrementaGiocatori(Pallacanestro p) {
		p.numeroGiocatori++;
	}
}