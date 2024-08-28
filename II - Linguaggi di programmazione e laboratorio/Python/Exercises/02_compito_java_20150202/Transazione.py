class Transazione:
    def __init__(self, tipo, identificativo, data):
        self._tipo = tipo
        self._identificativo = identificativo
        self._data = data
        self._libri = []
        self._prezzo_totale = 0.0

    def add_libro(self, l):
        self._libri.append(l)

    def add_costo(self, c):
        self._prezzo_totale += c
        
    def get_prezzo_totale(self):
        return str(self._prezzo_totale)

    def __str__(self):
        return str(self._identificativo) + " " + str(self._data)
