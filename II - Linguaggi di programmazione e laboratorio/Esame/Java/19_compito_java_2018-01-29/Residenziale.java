import java.util.*;

public class Residenziale extends Cliente {

	private String nome;

	public Residenziale(int id, String indirizzo, Boolean tipo_contratto, String nome) {
		super(id, indirizzo, tipo_contratto);
		this.nome = nome;
	}

	public String getNome() {
		return nome;
	}

	public String toString() {
		return id + "\tresidenziale\t" + nome + "\t-\t" + super.toString() + "-";
	}

}