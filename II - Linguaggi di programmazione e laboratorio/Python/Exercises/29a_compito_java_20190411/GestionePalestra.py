from Dipendente import Dipendente
from Trainer import Trainer
from Nutrizionista import Nutrizionista
from Cliente import Cliente
from Servizio import Servizio


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
                nome = f.readline().strip()

                line = f.readline().strip()
                tok = line.split()
                telefono_ore = int(tok[0])

                if tipo == "trainer":
                    costo = float(tok[1])
                    specialita = f.readline().strip()

                    tr = Trainer(codice, tipo, nome, telefono_ore, costo, specialita)
                    dipendenti.append(tr)
                    cod_to_dip[codice] = tr
                else:
                    medico = bool(tok[1])
                    app_settimanali = int(tok[2])
                    costo = float(tok[3])

                    nut = Nutrizionista(codice, tipo, nome, telefono_ore, medico, app_settimanali, costo)
                    dipendenti.append(nut)
                    cod_to_dip[codice] = nut

                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

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
                    d = cod_to_dip[codice_dipendente]
                    d.incrementa_numero_servizi()
                    serv = Servizio(codice_dipendente, ore_servizio)
                    cl.add_servizio(serv, (d.get_costo() * ore_servizio))

                    line = f.readline().strip()

                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        print("nome, codice, tipo, ore settimanali, specialità, telefono, medico, app.sett., costo orario")

        for d in dipendenti:
            print(d)
        print("")

        for c in clienti:
            print(c)
        print("")

        numero_servizi = 0
        dip_max_servizi = "boh"
        for dip in dipendenti:
            if dip.get_numero_servizi() > numero_servizi:
                dip_max_servizi = dip.get_nome()
                numero_servizi = dip.get_numero_servizi()

        print(dip_max_servizi + " " + str(numero_servizi))


if __name__ == "__main__":
    GestionePalestra.main()
