from Dipendente import Dipendente


class Nutrizionista(Dipendente):
    def __init__(self, codice, tipo, nome, telefono, medico, app_settimanali, costo):
        super().__init__(codice, tipo, nome, costo)
        self._telefono = telefono
        self._app_settimanali = app_settimanali
        self._medico = medico

    def __str__(self):
        return super().__str__() + "\tnutri" + "\t-\t-\t" + str(self._telefono) + "\t" + str(self._medico) + "\t" +\
            str(self._app_settimanali) + "\t" + str(self._costo)
