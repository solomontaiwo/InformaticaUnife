from Prodotto import Prodotto
from Libro import Libro
from Cd import Cd
from Autore import Autore


class GestioneNegozio:

    def main():

        prodotti = []
        autori = []
        prezzo_totale = 0.0

        try:
            f = open("vendite.txt", "r")
            line = f.readline().strip()

            while line != "":
                tok = line.split()
                tipo = tok[0]
                codice = int(tok[1])
                titolo = f.readline().strip()
                autore = f.readline().strip()
                prezzo = int(f.readline().strip())
                prezzo_totale += prezzo

                if tipo == "libro":
                    isbn = f.readline().strip()
                    lib = Libro(tipo, codice, titolo, autore, prezzo, isbn)
                    prodotti.append(lib)
                    line = f.readline().strip()
                else:
                    durata = int(f.readline().strip())
                    cd = Cd(tipo, codice, titolo, autore, prezzo, durata)
                    prodotti.append(cd)
                    line = f.readline().strip()

                aut = Autore(autore)
                trovato = 0

                for a in autori:
                    if autore == a.get_nome_autore():
                        a.incrementa_prodotti()
                        trovato = 1

                if trovato == 0:
                    autori.append(aut)

                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        print("Tipo Codice Titolo Autori Prezzo ISBN Durata")

        for p in prodotti:
            print(p)
        print()

        for aut in autori:
            print(aut)
        print()

        prezzo_medio = prezzo_totale / len(prodotti)

        print("Prezzo medio: " + str(prezzo_medio))


if __name__ == "__main__":
    GestioneNegozio.main()
