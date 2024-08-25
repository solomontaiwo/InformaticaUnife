import java.util.*;

public abstract class Cliente {

	protected int id; // codice
	protected String indirizzo;
	protected Boolean concordato;
	protected double totale_letture, lettura_max;

	public Cliente(int id, String indirizzo, Boolean tipo_contratto) {
		this.id = id;
		this.indirizzo = indirizzo;
		this.concordato = tipo_contratto;
		this.totale_letture = 0.0;
		this.lettura_max = 0.0;
	}

	public void aggiungiLettura(double l) {
		totale_letture = totale_letture + l;
		if (l > lettura_max)
			lettura_max = l;
	}

	public int getId() {
		return id;
	}

	public double getTotaleLet() {
		return totale_letture;
	}

	public Boolean getConcordato() {
		return concordato;
	}

	public abstract String getNome();

	public String toString() {
		String tipo_contratto;
		if (concordato)
			tipo_contratto = "canone concordato";
		else
			tipo_contratto = "mercato libero";
		return indirizzo + "\t" + tipo_contratto + "\t";
	}

}
