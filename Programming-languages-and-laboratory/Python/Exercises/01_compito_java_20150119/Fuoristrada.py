from Automobile import Automobile


class Fuoristrada(Automobile):
    def __init__(self, tipo, modello, produttore, marce, peso, codice_identificativo):
        super().__init__(tipo, modello, produttore, peso, codice_identificativo)
        self._marce = marce

    def __str__(self):
        return super().__str__() + " - " + str(self._marce)
