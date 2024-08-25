from Progetto import Progetto


class Ricerca(Progetto):
    def __init__(self, codice, tipo, titolo, nome, organizzazione, codice_argomento, numero_partner, importo):
        super().__init__(codice, tipo, titolo, nome, organizzazione, importo)
        self._codice_argomento = codice_argomento
        self._numero_partner = numero_partner

    def __str__(self):
        return super().__str__() + "\t" + self._codice_argomento + "\t" + str(self._numero_partner) + "\t-\t" + str(self._importo)
