from Squadra import Squadra
from Basket import Basket
from Pallavolo import Pallavolo
from Giocatore import Giocatore

import sys


class GestionePolisportiva:

    def main():

        squadre = []
        cod_to_squadra = {}
        nome_squadra_to_cod = {}
        giocatori = []

        try:
            f = open("squadre.txt", "r")
            line = f.readline().strip()

            while line != "":
                nome_squadra = line
                line = f.readline().strip()
                tok = line.split()
                codice = int(tok[0])
                sport = tok[1]
                line = f.readline().strip()
                tok = line.split()
                vinte = int(tok[0])
                perse = int(tok[1])
                punteggio_medio_numero_medio_set_vinti = float(tok[2])
                line = f.readline().strip()

                nome_squadra_to_cod[nome_squadra] = codice

                if sport == "basket":
                    bas = Basket(nome_squadra, codice, sport, vinte,
                                 perse, punteggio_medio_numero_medio_set_vinti)
                    squadre.append(bas)
                    cod_to_squadra[codice] = bas
                else:
                    pall = Pallavolo(nome_squadra, codice, sport, vinte,
                                     perse, punteggio_medio_numero_medio_set_vinti)
                    squadre.append(pall)
                    cod_to_squadra[codice] = pall

                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        print("nome della squadra, codice, n. partite vinte, n. partite perse, punteggio medio, n. medio di set vinti, sport")

        for s in squadre:
            print(s)
        print()

        try:
            f = open("giocatori.txt", "r")
            line = f.readline().strip()

            while line != "":
                tok = line.split()
                codice_squadra = int(tok[0])
                cognome = tok[1]
                eta = int(tok[2])
                maglia = int(tok[3])
                ruolo = tok[4]
                titolare = bool(tok[5])
                gio = Giocatore(codice_squadra, cognome, eta,
                                maglia, ruolo, titolare)
                cod_to_squadra[codice_squadra].add_giocatore(gio)
                giocatori.append(gio)
                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        for sq in squadre:
            sq.stampa_squadra()
        print()

        try:
            nome1 = sys.argv[1]
            nome2 = sys.argv[2]
            nome_squadra_riga_di_comando = nome1 + " " + nome2
            codice_squadra_cercata = nome_squadra_to_cod[nome_squadra_riga_di_comando]

            print("cognome, età, numero di maglia, ruolo, titolare")

            for giocat in giocatori:
                if codice_squadra_cercata == giocat.get_codice():
                    print(giocat)

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)


if __name__ == "__main__":
    GestionePolisportiva.main()
