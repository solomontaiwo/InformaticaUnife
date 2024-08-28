class Libretto:
    def __init__(self, codice_corso, voto):
        self._codice_corso = codice_corso
        self._voto = voto

    def __str__(self):
        return str(self._codice_corso) + ", " + self._voto
        