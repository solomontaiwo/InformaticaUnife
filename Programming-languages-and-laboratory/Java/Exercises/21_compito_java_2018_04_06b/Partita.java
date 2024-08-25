public class Partita {
	protected int codicePrimoGiocatore, codiceSecondoGiocatore;
	protected int setVintiPrimoGiocatore, setVintiSecondoGiocatore;

	public Partita(int codicePrimoGiocatore, int codiceSecondoGiocatore, int setVintiPrimoGiocatore,
			int setVintiSecondoGiocatore) {
		this.codicePrimoGiocatore = codicePrimoGiocatore;
		this.codiceSecondoGiocatore = codiceSecondoGiocatore;
		this.setVintiPrimoGiocatore = setVintiPrimoGiocatore;
		this.setVintiSecondoGiocatore = setVintiSecondoGiocatore;

	}

	public String toString() {
		return codiceSecondoGiocatore + ":" + setVintiPrimoGiocatore + "-" + setVintiSecondoGiocatore;
	}
}