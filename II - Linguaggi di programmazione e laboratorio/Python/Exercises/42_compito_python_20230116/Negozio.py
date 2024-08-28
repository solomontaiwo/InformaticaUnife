class Negozio:
    def __init__(self, codice, nome, indirizzo):
        self._codice = codice
        self._nome = nome
        self._indirizzo = indirizzo
        self._articoli_in_magazzino = []
        self._totale_art_magazzino = 0
        self._valore_totale_magazzino = 0

    def add_articolo_magazzino(self, a):
        self._articoli_in_magazzino.append(a)

    def somma_articolo_in_magazzino(self, art):
        self._totale_art_magazzino += art

    def get_codice_negozio(self):
        return self._codice

    def add_valore_totale(self, vt):
        self._valore_totale_magazzino += vt

    def get_valore_totale(self):
        return self._valore_totale_magazzino

    def __str__(self):
        return str(self._codice) + "\t" + self._nome + "\t" + self._indirizzo + "\t" + str(self._totale_art_magazzino) + "\t" + str([str(m) for m in self._articoli_in_magazzino])
