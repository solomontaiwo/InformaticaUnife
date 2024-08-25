class Automobile:
    def __init__(self, tipo, modello, produttore, peso, codice_identificativo):
        self._tipo = tipo
        self._modello = modello
        self._produttore = produttore
        self._peso = peso
        self._codice_identificativo = codice_identificativo
        
    def get_produttore(self):
        return self._produttore

    def __str__(self):
        return str(self._codice_identificativo) + " " + self._produttore + " " + self._modello
