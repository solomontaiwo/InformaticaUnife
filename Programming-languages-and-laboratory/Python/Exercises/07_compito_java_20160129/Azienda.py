from Cliente import Cliente


class Azienda(Cliente):
    def __init__(self, tipo, codice, indirizzo, giorno, mese, anno, ragione_sociale, fatturato):
        super().__init__(tipo, codice, indirizzo, giorno, mese, anno)
        self._ragione_sociale = ragione_sociale
        self._fatturato = fatturato
        
    def get_nome(self):
        return self._ragione_sociale

    def __str__(self):
        return "Azienda\t" + super().__str__() + "\t-\t" + self._ragione_sociale + "\t" + self._indirizzo + "\t" + str(self._giorno) + "-" + str(self._mese) + "-" + str(self._anno) + "\t" + str(self._fatturato)
