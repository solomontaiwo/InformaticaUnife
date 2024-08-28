class Visita:
    def __init__(self, codice_operatore, n_sedute):
        self._codice_operatore = codice_operatore
        self._n_sedute = n_sedute

    def __str__(self):
        return "(" + str(self._codice_operatore) + ", " + str(self._n_sedute) + ")"
