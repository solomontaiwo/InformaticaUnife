import java.util.*;
import java.io.*;

public class GestioneCampo {

	static List<Campo> campi = new LinkedList<Campo>();
	static List<Socio> soci = new LinkedList<Socio>();
	static Map<Integer, Campo> codCampo = new HashMap<Integer, Campo>();

	public static void main(String[] args) {

		// punto 1, memorizzazione campi

		try {
			BufferedReader br = new BufferedReader(new FileReader("campi.txt"));
			String line = br.readLine();

			while (line != null) {
				StringTokenizer tok = new StringTokenizer(line);
				int codice = Integer.parseInt(tok.nextToken());
				String sport = tok.nextToken();
				String nomeCampo = br.readLine();
				line = br.readLine();
				tok = new StringTokenizer(line);
				Float larghezza = Float.parseFloat(tok.nextToken());
				Float lunghezza = Float.parseFloat(tok.nextToken());

				if (sport.equals("tennis")) {
					float temperaturaMedia = Float.parseFloat(tok.nextToken());
					String terreno = br.readLine();
					float costoOrario = Float.parseFloat(br.readLine());
					Campo c = new Tennis(codice, sport, nomeCampo, larghezza, lunghezza, temperaturaMedia, terreno,
							costoOrario);
					campi.add(c);
					codCampo.put(codice, c);

				} else {
					float altezza = Float.parseFloat(tok.nextToken());
					int piano = Integer.parseInt(tok.nextToken());
					float costo = Float.parseFloat(tok.nextToken());
					Campo c = new Squash(codice, sport, nomeCampo, larghezza, lunghezza, altezza, piano, costo);
					campi.add(c);
					codCampo.put(codice, c);

				}
				line = br.readLine();

			}

			br.close();

		} catch (IOException e) {
			System.err.println(e);
		} catch (Exception e) {
			System.err.println(e);
		}

		// punto 2, memorizzazione soci

		try {
			BufferedReader br = new BufferedReader(new FileReader("soci.txt"));
			String line = br.readLine();

			while (line != null) {
				int codice = Integer.parseInt(line);
				String nome = br.readLine();
				line = br.readLine();
				StringTokenizer tok = new StringTokenizer(line);
				int eta = Integer.parseInt(tok.nextToken());
				int categoria = Integer.parseInt(tok.nextToken());
				line = br.readLine();
				tok = new StringTokenizer(line);

				Socio s = new Socio(codice, nome, eta, categoria);
				soci.add(s);

				while (tok.hasMoreElements()) {
					int codiceCampo = Integer.parseInt(tok.nextToken());
					int oraInizio = Integer.parseInt(tok.nextToken());
					Prenotazione p = new Prenotazione(codiceCampo, oraInizio);
					s.addPrenotazione(p);
					codCampo.get(codiceCampo).addPrenotazione();
				}

				line = br.readLine();

			}

			br.close();

		} catch (IOException e) {
			System.err.println(e);
		} catch (Exception e) {
			System.err.println(e);
		}

		// punto 3, stampa tutti i campi del circolo
		System.out.println(
				"sport\tnome del campo\tcodice\tlarghezza\tlunghezza\ttemperatura\tterreno\taltezza\tpiano\tcosto");

		for (Campo c : campi) {
			System.out.println(c);
		}

		// punto 4, stampa elenco dei soci
		System.out.println("codice\tnome e cognome\teta\tcategoria\tprenotazioni");

		for (Socio s : soci) {
			System.out.println(s);
		}

		int cod = Integer.parseInt(args[0]);
		System.out.println(codCampo.get(cod).incasso());
	}
}