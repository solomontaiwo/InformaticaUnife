from Acquisto import Acquisto
from Privato import Privato
from Professionista import Professionista


class GestioneVenditeBricolage:

    def main():

        acquisti = []

        try:
            f = open("transazioni.txt", "r")
            line = f.readline().strip()

            while line != "":
                tok = line.split()
                tipo = tok[0]
                codice = int(tok[1])
                line = f.readline().strip()
                tok = line.split()
                giorno = int(tok[0])
                mese = int(tok[1])
                anno = int(tok[2])
                nome_cognome_ragione_sociale = f.readline().strip()

                if tipo == "privato":
                    indirizzo = f.readline().strip()
                    codice_fiscale = f.readline().strip()

                    priv = Privato(tipo, codice, giorno, mese, anno,
                                   nome_cognome_ragione_sociale, indirizzo, codice_fiscale)
                    acquisti.append(priv)

                    line = f.readline().strip()

                    while line != "":
                        descrizione = line
                        line = f.readline().strip()
                        tok = line.split()
                        quantita_venduta = int(tok[0])
                        prezzo = int(tok[1])
                        priv.add_importo_transazione(quantita_venduta * prezzo)
                        line = f.readline().strip()

                else:
                    line = f.readline().strip()
                    tok = line.split()
                    partita_iva = int(tok[0])
                    codice_cliente = int(tok[1])

                    prof = Professionista(
                        tipo, codice, giorno, mese, anno, nome_cognome_ragione_sociale, partita_iva, codice_cliente)
                    acquisti.append(prof)

                    line = f.readline().strip()

                    while line != "":
                        descrizione = line
                        line = f.readline().strip()
                        tok = line.split()
                        quantita_venduta = int(tok[0])
                        prezzo = int(tok[1])
                        prof.add_importo_transazione(quantita_venduta * prezzo)
                        line = f.readline().strip()

                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        print(
            "ID Data Nome Indirizzo CodiceFiscale RagioneSociale PartitaIva CodiceCliente")

        for ac in acquisti:
            print(ac)
        print()

        print("C. trans. Importo totale")
        for acq in acquisti:
            print(str(acq.get_codice_transazione()) + "\t" +
                  str(acq.get_importo_totale_transazione()))
        print()

        totale_tutte_transazioni = 0.0
        for acqui in acquisti:
            totale_tutte_transazioni += acqui.get_importo_totale_transazione()

        print("L'importo totale di tutti le transazioni è pari a " +
              str(totale_tutte_transazioni))


if __name__ == "__main__":
    GestioneVenditeBricolage.main()
