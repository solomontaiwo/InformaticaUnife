import java.io.*;
import java.util.*;

public class GestionePalestra {

	static List<Dipendente> dipendenti = new LinkedList<Dipendente>();
	static List<Cliente> clienti = new LinkedList<Cliente>();
	static Map<Integer, Dipendente> codDip = new HashMap<Integer, Dipendente>();
	static Map<Integer, Integer> codNServ = new HashMap<Integer, Integer>();

	public static void main(String[] args) {

		// PUNTO 1: memorizzazione progetti
		try {
			BufferedReader br = new BufferedReader(new FileReader("dipendenti.txt"));
			String line = br.readLine();
			while (line != null) {
				StringTokenizer tok = new StringTokenizer(line);
				int cod = Integer.parseInt(tok.nextToken());
				String tipo = tok.nextToken();
				String nome = br.readLine();
				line = br.readLine();
				if (tipo.equals("trainer")) {
					tok = new StringTokenizer(line);
					int ore = Integer.parseInt(tok.nextToken());
					double costo = Double.parseDouble(tok.nextToken());
					line = br.readLine();
					String spec = line;
					Dipendente d = new Trainer(cod, nome, ore, spec, costo);
					dipendenti.add(d);
					codDip.put(cod, d);
					codNServ.put(cod, 0);
				} else {
					tok = new StringTokenizer(line);
					int tel = Integer.parseInt(tok.nextToken());
					boolean medico = Boolean.parseBoolean(tok.nextToken());
					int app = Integer.parseInt(tok.nextToken());
					double costo = Double.parseDouble(tok.nextToken());
					Dipendente d = new Nutri(cod, nome, tel, medico, app, costo);
					dipendenti.add(d);
					codDip.put(cod, d);
					codNServ.put(cod, 0);
				}
				line = br.readLine();
			}
			br.close();
		} catch (IOException e) {
			System.err.println(e);
		} catch (Exception e) {
			System.err.println(e);
		}
		// PUNTO 2: lettura di tutti i clienti

		try {
			BufferedReader br = new BufferedReader(new FileReader("clienti.txt"));
			String line = br.readLine();
			while (line != null) {
				int codcli = Integer.parseInt(line);
				String nomeCog = br.readLine();
				Cliente c = new Cliente(codcli, nomeCog);
				clienti.add(c);
				line = br.readLine();
				while (line != null && !line.equals("")) {
					StringTokenizer tok = new StringTokenizer(line);
					int cod = Integer.parseInt(tok.nextToken());
					double ore = Double.parseDouble(tok.nextToken());
					Dipendente dip = codDip.get(cod);
					c.addServizio(dip, ore);
					int current = codNServ.get(cod);
					codNServ.put(cod, current + 1);
					line = br.readLine();
				}
				line = br.readLine();
			}
			br.close();
		} catch (IOException e) {
			System.err.println(e);
		}

		// PUNTO 3: stampa di tutti i dipendenti
		System.out
				.println("nome, codice, tipo, ore settimanali, specialità, telefono, medico, app.sett., costo orario");
		for (Dipendente d : dipendenti)
			System.out.println(d);
		System.out.println();
		// //PUNTO 4: stampa clienti
		for (Cliente c : clienti)
			System.out.println(c);

		// PUNTO 5: stampe del dipendente che ha fatto più servizi
		System.out.println();
		int max = -1;
		String nome = null;
		for (Dipendente d : dipendenti) {
			int count = codNServ.get(d.getCod());
			if (count > max) {
				max = count;
				nome = d.getNome();
			}
		}
		System.out.println(nome + " " + max);

	}
}