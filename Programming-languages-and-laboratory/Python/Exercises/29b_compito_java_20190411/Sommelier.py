from Impiegato import Impiegato


class Sommelier(Impiegato):
    def __init__(self, codice, tipo, nome, ore, costo, specialita):
        super().__init__(codice, tipo, nome, costo)
        self._ore = ore
        self._specialita = specialita

    def __str__(self):
        return super().__str__() + "\tsommelier\t" + str(self._ore) + "\t" + self._specialita + "\t-\t-\t-\t" + \
            str(self._costo)
