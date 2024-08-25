import java.util.*;

public class Transazione {
	
	protected int id;
	protected String data;
	protected List<Libro> libri;
	
	public Transazione(int id, String data, ArrayList<Libro> l){
		this.id = id;
		this.data = data;
		libri = l;	
	}
	
	public int getPrezzoTot(){
	int p = 0;
		for(int i=0;i<this.libri.size();i++){
			p = p + this.libri.get(i).getPrezzo();
		}
		return p;
	}
}
