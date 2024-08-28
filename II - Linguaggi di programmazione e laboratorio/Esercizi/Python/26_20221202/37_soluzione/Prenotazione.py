class Prenotazione:
    def __init__(self, codice_campo, orario):
        self._codice_campo = codice_campo
        self._orario = orario
    

    def __str__(self):
        return "("+str(self._codice_campo)+","+str(self._orario)+")"
