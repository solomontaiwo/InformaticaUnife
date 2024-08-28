import java.io.*;
import java.util.*;

public class GestionePolisportiva {
	static List<Squadra> squadre = new LinkedList<Squadra>();
	static List<Giocatore> giocatori = new LinkedList<Giocatore>();

	public static void main(String[] args) {

		// punto 1

		try {
			BufferedReader br = new BufferedReader(new FileReader("squadre.txt"));
			String line = br.readLine();

			while (line != null) {
				StringTokenizer tok = new StringTokenizer(line);
				int codice = Integer.parseInt(tok.nextToken());
				String sport = tok.nextToken();
				String nomeSquadra = br.readLine();
				line = br.readLine();
				tok = new StringTokenizer(line);
				int vinte = Integer.parseInt(tok.nextToken());
				int perse = Integer.parseInt(tok.nextToken());

				if (sport.equals("pallacanestro")) {
					double falli = Double.parseDouble(tok.nextToken());
					int puntiSegnati = Integer.parseInt(tok.nextToken());
					line = br.readLine();
					Squadra s = new Pallacanestro(codice, sport, nomeSquadra, vinte, perse, falli, puntiSegnati);
					squadre.add(s);
				} else {
					double goalFatti = Double.parseDouble(tok.nextToken());
					line = br.readLine();
					Squadra s = new Pallamano(codice, sport, nomeSquadra, vinte, perse, goalFatti);
					squadre.add(s);

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

		// punto 2 - memorizzazione giocatori

		try {
			BufferedReader br = new BufferedReader(new FileReader("giocatori.txt"));
			String line = br.readLine();

			while (line != null) {
				int codice = Integer.parseInt(line);
				String cognome = br.readLine();
				String nome = br.readLine();
				line = br.readLine();
				StringTokenizer tok = new StringTokenizer(line);
				boolean titolare = Boolean.parseBoolean(tok.nextToken());
				int eta = Integer.parseInt(tok.nextToken());
				int numeroMaglia = Integer.parseInt(tok.nextToken());
				String ruolo = tok.nextToken();

				Giocatore g = new Giocatore(codice, cognome, nome, titolare, eta, numeroMaglia, ruolo);
				giocatori.add(g);

				line = br.readLine();
			}

			br.close();

		} catch (IOException e) {
			System.err.println(e);
		} catch (Exception e) {
			System.err.println(e);
		}

		// punto 3 - stampa tutte le squadre

		System.out.println(
				"nome della squadra\tcodice\tn. partite vinte\tn. partite perse\tpunti totali\tn. medio di falli\tn. medio di reti\tsport");

		for (Squadra s : squadre)
			System.out.println(s);

		// punto 4 - stampa giocatori titolari

		System.out.println("nome\tcognome\teta\tnumero di maglia\truolo\tnome squadra");

		for (Giocatore g : giocatori) {
			if (g.titolare) {
				for (Squadra s : squadre)
					if (g.codiceSquadra == s.codice) {
						System.out.print(g);
						System.out.println(s.nomeSquadra);
					}
			}
		}

		// punto 5 - stampa numero giocatori per squadra

		for (Squadra s : squadre) {
			int giocatoriTotali = 0;
			for (Giocatore g : giocatori) {
				if (s.codice == g.codiceSquadra)
					giocatoriTotali++;
			}
			System.out.println(s.nomeSquadra + " " + giocatoriTotali);
		}
	}
}
