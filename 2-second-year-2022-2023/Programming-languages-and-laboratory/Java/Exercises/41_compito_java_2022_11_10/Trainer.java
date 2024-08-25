public class Trainer extends Dipendente {
	private boolean laurea;
	private String specialita;
	private float oreSettimanali;
	
	public Trainer(int codice, String tipo, String nomeDipendente, boolean laurea, String specialita, float oreSettimanali, float costoOrario) {
		super(codice, tipo, nomeDipendente, costoOrario);
		this.laurea = laurea;
		this.specialita = specialita;
		this.oreSettimanali = oreSettimanali;
	}
	
	public String toString() {
		return "tra" + "\t" + super.toString() + "\t" + laurea + "\t" + specialita + "\t" + oreSettimanali + "\t-\t-\t-\t" + costoOrario;
	}
}