from veicolo import Veicolo
from auto import Auto
from furgone import Furgone
from noleggio import Noleggio
from cliente import Cliente

def main():
    veicoli = []
    clienti = []

    codice_veicolo = {}
    targa_veicolo = {}

    # PUNTO 1: lettura file veicoli.txt

    try:
        file = open("veicoli.txt", "r")

        line = file.readline().strip() # Il metodo strip rimuove tutti gli spazi (inclusi gli \n) in testa e in coda alla stringa

        while line != "":
            splitted_line = line.split()
            codice = int(splitted_line[0])
            tipo = splitted_line[1]
            targa = splitted_line[2]

            modello = file.readline().strip()

            marca = file.readline().strip()

            line = file.readline()
            if tipo == "auto":
                splitted_line = line.split()
                capienza_bagaglio = float(splitted_line[0])
                cilindrata = int(splitted_line[1])
                categoria = file.readline().strip()
                costo_giornaliero = float(file.readline())

                auto = Auto(codice, tipo, targa, marca, modello, costo_giornaliero, capienza_bagaglio, cilindrata, categoria)

                codice_veicolo[codice] = auto
                targa_veicolo[targa] = auto
                veicoli.append(auto)
            elif tipo == "furgone":
                splitted_line = line.split()
                rimorchio = splitted_line[0] == 'true'
                numero_posti = int(splitted_line[1])
                vano_carico = splitted_line[2] == 'true'
                costo_giornaliero = float(file.readline())

                furgone = Furgone(codice, tipo, targa, marca, modello, costo_giornaliero, rimorchio, numero_posti, vano_carico)

                codice_veicolo[codice] = furgone
                targa_veicolo[targa] = furgone
                veicoli.append(furgone)
            
            line = file.readline()

            ### FINE WHILE
        file.close()
    except IOError as io_exception:
        print(io_exception)
    except Exception as e:
        print(e)

    # PUNTO 2: lettura file clienti.txt
    try:
        file = open("clienti.txt", "r")

        line = file.readline().strip()
        while line != "":
            nome_cognome = line

            cliente = Cliente(nome_cognome)
            clienti.append(cliente)

            line = file.readline().strip()
            while line != "\n" and line != "":
                splitted_line = line.split()

                codice = int(splitted_line[0])
                numero_giorni = int(splitted_line[1])

                noleggio = Noleggio(codice, numero_giorni, codice_veicolo[codice].costo_giornaliero)

                cliente.add_noleggio(noleggio)
                codice_veicolo[codice].add_noleggio(noleggio)

                line = file.readline()
            
            line = file.readline().strip()

        file.close()
    except IOError as io_exception:
        print(io_exception)
    except Exception as e:
        print(e)

    # PUNTO 3: stampa veicoli

    print("tipo, targa, codice, modello, marca, costo giornaliero, bagagliaio, cilindrata, categoria, rimorchio, numero di posti, vano di carico")
    for veicolo in veicoli:
        print(veicolo)

    print("\n\n")

    # PUNTO 4: stampa clienti

    for cliente in clienti:
        print(cliente)

    print("\n\n")

    # PUNTO 5

    try:
        targa = input("Inserire una targa: ")
        veicolo = targa_veicolo[targa]

        print("Numero noleggi: ", len(veicolo.noleggi), "\n")

    except IOError as io_exception:
        print(io_exception)
    except KeyError as _:
        print("Targa non trovata.\n")



if __name__ == "__main__":
    main()