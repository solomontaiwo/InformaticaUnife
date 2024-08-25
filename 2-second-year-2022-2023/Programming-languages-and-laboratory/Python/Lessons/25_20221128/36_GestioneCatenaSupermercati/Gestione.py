import sys

from Cittadino import Cittadino
from Ipermercato import Ipermercato
from Cliente import Cliente, Visita

supermercati = []
clienti = []
cod_sup = {}

try:
    f = open("supermercati.txt", "r")
    line = f.readline().strip()  # elimina spazi bianchi e a capo dall'inizio e dalla fine
    while line != "":
        tokens = line.split()
        codice = int(tokens[0])
        tipo = tokens[1]
        indirizzo = f.readline().strip()
        line = f.readline().strip()
        tokens = line.split()
        if tipo == "cittadino":
            apertura = int(tokens[0])
            chiusura = int(tokens[1])
            superficie = float(tokens[2])
            addetti = int(tokens[3])
            citt = Cittadino(codice, indirizzo, superficie, addetti, apertura, chiusura)
            supermercati.append(citt)
            cod_sup[codice] = citt
        else:
            superficie = float(tokens[0])
            addetti = int(tokens[1])
            nome = f.readline().strip() 
            i = Ipermercato(codice, indirizzo, superficie, addetti, nome)
            supermercati.append(i)
            cod_sup[codice] = i
        
        line = f.readline().strip()

except IOError as i:
    print(i)
except Exception as e:
    print(e)

for s in supermercati:
    print(s)

try:
    f = open("clienti.txt", "r")
    line = f.readline().strip()
    while line != '':
        cognome = line
        nome = f.readline().strip()
        c = Cliente(nome, cognome)
        clienti.append(c)
        line = f.readline()
        while line != "" and line != "\n":
            tokens = line.split()
            codice = int(tokens[0])
            importo = float(tokens[1])
            v = Visita(codice, importo)
            c.add_visita(v)
            cod_sup[codice].add_spesa(importo)
            line = f.readline()
        line = f.readline().strip()

except IOError as e:
    print(e)
except Exception as e:
    print(e)

for c in clienti:
    print(c)

print("")

codice = int(sys.argv[1])

print(codice, "\t", cod_sup[codice].spesa_media())
