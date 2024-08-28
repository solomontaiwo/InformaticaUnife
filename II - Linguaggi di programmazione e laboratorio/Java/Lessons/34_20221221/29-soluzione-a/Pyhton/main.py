from dipendente import Dipendente
from trainer import Trainer
from nutrizionista import Nutrizionista
from servizio import Servizio
from cliente import Cliente

def main():
    dipendenti: list[Dipendente] = []
    clienti: list[Cliente] = []

    map_dipendenti = {}

    # PUNTO 1: lettura dipendenti.txt
    try:
        file = open("dipendenti.txt", "r", encoding = 'utf-8')

        line = file.readline().strip()

        while line != "":
            splitted_line = line.split()

            codice = int(splitted_line[0])
            tipo = splitted_line[1]

            nome = file.readline().strip()

            line = file.readline().strip()

            if tipo == "trainer":
                splitted_line = line.split()

                ore_settimanali = int(splitted_line[0])
                costo_orario = float(splitted_line[1])
                
                specialita = file.readline().strip()

                dipendente = Trainer(codice, tipo, nome, costo_orario, ore_settimanali, specialita)
                
                dipendenti.append(dipendente)
                map_dipendenti[codice] = dipendente
            elif tipo == "nutrizionista":
                splitted_line = line.split()

                telefono = int(splitted_line[0])
                medico = splitted_line[1] == 'true'
                appuntamenti_settimanali = int(splitted_line[2])
                costo_orario = float(splitted_line[3])

                dipendente = Nutrizionista(codice, tipo, nome, costo_orario, telefono, medico, appuntamenti_settimanali)
                dipendenti.append(dipendente)
                map_dipendenti[codice] = dipendente
            line = file.readline()
            ### FINE WHILE
        file.close()
    except IOError as io_exception:
        print(io_exception)
    except Exception as e:
        print(e)

    # PUNTO 2: lettura file clienti.txt
    try:
        file = open("clienti.txt", "r", encoding="utf-8")

        line = file.readline().strip()

        while line != "":
            codice = int(line)
            nome = file.readline().strip()

            cliente = Cliente(codice, nome)
            clienti.append(cliente)

            line = file.readline().strip()
            while line != "" and line != "\n":
                splitted_line = line.split()
                codice_dipendente = int(splitted_line[0])
                numero_ore = float(splitted_line[1])

                dipendente = map_dipendenti[codice_dipendente]

                servizio = Servizio(dipendente, numero_ore)
                cliente.add_servizio(servizio)
                dipendente.add_servizio(servizio)
                
                line = file.readline()
            
            line = file.readline().strip()
        file.close()
    except IOError as io_exception:
        print(io_exception)
    except Exception as e:
        print(e)

    # PUNTO 3: stampa dipendenti
    print("nome, codice, tipo, ore settimanali, specialità, telefono, medico, app.sett., costo orario")
    for dipendente in dipendenti:
        print(dipendente)

    print("\n\n")

    # PUNTO 4: stampa clienti
    for cliente in clienti:
        print(cliente)


    # PUNTO 5: dipendente con più servizi
    max = 0
    output = None
    for dipendente in dipendenti:
        if len(dipendente.servizi) > max:
            max = len(dipendente.servizi)
            output = dipendente

    if output is not None:
        print("\n\nDipendente che ha svolto il maggior numero di servizi: ", output.nome)
    else:
        print("Error.")


if __name__ == '__main__':
    main()