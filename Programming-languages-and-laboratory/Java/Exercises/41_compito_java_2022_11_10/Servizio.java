public class Servizio {
	protected Dipendente dip;
	protected float oreServizio;
	
	public Servizio(Dipendente dip, float oreServizio) {
		this.dip = dip;
		this.oreServizio = oreServizio;
	}
	
	public String toString() {
		return "(" + dip.codice + ", " + oreServizio + ")";
	}
}