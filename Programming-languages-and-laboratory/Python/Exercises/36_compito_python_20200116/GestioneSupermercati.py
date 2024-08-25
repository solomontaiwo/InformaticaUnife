from Cittadino import Cittadino
from Iper import Iper
from Cliente import Cliente
from Visita import Visita

import sys

supermercati = []
clienti = []
cod_to_supermercato = {}

try:
    f = open("supermercati.txt", "r")
    line = f.readline().strip()
    while line != "":
        tok = line.split()
        codice = int(tok[0])
        tipo = tok[1]
        indirizzo = f.readline().strip()
        line = f.readline().strip()
        tok = line.split()
        if tipo == "cittadino":
            apertura = int(tok[0])
            chiusura = int(tok[1])
            superficie = float(tok[2])
            addetti = int(tok[3])
            citt = Cittadino(codice, tipo, indirizzo, apertura, chiusura, superficie, addetti)
            supermercati.append(citt)
            cod_to_supermercato[codice] = citt
        else:
            superficie = float(tok[0])
            addetti = int(tok[1])
            nome = f.readline().strip()
            ip = Iper(codice, tipo, indirizzo, superficie, addetti, nome)
            supermercati.append(ip)
            cod_to_supermercato[codice] = ip
        line = f.readline().strip()
except IOError as i:
    print(i)
except Exception as e:
    print(e)

try:
    f = open("clienti.txt", "r")
    line = f.readline().strip()
    while line != "":
        cognome = line
        nome = f.readline().strip()
        cl = Cliente(cognome, nome)
        clienti.append(cl)
        line = f.readline().strip()
        while line != "":
            tok = line.split()
            codice_supermercato = int(tok[0])
            importo_speso = float(tok[1])
            vis = Visita(codice_supermercato, importo_speso)
            cl.add_spesa(importo_speso)
            cod_to_supermercato[codice_supermercato].add_spesa(importo_speso)
            line = f.readline().strip()
        line = f.readline().strip()
except IOError as i:
    print(i)
except Exception as e:
    print(e)

print("codice, tipo, indirizzo, apertura, chiusura, superficie, n. addetti, centro commerciale")
for s in supermercati:
    print(s)

print("\ncognome, nome, spesa totale")
for c in clienti:
    print(c)

codice_letto = int(sys.argv[1])

print("\n", str(codice_letto) + "\t" + str(cod_to_supermercato[codice_letto].spesa_media()))
