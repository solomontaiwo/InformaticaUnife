class Partecipazione:
    def __init__(self, codice, spesa, cognome):
        self._codice = codice
        self._spesa = spesa
        self._cognome = cognome

    def __str__(self):
        return self._cognome + " " + str(self._spesa)
