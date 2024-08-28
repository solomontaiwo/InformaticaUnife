import java.util.*;

public class Aziendale extends Cliente {

	private String ragioneSociale;
	private double portata_massima;

	public Aziendale(int id, String indirizzo, Boolean tipo_contratto, String ragioneSociale, double portata_massima) {
		super(id, indirizzo, tipo_contratto);
		this.portata_massima = portata_massima;
		this.ragioneSociale = ragioneSociale;
	}

	public String toString() {
		return id + "\taziendale\t-\t" + ragioneSociale + "\t" + super.toString() + portata_massima;
	}

	public String getNome() {
		return ragioneSociale;
	}
}