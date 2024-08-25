public class testaDiSerie extends Giocatore {
	private int ranking, eta;
	private boolean professionista;

	public testaDiSerie(int codiceGiocatore, String tipo, String nomeCognome, int ranking, int eta,
			boolean professionista) {
		super(codiceGiocatore, tipo, nomeCognome);
		this.ranking = ranking;
		this.eta = eta;
		this.professionista = professionista;
	}

	public String toString() {
		return nomeCognome + "\t" + codiceGiocatore + "\t" + tipo + "\t" + ranking + "\t" + eta + "\t" + professionista
				+ "\t-\t-\t-";
	}
}