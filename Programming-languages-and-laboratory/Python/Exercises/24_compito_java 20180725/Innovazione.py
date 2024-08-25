from Progetto import Progetto


class Innovazione(Progetto):
    def __init__(self, codice, tipo, titolo, nome, organizzazione, aziende, importo):
        super().__init__(codice, tipo, titolo, nome, organizzazione, importo)
        self._aziende = aziende

    def __str__(self):
        return super().__str__() + "\t-\t-\t" + str(self._aziende) + "\t" + str(self._importo)
