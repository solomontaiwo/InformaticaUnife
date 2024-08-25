public class Pallamano extends Squadra {
	private double goalFatti;
	private int numeroGiocatori;
	
	public Pallamano(int codice, String sport, String nomeSquadra, int vinte, int perse, double goalFatti) {
		super(codice, sport, nomeSquadra, vinte, perse);
		this.goalFatti = goalFatti;
		numeroGiocatori = 0;
	}

	public String toString() {
		return nomeSquadra + "\t" + codice + "\t" + vinte + "\t" + perse + "\t-\t-\t" + goalFatti + "\t" + sport;
	}
	
	public void incrementaGiocatori(Pallamano p) {
		p.numeroGiocatori++;
	}
}