import java.util.*;

public class Privato extends Transazione {
	
  private String nome;
  private String indirizzo;
  private String codiceFiscale;

  
  public Privato(int id, int giorno,
  int mese,int anno,String nome, String indirizzo, String codiceFiscale){
    super(id,giorno,mese,anno);
    this.nome = nome;
    this.indirizzo = indirizzo;
    this.codiceFiscale = codiceFiscale;
  }
  
  public String toString(){
	  return id + "\t"+giorno+"/"+mese+"/"+anno+"\t" + nome + "\t" + indirizzo + "\t" + 
    codiceFiscale +"-\t-\t-";
  }
}
