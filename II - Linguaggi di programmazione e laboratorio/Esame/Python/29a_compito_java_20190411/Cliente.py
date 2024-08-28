class Cliente:
    def __init__(self, codice_cliente, nome_cliente):
        self._codice_cliente = codice_cliente
        self._nome_cliente = nome_cliente
        self._servizi = []
        self._costo_servizi = 0

    def add_servizio(self, serv, costo_ser):
        self._servizi.append(serv)
        self._costo_servizi += costo_ser

    def __str__(self):
        return str(self._codice_cliente) + " " + self._nome_cliente + " " + str(self._costo_servizi)
