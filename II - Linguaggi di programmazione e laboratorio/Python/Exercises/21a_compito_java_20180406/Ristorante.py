class Ristorante:
    def __init__(self, codice, tipo, nome):
        self._codice = codice
        self._tipo = tipo
        self._nome = nome
        self._menu = []
        self._prezzo_totale = 0.0

    def add_menu(self, m):
        self._menu.append(m)

    def add_prezzo_totale(self, p):
        self._prezzo_totale += p

    def get_prezzo_medio(self):
        return float(self._prezzo_totale) / int(len(self._menu))

    def get_nome_ristorante(self):
        return self._nome

    def stampa_menu(self):
        return self._nome + "\n\t" + str([str(m) for m in self._menu])

    def __str__(self):
        return self._nome + "\t" + str(self._codice) + "\t" + self._tipo
