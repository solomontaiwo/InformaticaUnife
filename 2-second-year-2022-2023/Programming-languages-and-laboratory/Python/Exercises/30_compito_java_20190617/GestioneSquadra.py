from Squadra import Squadra
from Pallacanestro import Pallacanestro
from Pallamano import Pallamano
from Giocatore import Giocatore


class GestioneSquadra:
    def main():

        squadre = []
        giocatori = []
        cod_to_squadra = {}

        # Punto 1, memorizzazione squadre e giocatori

        try:
            f = open("squadre.txt", "r")
            line = f.readline().strip()

            while line != "":
                tok = line.split()
                codice = int(tok[0])
                sport = tok[1]
                nome_squadra = f.readline().strip()
                line = f.readline().strip()
                tok = line.split()
                vinte = int(tok[0])
                perse = int(tok[1])
                falli_goal = float(tok[2])
                if sport == "pallacanestro":
                    punti = int(tok[3])
                    canestro = Pallacanestro(
                        codice, sport, nome_squadra, vinte, perse, falli_goal, punti)
                    squadre.append(canestro)
                    line = f.readline().strip()
                    cod_to_squadra[codice] = canestro
                else:
                    mano = Pallamano(codice, sport, nome_squadra,
                                     vinte, perse, falli_goal)
                    squadre.append(mano)
                    line = f.readline().strip()
                    cod_to_squadra[codice] = mano
                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        try:
            f = open("giocatori.txt", "r")
            line = f.readline().strip()

            while line != "":
                codice = int(line)
                cognome = f.readline().strip()
                nome = f.readline().strip()
                line = f.readline().strip()
                tok = line.split()
                titolare = bool(tok[0])
                eta = int(tok[1])
                numero_maglia = int(tok[2])
                ruolo = tok[3]
                gioc = Giocatore(codice, cognome, nome,
                                 titolare, eta, numero_maglia, ruolo)
                giocatori.append(gioc)
                line = f.readline().strip()
                cod_to_squadra[codice].add_giocatore(gioc)

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        # Punto 2, stampa squadre

        print("nome della squadra, codice, n. partite vinte, n. partite perse, punti totali, n. medio di falli, n. medio di reti, sport")

        for s in squadre:
            print(s)
        print()

        # Punto 3, stampa giocatori

        print("nome, cognome, età, numero di maglia, ruolo, nome squadra")

        for g in giocatori:
            print(str(g) + "\t" + str(cod_to_squadra[g.get_codice_squadra()].get_nome()))
        print()
            

        # Punto 4, stampa numero giocatori per ogni squadra

        for sq in squadre:
            print(sq.get_nome() + " " + str(len(sq.get_giocatori())))
        print()


if __name__ == "__main__":
    GestioneSquadra.main()
