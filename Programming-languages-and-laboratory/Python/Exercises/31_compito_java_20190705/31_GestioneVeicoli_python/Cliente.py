class Cliente:
    def __init__(self, nome_cognome):
        self._nome_cognome = nome_cognome
        self._noleggi = []
        self._costo_max = 0.0

    def add_noleggio(self, n):
        self._noleggi.append(n)

    def confronta_costo(self, c):
        if c > self._costo_max:
            self._costo_max = c

    def __str__(self):
        return self._nome_cognome + " " + str(self._costo_max) + " " + str(len(self._noleggi))
