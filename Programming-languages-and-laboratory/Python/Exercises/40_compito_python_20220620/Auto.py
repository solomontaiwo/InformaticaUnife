from Veicolo import Veicolo


class Auto(Veicolo):

    def __init__(self, codice, marca, modello, targa, costo, cilindrata, bagagliaio):
        super().__init__(codice, marca, modello, targa, costo)

        self._cilindrata = cilindrata
        self._bagagliaio = bagagliaio

    def __str__(self):
        return "automobile\t" + super().__str__() + str(self._cilindrata) + "\t" + str(self._bagagliaio) + "\t-\t-\t-"
