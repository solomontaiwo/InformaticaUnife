from Dipendente import Dipendente


class Trainer(Dipendente):
    def __init__(self, codice, tipo, nome, ore_settimanali, costo_orario, specialita):
        super().__init__(codice, tipo, nome, costo_orario)
        self._ore_settimanali = ore_settimanali
        self._specialita = specialita

    def __str__(self):
        return self._nome + "\t" + str(self._codice) + "\t" + self._tipo + "\t" + str(self._ore_settimanali) + "\t" + self._specialita + "\t-\t-\t-\t" + str(self._costo_orario)
