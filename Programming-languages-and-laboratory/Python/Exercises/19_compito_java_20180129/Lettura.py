class Lettura:
    def __init__(self, codice_cliente, metri_cubi_consumati):
        self._codice_cliente = codice_cliente
        self._metri_cubi_consumati = metri_cubi_consumati
        
    def get_codice_cliente(self):
        return int(self._codice_cliente)

    def get_lettura(self):
        return float(self._metri_cubi_consumati)
