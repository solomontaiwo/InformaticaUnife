from Cliente import Cliente
from Residenziale import Residenziale
from Aziendale import Aziendale
from Lettura import Lettura


class GestioneAcquedotto:
    def main():

        clienti = []
        cod_to_cliente = {}
        letture = []
        
        try:
            f = open("clienti.txt", "r")
            line = f.readline().strip()

            while line != "":
                tok = line.split()
                tipo = tok[0]
                codice = int(tok[1])
                nome_cognome_ragione_sociale = f.readline().strip()

                if tipo == "residenziale":
                    tipo_contratto = f.readline().strip()
                    indirizzo = f.readline().strip()

                    res = Residenziale(
                        tipo, codice, nome_cognome_ragione_sociale, tipo_contratto, indirizzo)
                    clienti.append(res)
                    cod_to_cliente[codice] = res

                    line = f.readline().strip()

                else:
                    portata_massima = float(f.readline().strip())
                    tipo_contratto = f.readline().strip()
                    indirizzo = f.readline().strip()

                    az = Aziendale(tipo, codice, nome_cognome_ragione_sociale,
                                   portata_massima, tipo_contratto, indirizzo)
                    clienti.append(az)
                    cod_to_cliente[codice] = az

                    line = f.readline().strip()

                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        print("ID Tipo Nome/Cognome RagioneSociale Indirizzo TipoContratto PortataMassima")

        for c in clienti:
            print(c)
        print()

        try:
            f = open("letture.txt", "r")
            line = f.readline().strip()

            while line != "":
                tok = line.split()
                codice_cliente = int(tok[0])
                metri_cubi_consumati = float(tok[1])
                cod_to_cliente[codice_cliente].add_metri_cubi(
                    metri_cubi_consumati)
                let = Lettura(codice_cliente, metri_cubi_consumati)
                letture.append(let)
                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        print("ID Nome/Cognome/RagioneSociale Totale")

        for cl in clienti:
            if cl.get_tipo_contratto() == "mercato libero":
                totale = cl.get_metri_cubi() * 1.2
            else:
                totale = cl.get_metri_cubi() * 1.15
            print(str(cl.get_codice()) + " " +
                  cl.get_nome() + " " + str(totale))
        print()
            
        lettura_max = 0.0
        nome_cliente_lettura_max = ""
        for let in letture:
            if let.get_lettura() > lettura_max:
                lettura_max = let.get_lettura()
                nome_cliente_lettura_max = cod_to_cliente[let.get_codice_cliente()].get_nome()
                
        print("Il cliente con la lettura più alta è " + nome_cliente_lettura_max + " con " + str(lettura_max))


if __name__ == "__main__":
    GestioneAcquedotto.main()
