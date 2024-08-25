from Dipendente import Dipendente


class Nutrizionista(Dipendente):
    def __init__(self, codice, tipo, nome, costo_orario, telefono, medico, app_sett):
        super().__init__(codice, tipo, nome, costo_orario)
        self._telefono = telefono
        self._medico = medico
        self._app_sett = app_sett

    def __str__(self):
        return "nut" + "\t" + super().__str__() + "\t-\t-\t-\t" + str(self._telefono) + "\t" + str(self._medico) + "\t" + str(self._app_sett) + "\t" + str(self._costo_orario)
