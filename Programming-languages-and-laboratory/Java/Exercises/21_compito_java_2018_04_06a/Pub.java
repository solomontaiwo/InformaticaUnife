public class Pub extends Ristorante {
	private int numeroDipendenti;
	private int numeroTavoli;

	public Pub(int codiceRistorante, String tipoRistorante, String nomeRistorante, int numeroDipendenti, int numeroTavoli) {
		super(codiceRistorante, tipoRistorante, nomeRistorante);
		this.numeroDipendenti = numeroDipendenti;
		this.numeroTavoli = numeroTavoli;
	}

	public String toString() {
		return nomeRistorante + "\t" + codiceRistorante + "\t" + tipoRistorante + "\t" + numeroDipendenti + "\t"
				+ numeroTavoli + "\t-\t-\t-";
	}
}