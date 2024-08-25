from Transazione import Transazione


class Online(Transazione):
    def __init__(self, tipo, identificativo, data, indirizzo_ip):
        super().__init__(tipo, identificativo, data)
        self._indirizzo_ip = indirizzo_ip

    def __str__(self):
        return super().__str__() + " - " + str(self._indirizzo_ip)
