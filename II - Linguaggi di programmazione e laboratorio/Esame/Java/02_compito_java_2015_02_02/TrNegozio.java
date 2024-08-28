import java.util.*;

public class TrNegozio extends Transazione {
	
  private String citta;
  
  public TrNegozio(int id, String data, String c, ArrayList<Libro> l)
  {
    super(id,data,l);
    citta = c;
  }
  
  public String toString(){
	  return id + "\t" + data + "\t" + citta + "\t-\t" + getPrezzoTot();
  }
}
