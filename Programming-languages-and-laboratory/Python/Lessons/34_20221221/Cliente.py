class Cliente:
    def __init__(self, codice_cliente, nome_cliente):
        self._codice_cliente = codice_cliente
        self._nome_cliente = nome_cliente
        self._servizi = []
        self._costo_totale_servizi = 0

    def add_servizio(self, serv):
        self._servizi.append(serv)

    def add_costo(self, cos, ore):
        costo = cos * ore
        self._costo_totale_servizi += costo

    def __str__(self):
        return str(self._codice_cliente) + " " + self._nome_cliente + " " + str(self._costo_totale_servizi)