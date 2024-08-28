from Cliente import Cliente


class Aziendale(Cliente):
    def __init__(self, tipo, codice, ragione_sociale, portata_massima, tipo_contratto, indirizzo):
        super().__init__(tipo, codice, tipo_contratto, indirizzo)
        self._ragione_sociale = ragione_sociale
        self._portata_massima = portata_massima
        
    def get_nome(self):
        return self._ragione_sociale

    def __str__(self):
        return super().__str__() + "\t-\t" + self._ragione_sociale + "\t" + self._indirizzo + "\t" + self._tipo_contratto + "\t" + str(self._portata_massima)
