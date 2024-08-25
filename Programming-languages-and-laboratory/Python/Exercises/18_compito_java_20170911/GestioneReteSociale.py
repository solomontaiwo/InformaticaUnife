from Iscritto import Iscritto
from Azienda import Azienda
from Individuo import Individuo
from Seguace import Seguace


class GestioneReteSociale:

    def main():

        iscritti = []
        seguaci = []
        cod_to_iscritto = {}

        try:
            f = open("iscritti.txt", "r")
            line = f.readline().strip()

            while line != "":
                tok = line.split()
                tipo = tok[0]
                codice = int(tok[1])
                nome_cognome_ragione_sociale = f.readline().strip()
                indirizzo = f.readline().strip()
                line = f.readline().strip()
                if tipo == "individuo":
                    tok = line.split()
                    nome_account = tok[0]
                    password = tok[1]
                    ind = Individuo(
                        tipo, codice, nome_cognome_ragione_sociale, indirizzo, nome_account, password)
                    iscritti.append(ind)
                    line = f.readline().strip()
                    cod_to_iscritto[codice] = ind
                else:
                    nome_cognome_gestore = line
                    line = f.readline().strip()
                    tok = line.split()
                    nome_account = tok[0]
                    password = tok[1]
                    az = Azienda(tipo, codice, nome_cognome_ragione_sociale,
                                 indirizzo, nome_cognome_gestore, nome_account, password)
                    line = f.readline().strip()
                    cod_to_iscritto[codice] = az
                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        print("ID Nome/Cognome RagioneSociale Nome/CognomeGestoreAccount Indirizzo NomeAccount LunghezzaPassword")
        for i in iscritti:
            print(i)
        print()

        try:
            f = open("segue.txt", "r")
            line = f.readline().strip()

            while line != "":
                codice_iscritto = int(line)
                seg = Seguace(codice_iscritto,
                              cod_to_iscritto[codice_iscritto].get_nome())
                seguaci.append(seg)
                line = f.readline().strip()
                i = 0
                tok = line.split()
                while i <= len(tok):
                    codice_seguace = int(tok[0])
                    seg.aggiungi_seguace(codice_seguace)
                    i += 1
                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        print("ID Nome/Cognome/RagioneSociale NumeroSeguaci")
        for s in seguaci:
            print(s)
        print()

        piu_iscritti = 0
        nome_piu_iscritti = ""

        for se in seguaci:
            if se.get_numero_iscritti() > piu_iscritti:
                piu_iscritti = se.get_numero_iscritti()
                nome_piu_iscritti = se.get_nome_iscritto()

        print("L'iscritto con più seguaci è " +
              nome_piu_iscritti + " (" + str(piu_iscritti) + ")")


if __name__ == "__main__":
    GestioneReteSociale.main()
