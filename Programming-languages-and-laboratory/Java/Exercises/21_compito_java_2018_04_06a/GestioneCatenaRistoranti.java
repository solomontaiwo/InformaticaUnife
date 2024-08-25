import java.util.*;
import java.io.*;

public class GestioneCatenaRistoranti {
	static List<Ristorante> ristoranti = new LinkedList<Ristorante>();

	public static void main(String[] args) {

		// Punto 1, memorizzazione ristoranti

		try {
			BufferedReader br = new BufferedReader(new FileReader("ristoranti.txt"));
			String line = br.readLine();

			while (line != null) {
				StringTokenizer tok = new StringTokenizer(line);
				int codiceRistorante = Integer.parseInt(tok.nextToken());
				String tipoRistorante = tok.nextToken();
				String nomeRistorante = br.readLine();

				line = br.readLine();

				if (tipoRistorante.equals("pub")) {
					tok = new StringTokenizer(line);
					int numeroDipendenti = Integer.parseInt(tok.nextToken());
					int numeroTavoli = Integer.parseInt(tok.nextToken());

					Ristorante r = new Pub(codiceRistorante, tipoRistorante, nomeRistorante, numeroDipendenti,
							numeroTavoli);
					ristoranti.add(r);

				} else {
					tok = new StringTokenizer(line);
					int postiASedere = Integer.parseInt(tok.nextToken());
					double superficie = Double.parseDouble(tok.nextToken());
					boolean bagnoDisabili = Boolean.parseBoolean(tok.nextToken());

					Ristorante r = new Osteria(codiceRistorante, tipoRistorante, nomeRistorante, postiASedere,
							superficie, bagnoDisabili);
					ristoranti.add(r);

				}

				line = br.readLine();

			}

			br.close();

		} catch (IOException e) {
			System.err.println(e);
		} catch (Exception e) {
			System.err.println(e);
		}

		// Punto 2, memorizzazione menu

		try {
			BufferedReader br = new BufferedReader(new FileReader("menu.txt"));
			String line = br.readLine();

			while (line != null) {
				int codiceRistorante = Integer.parseInt(line);
				String descrizioneProdotto = br.readLine();
				line = br.readLine();
				StringTokenizer tok = new StringTokenizer(line);
				String tipoProdotto = tok.nextToken();
				float prezzoProdotto = Float.parseFloat(tok.nextToken());
				float costoMateriePrime = Float.parseFloat(tok.nextToken());
				line = br.readLine();
				line = br.readLine();

				Menu m = new Menu(codiceRistorante, descrizioneProdotto, tipoProdotto, prezzoProdotto,
						costoMateriePrime);

				for (Ristorante r : ristoranti) {
					if (r.codiceRistorante == m.codiceRistorante) {
						r.menu.add(m);
					}
				}

			}

			br.close();

		} catch (IOException e) {
			System.err.println(e);
		} catch (Exception e) {
			System.err.println(e);
		}

		// Punto 3, stampa tutti i ristoranti - 6 punti

		System.out.println("nome\tcodice\ttipo\tn. dipendenti\tn. tavoli\tn. posti\tsuperficie\tbagno disabili");

		for (Ristorante r : ristoranti) {
			System.out.println(r);
		}

		System.out.println("");

		// Punto 4, stampa locali con nome e menu

		for (Ristorante ris : ristoranti) {
			System.out.println(ris.nomeRistorante + " " + ris.menu);
		}

		// Punto 5, stampa locale con prezzo medio dei prodotti piu alto

		float max = 0;
		String nome = null;
		for (Ristorante l : ristoranti) {
			float media = l.getMedia();
			if (media > max) {
				max = media;
				nome = l.nomeRistorante;
			}
		}
		System.out.println("\nIl ristorante con il prezzo medio pi alto è " + nome + ".");

	}

}
