from Dipendente import Dipendente


class Trainer(Dipendente):
    def __init__(self, codice, tipo, nome, laurea, specialita, ore_settimanali, costo_orario):
        super().__init__(codice, tipo, nome, costo_orario)
        self._laurea = laurea
        self._specialita = specialita
        self._ore_settimanali = ore_settimanali

    def __str__(self):
        return "tra" + "\t" + super().__str__() + "\t" + str(self._laurea) + "\t" + self._specialita + "\t" + str(self._ore_settimanali) + "\t-\t-\t-\t" + str(self._costo_orario)
