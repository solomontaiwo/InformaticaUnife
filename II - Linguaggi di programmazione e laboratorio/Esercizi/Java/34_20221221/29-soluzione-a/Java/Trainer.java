import java.util.*;

public class Trainer extends Dipendente {
	
  private int ore;
  private String spec;
  
  public Trainer(int codice,  String nome, int ore, String spec, double costo)
  {
    super( codice, nome, "trainer",costo);
     this.ore=ore;
     this.spec=spec;
  }
    	public String toString(){
		return super.toString()+"\t"+ore+"\t"+spec+"\t-\t-\t-\t"+getCosto();
	}


}
