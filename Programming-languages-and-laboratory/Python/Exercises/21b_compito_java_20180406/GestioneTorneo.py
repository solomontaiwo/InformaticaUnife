from Giocatore import Giocatore
from TestaDiSerie import TestaDiSerie
from Normale import Normale
from Incontro import Incontro


class GestioneTorneo:
    def main():

        giocatori = []
        cod_to_giocatore = {}

        try:
            f = open("giocatori.txt", "r")
            line = f.readline().strip()

            while line != "":
                codice = int(line)
                tipo = f.readline().strip()
                nome_cognome = f.readline().strip()
                line = f.readline().strip()

                if tipo == "testa-di-serie":
                    tok = line.split()
                    ranking = int(tok[0])
                    eta = int(tok[1])
                    professionista = tok[2]
                    line = f.readline().strip()

                    tds = TestaDiSerie(codice, tipo, nome_cognome, ranking, eta, professionista)
                    giocatori.append(tds)
                    cod_to_giocatore[codice] = tds

                else:
                    circolo = line
                    line = f.readline().strip()
                    tok = line.split()
                    vinti = int(tok[0])
                    disputate = int(tok[1])
                    line = f.readline().strip()

                    norm = Normale(codice, tipo, nome_cognome, circolo, vinti, disputate)
                    giocatori.append(norm)
                    cod_to_giocatore[codice] = norm

                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        print("nome, codice, tipo, ranking, età, professionista, circolo, n. set vinti, n. partite")

        for g in giocatori:
            print(g)
        print()

        try:
            f = open("partite.txt", "r")
            line = f.readline().strip()

            while line != "":
                tok = line.split()
                codice_primo_giocatore = int(tok[0])
                codice_secondo_giocatore = int(tok[1])
                line = f.readline().strip()
                tok = line.split()
                set_vinti_primo_giocatore = int(tok[0])
                set_vinti_secondo_giocatore = int(tok[1])
                inc_per_primo_giocatore = Incontro(codice_primo_giocatore, codice_secondo_giocatore, set_vinti_primo_giocatore, set_vinti_secondo_giocatore)
                cod_to_giocatore[codice_primo_giocatore].add_incontro(inc_per_primo_giocatore)
                inc_per_secondo_giocatore = Incontro(codice_secondo_giocatore, codice_primo_giocatore, set_vinti_secondo_giocatore, set_vinti_primo_giocatore)
                cod_to_giocatore[codice_secondo_giocatore].add_incontro(inc_per_secondo_giocatore)

                if set_vinti_primo_giocatore > set_vinti_secondo_giocatore:
                    cod_to_giocatore[codice_primo_giocatore].add_partita_vinta()
                else:
                    cod_to_giocatore[codice_secondo_giocatore].add_partita_vinta()

                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        for gioc in giocatori:
            print(gioc.stampa_incontri())
        print()

        max_vincite = 0
        nome_giocatore_max_vincite = ""

        for gioca in giocatori:
            if gioca.get_partite_vinte() > max_vincite:
                max_vincite = gioca.get_partite_vinte()
                nome_giocatore_max_vincite = gioca.get_nome_giocatore()

        print("Il giocatore che ha vinto più partite è " + nome_giocatore_max_vincite)


if __name__ == "__main__":
    GestioneTorneo.main()
