from Tennis import Tennis
from Squash import Squash
from Socio import Socio, Prenotazione
import sys

campi = []
soci = []
cod_campi = {}

try:
    f = open("campi.txt", "r")
    line = f.readline().strip()
    while line != "":
        tok = line.split()
        codice = int(tok[0])
        sport = tok[1]
        nome = f.readline().strip()
        line = f.readline().strip()
        if sport == "tennis":
            tok = line.split()
            larghezza = float(tok[0])
            lunghezza = float(tok[1])
            temperatura = float(tok[2])
            terreno = f.readline().strip()
            costo = float(f.readline().strip())
            ten = Tennis(codice, sport, nome, larghezza, lunghezza, temperatura, terreno, costo)
            campi.append(ten)
            cod_campi[codice] = ten
        else:
            tok = line.split()
            larghezza = float(tok[0])
            lunghezza = float(tok[1])
            altezza = float(tok[2])
            piano = int(tok[3])
            costo = float(tok[4])
            squ = Squash(codice, sport, nome, larghezza, lunghezza, altezza, piano, costo)
            campi.append(squ)
            cod_campi[codice] = squ

        line = f.readline().strip()
    f.close()

except IOError as e:
    print(e)
except Exception as e:
    print(e)

try:
    f = open("soci.txt")
    line = f.readline().strip()
    while line != "":
        codice = int(line)
        nome_cognome = f.readline().strip()
        line = f.readline()
        tok = line.split()
        eta = int(tok[0])
        categoria = int(tok[1])
        soc = Socio(codice, nome_cognome, eta, categoria)
        soci.append(soc)
        line = f.readline()
        tok = line.split()

        for i in range(len(tok)//2):
            codice_campo = int(tok[i*2])
            ora_inizio = int(tok[i*2+1])
            pren = Prenotazione(codice_campo, ora_inizio)
            soc.add_prenotazione(pren)
            cod_campi[codice_campo].incrementa_prenotazione()

        line = f.readline()
    f.close()
except IOError as e:
    print(e)
except Exception as e:
    print(e)

print("sport, nome del campo, codice, larghezza, lunghezza, temperatura, terreno, altezza, piano, costo")

for c in campi:
    print(c)

print()

print("codice, nome e cognome, età, categoria, prenotazioni")

for s in soci:
    print(s)

print()

codice = int(sys.argv[1])

for c in campi:
    if codice == c.get_codice():
        print(codice, c.get_incasso())