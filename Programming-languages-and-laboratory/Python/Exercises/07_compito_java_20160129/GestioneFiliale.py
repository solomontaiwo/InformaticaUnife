from Cliente import Cliente
from Privato import Privato
from Azienda import Azienda


class GestioneFiliale:

    def main():

        clienti = []

        try:
            f = open("clienti.txt", "r")
            line = f.readline().strip()

            while line != "":
                tok = line.split()
                tipo = tok[0]
                codice = int(tok[1])
                indirizzo = f.readline().strip()
                line = f.readline().strip()
                tok = line.split()
                giorno = int(tok[0])
                mese = int(tok[1])
                anno = int(tok[2])
                nome_ragione_sociale = f.readline().strip()

                if tipo == "privato":
                    priv = Privato(tipo, codice, indirizzo, giorno, mese,
                                   anno, nome_ragione_sociale)
                    clienti.append(priv)

                    line = f.readline().strip()
                    while line != "":
                        premio = int(line)
                        priv.add_premio(premio)
                        line = f.readline().strip()

                else:
                    fatturato = int(f.readline().strip())
                    az = Azienda(tipo, codice, indirizzo, giorno, mese, anno,
                                 nome_ragione_sociale, fatturato)
                    clienti.append(az)

                    line = f.readline().strip()
                    while line != "":
                        premio = int(line)
                        az.add_premio(premio)
                        line = f.readline().strip()

                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        print("Tipo Codice Nome RagioneSociale Indirizzo Data Fatturato")
        for c in clienti:
            print(c)
        print()

        for cl in clienti:
            print("Premio pagato da " + cl.get_nome() +
                  ": "+str(cl.get_premio()))
        print()

        premio_max = 0
        nome_premio_max = ""
        for cli in clienti:
            if cli.get_premio() > premio_max:
                premio_max = cli.get_premio()
                nome_premio_max = cli.get_nome()
        print("Il cliente con il premio massimo di " +
              str(premio_max) + " è " + nome_premio_max)


if __name__ == "__main__":
    GestioneFiliale.main()
