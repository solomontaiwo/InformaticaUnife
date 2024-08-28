class Acquisto:
    def __init__(self, tipo, codice, giorno, mese, anno):
        self._tipo = tipo
        self._codice = codice
        self._giorno = giorno
        self._mese = mese
        self._anno = anno
        self._importo_totale_transazione = 0.0

    def add_prodotto(self, p):
        self._prodotti.append(p)

    def add_importo_transazione(self, i):
        self._importo_totale_transazione += i

    def get_importo_totale_transazione(self):
        return self._importo_totale_transazione

    def get_codice_transazione(self):
        return self._codice

    def __str__(self):
        return str(self._codice) + "\t" + str(self._giorno) + "-" + str(self._mese) + "-" + str(self._anno)
