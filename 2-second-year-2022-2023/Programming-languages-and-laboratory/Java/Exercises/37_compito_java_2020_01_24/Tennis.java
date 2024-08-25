public class Tennis extends Campo {
	private float temperaturaMedia;
	private String terreno;
	private float costoOrario;

	public Tennis(int codice, String sport, String nome, float larghezza, float lunghezza, float temperaturaMedia, String terreno, float costoOrario) {
		super(codice, sport, nome, larghezza, lunghezza, costoOrario);
		this.temperaturaMedia = temperaturaMedia;
		this.terreno = terreno;
	}

	public String toString() {
		return sport + "\t" + nome + "\t" + codice + "\t" + larghezza + "\t" + lunghezza + "\t" + temperaturaMedia
				+ "\t" + terreno + "\t-\t-\t" + costoOrario;
	}
}