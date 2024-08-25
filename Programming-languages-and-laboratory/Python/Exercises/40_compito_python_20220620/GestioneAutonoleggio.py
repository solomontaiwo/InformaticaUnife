
import sys
import argparse

from Veicolo import Veicolo
from Auto import Auto
from Furgone import Furgone
from Cliente import Cliente
from Noleggio import Noleggio

class Gestione:
    def __init__(self, arg):
        self._arg = arg

    def main(self):
        veicoli = []
        clienti = []
        cod_veicolo={}
        cod_importo={}

        try:
            f = open("veicoli.txt", "r")
            line = f.readline().strip()
            while(line != ''):
                tok = line.split()
                cod = int(tok[0])
                tipo = tok[1]
                targa=tok[2]
                modello = f.readline().strip()
                marca = f.readline().strip()
                if(tipo == "auto"):
                    line = f.readline().strip()
                    tok = line.split()
                    cilindrata = int(tok[0])
                    bagagliaio=float(tok[1])
                    costo = float(f.readline().strip())
                    a = Auto(cod, marca,  modello,  targa,costo,cilindrata,bagagliaio)
                    veicoli.append(a)
                    cod_veicolo[cod]=a
                else:
                    categoria = f.readline().strip()
                    line = f.readline().strip()
                    tok = line.split()
                    posti= int(tok[0])
                    carico=tok[1]
                    costo = float(f.readline().strip())
                    a = Furgone( cod, marca,  modello,  targa,costo, posti,categoria, carico)
                    veicoli.append(a)
                    cod_veicolo[cod]=a
                line = f.readline().strip()
            f.close()
        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        try:
            f = open("clienti.txt", "r")
            line = f.readline().strip()
            while line != '':
                nome = line
                c = Cliente(nome)
                clienti.append(c)
                line = f.readline().strip()
                tok = line.split()
                i=0
                while i < len(tok):
                    cod = int(tok[i])
                    giorni = int(tok[i+1])
                    v = cod_veicolo[cod]
                    nol = Noleggio(v.getTarga(), giorni, v.getCosto())
                    c.addNoleggio(nol)
                    i += 2
                    if cod_importo.get(cod):
                        cod_importo[cod] = cod_importo[cod]+giorni*v.getCosto()
                    else:
                        cod_importo[cod] = giorni*v.getCosto()

                line = f.readline().strip()
            f.close()
        except IOError as i:
            print(i)

        print("tipo, targa, codice, modello, marca, costo giornaliero, cilindrata, bagagliaio, categoria, numero di posti, vano di carico")

        for v in veicoli:
            print(str(v))

        print("\n")
        print("nome, costo totale, numero di noleggi, elenco noleggi")
        for c in clienti:
            print(c)

        print("\n")
        print(cod_importo[int(self._arg)])


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('codice', action='store')
    pa = parser.parse_args()
    g = Gestione(pa.codice)
    g.main()
