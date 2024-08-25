class Progetto:
    def __init__(self, codice, tipo, titolo, nome, organizzazione, importo):
        self._codice = codice
        self._tipo = tipo
        self._titolo = titolo
        self._nome = nome
        self._organizzazione = organizzazione
        self._importo = importo

    def get_nome_progetto(self):
        return self._titolo

    def __str__(self):
        return self._tipo + "\t" + self._titolo + "\t" + self._nome + "\t" + self._organizzazione
