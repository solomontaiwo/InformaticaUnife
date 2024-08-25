public class Menu {
	protected int codiceRistorante;
	protected String descrizioneProdotto;
	protected String tipoProdotto;
	protected float prezzoProdotto;
	protected float costoMateriePrime;

	public Menu(int codiceRistorante, String descrizioneProdotto, String tipoProdotto, float prezzoProdotto,
			float costoMateriePrime) {
		this.codiceRistorante = codiceRistorante;
		this.descrizioneProdotto = descrizioneProdotto;
		this.tipoProdotto = tipoProdotto;
		this.prezzoProdotto = prezzoProdotto;
		this.costoMateriePrime = costoMateriePrime;
	}

	public String toString() {
		return descrizioneProdotto + ": " + prezzoProdotto + "-" + costoMateriePrime;
	}
}