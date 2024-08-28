class Cliente:
    def __init__(self, nome_cognome):
        self._nome_cognome = nome_cognome
        self._posteggi = []
        self._costo_totale = 0

    def add_costo_totale(self, c):
        self._costo_totale += c

    def add_posteggi(self, lp):
        self._posteggi.append(lp)

    def __str__(self):
        return self._nome_cognome + " " + str(self._costo_totale)
