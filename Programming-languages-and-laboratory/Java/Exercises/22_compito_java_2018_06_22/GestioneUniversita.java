import java.util.*;
import java.io.*;

public class GestioneUniversita {
	static List<Corso> corsi = new LinkedList<Corso>();
	static List<Studente> studenti = new LinkedList<Studente>();
	static Map<Integer, String> nomeCorsi = new HashMap<Integer, String>();

	public static void main(String[] args) {

		// punto 1, memorizzazione corsi

		try {
			BufferedReader br = new BufferedReader(new FileReader("corsi.txt"));
			String line = br.readLine();

			while (line != null) {
				StringTokenizer tok = new StringTokenizer(line);
				int codiceCorso = Integer.parseInt(tok.nextToken());
				String tipoCorso = tok.nextToken();

				String nomeCorso = br.readLine();

				String nomeCognomeDocente = br.readLine();

				line = br.readLine();

				if (tipoCorso.equals("teoria")) {

					tok = new StringTokenizer(line);
					int codiceAula = Integer.parseInt(tok.nextToken());
					int oreSettimanali = Integer.parseInt(tok.nextToken());
					double oreLezione = Double.parseDouble(tok.nextToken());

					Corso c = new Teoria(codiceCorso, tipoCorso, nomeCorso, nomeCognomeDocente, codiceAula,
							oreSettimanali, oreLezione);
					corsi.add(c);

					line = br.readLine();

				} else {

					String nomeLaboratorio = line;
					String nomeAssistente = br.readLine();
					int numeroPostazioniLaboratorio = Integer.parseInt(br.readLine());

					Corso c = new Laboratorio(codiceCorso, tipoCorso, nomeCorso, nomeCognomeDocente, nomeLaboratorio,
							nomeAssistente, numeroPostazioniLaboratorio);
					corsi.add(c);

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

		// punto 2, memorizzazione studenti

		try {
			BufferedReader br = new BufferedReader(new FileReader("studenti.txt"));
			String line = br.readLine();

			while (line != null) {
				int matricolaStudente = Integer.parseInt(line);
				String nomeCognomeStudente = br.readLine();

				Studente s = new Studente(matricolaStudente, nomeCognomeStudente);
				studenti.add(s);

				line = br.readLine();

				while (line != null && !line.isEmpty()) {
					StringTokenizer tok = new StringTokenizer(line);
					int codiceCorso = Integer.parseInt(tok.nextToken());
					String voto = tok.nextToken();

					Libretto l = new Libretto(codiceCorso, voto);
					s.corsiLibretto.add(l);

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
		// punto 3, stampa elenco di tutti i corsi

		System.out.println("nome\tcodice\tdocente\ttipo\taula\tore sett.\tore/lez.\tlab.\tassistente\tpostazioni");

		for (Corso c : corsi) {
			System.out.println(c);
		}

		System.out.println("");

		// punto 4, stampa elenco tutti studenti con nome, media esami e libretto

		for (Studente s : studenti)
			System.out.println(s);
	}
}
