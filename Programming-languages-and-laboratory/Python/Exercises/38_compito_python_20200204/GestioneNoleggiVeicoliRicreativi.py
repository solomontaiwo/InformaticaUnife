from Roulotte import Roulotte
from Caravan import Caravan
from Cliente import Cliente
from Noleggio import Noleggio

veicoli = []
clienti = []
cod_to_veicolo = {}

# PUNTO 1, lettura e memorizzazione veicoli.txt

try:
    f = open("veicoli.txt", "r")
    line = f.readline().strip()

    while line != "":
        tok = line.split()
        codice = int(tok[0])
        sport = tok[1]
        marca = f.readline().strip()
        line = f.readline().strip()

        if sport == "roulotte":
            tok = line.split()
            peso = int(tok[0])
            lunghezza = float(tok[1])
            larghezza = float(tok[2])
            posti_letto = int(tok[3])
            line = f.readline().strip()
            tok = line.split()
            veranda = tok[0]
            costo_giornaliero = float(tok[1])

            rou = Roulotte(codice, sport, marca, peso, lunghezza, larghezza, posti_letto, veranda, costo_giornaliero)
            veicoli.append(rou)
            cod_to_veicolo[codice] = rou

            line = f.readline().strip()
        else:
            tok = line.split()
            larghezza = float(tok[0])
            lunghezza = float(tok[1])
            potenza = int(tok[2])
            posti_letto = int(tok[3])
            costo_giornaliero = float(tok[4])

            car = Caravan(codice, sport, marca, larghezza, lunghezza, potenza, posti_letto, costo_giornaliero)
            veicoli.append(car)
            cod_to_veicolo[codice] = car

            line = f.readline().strip()

        line = f.readline().strip()

    f.close()

except IOError as e:
    print(e)
except Exception as e:
    print(e)

# PUNTO 2, lettura e memorizzazione clienti.txt

try:
    f = open("clienti.txt", "r")
    line = f.readline().strip()
    while line != "":
        codice_cliente = line
        nome = f.readline().strip()
        cognome = f.readline().strip()
        indirizzo = f.readline().strip()
        cl = Cliente(codice_cliente, nome, cognome, indirizzo)
        clienti.append(cl)
        line = f.readline().strip()

        while line != "":
            tok = line.split()
            codice_veicolo = int(tok[0])
            giorni = int(tok[1])
            nol = Noleggio(codice_veicolo, giorni)
            cl.add_noleggio(nol)

            v = cod_to_veicolo[codice_veicolo]
            v.add_giorni_noleggio(giorni)

            line = f.readline().strip()

        line = f.readline().strip()

    f.close()


except IOError as e:
    print(e)
except Exception as e:
    print(e)

# PUNTO 3, stampa elenco veicoli

print("tipo, codice, marca, larghezza, lunghezza, posti letto, peso, veranda, potenza, costo")

for v in veicoli:
    print(v)
print()

# PUNTO 4, stampa elenco clienti

print("codice, cognome, nome, indirizzo, prenotazioni")

for c in clienti:
    print(c)
print()

# PUNTO 5, stampa incasso totale per ciascun veicolo

print("codice, incasso")

for v in veicoli:
    print(str(v.getCodice()) + "\t" + str(v.incasso()))
print()
