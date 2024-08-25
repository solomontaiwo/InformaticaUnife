import java.io.*;
import java.util.*;

public class GestioneGarage {

	static List<Veicolo> veicoli = new LinkedList<Veicolo>();
	static List<Cliente> clienti = new LinkedList<Cliente>();
	static Map<Integer, String> codTarga = new HashMap<Integer, String>();
	static Map<Integer, Double> codCosto = new HashMap<Integer, Double>();
	static Map<Integer, Double> codTot = new HashMap<Integer, Double>();

	public static void main(String[] args) {

		// PUNTO 1: memorizzazione progetti
		try {
			BufferedReader br = new BufferedReader(new FileReader("veicoli.txt"));
			String line = br.readLine();
			while (line != null) {
				StringTokenizer tok = new StringTokenizer(line);
				int cod = Integer.parseInt(tok.nextToken());
				String tipo = tok.nextToken();
				String targa = tok.nextToken();
				line = br.readLine();
				if (tipo.equals("auto")) {
					tok = new StringTokenizer(line);
					int cil = Integer.parseInt(tok.nextToken());
					boolean diesel = Boolean.parseBoolean(tok.nextToken());
					line = br.readLine();
					String modello = line;
					line = br.readLine();
					String marca = line;
					Auto t = new Auto(cod, targa, modello, marca, cil, diesel);
					veicoli.add(t);
					codTarga.put(cod, targa);
					codTot.put(cod, 0.0);
					codCosto.put(cod, 10.0);
				} else {
					String cat = line;
					line = br.readLine();
					int posti = Integer.parseInt(line);
					line = br.readLine();
					String modello = line;
					line = br.readLine();
					String marca = line;
					Furgone t = new Furgone(cod, targa, modello, marca, posti, cat);
					veicoli.add(t);
					codTarga.put(cod, targa);
					codTot.put(cod, 0.0);
					codCosto.put(cod, 15.0);
				}
				line = br.readLine();
			}
			br.close();
		} catch (IOException e) {
			System.err.println(e);
		} catch (Exception e) {
			System.err.println(e);
		}
		// PUNTO 2: lettura di tutti i ricercatori

		try {
			BufferedReader br = new BufferedReader(new FileReader("posteggi.txt"));
			String line = br.readLine();
			while (line != null) {
				String nomeCog = line;
				Cliente c = new Cliente(nomeCog);
				clienti.add(c);
				line = br.readLine();
				StringTokenizer tok = new StringTokenizer(line);
				while (tok.hasMoreElements()) {
					int cod = Integer.parseInt(tok.nextToken());
					int giorni = Integer.parseInt(tok.nextToken());
					String targa = codTarga.get(cod);
					double costo = codCosto.get(cod);
					c.addPosteggio(targa, giorni, costo);
					double current = codTot.get(cod);
					codTot.put(cod, current + giorni * costo);
				}
				line = br.readLine();
			}
			br.close();
		} catch (IOException e) {
			System.err.println(e);
		}

		// PUNTO 3: stampa di tutti i veicoli
		System.out.println("tipo, targa, codice, modello, marca, cilindrata, diesel, categoria, numero di posti");
		for (Veicolo v : veicoli)
			System.out.println(v);
		System.out.println();
		// PUNTO 4: stampa clienti
		for (Cliente c : clienti)
			System.out.println(c);

		// PUNTO 5: stampe del totale dei noleggi
		System.out.println();
		int targa = Integer.parseInt(args[0]);
		double tot = codTot.get(targa);
		System.out.println(targa + " " + tot);

	}
}
