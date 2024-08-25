import sys
import argparse

from Campo import Campo
from Tennis import Tennis
from Squash import Squash
from Socio import Socio
from Prenotazione import Prenotazione

class Gestione:
    def __init__(self, arg):
        self._arg = arg

    def main(self):
        campi = []
        soci = []
        cod_campi={}


        try:
            f = open("campi.txt", "r")
            line = f.readline().strip()
            while(line != ''):
                tok = line.split()
                cod = int(tok[0])
                tipo = tok[1]
                nome_campo = f.readline().strip()
                line = f.readline().strip()
                tok = line.split()
                lunghezza= float(tok[0])
                larghezza= float(tok[1])
                if(tipo == "tennis"):
                    temperatura = float(tok[2])
                    terreno = f.readline().strip()
                    costo=float(f.readline().strip())
                    c = Tennis(cod, nome_campo,larghezza,lunghezza,temperatura,costo,terreno)
                    campi.append(c)
                    cod_campi[cod]=c
                else:
                    altezza = float(tok[2])
                    piano = int(tok[3])
                    costo = float(tok[4])
                    c = Squash(cod, nome_campo,larghezza,lunghezza,altezza,costo, piano)
                    campi.append(c)
                    cod_campi[cod]=c

                line = f.readline().strip()
            f.close()
        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        try:
            f = open("soci.txt", "r")
            line = f.readline().strip()
            while(line != ''):
                codice = int(line)
                nome_cognome = f.readline().strip()
                line = f.readline().strip()
                tok = line.split()
                eta=int(tok[0])
                categoria=int(tok[1])
                s = Socio(codice, nome_cognome, eta, categoria)
                soci.append(s)
                line = f.readline()
                tok = line.split()
                for i in range(len(tok)//2):
                    cod = int(tok[i*2])
                    orario = int(tok[i*2+1])
                    prenotazione = Prenotazione(cod, orario)
                    s.addPrenotazione(prenotazione)
                    cod_campi[cod].addPrenotazione()
                line = f.readline().strip()
            f.close()
        except IOError as i:
            print(i)

        print("sport, nome del campo, codice, larghezza, lunghezza, temperatura, terreno, altezza, piano, costo")

        for c in campi:
            print(str(c))

        print("\n")

        for s in soci:
            print(s)

        print("\n")

        try:
            cod = int(self._arg)
            print(str(cod_campi.get(cod).incasso()))

        except IOError as i:
            print(i)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('campo', action='store')
    pa = parser.parse_args()
    g = Gestione(pa.campo)
    g.main()
