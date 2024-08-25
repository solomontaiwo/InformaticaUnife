import java.util.*;
import java.io.*;

public class GestionePalestra {
	static List<Dipendente> dipendenti = new LinkedList<Dipendente>();
	static List<Cliente> clienti = new LinkedList<Cliente>();
	static Map<Integer, Dipendente> codice_to_dipendente = new HashMap<Integer, Dipendente>();

	public static void main(String[] args) {

		// Punto 1, memorizzazione dipendenti

		try {
			BufferedReader br = new BufferedReader(new FileReader("dipendenti.txt"));
			String line = br.readLine();

			while (line != null) {
				StringTokenizer tok = new StringTokenizer(line);
				int codice = Integer.parseInt(tok.nextToken());
				String tipo = tok.nextToken();
				String nomeDipendente = br.readLine();

				if (tipo.equals("trainer")) {
					boolean laurea = Boolean.parseBoolean(br.readLine());
					String specialita = br.readLine();
					line = br.readLine();
					tok = new StringTokenizer(line);
					float oreSettimanali = Float.parseFloat(tok.nextToken());
					float costoOrario = Float.parseFloat(tok.nextToken());
					Trainer t = new Trainer(codice, tipo, nomeDipendente, laurea, specialita, oreSettimanali,
							costoOrario);
					dipendenti.add(t);
					codice_to_dipendente.put(codice, t);
				} else {
					line = br.readLine();
					tok = new StringTokenizer(line);
					float costoOrario = Float.parseFloat(tok.nextToken());
					int telefono = Integer.parseInt(tok.nextToken());
					boolean medico = Boolean.parseBoolean(tok.nextToken());
					int appuntamentiSettimanali = Integer.parseInt(tok.nextToken());
					Nutrizionista n = new Nutrizionista(codice, tipo, nomeDipendente, costoOrario, telefono, medico,
							appuntamentiSettimanali);
					dipendenti.add(n);
					codice_to_dipendente.put(codice, n);
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
				int codiceCliente = Integer.parseInt(line);
				String nomeCliente = br.readLine();

				Cliente c = new Cliente(codiceCliente, nomeCliente);
				clienti.add(c);

				line = br.readLine();
				StringTokenizer tok = new StringTokenizer(line);

				while (line != null && tok.hasMoreTokens()) {
					int codiceDipendente = Integer.parseInt(tok.nextToken());
					float oreServizio = Float.parseFloat(tok.nextToken());

					Dipendente dip = codice_to_dipendente.get(codiceDipendente);

					Servizio s = new Servizio(dip, oreServizio);
					c.addServizio(s);
					dip.incrementaNumeroServiziSvolti();		

				}

				line = br.readLine();
			}

			br.close();

		} catch (IOException e) {
			System.err.println(e);
		} catch (Exception e) {
			System.err.println(e);
		}

		// Punto 3, stampa elenco di tutti i dipendenti

		System.out.println(
				"Tipo, nome, codice, laurea, specialità, ore settimanali, telefono, medico, app.sett., costo orario");

		for (Dipendente d : dipendenti)
			System.out.println(d);

		System.out.println(); // spazio

		// Punto 4, stampa elenco clienti con dipendente che ha fornito il servizio più
		// lungo ed elenco servizi utilizzato

		System.out.println("codice, nome, dipendente, servizi");
		for (Cliente c : clienti)
			System.out.println(c);

		System.out.println();

		// Punto 5, legge da riga di comando il codice di un dipendente e ne stampa il
		// numero di servizi svolti

		try {
			int codiceInserito = Integer.parseInt(args[0]);

			for (Dipendente d : dipendenti) {
				if (d.codice == codiceInserito)
					System.out.println("Servizi fatti dal dipendente " + codiceInserito + ": " + d.numeroServiziSvolti);
			}
		} catch (Exception e) {
			System.err.println(e);
		}
	}
}