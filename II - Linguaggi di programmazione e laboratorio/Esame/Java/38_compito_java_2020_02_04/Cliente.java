import java.util.*;

public class Cliente {

	private String nome, cognome, indirizzo;
	private int codice;
	protected List<Prenotazione> prenotazioni;

	public Cliente(int c, String n, String cog, String i) {
		codice = c;
		nome = n;
		cognome = cog;
		indirizzo = i;
		prenotazioni = new LinkedList<Prenotazione>();
	}

	public void addPrenotazione(Prenotazione p) {
		prenotazioni.add(p);
	}

	public String toString() {
		return codice + "\t" + cognome + "\t" + nome + "\t" + indirizzo + "\t" + prenotazioni;
	}
}
