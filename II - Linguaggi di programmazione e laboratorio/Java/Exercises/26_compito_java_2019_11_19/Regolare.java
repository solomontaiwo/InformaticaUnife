import java.util.*;

public class Regolare extends Partecipante {

	private int dip;
	private String ente;
	private boolean acc;

	public Regolare(int codice, String nome, String cognome, String ente, int dip, boolean acc) {
		super(codice, nome, cognome, "regolare");
		this.ente = ente;
		this.dip = dip;
		this.acc = acc;
	}

	public String getEnte() {
		return ente;
	}

	public String toString() {
		return super.toString() + "\t-\t-\t" + ente + "\t" + dip + "\t" + acc;
	}

}
