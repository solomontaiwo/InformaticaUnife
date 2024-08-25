from Veicolo import Veicolo
from Furgone import Furgone
from Auto import Auto
from Cliente import Cliente
from Noleggio import Noleggio


import sys


class GestioneAutonoleggio:
    def main():

        veicoli = []
        clienti = []
        cod_to_veicolo = {}

        try:
            f = open("veicoli.txt", "r")
            line = f.readline().strip()

            while line != "":
                tok = line.split()
                codice = int(tok[0])
                tipo = tok[1]
                targa = tok[2]
                modello = f.readline().strip()
                marca = f.readline().strip()
                line = f.readline().strip()
                tok = line.split()

                if tipo == "auto":
                    bagagliaio = float(tok[0])
                    cilindrata = int(tok[1])
                    categoria = f.readline().strip()
                    costo_giornaliero = f.readline().strip()

                    au = Auto(codice, tipo, targa, modello, marca,
                              bagagliaio, cilindrata, categoria, costo_giornaliero)
                    veicoli.append(au)
                    cod_to_veicolo[codice] = au

                else:
                    rimorchio = tok[0]
                    posti = int(tok[1])
                    vano = tok[2]
                    costo_giornaliero = f.readline().strip()

                    fur = Furgone(codice, tipo, targa, modello, marca,
                                  rimorchio, posti, vano, costo_giornaliero)
                    veicoli.append(fur)
                    cod_to_veicolo[codice] = fur

                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        print("tipo, targa, codice, modello, marca, costo giornaliero, bagagliaio, cilindrata, categoria, rimorchio, numero di posti, vano di carico")

        for v in veicoli:
            print(v)
        print()

        try:
            f = open("clienti.txt", "r")
            line = f.readline().strip()

            while line != "":
                nome_cognome = line
                cl = Cliente(nome_cognome)
                clienti.append(cl)

                line = f.readline().strip()

                while line != "":
                    tok = line.split()
                    codice_veicolo = int(tok[0])
                    giorni = int(tok[1])

                    nol = Noleggio(codice_veicolo, giorni)
                    cl.add_noleggio(nol)
                    costo_noleggio = cod_to_veicolo[codice_veicolo].get_costo(
                    ) * giorni
                    cl.confronta_costo(float(costo_noleggio))
                    cod_to_veicolo[codice_veicolo].incrementa_numero_noleggi()

                    line = f.readline().strip()

                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        for c in clienti:
            print(c)
        print()

        try:
            targa_veicolo_letto = input("Inserisci la targa del veicolo desiderato: ")
            targa_in_maiuscolo = targa_veicolo_letto.upper()

            for ve in veicoli:
                if targa_in_maiuscolo == ve.get_targa():
                    print("Il numero di noleggi effettuati da questo veicolo è pari a " + str(ve.get_numero_noleggi()) + ".")
                
        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

if __name__ == "__main__":
    GestioneAutonoleggio.main()
