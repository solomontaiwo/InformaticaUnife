from Veicolo import Veicolo


class Furgone(Veicolo):
    def __init__(self, codice, tipo, targa, categoria, posti, modello, marca):
        super().__init__(codice, tipo, targa, modello, marca)
        self._categoria = categoria
        self._posti = posti
        self._costo = 15
        self._costo_totale = 0

    def add_costo_totale(self, c):
        self._costo_totale += c

    def get_costo(self):
        return self._costo

    def get_costo_totale(self):
        return self._costo_totale

    def __str__(self):
        return "comerciale\t" + super().__str__() + "\t-\t-\t" + self._categoria + "\t" + str(self._posti)
