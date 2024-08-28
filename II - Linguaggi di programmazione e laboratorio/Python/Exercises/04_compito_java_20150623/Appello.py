class Appello:
    def __init__(self, tipo, codice, docente, corso, giorno, mese, anno, ora):
        self._tipo = tipo
        self._codice = codice
        self._docente = docente
        self._corso = corso
        self._giorno = giorno
        self._mese = mese
        self._anno = anno
        self._ora = ora

    def get_ora_inizio(self):
        return self._ora

    def __str__(self):
        return str(self._codice) + "\t" + self._docente + "\t" + self._corso + "\t" + str(self._giorno) + "-" + str(self._mese) + "-" + str(self._anno) + "\t" + str(self._ora)
