class Partecipazione:
    def __init__(self, codice_progetto, impegno_orario):
        self._codice_progetto = codice_progetto
        self._impegno_orario = impegno_orario

    def get_impegno_orario(self):
        return self._impegno_orario

    def get_codice_progetto(self):
        return self._codice_progetto

    def __str__(self):
        return "(" + str(self._codice_progetto) + ", " + str(self._impegno_orario) + ")"
