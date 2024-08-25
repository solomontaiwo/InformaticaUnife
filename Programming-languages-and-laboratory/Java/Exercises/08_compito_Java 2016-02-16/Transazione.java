import java.util.*;

public class Transazione {
	
	protected int id;
	protected int giorno;
	protected int mese;
	protected int anno;
	
	public Transazione(int id, int giorno,
  int mese,int anno){
		this.id = id;
		this.giorno = giorno;
		this.mese = mese;
		this.anno = anno;
	}
}
