import java.util.*;

public class Cliente {
	protected int codice;
	protected String nome;
	protected List<Servizio> servizi;

	public Cliente(int codice, String nome) {
		this.codice = codice;
		this.nome = nome;
		servizi = new LinkedList<Servizio>();
	}

	public void addServizio(Servizio s) {
		servizi.add(s);
	}

	public int maxServizi() {
		int dipendenteMaxServizio = 0;
		float oreMaxServizio = 0;
		for (Servizio s : servizi) {
			if (s.oreServizio > oreMaxServizio)
				dipendenteMaxServizio = s.dip.codice;
				oreMaxServizio = s.oreServizio;
		}
		return dipendenteMaxServizio;
	}
	
	public String toString() {
		return codice + "\t" + nome + "\t" + maxServizi() + "\t" + servizi;
	}
}