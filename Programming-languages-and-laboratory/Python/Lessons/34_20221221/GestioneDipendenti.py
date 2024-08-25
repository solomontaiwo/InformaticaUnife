from Trainer import Trainer
from Nutrizionista import Nutrizionista
from Cliente import Cliente
from Servizio import Servizio
from Dipendente import Dipendente


class GestioneDipendenti:

    def main(self):

        dipendenti = []
        clienti = []
        codice_to_dipendente = {}

        try:
            f = open("dipendenti.txt", "r")
            line = f.readline().strip()

            while line != "":
                tok = line.split()
                codice = int(tok[0])
                tipo = tok[1]
                nome = f.readline().strip()
                line = f.readline().strip()
                tok = line.split()

                if tipo == "trainer":
                    ore_settimanali = int(tok[0])
                    costo_orario = float(tok[1])
                    specialita = f.readline().strip()

                    tr = Trainer(codice, tipo, nome, ore_settimanali, costo_orario, specialita)
                    dipendenti.append(tr)
                    codice_to_dipendente[codice] = tr
                else:
                    telefono = int(tok[0])
                    medico = tok[1]
                    appuntamenti_settimanali = int(tok[2])
                    costo_orario = float(tok[3])

                    nut = Nutrizionista(codice, tipo, nome, telefono, medico, appuntamenti_settimanali, costo_orario)
                    dipendenti.append(nut)
                    codice_to_dipendente[codice] = nut

                line = f.readline().strip()

            f.close()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        print("nome, codice, tipo, ore settimanali, specialità, telefono, medico, app.sett., costo orario")

        for d in dipendenti:
            print(d)
        print("")

        try:
            f = open("clienti.txt", "r")
            line = f.readline().strip()

            while line != "":

                codice_cliente = int(line)
                nome_cliente = f.readline().strip()
                cl = Cliente(codice_cliente, nome_cliente)
                clienti.append(cl)

                line = f.readline().strip()

                while line != "":
                    tok = line.split()
                    codice_dipendente = int(tok[0])
                    ore_servizio = float(tok[1])
                    ser = Servizio(codice_dipendente, ore_servizio)
                    cl.add_servizio(ser)
                    dip = codice_to_dipendente[codice_dipendente]
                    cl.add_costo(dip.get_costo(), ore_servizio)
                    line = f.readline().strip()
                    dip.add_servizio()

                line = f.readline().strip()

            f.close()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        for c in clienti:
            print(c)
        print("")

        numero_max_servizi = 0
        cod_dipendente_max_servizi = 0

        for d in dipendenti:
             if d.get_numero_servizi() > numero_max_servizi:
                cod_dipendente_max_servizi = d.get_codice()
                numero_max_servizi = d.get_numero_servizi()

        print(codice_to_dipendente[cod_dipendente_max_servizi].get_nome() + " " + str(numero_max_servizi))


if __name__ == "__main__":
    GestioneDipendenti.main(__name__)
