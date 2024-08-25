import java.io.*;
import java.util.*;

public class Vendite {

    public static void main(String[] args) {

        List<Transazione> transazioni = new LinkedList<Transazione>();
        Map<String,Integer> copie = new HashMap<String,Integer>();

        //PUNTO 1: memorizzazione transazioni
        try {
            BufferedReader br = new BufferedReader(new FileReader("transazioni.txt"));
            String line=br.readLine(); //prima riga: prima transazione
            while (line!= null){
            	//dati transazione
                StringTokenizer tokenizer = new StringTokenizer(line);
                String type         = tokenizer.nextToken();
                int id              = Integer.parseInt(tokenizer.nextToken());
                String data			= tokenizer.nextToken();
                String luogo 		= tokenizer.nextToken();
                //libri della transazione
                List<Libro> libri = new ArrayList<Libro>();
                line=br.readLine(); //primo titolo
                while ((line != null) && (!line.isEmpty())) {
                    libri.add(readBook(br,line,copie));                   
                    line=br.readLine();
                 }
                /* verifica uscita ciclo while */
                if (line == null) { // EOF
                    if (type.equals("f")) {
                        Transazione t=new TrNegozio(id,data,luogo,(ArrayList<Libro>)libri);
                        transazioni.add(t);
                    } else {
                        Transazione t=new TrWeb(id,data,luogo,(ArrayList<Libro>)libri);
                        transazioni.add(t);
                    }
                    br.close();
                } else { //line is empty
                    if (type.equals("f")) {
                        Transazione t=new TrNegozio(id,data,luogo,(ArrayList<Libro>)libri);
                        transazioni.add(t);
                    } else {
                        Transazione t=new TrWeb(id,data,luogo,(ArrayList<Libro>)libri);
                        transazioni.add(t);
                    }
                    line = br.readLine(); 
                }
            }
            br.close();
            System.out.println("Totale transazioni lette: " + transazioni.size() +"\n"); //controllo lettura
        } catch (IOException e) {
            System.err.println(e);
        }
        catch (Exception e) {
			System.err.println(e);
        }

  		//PUNTO 2
		System.out.println("ID\tData\tCitta'\tIndirizzoIP\tTotale");
  		  for (Transazione t: transazioni){
    		System.out.println(t);
    	}
    	
        //PUNTO 3
        System.out.println("\nN. copie vendute per libro");        
        System.out.println(copie);

		//PUNTO 4
		int incasso = 0;
  		for (Transazione t: transazioni){
  		  	 incasso = incasso + t.getPrezzoTot();
    	}
    	System.out.println("\nIncasso totale = " + incasso);
    }//main

    private static Libro readBook(BufferedReader br, String line, Map<String,Integer> copie) throws IOException {
        
        String titolo		= line;
        String autori       = br.readLine();
        int prezzo          = Integer.parseInt(br.readLine());
		Integer pezzi = copie.get(titolo);
		if (pezzi==null)
			copie.put(titolo, new Integer(1));
		else
			copie.put(titolo, new Integer(pezzi+1));
			
        return new Libro(titolo,autori,prezzo);
    }
}
