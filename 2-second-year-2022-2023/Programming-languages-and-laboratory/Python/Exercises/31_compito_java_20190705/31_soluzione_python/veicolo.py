from noleggio import Noleggio

class Veicolo:
    codice: int
    tipo: str
    targa: str
    marca: str
    modello: str
    costo_giornaliero: float # Python non ha il tipo double

    noleggi: list

    def __init__(self, codice: int, tipo: str, targa: str, marca: str, modello: str, costo_giornaliero: float):
        self.codice = codice
        self.tipo = tipo
        self.marca = marca
        self.modello = modello
        self.targa = targa
        self.costo_giornaliero = costo_giornaliero

        self.noleggi = []

    def add_noleggio(self, noleggio: Noleggio):
        self.noleggi.append(noleggio)

    def __str__(self):
        tipo = self.tipo
        if tipo == "auto":
            tipo = "automobile"
        #tipo, targa, codice, modello, marca, costo giornaliero
        return tipo + ", " + self.targa + ", " + str(self.codice) + ", " + self.modello + ", " + self.marca + ", " + str(self.costo_giornaliero)
    