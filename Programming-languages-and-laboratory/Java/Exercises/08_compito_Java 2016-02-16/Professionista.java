import java.util.*;

public class Professionista extends Transazione {
	
  private String ragioneSociale;
  private int partitaIva;
  private int codice;
  
  public Professionista(int id, int giorno,
  int mese,int anno,String ragioneSociale, int partitaIva,int codice){
    super(id,giorno,mese,anno);
    this.ragioneSociale = ragioneSociale;
    this.partitaIva = partitaIva;
    this.codice=codice;
  }
  
  public String toString(){
	  return id +"\t"+giorno +"/"+mese+"/"+anno+ "\t-\t-\t-\t" 
   +ragioneSociale+"\t"+partitaIva+"\t"+codice;
  }
}
