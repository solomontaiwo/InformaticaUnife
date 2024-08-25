from Transazione import Transazione


class Fisica(Transazione):
    def __init__(self, tipo, identificativo, data, citta):
        super().__init__(tipo, identificativo, data)
        self._citta = citta

    def __str__(self):
        return super().__str__() + " " + self._citta
