import java.util.*;

public class Conferenza {

	protected String nome, luogo;
	protected List<Partecipazione> partecipanti;

	public Conferenza(String nome, String luogo) {
		this.nome = nome;
		this.luogo = luogo;
		this.partecipanti = new LinkedList<Partecipazione>();
	}

	public void addPart(Partecipazione part) {
		partecipanti.add(part);
	}

	public int getTot() {
		int tot = 0;
		for (Partecipazione p : partecipanti)
			tot = tot + p.getReg();
		return tot;
	}

	public String toString() {
		return nome + "\n" + luogo + "\n" + getTot() + "\t" + partecipanti.size() + "\n" + partecipanti;
	}
}