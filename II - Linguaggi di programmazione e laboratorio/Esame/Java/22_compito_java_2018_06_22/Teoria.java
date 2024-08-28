public class Teoria extends Corso {
	private int codiceAula, oreSettimanali;
	private double oreLezione;
	
	public Teoria(int codiceCorso, String tipo, String nomeCorso, String nomeCognomeDocente, int codiceAula, int oreSettimanali, double oreLezione) {
		super(codiceCorso, tipo, nomeCorso, nomeCognomeDocente);
		this.codiceAula = codiceAula;
		this.oreSettimanali = oreSettimanali;
		this.oreLezione = oreLezione;
	}
	
	public String toString() {
		return nomeCorso + "\t" + codiceCorso + "\t" + nomeCognomeDocente + "\t" + tipo + "\t" + codiceAula + "\t" + oreSettimanali + "\t" + oreLezione + "\t-\t-\t-";
	}
}