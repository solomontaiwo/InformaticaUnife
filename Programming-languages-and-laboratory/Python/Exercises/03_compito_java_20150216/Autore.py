class Autore:
    def __init__(self, nome):
        self._nome = nome
        self._prodotti = 1

    def incrementa_prodotti(self):
        self._prodotti += 1

    def get_nome_autore(self):
        return self._nome

    def __str__(self):
        return self._nome + " " + str(self._prodotti)
