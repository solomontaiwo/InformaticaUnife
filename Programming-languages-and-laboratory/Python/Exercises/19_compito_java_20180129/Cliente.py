class Cliente:
    def __init__(self, tipo, codice, tipo_contratto, indirizzo):
        self._tipo = tipo
        self._codice = codice
        self._tipo_contratto = tipo_contratto
        self._indirizzo = indirizzo
        self._letture_metri_cubi = 0.0
        
    def add_metri_cubi(self, m):
        self._letture_metri_cubi += m
    
    def get_codice(self):
        return self._codice
    
    def get_metri_cubi(self):
        return float(self._letture_metri_cubi)
    
    def get_tipo_contratto(self):
        return self._tipo_contratto

    def __str__(self):
        return str(self._codice) + "\t" + self._tipo
