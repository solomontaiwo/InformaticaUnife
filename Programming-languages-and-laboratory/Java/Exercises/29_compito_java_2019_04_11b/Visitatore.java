import java.util.*;

public class Visitatore {

	private int codice;
	private String nomeCognome;
	private List<Servizio> servizi;

	public Visitatore(int codice, String nomeCognome) {
		this.codice = codice;
		this.nomeCognome = nomeCognome;
		this.servizi = new LinkedList<Servizio>();
	}

	public void addServizio(Impiegato dip, double ore) {
		servizi.add(new Servizio(dip, ore));
	}

	public double getTot() {
		double tot = 0;
		for (Servizio s : servizi)
			tot = tot + s.getValore();
		return tot;

	}

	public String toString() {
		return codice + " " + nomeCognome + " " + servizi;
	}
}