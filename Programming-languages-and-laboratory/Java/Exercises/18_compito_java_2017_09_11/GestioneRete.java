import java.util.*;
import java.io.*;

public class GestioneRete {
	static List<Iscritto> iscritti = new LinkedList<Iscritto>();
	static Map<Integer, Iscritto> id_to_is = new HashMap<Integer, Iscritto>();
	static Map<Integer, Integer> seguaci = new HashMap<Integer, Integer>();

	public static void main(String[] args) {

		// 1 memorizzazione iscritti

		try {
			BufferedReader br = new BufferedReader(new FileReader("iscritti.txt"));
			String line = br.readLine();

			while (line != null) {
				StringTokenizer tok = new StringTokenizer(line);
				String tipoIscritto = tok.nextToken();
				int codiceIscritto = Integer.parseInt(tok.nextToken());
				String nomeCognome_ragioneSociale = br.readLine();
				String indirizzo = br.readLine();

				if (tipoIscritto.equals("individuo")) {
					line = br.readLine();
					tok = new StringTokenizer(line);
					String nomeAccount = tok.nextToken();
					String password = tok.nextToken();

					Iscritto i = new Individuo(tipoIscritto, codiceIscritto, nomeCognome_ragioneSociale, indirizzo,
							nomeAccount, password);
					iscritti.add(i);

					id_to_is.put(codiceIscritto, i);

					line = br.readLine();
				} else {
					String nomeCognomeGestore = br.readLine();
					line = br.readLine();
					tok = new StringTokenizer(line);
					String nomeAccount = tok.nextToken();
					String password = tok.nextToken();

					Iscritto i = new Azienda(tipoIscritto, codiceIscritto, nomeCognome_ragioneSociale, indirizzo,
							nomeCognomeGestore, nomeAccount, password);
					iscritti.add(i);

					id_to_is.put(codiceIscritto, i);

					line = br.readLine();

				}

				line = br.readLine();
			}

			br.close();
		} catch (IOException e) {
			System.out.println(e);
		} catch (Exception e) {
			System.out.println(e);
		}

		// 2, memorizzazione iscritti

		try {
			BufferedReader br = new BufferedReader(new FileReader("segue.txt"));
			String line = br.readLine();

			while (line != null) {
				int codiceIscritto = Integer.parseInt(line);

				Iscritto i = id_to_is.get(codiceIscritto);

				line = br.readLine();
				StringTokenizer tok = new StringTokenizer(line);

				while (line != null && tok.hasMoreTokens()) {
					int codiceFollower = Integer.parseInt(tok.nextToken());
					Iscritto seguace = id_to_is.get(codiceFollower);
					i.aggiungiSeguace(seguace);

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

		// 3, stampa iscritti

		System.out.println(
				"ID\tNome/Cognome\tRagioneSociale\tNome/CognomeGestoreAccount\tIndirizzo\tNomeAccount\tLunghezzaPassword");

		for (Iscritto i : iscritti) {
			System.out.println(i);
		}

		// 4, stampa iscritti + follower

		System.out.println("ID\tNome/Cognome/RagioneSociale\tNumeroSeguaci");
		for (Iscritto i : iscritti) {
			System.out.println(i.getId() + "\t" + i.getNome() + "\t" + i.getNumeroSeguaci());
		}

		// PUNTO 5
		int cod = -1, maxSeguaci = -1;
		String nome = "";
		for (Iscritto i : iscritti)
			if (i.getNumeroSeguaci() > maxSeguaci) {
				cod = i.getId();
				nome = i.getNome();
				maxSeguaci = i.getNumeroSeguaci();

			}
		System.out.println("\nIscritto con max seguaci: " + cod + "\t" + nome);
	}// main
}// class
