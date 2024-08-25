class Prodotto:
    def __init__(self, tipo, codice, modello, produttore, giorno, mese, anno, prezzo):
        self._tipo = tipo
        self._codice = codice
        self._modello = modello
        self._produttore = produttore
        self._giorno = giorno
        self._mese = mese
        self._anno = anno
        self._prezzo = prezzo
        self._pezzi = []
        self._numero_totale_pezzi = 0

    def add_pezzo(self, p):
        self._pezzi.append(p)
        self._numero_totale_pezzi += p

    def get_numero_totale_pezzi(self):
        return self._numero_totale_pezzi

    def stampa_pezzi(self):
        print("Totale pezzi " + self._produttore + " " + self._modello +
              ": " + str(self._numero_totale_pezzi))

    def get_produttore(self):
        return self._produttore

    def get_modello(self):
        return self._modello

    def get_numero_medio_pezzi_per_magazzino(self):
        return self._numero_totale_pezzi / len(self._pezzi)

    def __str__(self):
        return str(self._codice) + "\t" + self._modello + "\t" + self._produttore + "\t" + str(self._giorno) + "-" + str(self._mese) + "-" + str(self._anno) + "\t" + str(self._prezzo)
