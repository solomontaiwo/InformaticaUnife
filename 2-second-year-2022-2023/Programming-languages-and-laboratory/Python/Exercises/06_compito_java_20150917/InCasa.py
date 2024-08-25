from Partita import Partita


class InCasa(Partita):
    def __init__(self, tipo, nome_palazzetto, data, ora, risultato, vinta):
        super().__init__(tipo, data, ora, risultato, vinta)
        self._nome_palazzetto = nome_palazzetto

    def __str__(self):
        return self._nome_palazzetto + "\t-\t" + super().__str__()
