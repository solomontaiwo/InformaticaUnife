from Automobile import Automobile
from Berlina import Berlina
from Fuoristrada import Fuoristrada


import sys


class GestioneConcessionaria:
    def main():

        automobili = []
        range_800_1000 = 0
        range_1000_1500 = 0
        range_1500_2000 = 0

        try:
            f = open("ordini.txt", "r")
            line = f.readline().strip()

            while line != "":
                tok = line.split()
                tipo = tok[0]
                modello = tok[1]
                produttore = tok[2]

                if tipo == "b":
                    bagagliaio = float(tok[3])
                    peso = int(tok[4])
                    codice_identificativo = int(tok[5])

                    ber = Berlina(tipo, modello, produttore,
                                  bagagliaio, peso, codice_identificativo)
                    automobili.append(ber)

                    if peso <= 1000:
                        range_800_1000 += 1
                    elif peso <= 1500:
                        range_1000_1500 += 1
                    else:
                        range_1500_2000 += 1

                else:
                    marce = int(tok[3])
                    peso = int(tok[4])
                    codice_identificativo = int(tok[5])

                    fuor = Fuoristrada(
                        tipo, modello, produttore, marce, peso, codice_identificativo)
                    automobili.append(fuor)

                    if peso <= 1000:
                        range_800_1000 += 1
                    elif peso <= 1500:
                        range_1000_1500 += 1
                    else:
                        range_1500_2000 += 1

                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        print("Codice Marca Modello Bagagliaio Marce")

        for a in automobili:
            print(a)
        print()

        print("800-1000\t1000-1500\t1500-2000\n" + str(range_800_1000) + "\t\t" +
              str(range_1000_1500) + "\t\t" + str(range_1500_2000) + "\n")

        try:

            marca_letta = sys.argv[1]

            for au in automobili:
                if marca_letta == au.get_produttore():
                    print(au)

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)


if __name__ == "__main__":
    GestioneConcessionaria.main()
