import java.io.*;
import java.util.*;

public class GestioneAcquedotto {

	public static void main(String[] args) {
		List<Cliente> clienti = new LinkedList<Cliente>();
		Map<Integer, Cliente> id_to_cl = new HashMap<Integer, Cliente>();
		double max = 0;
		String max_cl = "";

		// PUNTO 1: memorizzazione clienti
		try {
			BufferedReader br = new BufferedReader(new FileReader("clienti.txt"));
			String line = br.readLine(); // prima riga: tipo+codice
			while (line != null) {
				// lettura di 1 cliente
				String nome;
				String indirizzo;
				String ragioneSociale;
				String tipo_contratto;
				double portata;
				int codice;
				StringTokenizer tokenizer = new StringTokenizer(line);
				String type = tokenizer.nextToken();
				int id = Integer.parseInt(tokenizer.nextToken());
				if (type.equals("residenziale")) {
					nome = br.readLine();
					tipo_contratto = br.readLine();
					indirizzo = br.readLine();
					Cliente c = new Residenziale(id, indirizzo, tipo_contratto.equals("canone concordato"), nome);
					clienti.add(c);
					id_to_cl.put(id, c);

				} else {
					ragioneSociale = br.readLine();
					portata = Double.parseDouble(br.readLine());

					tipo_contratto = br.readLine();

					indirizzo = br.readLine();
					Cliente c = new Aziendale(id, indirizzo, tipo_contratto.equals("canone concordato"), ragioneSociale,
							portata);
					clienti.add(c);
					id_to_cl.put(id, c);
				}
				line = br.readLine();
				line = br.readLine();
			} // while
			br.close();
		} catch (IOException e) {
			System.err.println(e);
		} catch (Exception e) {
			System.err.println(e);
		}
		// PUNTO 2
		try {
			BufferedReader br = new BufferedReader(new FileReader("letture.txt"));
			String line = br.readLine();
			while (line != null) {
				StringTokenizer tokenizer = new StringTokenizer(line);
				int id = Integer.parseInt(tokenizer.nextToken());
				double vol = Double.parseDouble(tokenizer.nextToken());
				Cliente c = id_to_cl.get(id);
				c.aggiungiLettura(vol);
				if (vol > max) {
					max_cl = c.getNome();
					max = vol;
				}
				line = br.readLine();
			} // while
			br.close();
		} catch (IOException e) {
			System.err.println(e);
		} catch (Exception e) {
			System.err.println(e);
		}
		// punto 3
		System.out.println("ID\tTipo\tNome/Cognome\tRagioneSociale\tIndirizzo\tTipoContratto\tPortataMassima");
		for (Cliente c : clienti)
			System.out.println(c);

		System.out.println();

		// punto 4
		System.out.println("ID\tNome/Cognome/RagioneSociale\tTotale");
		for (Cliente c : clienti) {
			double bolletta;
			if (c.getConcordato())
				bolletta = c.getTotaleLet() * 1.15;
			else
				bolletta = c.getTotaleLet() * 1.2;

			System.out.println(c.getId() + "\t" + c.getNome() + "\t" + bolletta);
		}

		// PUNTO 5
		System.out.println("\nCliente con bolletta piu' alta: " + max_cl + "\t" + max);
	}// main
}// class
