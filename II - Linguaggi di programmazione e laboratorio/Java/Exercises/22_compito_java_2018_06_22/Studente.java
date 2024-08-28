import java.util.*;

public class Studente {
	protected int matricolaStudente;
	protected String nomeCognomeStudente;
	protected List<Libretto> corsiLibretto;

	public Studente(int matricolaStudente, String nomeCognomeStudente) {
		this.matricolaStudente = matricolaStudente;
		this.nomeCognomeStudente = nomeCognomeStudente;
		this.corsiLibretto = new LinkedList<Libretto>();
	}

	public int getMat() {
		return matricolaStudente;
	}

	public String getNome() {
		return nomeCognomeStudente;
	}

	public Libretto votoMax() {
		int max = 0;
		Libretto maxe = null;
		for (Libretto e : corsiLibretto)
			if (e.getVotoAsInt() > max) {
				max = e.getVotoAsInt();
				maxe = e;
			}
		return maxe;
	}

	public void addEsame(Libretto e) {
		corsiLibretto.add(e);
	}

	private double getMedia() {
		double tot = 0;
		for (Libretto e : corsiLibretto)
			tot = tot + e.getVotoAsInt();
		return tot / corsiLibretto.size();

	}

	public String toString() {
		return nomeCognomeStudente + "\t" + getMedia() + "\t" + corsiLibretto;
	}
}