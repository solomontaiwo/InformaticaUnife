from Filiale import Filiale
from Cliente import Cliente
from Privato import Privato
from Azienda import Azienda


class GestioneAssicurazione:

    def main():

        filiali = []
        cod_to_filiale = {}
        clienti = []

        try:
            f = open("filiali.txt", "r")
            line = f.readline().strip()

            while line != "":
                nome_filiale = line
                codice = int(f.readline().strip())
                indirizzo = f.readline().strip()
                line = f.readline().strip()
                fil = Filiale(nome_filiale, codice, indirizzo)
                filiali.append(fil)
                cod_to_filiale[codice] = fil
                line = f.readline().strip()

        except IOError as i:
            print(e)
        except Exception as e:
            print(e)

        try:
            f = open("clienti.txt", "r")
            line = f.readline().strip()

            while line != "":
                tok = line.split()
                tipo = tok[0]
                codice_cliente = int(tok[1])
                nome_cognome_ragione_sociale = f.readline().strip()
                codice_filiale_attuale = int(f.readline().strip())
                line = f.readline().strip()

                if tipo == "privato":
                    priv = Privato(
                        tipo, codice_cliente, nome_cognome_ragione_sociale, codice_filiale_attuale)
                    clienti.append(priv)
                    cod_to_filiale[codice_filiale_attuale].add_cliente_attuale(
                        priv)

                    tok = line.split()
                    i = 0
                    while i < len(tok):
                        codice_filiale_passata = int(tok[i])
                        priv.add_filiale_passata(codice_filiale_passata)
                        cod_to_filiale[codice_filiale_passata].add_cliente_passato(
                            priv)
                        i += 1

                    premio_corrente = float(f.readline().strip())
                    priv.add_premio_corrente(premio_corrente)
                    line = f.readline().strip()
                else:
                    azi = Azienda(
                        tipo, codice_cliente, nome_cognome_ragione_sociale, codice_filiale_attuale)
                    clienti.append(azi)
                    cod_to_filiale[codice_filiale_attuale].add_cliente_attuale(
                        azi)

                    tok = line.split()
                    i = 0
                    while i < len(tok):
                        codice_filiale_passata = int(tok[i])
                        azi.add_filiale_passata(codice_filiale_passata)
                        cod_to_filiale[codice_filiale_passata].add_cliente_passato(
                            azi)
                        i += 1

                    premio_corrente = float(f.readline().strip())
                    azi.add_premio_corrente(premio_corrente)
                    premio_piu_tasse = float(f.readline().strip())
                    azi.add_premio_piu_tasse(premio_piu_tasse)
                    line = f.readline().strip()

                line = f.readline().strip()

        except IOError as i:
            print(e)
        except Exception as e:
            print(e)

        print("tipo, nome e cognome o ragione sociale, codice, nome filiale attuale, premio corrente, premio corrente più tasse")

        for c in clienti:
            if c.get_tipo() == "privato":
                print(c.get_tipo() + "\t" + c.get_nome() + "\t" + str(c.get_codice()) + "\t" +
                      str(cod_to_filiale[c.get_codice_filiale_corrente()].get_nome_filiale()) + "\t" + str(c.get_premio_corrente()) + "\t-")
            else:
                print(c.get_tipo() + "\t" + c.get_nome() + "\t" + str(c.get_codice()) + "\t" +
                      str(cod_to_filiale[c.get_codice_filiale_corrente()].get_nome_filiale()) + "\t" + str(c.get_premio_corrente()) + "\t" + str(c.get_premio_piu_tasse()))
        print()

        for f in filiali:
            print(f)


if __name__ == "__main__":
    GestioneAssicurazione.main()
