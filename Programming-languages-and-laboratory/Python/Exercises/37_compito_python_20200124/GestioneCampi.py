import sys

from Tennis import Tennis
from Squash import Squash
from Socio import Socio
from Prenotazione import Prenotazione


campi = []
soci = []
cod_to_campi = {}

# PUNTO 1, lettura e memorizzazione campi.txt

try:
    f = open("campi.txt", "r")
    line = f.readline().strip()

    while line != "":
        tok = line.split()
        codice = int(tok[0])
        sport = tok[1]
        nome_campo = f.readline().strip()
        line = f.readline().strip()
        tok = line.split()
        larghezza = float(tok[0])
        lunghezza = float(tok[1])
        temperatura_altezza = float(tok[2])

        if sport == "tennis":
            terreno = f.readline().strip()
            costo_orario = float(f.readline().strip())

            ten = Tennis(codice, sport, nome_campo, larghezza, lunghezza, temperatura_altezza, terreno, costo_orario)
            campi.append(ten)
            cod_to_campi[codice] = ten
        else:
            piano = int(tok[3])
            costo_orario = float(tok[4])

            sq = Squash(codice, sport, nome_campo, larghezza, lunghezza, temperatura_altezza, piano, costo_orario)
            campi.append(sq)
            cod_to_campi[codice] = sq
                
        line = f.readline().strip()
    f.close()
        
except IOError as i:
    print(i)
except Exception as e:
    print(e)

# PUNTO 2, lettura e memorizzazione soci.txt

try:
    f = open("soci.txt", "r")
    line = f.readline().strip()

    while line != "":
        codice_socio = int(line)
        nome_cognome = f.readline().strip()
        line = f.readline().strip()
        tok = line.split()
        eta = int(tok[0])
        categoria = int(tok[1])

        soc = Socio(codice_socio, nome_cognome, eta, categoria)
        soci.append(soc)

        line = f.readline().strip()
        tok = line.split()
        i = 0

        while i < len(tok):
            codice_campo = int(tok[i])
            ora_inizio = int(tok[i+1])
            i += 2
            pren = Prenotazione(codice_campo, ora_inizio)
            soc.add_prenotazione(pren)
            cam = cod_to_campi[codice_campo]
            cam.incrementa_prenotazioni()

        line = f.readline().strip()

    f.close()

except IOError as i:
    print(i)
except Exception as e:
    print(e)


# PUNTO 3, stampa elenco campi

print("sport, nome del campo, codice, larghezza, lunghezza, temperatura, terreno, altezza, piano, costo")

for c in campi:
    print(c)
print()

# PUNTO 4, stampa elenco soci

print("codice, nome e cognome, età, categoria, prenotazioni")

for s in soci:
    print(s)
print()

# PUNTO 5, stampa incasso totale campo leggendo da riga di comando

codice_letto = int(sys.argv[1])

print(cod_to_campi[codice_letto].incasso())
