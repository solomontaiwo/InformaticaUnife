from Partecipante import Partecipante
from Studente import Studente
from Regolare import Regolare
from Conferenza import Conferenza
from Partecipazione import Partecipazione

import sys


class GestioneConferenze:

    def main():

        partecipanti = []
        conferenze = []
        cod_to_partecipante = {}

        try:
            f = open("partecipanti.txt", "r")
            line = f.readline().strip()
            
            while line != "":
                tok = line.split()
                codice = int(tok[0])
                tipo = tok[1]
                nome = f.readline().strip()
                cognome = f.readline().strip()
                corso_ente = f.readline().strip()

                if tipo == "studente":
                    universita = f.readline().strip()
                    anno = int(f.readline().strip())

                    st = Studente(codice, tipo, nome, cognome, corso_ente, universita, anno)
                    partecipanti.append(st)
                    cod_to_partecipante[codice] = st

                else:
                    line = f.readline().strip()
                    tok = line.split()

                    dipendenti = int(tok[0])
                    accademico = bool(tok[1])

                    reg = Regolare(codice, tipo, nome, cognome, corso_ente, dipendenti, accademico)
                    partecipanti.append(reg)
                    cod_to_partecipante[codice] = reg

                
                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        print("tipo, codice, nome, cognome, corso di studi, università, anno di corso, ente di appartenenza, numero di dipendenti, accademico")

        for p in partecipanti:
            print(p)
        print()

        try:
            f = open("conferenze.txt", "r")
            line = f.readline().strip()

            while line != "":
                nome_conferenza = line
                luogo_conferenza = f.readline().strip()

                conf = Conferenza(nome_conferenza, luogo_conferenza)
                conferenze.append(conf)

                line = f.readline().strip()

                while line != "":
                    tok = line.split()
                    codice = int(tok[0])
                    spesa  = int(tok[1])

                    part = Partecipazione(codice, spesa, cod_to_partecipante[codice].get_cognome())

                    conf.add_partecipazione(part)
                    conf.add_costo(spesa)
                    
                    line = f.readline().strip()

                line = f.readline().strip()
        
        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        for c in conferenze:
            print(c)
        print()

        try:
            codice_letto = int(sys.argv[1])

            for par in partecipanti:
                if codice_letto == par.get_codice():
                    if par.get_tipo() == "studente":
                        print(str(codice_letto) + "\nStudente, universita: " + par.get_universita())
                    else:
                        print(str(codice_letto) + "\nRegolare, ente: " + par.get_ente())

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)


if __name__ == "__main__":
    GestioneConferenze.main()
