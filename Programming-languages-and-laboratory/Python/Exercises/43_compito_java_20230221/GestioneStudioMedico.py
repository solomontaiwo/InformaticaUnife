from Operatore import Operatore
from Medico import Medico
from Terapista import Terapista
from Paziente import Paziente
from Visita import Visita

# Per leggere il codice di un paziente da riga di comando
import sys


class GestioneStudioMedico:

    def main():
        operatori = []
        pazienti = []

        # PUNTO 1: MEMORIZZAZIONE OPERATORI

        try:
            file = open("operatori.txt", "r")
            line = file.readline().strip()

            while line != "":
                tok = line.split()
                codice_operatore = int(tok[0])
                tipo = tok[1]
                nome_operatore = file.readline().strip()
                costo_visita = float(file.readline().strip())

                line = file.readline().strip()

                if tipo == "medico":
                    specialita = line
                    line = file.readline().strip()
                    tok = line.split()
                    n_visite_mese_precedente = int(tok[0])
                    ambulatorio = tok[1]

                    med = Medico(codice_operatore, tipo, nome_operatore, costo_visita,
                                 specialita, n_visite_mese_precedente, ambulatorio)
                    operatori.append(med)

                else:
                    terapia = line
                    line = file.readline().strip()
                    tok = line.split()
                    studio = tok[0]
                    n_sedute = int(tok[1])

                    ter = Terapista(codice_operatore, tipo, nome_operatore,
                                    costo_visita, terapia, studio, n_sedute)
                    operatori.append(ter)

                line = file.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        # PUNTO 2: MEMORIZZAZIONE PAZIENTI

        try:
            file = open("pazienti.txt", "r")
            line = file.readline().strip()

            while line != "":
                codice_paziente = int(line)
                nome_paziente = file.readline().strip()

                paz = Paziente(codice_paziente, nome_paziente)
                pazienti.append(paz)

                line = file.readline().strip()

                # uso la variabile "i" per capire quando sono arrivato alla fine della riga e, quindi, dei valori delle visite
                # da memorizzare ed aggiungere all'oggetto "paz"
                i = 0
                tok = line.split()

                # finchè "i" è minore dei token totali di "line"...
                while i < len(tok):
                    codice_operatore = int(tok[i])
                    n_sedute = int(tok[i+1])
                    vis = Visita(codice_operatore, n_sedute)

                    paz.add_visita(vis)

                    # incremento il numero di visite totali del paziente attraverso il metodo
                    # creato appositamente nella classe "Paziente"
                    paz.incrementa_n_visite_totali(n_sedute)

                    # incremento "i" di 2 per verificare ed eventualmente salvare la prossima coppia di valori
                    i += 2

                line = file.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        # PUNTO 1: STAMPA ELENCO OPERATORI

        print("nome operatore, codice, costo, specialità, visite, ambulatorio, terapia, studio, sedute, tipo")

        for op in operatori:
            print(op)
        print()

        # PUNTO 2: STAMPA ELENCO PAZIENTI

        print("codice, nome, numero operatori, visite")

        for pazi in pazienti:
            print(pazi)
        print()

        # PUNTO 3: STAMPA NOME PAZIENTE E NUMERO TOTALE DI VISITE, CODICE PAZIENTE LETTO DA RIGA DI COMANDO

        try:
            codice_letto = int(sys.argv[1])

            for pa in pazienti:
                if codice_letto == pa.get_codice_paziente():
                    print("Numero di visite del paziente " +
                          pa.get_nome_paziente() + ": " + str(pa.get_visite_totali()))

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)


if __name__ == "__main__":
    GestioneStudioMedico.main()
