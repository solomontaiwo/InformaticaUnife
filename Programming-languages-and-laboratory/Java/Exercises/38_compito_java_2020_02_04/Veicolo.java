import java.util.*;

public class Veicolo {

	protected int codice, posti;
	protected String marca;
	protected float larghezza, lunghezza, costo;
	protected List<Prenotazione> prenotazioni;

	public Veicolo(int c, String m, float larghezza, float lunghezza, float costo, int posti) {
		codice = c;
		marca = m;
		this.larghezza = larghezza;
		this.lunghezza = lunghezza;
		this.costo = costo;
		this.posti = posti;
		prenotazioni = new LinkedList<Prenotazione>();
	}

	public void addPrenotazione(Prenotazione pren) {
		prenotazioni.add(pren);
	}

	public float incasso() {
		int giorni = 0;
		for (Prenotazione pren : prenotazioni) {
			giorni = giorni + pren.getGiorni();
		}
		return giorni * costo;
	}

	public int getCod() {
		return codice;
	}

	public String toString() {
		return codice + "\t" + marca + "\t" + larghezza + "\t" + lunghezza + "\t" + posti + "\t";
	}
}