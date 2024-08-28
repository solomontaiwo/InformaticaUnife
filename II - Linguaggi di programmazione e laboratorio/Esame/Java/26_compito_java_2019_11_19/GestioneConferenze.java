import java.io.*;
import java.util.*;

public class GestioneConferenze {

	static List<Partecipante> partecipanti = new LinkedList<Partecipante>();
	static List<Conferenza> conferenze = new LinkedList<Conferenza>();
	static Map<Integer, Partecipante> codPart = new HashMap<Integer, Partecipante>();

	public static void main(String[] args) {

		// PUNTO 1: memorizzazione progetti
		try {
			BufferedReader br = new BufferedReader(new FileReader("partecipanti.txt"));
			String line = br.readLine();
			while (line != null) {
				StringTokenizer tok = new StringTokenizer(line);
				int cod = Integer.parseInt(tok.nextToken());
				String tipo = tok.nextToken();
				String nome = br.readLine();
				String cognome = br.readLine();

				if (tipo.equals("studente")) {
					String corso = br.readLine();
					String uni = br.readLine();
					line = br.readLine();
					int anno = Integer.parseInt(line);
					Studente s = new Studente(cod, nome, cognome, corso, uni, anno);
					partecipanti.add(s);
					codPart.put(cod, s);
				} else {
					String ente = br.readLine();
					line = br.readLine();
					tok = new StringTokenizer(line);
					int dip = Integer.parseInt(tok.nextToken());
					boolean acc = Boolean.parseBoolean(tok.nextToken());
					Regolare r = new Regolare(cod, nome, cognome, ente, dip, acc);
					partecipanti.add(r);
					codPart.put(cod, r);
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
			BufferedReader br = new BufferedReader(new FileReader("conferenze.txt"));
			String line = br.readLine();
			while (line != null) {
				String nome = line;
				String luogo = br.readLine();
				Conferenza c = new Conferenza(nome, luogo);
				conferenze.add(c);
				line = br.readLine();
				while (!line.equals("")) {
					StringTokenizer tok = new StringTokenizer(line);
					int cod = Integer.parseInt(tok.nextToken());
					int reg = Integer.parseInt(tok.nextToken());
					Partecipante p = codPart.get(cod);
					Partecipazione part = new Partecipazione(p, reg);
					c.addPart(part);
					line = br.readLine();
				}
				line = br.readLine();
			}
			br.close();
		} catch (IOException e) {
			System.err.println(e);
		}

		// PUNTO 3: stampa di tutti i partecipanti
		System.out.println(
				"tipo, codice, nome, cognome, corso di studi, università, anno di corso, ente di appartenenza, numero di dipendenti, accademico");
		for (Partecipante p : partecipanti)
			System.out.println(p);
		System.out.println();
		// PUNTO 4: stampa conferenze
		for (Conferenza c : conferenze)
			System.out.println(c);

		// PUNTO 5: stampe del totale dei noleggi
		System.out.println();
		String line;
		int cod;
		try {
			BufferedReader kbd = new BufferedReader(new InputStreamReader(System.in));
			line = kbd.readLine();
			cod = Integer.parseInt(line);

			Partecipante part = codPart.get(cod);
			if (part.getTipo().equals("studente")) {
				Studente s = (Studente) part;
				System.out.println("Studente, università: " + s.getUni());
			} else {
				Regolare r = (Regolare) part;
				System.out.println("Regolare, ente: " + r.getEnte());

			}
		} catch (IOException e) {
			System.err.println(e);
		}
	}
}
