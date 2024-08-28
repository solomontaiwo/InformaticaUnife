from Dipendente import Dipendente


class Nutrizionista(Dipendente):
    def __init__(self, codice, tipo, nome, telefono, medico, appuntamenti_settimanali, costo_orario):
        super().__init__(codice, tipo, nome, costo_orario)
        self._telefono = telefono
        self._medico = medico
        self._appuntamenti_settimanali = appuntamenti_settimanali

    def __str__(self):
        return self._nome + "\t" + str(self._codice) + "\t" + self._tipo + "\t-\t-\t" + str(self._telefono) + "\t" + str(self._medico) + "\t" + str(self._appuntamenti_settimanali) + "\t" + str(self._costo_orario)
