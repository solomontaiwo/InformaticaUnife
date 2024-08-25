class Noleggio:
    codice: int
    numero_giorni: int
    costo_giornaliero: float

    def __init__(self, codice: int, numero_giorni: int, costo_giornaliero: float):
        self.codice = codice
        self.numero_giorni = numero_giorni
        self.costo_giornaliero = costo_giornaliero