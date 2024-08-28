public class Individuo extends Iscritto {
	private String nomeCognome;

	public Individuo(String tipo, int codice, String nomeCognome, String indirizzo, String nomeAccount,
			String password) {
		super(tipo, codice, indirizzo, nomeAccount, password);
		this.nomeCognome = nomeCognome;
	}

	public String getNome() {
		return nomeCognome;
	}

	public String toString() {
		return codice + "\t" + nomeCognome + "\t-\t-\t" + indirizzo + "\t" + nomeAccount + "\t" + password.length();
	}

	public String toStringFollowerNumber() {
		return codice + "\t" + nomeCognome + "\t" + seguaci.size();
	}
}