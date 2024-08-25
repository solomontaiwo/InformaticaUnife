public class Osteria extends Ristorante {
	private int postiASedere;
	private double superficie;
	private boolean bagnoDisabili;

	public Osteria(int codiceRistorante, String tipoRistorante, String nomeRistorante, int postiASedere,
			double superficie, boolean bagnoDisabili) {
		super(codiceRistorante, tipoRistorante, nomeRistorante);
		this.postiASedere = postiASedere;
		this.superficie = superficie;
		this.bagnoDisabili = bagnoDisabili;
	}

	public String toString() {
		return nomeRistorante + "\t" + codiceRistorante + "\t" + tipoRistorante + "\t-\t-\t" + postiASedere + "\t"
				+ superficie + "\t" + bagnoDisabili;
	}
}