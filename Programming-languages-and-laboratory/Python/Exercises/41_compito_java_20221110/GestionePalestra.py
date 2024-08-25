from Dipendente import Dipendente
from Trainer import Trainer
from Nutrizionista import Nutrizionista
from Cliente import Cliente
from Servizio import Servizio


import sys


class GestionePalestra:
    def main():

        dipendenti = []
        clienti = []
        cod_to_dip = {}

        try:
            f = open("dipendenti.txt", "r")
            line = f.readline().strip()

            while line != "":
                tok = line.split()
                codice = int(tok[0])
                tipo = tok[1]
                nome_dipendente = f.readline().strip()

                if tipo == "trainer":
                    laurea = f.readline().strip()
                    specialita = f.readline().strip()
                    line = f.readline().strip()
                    tok = line.split()
                    ore_settimanali = float(tok[0])
                    costo_orario = float(tok[1])

                    tr = Trainer(codice, tipo, nome_dipendente, laurea, specialita, ore_settimanali, costo_orario)
                    dipendenti.append(tr)
                    cod_to_dip[codice] = tr

                else:
                    line = f.readline().strip()
                    tok = line.split()
                    costo_orario = float(tok[0])
                    telefono = int(tok[1])
                    medico = bool(tok[2])
                    app_sett = int(tok[3])

                    nu = Nutrizionista(codice, tipo, nome_dipendente, costo_orario, telefono, medico, app_sett)
                    dipendenti.append(nu)
                    cod_to_dip[codice] = nu

                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        print("tipo, nome, codice, laurea, specialità, ore settimanali, telefono, medico, app.sett., costo orario")

        for d in dipendenti:
            print(d)
        print()

        try:
            f = open("clienti.txt", "r")
            line = f.readline().strip()

            while line != "":
                codice_cliente = int(line)
                nome_cliente = f.readline().strip()

                cl = Cliente(codice_cliente, nome_cliente)
                clienti.append(cl)

                line = f.readline().strip()
                tok = line.split()
                i = 0

                while i < len(tok):
                    codice_dipendente = int(tok[i])
                    ore_servizio = float(tok[i+1])
                    i += 2
                    ser = Servizio(codice_dipendente, ore_servizio)
                    cl.add_servizio(ser)
                    cl.confronta_ore_servizio(ore_servizio, codice_dipendente)
                    cod_to_dip[codice_dipendente].incrementa_servizi()

                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        for c in clienti:
            print(c)
        print()

        try:
            codice_letto = int(sys.argv[1])

            for dip in dipendenti:
                if codice_letto == dip.get_codice():
                    print("Servizi fatti dal dipendente " + str(codice_letto) + ": "  + str(dip.get_servizi_svolti()))

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)


if __name__ == "__main__":
    GestionePalestra.main()
