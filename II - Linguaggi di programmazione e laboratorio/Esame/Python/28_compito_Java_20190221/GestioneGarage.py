from Veicolo import Veicolo
from Auto import Auto
from Furgone import Furgone
from Cliente import Cliente
from Posteggio import Posteggio

import sys


class GestioneGarage:

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

                line = f.readline().strip()

                if tipo == "auto":
                    tok = line.split()
                    cilindrata = int(tok[0])
                    diesel = bool(tok[1])
                    modello = f.readline().strip()
                    marca = f.readline().strip()

                    au = Auto(codice, tipo, targa, cilindrata, diesel, modello, marca)
                    veicoli.append(au)
                    cod_to_veicolo[codice] = au
                else:
                    categoria = line
                    posti = int(f.readline().strip())
                    modello = f.readline().strip()
                    marca = f.readline().strip()

                    fur = Furgone(codice, tipo, targa, categoria, posti, modello, marca)
                    veicoli.append(fur)
                    cod_to_veicolo[codice] = fur


                line = f.readline().strip()


        except IOError as i:
            print(i)
        except Exception as e:
            print(e)    

        print("tipo, targa, codice, modello, marca, cilindrata, diesel, categoria, numero di posti")

        for v in veicoli:
            print(v)
        print()

        try:
            f = open("posteggi.txt", "r")
            line = f.readline().strip()

            while line != "":
                nome_cognome = line

                cl = Cliente(nome_cognome)
                clienti.append(cl)

                line = f.readline().strip()
                i = 0
                tok = line.split()

                while i < len(tok):
                    codice_veicolo = int(tok[i])
                    giorni = int(tok[i+1])

                    veic = cod_to_veicolo[codice_veicolo]

                    pos = Posteggio(codice_veicolo, giorni)
                    cl.add_posteggi(pos)

                    cl.add_costo_totale(veic.get_costo() * giorni)
                    veic.add_costo_totale(veic.get_costo() * giorni)

                    i += 2

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

            for vei in veicoli:
                if codice_letto == vei.get_codice():
                    print(str(codice_letto) + " " + str(vei.get_costo_totale()))

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)


if __name__ == "__main__":
    GestioneGarage.main()
