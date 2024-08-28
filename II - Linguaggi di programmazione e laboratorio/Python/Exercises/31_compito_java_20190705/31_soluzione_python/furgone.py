from veicolo import Veicolo

class Furgone(Veicolo):
    rimorchio: bool
    numero_posti: int
    vano_carico: bool

    def __init__(self, codice: int, tipo: str, targa: str, marca: str, modello: str, costo_giornaliero: float, rimorchio: bool, numero_posti: int, vano_carico: bool):
        super().__init__(codice, tipo, targa, marca, modello, costo_giornaliero)
        self.rimorchio = rimorchio
        self.numero_posti = numero_posti
        self.vano_carico = vano_carico
        
    def __str__(self):
        #rimorchio, numero di posti, vano di carico
        return super().__str__() + ", -, -, -, " + str(self.rimorchio) + ", " + str(self.numero_posti) + ", " + str(self.vano_carico)