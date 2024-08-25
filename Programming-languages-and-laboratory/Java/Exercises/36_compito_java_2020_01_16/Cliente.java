import java.util.*;

public class Cliente {
	protected String cognome, nome;
	protected List<Visita> visite;

	public Cliente(String cognome, String nome) {
		this.cognome = cognome;
		this.nome = nome;
		visite = new LinkedList<Visita>();
	}

	public float spesaTotale() {
		float totale = 0;
		for (Visita v : visite) {
			totale = totale + v.importoSpeso;
		}
		return totale;
	}

	public String toString() {
		return cognome + "\t" + nome + "\t" + spesaTotale();
	}
}