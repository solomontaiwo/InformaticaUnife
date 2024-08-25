public class Laboratorio extends Corso {
	private String nomeLaboratorio, nomeAssistente;
	private int numeroPostazioniLaboratorio;
	
	public Laboratorio(int codice, String tipo, String nomeCorso, String nomeCognomeDocente, String nomeLaboratorio, String nomeAssistente, int numeroPostazioniLaboratorio) {
		super(codice, tipo, nomeCorso, nomeCognomeDocente);
		this.nomeLaboratorio = nomeLaboratorio;
		this.nomeAssistente = nomeAssistente;
		this.numeroPostazioniLaboratorio = numeroPostazioniLaboratorio;
	}
	
	public String toString() {
		return nomeCorso + "\t" + codiceCorso + "\t" + nomeCognomeDocente + "\t" + tipo + "\t-\t-\t-\t" + nomeLaboratorio + "\t" + nomeAssistente + "\t" + numeroPostazioniLaboratorio; 
	}
}