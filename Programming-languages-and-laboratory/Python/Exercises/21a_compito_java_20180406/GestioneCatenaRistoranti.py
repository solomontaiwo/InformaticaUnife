from Ristorante import Ristorante
from Pub import Pub
from Osteria import Osteria
from Menu import Menu


class GestioneCatenaRistoranti:
    def main():

        ristoranti = []
        cod_to_rist = {}

        try:
            f = open("ristoranti.txt", "r")
            line = f.readline().strip()

            while line != "":
                tok = line.split()
                codice = int(tok[0])
                tipo = tok[1]
                nome_ristorante = f.readline().strip()
                line = f.readline().strip()
                tok = line.split()

                if tipo == "pub":
                    dipendenti = int(tok[0])
                    tavoli = int(tok[1])

                    pu = Pub(codice, tipo, nome_ristorante, dipendenti, tavoli)
                    ristoranti.append(pu)
                    cod_to_rist[codice] = pu

                else:
                    posti = int(tok[0])
                    superficie = float(tok[1])
                    bagno_disabili = tok[2]

                    ost = Osteria(codice, tipo, nome_ristorante,
                                  posti, superficie, bagno_disabili)
                    ristoranti.append(ost)
                    cod_to_rist[codice] = ost

                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        print("nome, codice, tipo, n. dipendenti, n. tavoli, n. posti, superficie, bagno disabili")

        for r in ristoranti:
            print(r)
        print()

        try:
            f = open("menu.txt", "r")
            line = f.readline().strip()

            while line != "":
                codice_ristorante = int(line)
                descrizione_prodotto = f.readline().strip()
                line = f.readline().strip()
                tok = line.split()
                tipo = tok[0]
                prezzo = float(tok[1])
                costo_materie_prime = float(tok[2])
                line = f.readline().strip()

                me = Menu(codice_ristorante, descrizione_prodotto,
                          tipo, prezzo, costo_materie_prime)
                cod_to_rist[codice_ristorante].add_menu(me)
                cod_to_rist[codice_ristorante].add_prezzo_totale(prezzo)

                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        for ri in ristoranti:
            print(ri.stampa_menu())
        print()

        nome_ristorante_costoso = ""
        prezzo_medio_max = 0.0

        for ris in ristoranti:
            if ris.get_prezzo_medio() > prezzo_medio_max:
                prezzo_medio_max = ris.get_prezzo_medio()
                nome_ristorante_costoso = ris.get_nome_ristorante()

        print("Il locale con il prezzo medio più alto è " +
              nome_ristorante_costoso + ".")


if __name__ == "__main__":
    GestioneCatenaRistoranti.main()
