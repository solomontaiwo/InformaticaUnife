from Acquisto import Acquisto


class Professionista(Acquisto):
    def __init__(self, tipo, codice, giorno, mese, anno, ragione_sociale, partita_iva, codice_cliente):
        super().__init__(tipo, codice, giorno, mese, anno)
        self._ragione_sociale = ragione_sociale
        self._partita_iva = partita_iva
        self._codice_cliente = codice_cliente

    def __str__(self):
        return super().__str__() + "\t-\t-\t-\t" + self._ragione_sociale + "\t" + str(self._partita_iva) + "\t" + str(self._codice_cliente)
