from Prodotto import Prodotto
from Toner import Toner
from Stampante import Stampante


class GestioneMagazzini:

    def main():

        prodotti = []

        try:
            f = open("inventario.txt", "r")
            line = f.readline().strip()

            while line != "":
                tok = line.split()
                tipo = tok[0]
                codice = int(tok[1])
                modello = f.readline().strip()
                produttore = f.readline().strip()
                line = f.readline().strip()
                tok = line.split()
                giorno = int(tok[0])
                mese = int(tok[1])
                anno = int(tok[2])
                prezzo = int(f.readline().strip())

                if tipo == "toner":
                    modello_stampante = f.readline().strip()
                    ton = Toner(tipo, codice, modello, produttore,
                                giorno, mese, anno, prezzo, modello_stampante)
                    prodotti.append(ton)

                    line = f.readline().strip()

                    while line != "":
                        pezzo = int(line)
                        ton.add_pezzo(pezzo)
                        line = f.readline().strip()

                else:
                    peso = int(f.readline().strip())
                    stamp = Stampante(
                        tipo, codice, modello, produttore, giorno, mese, anno, prezzo, peso)
                    prodotti.append(stamp)

                    line = f.readline().strip()

                    while line != "":
                        pezzo = int(line)
                        stamp.add_pezzo(pezzo)
                        line = f.readline().strip()

                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        print("Tipo Codice Modello Produttore Data Prezzo ModelloStampante Peso")
        for p in prodotti:
            print(p)
        print()

        for pr in prodotti:
            pr.stampa_pezzi()
        print()

        for pri in prodotti:
            print("Numero medio di pezzi per magazzino di " + pri.get_produttore() +
                  " " + pri.get_modello() + ": " + str(pri.get_numero_medio_pezzi_per_magazzino()))


if __name__ == "__main__":
    GestioneMagazzini.main()
