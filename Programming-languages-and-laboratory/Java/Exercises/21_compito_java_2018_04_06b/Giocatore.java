import java.util.*;

public class Giocatore {
	protected int codiceGiocatore, vittorie;
	protected String tipo;
	protected String nomeCognome;
	protected List<Partita> partite;

	public Giocatore(int codiceGiocatore, String tipo, String nomeCognome) {
		this.codiceGiocatore = codiceGiocatore;
		this.tipo = tipo;
		this.nomeCognome = nomeCognome;
		partite = new LinkedList<Partita>();
		vittorie = 0;
	}
	
	public void nuovaVittoria() {
		vittorie++;
	}
}