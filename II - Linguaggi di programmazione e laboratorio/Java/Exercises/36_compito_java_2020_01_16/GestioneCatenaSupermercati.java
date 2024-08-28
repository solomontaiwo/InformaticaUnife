import java.util.*;
import java.io.*;

public class GestioneCatenaSupermercati {
	static List<Supermercato> supermercati = new LinkedList<Supermercato>();
	static List<Ipermercato> ipermercati = new LinkedList<Ipermercato>();
	static List<Cittadino> cittadini = new LinkedList<Cittadino>();
	static List<Cliente> clienti = new LinkedList<Cliente>();
	static List<Visita> visite = new LinkedList<Visita>();
	static HashMap<Integer, Integer> codiceSupermercato_numeroVisite = new HashMap<Integer, Integer>();

	public static void main(String[] args) {

		// Punto 1, memorizzazione supermercati

		try {
			BufferedReader br = new BufferedReader(new FileReader("supermercati.txt"));
			String line = br.readLine();

			while (line != null && !line.isEmpty()) {
				StringTokenizer tok = new StringTokenizer(line);
				int codice = Integer.parseInt(tok.nextToken());
				String tipo = tok.nextToken();
				String indirizzo = br.readLine();

				line = br.readLine();

				if (tipo.equals("cittadino")) {
					tok = new StringTokenizer(line);
					int orarioApertura = Integer.parseInt(tok.nextToken());
					int orarioChiusura = Integer.parseInt(tok.nextToken());
					float superficie = Float.parseFloat(tok.nextToken());
					int numeroAddetti = Integer.parseInt(tok.nextToken());
					Cittadino s = new Cittadino(codice, tipo, indirizzo, orarioApertura, orarioChiusura, superficie,
							numeroAddetti);
					supermercati.add(s);
					cittadini.add(s);
				} else {
					tok = new StringTokenizer(line);
					float superficie = Float.parseFloat(tok.nextToken());
					int numeroAddetti = Integer.parseInt(tok.nextToken());
					String nomeCentroCommerciale = br.readLine();
					Ipermercato s = new Ipermercato(codice, tipo, indirizzo, superficie, numeroAddetti,
							nomeCentroCommerciale);
					supermercati.add(s);
					ipermercati.add(s);
				}
				line = br.readLine();
			}

			br.close();

		} catch (IOException e) {
			System.err.println(e);
		} catch (Exception e) {
			System.err.println(e);
		}

		// Punto 2, memorizzazione clienti

		try {
			BufferedReader br = new BufferedReader(new FileReader("clienti.txt"));
			String line = br.readLine();

			while (line != null) {
				String cognome = line;
				String nome = br.readLine();

				Cliente c = new Cliente(cognome, nome);

				line = br.readLine();
				while (line != null && !line.isEmpty()) {
					StringTokenizer tok = new StringTokenizer(line);
					int codiceSupermercato = Integer.parseInt(tok.nextToken());
					float importoSpeso = Float.parseFloat(tok.nextToken());

					Visita v = new Visita(codiceSupermercato, importoSpeso);
					visite.add(v);
					c.visite.add(v);

					codiceSupermercato_numeroVisite.put(codiceSupermercato, null);

					for (Ipermercato i : ipermercati) {
						if (i.codice == v.codiceSupermercato) {
							i.addvisite();
						}
					}

					for (Cittadino citt : cittadini) {
						if (citt.codice == v.codiceSupermercato) {
							citt.addvisite();
						}
					}

					line = br.readLine();
				}
				clienti.add(c);
				line = br.readLine();
			}

			br.close();

		} catch (IOException e) {
			System.err.println(e);
		} catch (Exception e) {
			System.err.println(e);
		}

		// Punto 3, stampa elenco supermercati

		System.out.println("codice\ttipo\tindirizzo\tapertura\tchiusura\tsuperficie\tn. addetti\tcentro commerciale");

		for (Supermercato s : supermercati) {
			System.out.println(s);
		}

		System.out.println();

		// Punto 4, stampa elenco clienti

		System.out.println("cognome\tnome\tspesa totale");

		for (Cliente c : clienti) {
			System.out.println(c);
		}

		System.out.println();

		/*
		 * // Punto 5, lettura da linea di comando codice e stampa spesa media del //
		 * supermercato
		 * 
		 * Scanner scanner = new Scanner(System.in); int codiceLetto =
		 * scanner.nextInt(); float totale = 0;
		 * 
		 * for (Cittadino cittad : cittadini) { if (cittad.codice == codiceLetto) { for
		 * (Visita v : visite) { if (v.codiceSupermercato == codiceLetto) totale =
		 * totale + v.importoSpeso; } totale = totale / cittad.getNumeroVisite();
		 * 
		 * } else { for (Ipermercato i : ipermercati) { if (i.codice == codiceLetto) {
		 * for (Visita v : visite) { if (v.codiceSupermercato == codiceLetto) totale =
		 * totale + v.importoSpeso; } } totale = totale / i.getNumeroVisite(); }
		 * 
		 * } }
		 * 
		 * System.out.println(totale);
		 */
	}
}
