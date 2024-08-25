import java.io.*;
import java.util.*;

public class Gestione {

  public static void main(String[] args) {
    List<Transazione> transazioni = new LinkedList<Transazione>();
       Map<Integer,Integer> totali = new HashMap<Integer,Integer>();
int totale=0;
        //PUNTO 1: memorizzazione prodotti
        try {
            BufferedReader br = new BufferedReader(new FileReader("transazioni.txt"));
            String line=br.readLine(); //prima riga: tipo+codice
            while (line!= null){
            	//lettura di 1 transazione
                String nome;
                String indirizzo;
                String codiceFiscale;
                String ragioneSociale;
                int partitaIva; 
                int codice;
            	StringTokenizer tokenizer = new StringTokenizer(line);
                String type         = tokenizer.nextToken();
                int id              = Integer.parseInt(tokenizer.nextToken());
                    line = br.readLine(); 
            	  tokenizer = new StringTokenizer(line);  
                int giorno              = Integer.parseInt(tokenizer.nextToken());
                int mese              = Integer.parseInt(tokenizer.nextToken());
                int anno              = Integer.parseInt(tokenizer.nextToken());
                if (type.equals("privato"))
                {
                nome		= br.readLine();
                indirizzo       = br.readLine();
                codiceFiscale=br.readLine(); 
                ragioneSociale=null;
                partitaIva=0; 
                codice=0;
                
                } else {
                ragioneSociale=br.readLine();
                line = br.readLine(); 
            	  tokenizer = new StringTokenizer(line);  
                partitaIva=Integer.parseInt(tokenizer.nextToken()); 
                codice=Integer.parseInt(tokenizer.nextToken()); 
                nome		= null;
                indirizzo       = null;
                codiceFiscale=null; 
                }
                    line = br.readLine(); 
                    int totTr=0;
                    while (line!= null && !line.isEmpty()){
            	                      line = br.readLine(); 
          tokenizer = new StringTokenizer(line);  
                      int pezzi =Integer.parseInt(tokenizer.nextToken());
                      int prezzo=Integer.parseInt(tokenizer.nextToken());
                      totTr=totTr+pezzi*prezzo;
                      line = br.readLine(); 
                    }
                  totale=totale+totTr;
                    if (type.equals("privato")) {
                        Transazione t = new Privato(id, giorno, mese, anno,nome, indirizzo, codiceFiscale);
                        transazioni.add(t);
                    } else {
                        Transazione t = new Professionista(id, giorno, mese,anno,ragioneSociale,
                        partitaIva,codice);
                        transazioni.add(t);
                    }
                    totali.put(id, new Integer(totTr));
                      line = br.readLine(); 
            }//while
            br.close();
        } catch (IOException e) {
            System.err.println(e);
        }
        catch (Exception e) {
			System.err.println(e);
        }
  		//PUNTO 2
		System.out.println("ID\tData\tNome\tIndirizzo\tCodiceFiscale\tRagioneSociale\tPartitaIva\tCodice");
  		for (Transazione t: transazioni)
  			System.out.println(t);
    	
        //PUNTO 3
        System.out.println("\nTotale per transazione");        
        System.out.println(totali);

        //PUNTO 4
        System.out.println("\nTotale complessivo");        
        System.out.println(totale);
    }//main   
}//class
