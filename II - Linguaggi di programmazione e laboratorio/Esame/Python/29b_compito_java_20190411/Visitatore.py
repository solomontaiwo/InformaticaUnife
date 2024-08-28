class Visitatore:
    def __init__(self, codice_visitatore, nome_visitatore):
        self._codice_visitatore = codice_visitatore
        self._nome_visitatore = nome_visitatore
        self._servizi = []

    def add_servizio(self, s):
        self._servizi.append(s)

    def __str__(self):
        return str(self._codice_visitatore) + " " + self._nome_visitatore + " " + str([str(s) for s in self._servizi])
