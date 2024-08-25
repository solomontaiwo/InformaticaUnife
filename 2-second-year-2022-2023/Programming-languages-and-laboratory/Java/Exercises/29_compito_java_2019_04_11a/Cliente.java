import java.io.*;
import java.util.*;

public class Cliente {

	private int codice;
	private String nomeCognome;
	private List<Servizio> servizi;

	public Cliente(int codice, String nomeCognome) {
		this.codice = codice;
		this.nomeCognome = nomeCognome;
		this.servizi = new LinkedList<Servizio>();
	}

	public void addServizio(Dipendente dip, double ore) {
		servizi.add(new Servizio(dip, ore));
	}

	public double getTot() {
		double tot = 0;
		for (Servizio s : servizi)
			tot = tot + s.getValore();
		return tot;

	}

	public String toString() {
		return codice + " " + nomeCognome + " " + getTot();
	}
}
