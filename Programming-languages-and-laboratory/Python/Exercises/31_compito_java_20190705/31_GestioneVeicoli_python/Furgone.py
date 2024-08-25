from Veicolo import Veicolo


class Furgone(Veicolo):
    def __init__(self, codice, tipo, targa, modello, marca, rimorchio, posti, vano, costo_giornaliero):
        super().__init__(codice, tipo, targa, modello, marca, costo_giornaliero)
        self._rimorchio = rimorchio
        self._posti = posti
        self._vano = vano

    def __str__(self):
        return "furgone" + "\t" + super().__str__() + "\t-\t-\t-\t" + self._rimorchio + "\t" + str(self._posti) + "\t" + self._vano
