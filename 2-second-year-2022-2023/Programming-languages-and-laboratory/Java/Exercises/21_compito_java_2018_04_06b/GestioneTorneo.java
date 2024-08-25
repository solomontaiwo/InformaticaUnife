import java.util.*;
import java.io.*;

public class GestioneTorneo {
	static List<Giocatore> giocatori = new LinkedList<Giocatore>();

	public static void main(String[] args) {

		// Punto 1, memorizzazione giocatori

		try {

			BufferedReader br = new BufferedReader(new FileReader("giocatori.txt"));
			String line = br.readLine();

			while (line != null) {
				int codiceGiocatore = Integer.parseInt(line);
				String tipo = br.readLine();
				String nomeCognomeGiocatore = br.readLine();

				line = br.readLine();

				if (tipo.equals("testa-di-serie")) {
					StringTokenizer tok = new StringTokenizer(line);
					int ranking = Integer.parseInt(tok.nextToken());
					int eta = Integer.parseInt(tok.nextToken());
					boolean professionista = Boolean.parseBoolean(tok.nextToken());

					Giocatore g = new testaDiSerie(codiceGiocatore, tipo, nomeCognomeGiocatore, ranking, eta,
							professionista);
					giocatori.add(g);

					line = br.readLine();

				} else {
					String nomeCircolo = line;
					line = br.readLine();
					StringTokenizer tok = new StringTokenizer(line);
					int numeroSetVinti = Integer.parseInt(tok.nextToken());
					int numeroPartiteDisputate = Integer.parseInt(tok.nextToken());

					Giocatore g = new Normale(codiceGiocatore, tipo, nomeCognomeGiocatore, nomeCircolo, numeroSetVinti,
							numeroPartiteDisputate);
					giocatori.add(g);

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

		// Punto 2, memorizzazione partite

		try {

			BufferedReader br = new BufferedReader(new FileReader("partite.txt"));
			String line = br.readLine();

			while (line != null) {
				StringTokenizer tok = new StringTokenizer(line);
				int codicePrimoGiocatore = Integer.parseInt(tok.nextToken());
				int codiceSecondoGiocatore = Integer.parseInt(tok.nextToken());
				line = br.readLine();
				tok = new StringTokenizer(line);
				int setVintiPrimoGiocatore = Integer.parseInt(tok.nextToken());
				int setVintiSecondoGiocatore = Integer.parseInt(tok.nextToken());

				Partita p = new Partita(codicePrimoGiocatore, codiceSecondoGiocatore, setVintiPrimoGiocatore,
						setVintiSecondoGiocatore);

				for (Giocatore g : giocatori) {
					if (p.codicePrimoGiocatore == g.codiceGiocatore) {
						g.partite.add(p);
					}

					if (p.codiceSecondoGiocatore == g.codiceGiocatore) {
						Partita par = new Partita(codiceSecondoGiocatore, codicePrimoGiocatore,
								setVintiSecondoGiocatore, setVintiPrimoGiocatore);
						g.partite.add(par);
					}

				}

				line = br.readLine();

			}

			br.close();

		} catch (

		IOException e) {
			System.err.println(e);
		} catch (Exception e) {
			System.err.println(e);
		}

		// Punto 3, stampa elenco giocatori

		System.out.println("nome\tcodice\ttipo\tranking\tetà\tprofessionista\tcircolo\tn. set vinti\tn. partite");

		for (Giocatore g : giocatori) {
			System.out.println(g);
		}

		System.out.println("");

		// Punto 4, stampa nome ed elenco partite giocatore

		for (Giocatore gio : giocatori) {
			System.out.println(gio.nomeCognome + " " + gio.partite);
		}

		System.out.println("");

	}
}
