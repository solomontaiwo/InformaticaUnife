import java.util.*;

public class Auto extends Veicolo {

	private int cilindrata;
	private boolean diesel;

	public Auto(int codice, String targa, String modello, String marca, int cilindrata, boolean diesel) {
		super(codice, targa, modello, marca, 10);
		this.cilindrata = cilindrata;
		this.diesel = diesel;
	}

	public String toString() {
		return "automobile\t" + super.toString() + cilindrata + "\t" + diesel + "\t-\t-";
	}

}
