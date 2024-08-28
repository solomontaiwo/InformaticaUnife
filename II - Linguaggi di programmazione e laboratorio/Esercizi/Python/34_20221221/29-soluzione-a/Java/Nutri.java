import java.util.*;

public class Nutri extends Dipendente {
	
  private int app;
  private boolean medico;
  private int tel;
  
  public Nutri(int codice,  String nome, int tel, boolean medico, int app, double costo)
  {
    super( codice, nome, "nutri",costo);
     this.app=app;
     this.tel=tel;
     this.medico=medico;
  }
    	public String toString(){
		return super.toString()+"\t-\t-\t"+tel+"\t"+medico+"\t"+app+"\t"+getCosto();
	}

}
