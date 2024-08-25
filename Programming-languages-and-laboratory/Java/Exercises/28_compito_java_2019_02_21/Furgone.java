import java.util.*;

public class Furgone extends Veicolo {

	private int posti;
	private String categoria;

	public Furgone(int codice, String targa, String modello, String marca, int posti, String categoria) {
		super(codice, targa, modello, marca, 15);
		this.posti = posti;
		this.categoria = categoria;
	}

	public String toString() {
		return "commerciale\t" + super.toString() + "\t-\t-\t" + categoria + "\t" + posti;
	}

}