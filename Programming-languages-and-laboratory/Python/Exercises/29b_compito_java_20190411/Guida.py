from Impiegato import Impiegato


class Guida(Impiegato):
    def __init__(self, codice, tipo, nome, telefono, inglese, app_settimanali, costo):
        super().__init__(codice, tipo, nome, costo)
        self._app_settimanali = app_settimanali
        self._telefono = telefono
        self._inglese = inglese

    def __str__(self):
        return super().__str__() + "\tguida\t-\t-\t" + str(self._telefono) + "\t" + str(self._inglese) + "\t" + \
            str(self._app_settimanali) + "\t" + str(self._costo)
