from Appello import Appello
from Scritto import Scritto
from Orale import Orale
from Docente import Docente


class GestioneAppelli:

    def main():

        appelli = []
        docenti = []

        try:
            f = open("appelli.txt", "r")
            line = f.readline().strip()

            while line != "":
                tok = line.split()
                tipo = tok[0]
                codice = int(tok[1])

                docente = f.readline().strip()
                doc = Docente(docente)

                corso = f.readline().strip()
                line = f.readline().strip()
                tok = line.split()
                giorno = int(tok[0])
                mese = int(tok[1])
                anno = int(tok[2])
                ora = int(f.readline().strip())

                trovato = 0
                for d in docenti:
                    if docente == d.get_nome_docente():
                        d.incrementa_numero_appelli()
                        trovato = 1

                if trovato == 0:
                    docenti.append(doc)

                if tipo == "scritto":
                    aula = f.readline().strip()
                    durata = int(f.readline().strip())

                    scr = Scritto(tipo, codice, docente, corso, giorno, mese, anno, ora, aula, durata)
                    appelli.append(scr)

                    line = f.readline().strip()
                else:
                    max_studenti = int(f.readline().strip())

                    oral = Orale(tipo, codice, docente, corso, giorno, mese, anno, ora, max_studenti)
                    appelli.append(oral)

                    line = f.readline().strip()

                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        print("Tipo\tCodice\tProfessore\tCorso\tData\tOra\tAula\tDurata\tStudentiMax")
        for a in appelli:
            print(a)
        print()

        for docent in docenti:
            print(docent)
        print()

        ora_max = 0
        for ap in appelli:
            if ap.get_ora_inizio() > ora_max:
                ora_max = ap.get_ora_inizio()
        print("Ora di inizio massima degli appelli: " + str(ora_max))


if __name__ == "__main__":
    GestioneAppelli.main()
