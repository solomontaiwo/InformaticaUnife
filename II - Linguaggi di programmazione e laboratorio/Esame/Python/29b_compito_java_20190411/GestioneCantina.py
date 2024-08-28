from Impiegato import Impiegato
from Guida import Guida
from Sommelier import Sommelier
from Visitatore import Visitatore
from Servizio import Servizio

import sys


class GestioneCantina:

    def main():

        impiegati = []
        visitatori = []
        cod_to_impiegato = {}

        try:
            f = open("impiegati.txt", "r")
            line = f.readline().strip()

            while line != "":
                tok = line.split()
                codice = int(tok[0])
                tipo = tok[1]

                nome = f.readline().strip()

                line = f.readline().strip()
                tok = line.split()
                telefono_ore = int(tok[0])

                if tipo == "guida":
                    inglese = bool(tok[1])
                    app_settimanali = int(tok[2])
                    costo = float(tok[3])

                    g = Guida(codice, tipo, nome, telefono_ore, inglese, app_settimanali, costo)
                    impiegati.append(g)
                    cod_to_impiegato[codice] = g

                else:
                    costo = float(tok[1])
                    specialita = f.readline().strip()

                    s = Sommelier(codice, tipo, nome, telefono_ore, costo, specialita)
                    impiegati.append(s)
                    cod_to_impiegato[codice] = s

                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        try:
            f = open("visitatori.txt", "r")
            line = f.readline().strip()

            while line != "":
                codice_visitatore = int(line)
                nome_visitatore = f.readline().strip()

                vis = Visitatore(codice_visitatore, nome_visitatore)
                visitatori.append(vis)

                line = f.readline().strip()

                while line != "":
                    tok = line.split()
                    codice_impiegato = int(tok[0])
                    ore_servizio = float(tok[1])

                    dip = cod_to_impiegato[codice_impiegato]

                    ser = Servizio(codice_impiegato, ore_servizio, dip.get_nome(), dip.get_costo())
                    vis.add_servizio(ser)
                    dip.incrementa_numero_servizi_svolti()

                    line = f.readline().strip()

                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        print("nome, codice, tipo, ore settimanali, specialità, telefono, inglese, app.sett., costo orario")

        for i in impiegati:
            print(i)
        print()

        for v in visitatori:
            print(v)
        print()

        try:
            codice_inserito = int(sys.argv[1])

            for i in impiegati:
                if codice_inserito == i.get_codice():
                    print("Numero di servizi svolti da " + i.get_nome() + ": " + str(i.get_numero_servizi()))

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)


if __name__ == "__main__":
    GestioneCantina.main()
