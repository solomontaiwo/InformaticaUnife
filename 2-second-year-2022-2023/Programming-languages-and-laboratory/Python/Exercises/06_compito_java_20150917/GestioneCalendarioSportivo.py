from Partita import Partita
from InCasa import InCasa
from FuoriCasa import FuoriCasa


import sys


class GestioneCalendarioSportivo:

    def main():

        partite = []
        partite_in_casa = 0
        partite_vinte_in_casa = 0
        partite_fuori_casa = 0
        partite_vinte_fuori_casa = 0

        try:
            f = open("partite.txt", "r")
            line = f.readline().strip()

            while line != "":
                tok = line.split()
                tipo = tok[0]
                nome_palazzetto_citta = tok[1]
                data = tok[2]
                ora = tok[3]
                risultato = tok[4]
                vinta = int(tok[5])

                if tipo == "c":
                    casa = InCasa(tipo, nome_palazzetto_citta,
                                  data, ora, risultato, vinta)
                    partite.append(casa)
                    partite_in_casa += 1

                    if vinta == 1:
                        partite_vinte_in_casa += 1

                else:
                    fuori = FuoriCasa(tipo, nome_palazzetto_citta,
                                      data, ora, risultato, vinta)
                    partite.append(fuori)
                    partite_fuori_casa += 1

                    if vinta == 1:
                        partite_vinte_fuori_casa += 1

                line = f.readline().strip()

        except IOError as i:
            print(e)
        except Exception as e:
            print(e)

        print("Palazzetto Città Data Ora Risultato")
        for p in partite:
            print(p)
        print()

        print("Partite in casa: " + str(partite_in_casa) +
              ", vinte: " + str(partite_vinte_in_casa))
        print("Partite fuori casa: " + str(partite_fuori_casa) +
              ", vinte: " + str(partite_vinte_fuori_casa) + "\n")

        try:

            citta_riga_di_comando = sys.argv[1]
            partita_trovata = 0

            for par in partite:
                if par.get_tipo() == "f":
                    if par.get_citta() == citta_riga_di_comando:
                        print(par.stampa_partita_trovata())
                        partita_trovata = 1

            if partita_trovata == 0:
                print(citta_riga_di_comando + ": " +
                      "Partita non ancora giocata")

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)


if __name__ == "__main__":
    GestioneCalendarioSportivo.main()
