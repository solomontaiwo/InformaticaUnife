from Cliente import Cliente


class Privato(Cliente):
    def __init__(self, tipo, codice, indirizzo, giorno, mese, anno, nome):
        super().__init__(tipo, codice, indirizzo, giorno, mese, anno)
        self._nome = nome
        
    def get_nome(self):
        return self._nome

    def __str__(self):
        return "Privato\t" + super().__str__() + "\t" + self._nome + "\t-\t" + self._indirizzo + "\t" + str(self._giorno) + "-" + str(self._mese) + "-" + str(self._anno) + "\t-"
