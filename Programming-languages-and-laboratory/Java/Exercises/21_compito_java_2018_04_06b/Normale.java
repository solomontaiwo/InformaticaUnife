public class Normale extends Giocatore {
	private String nomeCircolo;
	private int setVinti;
	private int partiteDisputate;

	public Normale(int codiceGiocatore, String tipo, String nomeCognome, String nomeCircolo, int setVinti,
			int partiteDisputate) {
		super(codiceGiocatore, tipo, nomeCognome);
		this.nomeCircolo = nomeCircolo;
		this.setVinti = setVinti;
		this.partiteDisputate = partiteDisputate;
	}

	public String toString() {
		return nomeCognome + "\t" + codiceGiocatore + "\t" + tipo + "\t-\t-\t-\t" + nomeCircolo + "\t" + setVinti + "\t"
				+ partiteDisputate;
	}
}