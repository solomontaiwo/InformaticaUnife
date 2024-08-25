public class Prenotazione {
	protected int codice, giorni;

	public Prenotazione(int codice, int giorni) {
		this.codice = codice;
		this.giorni = giorni;
	}

	public int getGiorni() {
		return giorni;
	}

	public String toString() {
		return "(" + codice + "," + giorni + ")";
	}
}