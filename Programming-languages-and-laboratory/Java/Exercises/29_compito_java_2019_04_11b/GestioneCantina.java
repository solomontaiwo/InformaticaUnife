import java.io.*;
import java.util.*;

public class GestioneCantina {

	static List<Impiegato> impiegati = new LinkedList<Impiegato>();
	static List<Visitatore> visitatori = new LinkedList<Visitatore>();
	static Map<Integer, Impiegato> codImp = new HashMap<Integer, Impiegato>();
	static Map<Integer, Integer> codNServ = new HashMap<Integer, Integer>();

	public static void main(String[] args) {

		// PUNTO 1: memorizzazione progetti
		try {
			BufferedReader br = new BufferedReader(new FileReader("impiegati.txt"));
			String line = br.readLine();
			while (line != null) {
				StringTokenizer tok = new StringTokenizer(line);
				int cod = Integer.parseInt(tok.nextToken());
				String tipo = tok.nextToken();
				String nome = br.readLine();
				line = br.readLine();
				if (tipo.equals("sommelier")) {
					tok = new StringTokenizer(line);
					int ore = Integer.parseInt(tok.nextToken());
					double costo = Double.parseDouble(tok.nextToken());
					line = br.readLine();
					String spec = line;
					Impiegato d = new Sommelier(cod, nome, ore, spec, costo);
					impiegati.add(d);
					codImp.put(cod, d);
					codNServ.put(cod, 0);
				} else {
					tok = new StringTokenizer(line);
					int tel = Integer.parseInt(tok.nextToken());
					boolean medico = Boolean.parseBoolean(tok.nextToken());
					int app = Integer.parseInt(tok.nextToken());
					double costo = Double.parseDouble(tok.nextToken());
					Impiegato d = new Guida(cod, nome, tel, medico, app, costo);
					impiegati.add(d);
					codImp.put(cod, d);
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
		// PUNTO 2: lettura di tutti i visitatori

		try {
			BufferedReader br = new BufferedReader(new FileReader("visitatori.txt"));
			String line = br.readLine();
			while (line != null) {
				int codcli = Integer.parseInt(line);
				String nomeCog = br.readLine();
				Visitatore c = new Visitatore(codcli, nomeCog);
				visitatori.add(c);
				line = br.readLine();
				while (line != null && !line.equals("")) {
					StringTokenizer tok = new StringTokenizer(line);
					int cod = Integer.parseInt(tok.nextToken());
					double ore = Double.parseDouble(tok.nextToken());
					Impiegato dip = codImp.get(cod);
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

		// PUNTO 3: stampa di tutti i impiegati
		System.out
				.println("nome, codice, tipo, ore settimanali, specialità, telefono, inglese, app.sett., costo orario");
		for (Impiegato d : impiegati)
			System.out.println(d);
		System.out.println();
		// //PUNTO 4: stampa visitatori
		for (Visitatore c : visitatori)
			System.out.println(c);
		System.out.println();

		// PUNTO 5: stampe del Impiegato che ha fatto più servizi
		int cod = Integer.parseInt(args[0]);
		System.out.println(codNServ.get(cod));

	}
}
