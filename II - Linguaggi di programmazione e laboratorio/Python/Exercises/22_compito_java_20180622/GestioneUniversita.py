from Corso import Corso
from Teoria import Teoria
from Laboratorio import Laboratorio
from Studente import Studente
from Libretto import Libretto

import sys


class GestioneUniversita:

    def main():

        corsi = []
        studenti = []
        cod_to_studente = {}
        cod_to_corso = {}

        try:
            f = open("corsi.txt", "r")
            line = f.readline().strip()

            while line != "":
                tok = line.split()
                codice = int(tok[0])
                tipo = tok[1]
                nome_corso = f.readline().strip()
                nome_cognome_docente = f.readline().strip()
                
                line = f.readline().strip()
                if tipo == "teoria":
                    tok = line.split()
                    codice_aula = int(tok[0])
                    ore_settimanali = int(tok[1])
                    ore_lezione = float(tok[2])

                    t = Teoria(codice, tipo, nome_corso, nome_cognome_docente, codice_aula, ore_settimanali, ore_lezione)
                    corsi.append(t)
                    line = f.readline().strip()
                    cod_to_corso[codice] = t

                else:
                    nome_laboratorio = line
                    nome_assistente = f.readline().strip()
                    numero_postazioni = int(f.readline().strip())

                    l = Laboratorio(codice, tipo, nome_corso, nome_cognome_docente, nome_laboratorio, nome_assistente, numero_postazioni)
                    corsi.append(l)

                    line = f.readline().strip()
                    cod_to_corso[codice] = l

                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        print("nome, codice, docente, tipo, aula, ore sett., ore/lez., lab., assistente, postazioni")

        for c in corsi:
            print(c)
        print()

        try:
            f = open("studenti.txt", "r")
            line = f.readline().strip()

            while line != "":
                matricola = int(line)
                nome_cognome_studente = f.readline().strip()
                st = Studente(matricola, nome_cognome_studente)
                studenti.append(st)
                cod_to_studente[matricola] = st

                line = f.readline().strip()

                while line != "":
                    tok = line.split()
                    codice_corso = int(tok[0])
                    voto = tok[1]

                    lib = Libretto(codice_corso, voto)
                    st.add_libretto(lib)
                    st.add_voto(voto, cod_to_corso[codice_corso].get_nome_corso())

                    line = f.readline().strip()
                
                line = f.readline().strip()

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)

        for s in studenti:
            print(s)
        print()

        try:
            codice_letto = int(sys.argv[1])

            for st in studenti:
                if codice_letto == st.get_matricola():
                    print(st.get_nome_studente() + " " + st.get_nome_corso_max() + " " + st.get_voto_max())

        except IOError as i:
            print(i)
        except Exception as e:
            print(e)


if __name__ == "__main__":
    GestioneUniversita.main()
