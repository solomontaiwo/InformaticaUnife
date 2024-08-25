from Progetto import Progetto
from Partecipazione import Partecipazione
from Ricerca import Ricerca
from Innovazione import Innovazione
from RIcercatore import Ricercatore

import sys


class GestioneProgetti:

    def main():

        progetti = []
        ricercatori = []
        cod_to_prog = {}

        try:
            f = open("progetti.txt", "r")
            line = f.readline().strip()

            while line != "":
                tok = line.split()
                codice = int(tok[0])
                tipo = tok[1]
                titolo = f.readline().strip()
                nome_coordinatore = f.readline().strip()
                organizzazione_coordinatore = f.readline().strip()

                line = f.readline().strip()
                tok = line.split()

                if tipo == "ricerca":
                    codice_argomento = tok[0]
                    partner = int(tok[1])
                    importo = float(f.readline().strip())

                    r = Ricerca(codice, tipo, titolo, nome_coordinatore, organizzazione_coordinatore, codice_argomento, partner, importo)
                    progetti.append(r)
                    cod_to_prog[codice] = r

                else:
                    aziende = int(tok[0])
                    importo = float(tok[1])

                    i = Innovazione(codice, tipo, titolo, nome_coordinatore, organizzazione_coordinatore, aziende, importo)
                    progetti.append(i)
                    cod_to_prog[codice] = i

                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        print("tipo, titolo, codice, coordinatore, organizzazione, argomento, partner, aziende, importo totale in migliaia di euro")

        for p in progetti:
            print(p)
        print()

        try:
            f = open("ricercatori.txt", "r")
            line = f.readline().strip()

            while line != "":
                nome_ricercatore = line
                cognome_ricercatore = f.readline().strip()

                ric = Ricercatore(nome_ricercatore, cognome_ricercatore)
                ricercatori.append(ric)

                line = f.readline().strip()

                while line != "":
                    tok = line.split()
                    codice_progetto = int(tok[0])
                    impegno_orario = float(tok[1])

                    part = Partecipazione(codice_progetto, impegno_orario)
                    ric.add_progetto(part)
                    ric.add_ore_impegno(impegno_orario, cod_to_prog[codice_progetto].get_nome_progetto())

                    line = f.readline().strip()

                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        for ricerc in ricercatori:
            print(ricerc)
        print()

        try:

            cognome_letto = sys.argv[1]

            for ri in ricercatori:
                if cognome_letto == ri.get_cognome():
                    print(ri.get_nome() + " " + ri.get_cognome() + " " + str(ri.get_impegno_max()) + " " + ri.get_nome_impegno_max())

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)
                

if __name__ == "__main__":
    GestioneProgetti.main()
