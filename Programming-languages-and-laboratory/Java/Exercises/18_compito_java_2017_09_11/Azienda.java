public class Azienda extends Iscritto {
	private String ragioneSociale, nomeCognomeGestore;

	public Azienda(String tipo, int codice, String ragioneSociale, String indirizzo, String nomeCognomeGestore,
			String nomeAccount, String password) {
		super(tipo, codice, indirizzo, nomeAccount, password);
		this.ragioneSociale = ragioneSociale;
		this.nomeCognomeGestore = nomeCognomeGestore;
	}

	public String getNome() {
		return ragioneSociale;
	}

	public String toString() {
		return codice + "\t-\t" + ragioneSociale + "\t" + nomeCognomeGestore + "\t" + super.toString();
	}

	public String toStringFollowerNumber() {
		return codice + "\t" + ragioneSociale + "\t" + seguaci.size();
	}
}