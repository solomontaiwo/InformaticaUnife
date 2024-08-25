import java.util.*;

public class TrWeb extends Transazione {
	
  private String ip;
  
  public TrWeb(int id, String data, String ip, ArrayList<Libro> l)
  {
    super(id,data,l);
    this.ip = ip;
  }
  
  public String toString(){
	  return id + "\t" + data + "\t-\t" + ip + "\t" + getPrezzoTot();
  }
}
