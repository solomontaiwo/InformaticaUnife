import sys
import argparse

from Cittadino import Cittadino
from Ipermercato import Ipermercato
from Cliente import Cliente
from Visita import Visita

class Gestione:
    def __init__(self, arg):
        self._arg = arg

    def main(self):
        supermercati = []
        clienti = []


        try:
            f = open("supermercati.txt", "r")
            line = f.readline().strip()
            while(line != ''):
                tok = line.split()
                cod = int(tok[0])
                tipo = tok[1]
                indirizzo = f.readline().strip()
                line = f.readline().strip()
                tok = line.split()
                if(tipo == "cittadino"):
                    apertura = int(tok[0])
                    chiusura = int(tok[1])
                    superficie = float(tok[2])
                    addetti = int(tok[3])
                    c = Cittadino(cod, indirizzo, superficie, addetti, apertura, chiusura)
                    supermercati.append(c)
                else:
                    superficie = float(tok[0])
                    addetti = int(tok[1])
                    centro = f.readline().strip()
                    i = Ipermercato(cod, indirizzo, superficie, addetti,centro)
                    supermercati.append(i)

                line = f.readline().strip()
            f.close()
        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        try:
            f = open("clienti.txt", "r")
            line = f.readline().strip()
            while(line != ''):
                cognome = line
                nome = f.readline().strip()
                c = Cliente(cognome, nome)
                clienti.append(c)
                line = f.readline()
                while(line != "\n" and line !=''):
                    tok = line.split()
                    cod = int(tok[0])
                    spesa = float(tok[1])
                    visita = Visita(cod, spesa)
                    c.addVisita(visita)
                    line = f.readline()
                line = f.readline().strip()
            f.close()
        except IOError as i:
            print(i)

        print("codice, tipo, indirizzo, apertura, chiusura, superficie, n. addetti, centro commerciale")

        for s in supermercati:
            print(s.toString())

        print("\n")

        for c in clienti:
            print(c.toString())

        print("\n")

        try:
            cod = int(self._arg)
            tot = 0.0
            n_visite =0
            for c in clienti:
                visite = c.getVisite()
                for v in visite:
                    if (cod ==v.getCodice()):
                        n_visite = n_visite +1 
                        tot = tot + v.getSpesa()
            spesa_media = tot/n_visite
            print(str(cod)+ "\t"+ str(spesa_media))

        except IOError as i:
            print(i)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('supermercato', action='store')
    pa = parser.parse_args()
    g = Gestione(pa.supermercato)
    g.main()
