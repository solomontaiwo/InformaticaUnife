class Cliente:
    def __init__(self, tipo, codice, indirizzo, giorno, mese, anno):
        self._tipo = tipo
        self._codice = codice
        self._indirizzo = indirizzo
        self._giorno = giorno
        self._mese = mese
        self._anno = anno
        self._premi_pagati = []
        self._totale_premi_pagati = 0

    def add_premio(self, p):
        self._premi_pagati.append(p)
        self._totale_premi_pagati += p
        
    def get_premio(self):
        return self._totale_premi_pagati

    def __str__(self):
        return str(self._codice)
