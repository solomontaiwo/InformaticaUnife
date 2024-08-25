import java.io.*;
import java.util.*;

public class Gestione {

        static List<Veicolo> veicoli   = new LinkedList<Veicolo>();
        static List<Cliente> clienti   = new LinkedList<Cliente>();
        static Map<Integer,String> codTarga = new HashMap<Integer,String>();
        static Map<Integer,Double> codCosto = new HashMap<Integer,Double>();
        static Map<String,Integer> targaNoleggi = new HashMap<String,Integer>();

    public static void main(String[] args) {


        //PUNTO 1: memorizzazione progetti
        try {
            BufferedReader br = new BufferedReader(new FileReader("veicoli.txt"));
            String line=br.readLine();
            while (line!= null){
                StringTokenizer tok = new StringTokenizer(line);
                int cod=Integer.parseInt(tok.nextToken());
                String tipo=tok.nextToken();
                String targa=tok.nextToken();
                line                = br.readLine();
                String modello = line;
                line                = br.readLine();
                String marca = line;
                line= br.readLine();
                    if (tipo.equals("auto")) {
                        tok = new StringTokenizer(line);
                        double bag=Double.parseDouble(tok.nextToken());
                        int cil=Integer.parseInt(tok.nextToken());
                        line= br.readLine();
                        String categoria= line;
                        double costo=Double.parseDouble(br.readLine());
                        Auto t=new Auto(cod,targa,modello,marca,costo,cil,bag,categoria);
                        veicoli.add(t);
                        codTarga.put(cod,targa);
                        codCosto.put(cod,costo);
                    } else {
                        tok = new StringTokenizer(line);
                        boolean rimorchio=Boolean.parseBoolean(tok.nextToken());
                        int posti=Integer.parseInt(tok.nextToken());
                        boolean carico=Boolean.parseBoolean(tok.nextToken());
                        double costo=Double.parseDouble(br.readLine());
                        Furgone t=new Furgone(cod,targa,modello,marca,costo,posti,rimorchio,carico);
                        veicoli.add(t);
                        codTarga.put(cod,targa);
                        codCosto.put(cod,costo);
                    }
                    line = br.readLine();
                }
            br.close();
        } catch (IOException e) {
            System.err.println(e);
        }
        catch (Exception e) {
			System.err.println(e);
        }
        //PUNTO 2: lettura di tutti i ricercatori

        try {
            BufferedReader br = new BufferedReader(new FileReader("clienti.txt"));
            String line=br.readLine();
            while (line!= null){
                String nomeCog=line;
                Cliente c=new Cliente(nomeCog);
                clienti.add(c);
                line=br.readLine();
                while (line!=null && !line.equals("")){
                    StringTokenizer tok = new StringTokenizer(line);
                    int cod=Integer.parseInt(tok.nextToken());
                    int giorni=Integer.parseInt(tok.nextToken());
                    String targa=codTarga.get(cod);
                    double costo=codCosto.get(cod);
                    c.addNoleggio(targa,giorni,costo);
                    Integer noleggi=targaNoleggi.get(targa);
                    if (noleggi==null)
                        targaNoleggi.put(targa,1);
                    else
                        targaNoleggi.put(targa,noleggi+1);
                    line=br.readLine();
            }
                line=br.readLine();
            }
           br.close();
            }
        catch (IOException e) {
            System.err.println(e);
        }


        //PUNTO 3: stampa di tutti i veicoli
        System.out.println("tipo, targa, codice, modello, marca, costo giornaliero, bagagliaio, cilindrata, categoria, rimorchio, numero di posti, vano di carico");
        for (Veicolo v : veicoli)
            System.out.println(v);
        System.out.println();
        //PUNTO 4: stampa clienti
        for (Cliente c : clienti)
          System.out.println(c);

        //PUNTO 5: stampe del totale dei noleggi
        System.out.println();
        try {
            BufferedReader kbd =
            new BufferedReader(new InputStreamReader(System.in));
            String targa=kbd.readLine();
            

        int n=targaNoleggi.get(targa);
                System.out.println(n);
            }
            catch (IOException e) {
               System.err.println(e);
           }
    }
}
