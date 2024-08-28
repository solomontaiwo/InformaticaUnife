from Acquisto import Acquisto


class Privato(Acquisto):
    def __init__(self, tipo, codice, giorno, mese, anno, nome_cognome, indirizzo, codice_fiscale):
        super().__init__(tipo, codice, giorno, mese, anno)
        self._nome_cognome = nome_cognome
        self._indirizzo = indirizzo
        self._codice_fiscale = codice_fiscale

    def __str__(self):
        return super().__str__() + "\t" + self._indirizzo + "\t" + self._nome_cognome + "\t" + self._codice_fiscale + "\t-\t-\t-"
