from veicolo import Veicolo

class Auto(Veicolo):
    capienza_bagaglio: float #Python non ha il tipo double
    cilindrata: int
    categoria: str

    def __init__(self, codice: int, tipo: str, targa: str, marca: str, modello: str, costo_giornaliero: float, capienza_bagaglio: float, cilindrata: int, categoria: str):
        super().__init__(codice, tipo, targa, marca, modello, costo_giornaliero)
        self.capienza_bagaglio = capienza_bagaglio
        self.cilindrata = cilindrata
        self.categoria = categoria

    def __str__(self):
        #bagagliaio, cilindrata, categoria
        return super().__str__() + ", " + str(self.capienza_bagaglio) + ", " + str(self.cilindrata) + ", " + self.categoria + ", -, -, -"