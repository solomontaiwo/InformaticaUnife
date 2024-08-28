import java.io.*;
import java.util.*;

public class Gestione {

	static List<Veicolo> veicoli = new LinkedList<Veicolo>();
	static List<Cliente> clienti = new LinkedList<Cliente>();
	static Map<Integer, Veicolo> codVeicolo = new HashMap<Integer, Veicolo>();

	public static void main(String[] args) {

		// PUNTO 1: memorizzazione veicoli
		try {
			BufferedReader br = new BufferedReader(new FileReader("veicoli.txt"));
			String line = br.readLine();
			while (line != null) {
				StringTokenizer tok = new StringTokenizer(line);
				int cod = Integer.parseInt(tok.nextToken());
				String tipo = tok.nextToken();
				String marca = br.readLine();
				line = br.readLine();
				tok = new StringTokenizer(line);
				if (tipo.equals("roulotte")) {
					int peso = Integer.parseInt(tok.nextToken());
					float lunghezza = Float.parseFloat(tok.nextToken());
					float larghezza = Float.parseFloat(tok.nextToken());
					int posti = Integer.parseInt(tok.nextToken());
					line = br.readLine();
					tok = new StringTokenizer(line);
					String veranda = tok.nextToken();
					float costo = Float.parseFloat(tok.nextToken());
					Veicolo v = new Roulotte(cod, marca, larghezza, lunghezza, costo, posti, peso, veranda);
					veicoli.add(v);
					codVeicolo.put(cod, v);

				} else {
					float larghezza = Float.parseFloat(tok.nextToken());
					float lunghezza = Float.parseFloat(tok.nextToken());
					int potenza = Integer.parseInt(tok.nextToken());
					int posti = Integer.parseInt(tok.nextToken());
					float costo = Float.parseFloat(tok.nextToken());
					Veicolo v = new Caravan(cod, marca, larghezza, lunghezza, costo, posti, potenza);
					veicoli.add(v);
					codVeicolo.put(cod, v);

				}
				line = br.readLine();
				line = br.readLine();
			}
			br.close();
		} catch (IOException e) {
			System.err.println(e);
		} catch (Exception e) {
			System.err.println(e);
		}
		// PUNTO 2: lettura di tutti i giocatori

		try {
			BufferedReader br = new BufferedReader(new FileReader("clienti.txt"));
			String line = br.readLine();
			while (line != null) {
				int codice = Integer.parseInt(line);
				String nome = br.readLine();
				String cognome = br.readLine();
				String indirizzo = br.readLine();
				Cliente c = new Cliente(codice, nome, cognome, indirizzo);
				clienti.add(c);
				line = br.readLine();
				while (line != null && !line.equals("")) {
					StringTokenizer tok = new StringTokenizer(line);
					tok = new StringTokenizer(line);
					int cod = Integer.parseInt(tok.nextToken());
					int giorni = Integer.parseInt(tok.nextToken());
					Prenotazione pren = new Prenotazione(cod, giorni);
					c.addPrenotazione(pren);
					Veicolo v = codVeicolo.get(cod);
					v.addPrenotazione(pren);
					line = br.readLine();
				}
				line = br.readLine();
			}
			br.close();
		} catch (IOException e) {
			System.err.println(e);
		} catch (Exception e) {
			System.err.println(e);
		}

		// PUNTO 3: stampa di tutti i veicoli
		System.out.println("tipo, codice, marca, larghezza, lunghezza, posti letto, peso, veranda, potenza, costo");
		for (Veicolo v : veicoli)
			System.out.println(v);

		// PUNTO 4: elenco dei clienti
		System.out.println("\ncodice, cognome, nome, indirizzo, prenotazioni ");
		for (Cliente c : clienti)
			System.out.println(c);
		System.out.println("\ncodice, incasso");
		// PUNTO 5: stampe dell'incasso di ciascun veicolo
		for (Veicolo v : veicoli)
			System.out.println(v.getCod() + "\t" + v.incasso());

	}// main

}