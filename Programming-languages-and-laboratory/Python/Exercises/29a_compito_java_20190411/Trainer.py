from Dipendente import Dipendente


class Trainer(Dipendente):
    def __init__(self, codice, tipo, nome, ore_settimanali, costo, specialita):
        super().__init__(codice, tipo, nome, costo)
        self._ore_settimanali = ore_settimanali
        self._specialita = specialita

    def __str__(self):
        return super().__str__() + "\ttrainer\t" + str(self._ore_settimanali) + "\t" + self._specialita + "\t-\t-\t-\t" +\
            str(self._costo)
