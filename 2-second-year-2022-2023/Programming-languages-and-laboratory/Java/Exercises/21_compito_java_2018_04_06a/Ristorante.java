import java.util.*;

public class Ristorante {
	protected int codiceRistorante;
	protected String tipoRistorante, nomeRistorante;
	protected List<Menu> menu;

	public Ristorante(int codiceRistorante, String tipoRistorante, String nomeRistorante) {
		this.codiceRistorante = codiceRistorante;
		this.tipoRistorante = tipoRistorante;
		this.nomeRistorante = nomeRistorante;
		menu = new LinkedList<Menu>();
	}

	public float getMedia() {
		int n = menu.size();
		float tot = 0;
		for (Menu p : menu)
			tot = tot + p.prezzoProdotto;
		return tot / n;
	}
}