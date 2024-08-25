from Transazione import Transazione
from Fisica import Fisica
from Libro import Libro
from Online import Online


class GestioneVenditeLibri:

    def main():

        transazioni = []
        libri = []
        incasso_complessivo = 0.0

        try:
            f = open("transazioni.txt", "r")
            line = f.readline().strip()

            while line != "":
                tok = line.split()
                tipo = tok[0]
                identificativo = int(tok[1])
                data = int(tok[2])
                citta_indirizzo_ip = tok[3]

                if tipo == "f":
                    tr = Fisica(tipo, identificativo, data, citta_indirizzo_ip)
                    transazioni.append(tr)
                else:
                    tr = Online(tipo, identificativo, data, citta_indirizzo_ip)
                    transazioni.append(tr)

                line = f.readline().strip()

                while line != "":

                    titolo = line
                    autore = f.readline().strip()
                    prezzo = int(f.readline().strip())

                    lib = Libro(titolo, autore, prezzo)
                    tr.add_libro(lib)
                    tr.add_costo(prezzo)

                    libro_in_lista = 0

                    for li in libri:
                        if li.get_titolo() == titolo:
                            li.aggiorna_numero_copie()
                            libro_in_lista = 1

                    if libro_in_lista == 0:
                        libri.append(lib)
                        
                    incasso_complessivo += prezzo

                    line = f.readline().strip()

                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        print("ID Data Città IndirizzoIP Totale")
        for t in transazioni:
            print(str(t) + " " + t.get_prezzo_totale())
        print()

        for lib in libri:
            print(lib)
        print()
        
        print("L'incasso complessivo è pari a " + str(incasso_complessivo))

if __name__ == "__main__":
    GestioneVenditeLibri.main()
