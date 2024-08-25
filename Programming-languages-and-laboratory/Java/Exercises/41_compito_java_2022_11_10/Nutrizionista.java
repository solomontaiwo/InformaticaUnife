public class Nutrizionista extends Dipendente {
	private int telefono;
	private boolean medico;
	private int appuntamentiSettimanali;

	public Nutrizionista(int codice, String tipo, String nomeDipendente, float costoOrario, int telefono,
			boolean medico, int appuntamentiSettimanali) {
		super(codice, tipo, nomeDipendente, costoOrario);
		this.telefono = telefono;
		this.medico = medico;
		this.appuntamentiSettimanali = appuntamentiSettimanali;
	}

	public String toString() {
		return "nutri" + "\t" + super.toString() + "\t-\t-\t-\t" + telefono + "\t" + medico + "\t" + appuntamentiSettimanali
				+ "\t" + costoOrario;
	}
}