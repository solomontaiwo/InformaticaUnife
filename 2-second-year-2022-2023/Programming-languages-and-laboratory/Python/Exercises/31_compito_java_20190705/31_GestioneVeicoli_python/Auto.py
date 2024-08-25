from Veicolo import Veicolo


class Auto(Veicolo):
    def __init__(self, codice, tipo, targa, modello, marca, bagagliaio, cilindrata, categoria, costo_giornaliero):
        super().__init__(codice, tipo, targa, modello, marca, costo_giornaliero)
        self._bagagliaio = bagagliaio
        self._cilindrata = cilindrata
        self._categoria = categoria

    def __str__(self):
        return "automobile" + "\t" + super().__str__() + "\t" + str(self._bagagliaio) + "\t" + str(self._cilindrata) + "\t" + self._categoria + "\t-\t-\t-"
