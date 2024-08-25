import java.util.*;

public class Guida extends Impiegato {

	private int app;
	private boolean inglese;
	private int tel;

	public Guida(int codice, String nome, int tel, boolean inglese, int app, double costo) {
		super(codice, nome, "guida", costo);
		this.app = app;
		this.tel = tel;
		this.inglese = inglese;
	}

	public String toString() {
		return super.toString() + "\t-\t-\t" + tel + "\t" + inglese + "\t" + app + "\t" + getCosto();
	}

}