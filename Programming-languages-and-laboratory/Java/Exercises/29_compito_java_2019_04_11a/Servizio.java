public class Servizio {
	protected Dipendente dip;
	protected double oreServizio;

	public Servizio(Dipendente dip, double oreServizio) {
		this.dip = dip;
		this.oreServizio = oreServizio;
	}

	public double getValore() {
		return oreServizio * dip.getCosto();

	}
}