from Automobile import Automobile


class Berlina(Automobile):
    def __init__(self, tipo, modello, produttore, bagagliaio, peso, codice_identificativo):
        super().__init__(tipo, modello, produttore, peso, codice_identificativo)
        self._bagagliaio = bagagliaio

    def __str__(self):
        return super().__str__() + " " + str(self._bagagliaio) + " -"
