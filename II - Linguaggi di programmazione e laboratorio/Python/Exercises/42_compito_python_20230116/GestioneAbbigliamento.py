from GiaccaAVento import GiaccaAVento
from Piumino import Piumino
from Negozio import Negozio
from Magazzino import Magazzino


class GestioneAbbigliamento:

    def main():

        articoli = []
        negozi = []
        cod_to_articolo = {}

        # Punto 1, memorizzazione articoli

        try:
            f = open("articoli.txt", "r")
            line = f.readline().strip()

            while line != "":
                tok = line.split()
                codice = int(tok[0])
                tipo = tok[1]
                marca = f.readline().strip()

                line = f.readline().strip()

                if tipo == "giacca-a-vento":
                    taglia = line
                    modello = f.readline().strip()
                    line = f.readline().strip()
                    tok = line.split()
                    costo = float(tok[0])
                    tasche = int(tok[1])
                    sconto = int(tok[2])

                    giac = GiaccaAVento(codice, tipo, marca, taglia, modello, costo, tasche, sconto)
                    articoli.append(giac)
                    cod_to_articolo[codice] = giac
                else:
                    tok = line.split()
                    taglia = tok[0]
                    peso = int(tok[1])
                    modello = f.readline().strip()
                    line = f.readline().strip()
                    tok = line.split()
                    costo = float(tok[0])
                    sconto = int(tok[1])

                    pium = Piumino(codice, tipo, marca, taglia, peso, modello, costo, sconto)
                    articoli.append(pium)
                    cod_to_articolo[codice] = pium

                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        # Punto 2, memorizzazione negozi

        try:
            f = open("negozi.txt", "r")
            line = f.readline().strip()

            while line != "":
                codice_negozio = int(line)
                nome = f.readline().strip()
                indirizzo = f.readline().strip()

                neg = Negozio(codice_negozio, nome, indirizzo)
                negozi.append(neg)

                line = f.readline().strip()
                i = 0
                tok = line.split()

                while i < len(tok):
                    codice_articolo = int(tok[i])
                    quantita = int(tok[i+1])
                    mag = Magazzino(codice_articolo, quantita)
                    neg.add_articolo_magazzino(mag)
                    neg.somma_articolo_in_magazzino(quantita)
                    costo_totale_articolo = cod_to_articolo[codice_articolo].get_costo() * quantita
                    neg.add_valore_totale(costo_totale_articolo)
                    i += 2

                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        # Punto 3, stampa articoli

        print("tipo, codice, marca, modello, taglia, tasche, peso, costo, sconto")

        for a in articoli:
            print(a)
        print()

        # Punto 4, stampa elenco negozi

        print("codice, nome, indirizzo, numero di articoli, magazzino")

        for n in negozi:
            print(n)
        print()

        # Punto 5, valore totale del magazzino

        try:

            codice_negozio_letto = int(input("Inserire codice negozio: "))

            for ne in negozi:
                if codice_negozio_letto == ne.get_codice_negozio():
                    print(str(ne.get_valore_totale()))

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)


if __name__ == "__main__":
    GestioneAbbigliamento.main()
