from dipendente import Dipendente

class Servizio:
    dipendente: Dipendente
    numero_ore: float

    def __init__(self, dipendente: Dipendente, numero_ore: float):
        self.dipendente = dipendente
        self.numero_ore = numero_ore

    def get_costo(self) -> float:
        return self.numero_ore * self.dipendente.costo_orario