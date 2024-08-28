from Veicolo import Veicolo


class Furgone(Veicolo):

    def __init__(self, codice, marca,  modello,  targa,costo, posti,categoria, carico):
        super().__init__(codice, marca,  modello,  targa,costo)

        self._posti = posti
        self._categoria = categoria
        self._carico = carico

    def __str__(self):
        return "commerciale\t"+super().__str__() + "-\t-\t-\t"  +str(self._categoria)+"\t" +str(self._posti) +"\t"+str(self._carico)
