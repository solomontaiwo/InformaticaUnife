from Veicolo import Veicolo


class Auto(Veicolo):
    def __init__(self, codice, tipo, targa, cilindrata, diesel, modello, marca):
        super().__init__(codice, tipo, targa, modello, marca)
        self._cilindrata = cilindrata
        self._diesel = diesel
        self._costo = 10
        self._costo_totale = 0

    def add_costo_totale(self, c):
        self._costo_totale += c

    def get_costo(self):
        return self._costo

    def get_costo_totale(self):
        return self._costo_totale

    def __str__(self):
        return "automobile\t" + super().__str__() + "\t" + str(self._cilindrata) + "\t" + str(self._diesel) + "\t-\t-" 
