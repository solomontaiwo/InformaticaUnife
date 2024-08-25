from Squadra import Squadra
from Hockey import Hockey
from Pallamano import Pallamano
from Giocatore import Giocatore


class GestioneSquadrePolisportiva:

    def main():

        squadre = []
        giocatori = []
        cod_to_squadra = {}
        hockey_vinte = 0
        pallamano_vinte = 0

        try:
            f = open("squadre.txt", "r")
            line = f.readline().strip()

            while line != "":
                tok = line.split()
                codice = int(tok[0])
                sport = tok[1]
                
                nome = f.readline().strip()
                line = f.readline().strip()
                
                tok = line.split()
                vinte = int(tok[0])
                perse = int(tok[1])
                goal = float(tok[2])

                if sport == "hockey":
                    falli = float(tok[3])
                    hoc = Hockey(codice, sport, nome, vinte, perse, goal, falli)
                    squadre.append(hoc)
                    cod_to_squadra[codice] = hoc
                    line = f.readline().strip()
                    hockey_vinte += vinte

                else:
                    mano = Pallamano(codice, sport, nome, vinte, perse, goal)
                    squadre.append(mano)
                    cod_to_squadra[codice] = mano 
                    line = f.readline().strip()
                    pallamano_vinte += vinte

                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        try:
            f = open("giocatori.txt", "r")
            line = f.readline().strip()

            while line != "":
                codice_squadra = int(line)
                cognome = f.readline().strip()
                nome = f.readline().strip()
                
                line = f.readline().strip()
                tok = line.split()
                eta = int(tok[0])
                maglia = int(tok[1])
                ruolo = tok[2]
                titolare = bool(tok[3])
                gioc = Giocatore(codice_squadra, cognome, nome, eta, maglia, ruolo, titolare)
                giocatori.append(gioc)
                
                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        print("nome della squadra, codice, n. partite vinte, n. partite perse, n. medio di gol, n. medio di falli, n. medio di reti, sport")

        for s in squadre:
            print(s)
        print("")

        print("nome, cognome, età, numero di maglia, ruolo, titolare, nome squadra")

        for g in giocatori:
            print(str(g) + "\t" + cod_to_squadra[g.get_codice()].get_nome_squadra())
        print("")

        print("Media partite vinte dalle squadre di hockey: " + str(hockey_vinte / 2))
        print("Media partite vinte dalle squadre di pallamano: " + str(pallamano_vinte / 2))


if __name__ == "__main__":
    GestioneSquadrePolisportiva.main()
