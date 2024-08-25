import java.util.*;

public class Studente extends Partecipante {

	private String corso, universita;
	private int anno;

	public Studente(int codice, String nome, String cognome, String corso, String universita, int anno) {
		super(codice, nome, cognome, "studente");
		this.corso = corso;
		this.universita = universita;
		this.anno = anno;
	}

	public String getUni() {
		return universita;
	}

	public String toString() {
		return super.toString() + corso + "\t" + universita + "\t" + anno + "-\t-\t-";
	}

}