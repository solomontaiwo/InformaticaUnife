class Partita:
    def __init__(self, tipo, data, ora, risultato, vinta):
        self._tipo = tipo
        self._data = data
        self._ora = ora
        self._risultato = risultato
        self._vinta = vinta
        
    def get_tipo(self):
        return self._tipo

    def __str__(self):
        return self._data + "\t" + str(self._ora) + "\t" + self._risultato
