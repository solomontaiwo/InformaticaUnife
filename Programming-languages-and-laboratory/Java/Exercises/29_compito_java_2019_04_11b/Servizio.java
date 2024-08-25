public class Servizio {

	protected Impiegato imp;
	protected double ore;

	public Servizio(Impiegato imp, double ore) {
		this.imp = imp;
		this.ore = ore;
	}

	public double getValore() {
		return ore * imp.getCosto();
	}

	public String toString() {
		return imp.getNome() + " " + ore + " " + getValore();
	}
}