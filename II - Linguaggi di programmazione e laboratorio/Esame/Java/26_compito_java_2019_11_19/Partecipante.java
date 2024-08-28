import java.util.*;

public abstract class Partecipante {

	protected int codice;
	protected String nome, cognome, tipo;

	public Partecipante(int codice, String nome, String cognome, String tipo) {
		this.codice = codice;
		this.nome = nome;
		this.cognome = cognome;
		this.tipo = tipo;
	}

	public String getTipo() {
		return tipo;
	}

	public int getCod() {
		return codice;
	}

	public String getCognome() {
		return cognome;
	}

	public String toString() {
		return tipo + "\t" + codice + "\t" + nome + "\t" + cognome + "\t";
	}
}