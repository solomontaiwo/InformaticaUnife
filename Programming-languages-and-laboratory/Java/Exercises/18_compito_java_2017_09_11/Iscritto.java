import java.util.*;

public class Iscritto {
	protected String tipo;
	protected int codice;
	protected String indirizzo, nomeAccount, password;
	protected List<Iscritto> seguaci;

	public Iscritto(String tipo, int codice, String indirizzo, String nomeAccount, String password) {
		this.tipo = tipo;
		this.codice = codice;
		this.indirizzo = indirizzo;
		this.nomeAccount = nomeAccount;
		this.password = password;
		seguaci = new LinkedList<Iscritto>();
	}

	public void aggiungiSeguace(Iscritto i) {
		seguaci.add(i);
	}

	public int getNumeroSeguaci() {
		return seguaci.size();
	}

	public String getNome() {
		return "";
	}

	public int getId() {
		return codice;
	}

	public String toString() {
		return indirizzo + "\t" + nomeAccount + "\t" + password.length();
	}

	public String toStringFollowerNumber() {
		return "";
	}
}
