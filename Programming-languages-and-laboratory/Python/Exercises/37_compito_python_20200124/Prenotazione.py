class Prenotazione:
    def __init__(self, codice_campo, ora_inizio):
        self._codice_campo = codice_campo
        self._ora_inizio = ora_inizio

    def __str__(self):
        return "(" + str(self._codice_campo) + ", " + str(self._ora_inizio) + ")"
