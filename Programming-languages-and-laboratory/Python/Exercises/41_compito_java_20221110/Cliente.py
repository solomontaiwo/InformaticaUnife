class Cliente:
    def __init__(self, codice_cliente, nome_cliente):
        self._codice_cliente = codice_cliente
        self._nome_cliente = nome_cliente
        self._servizi = []
        self._codice_dip_max_servizio = 0
        self._ore_servizio_max = 0.0

    def add_servizio(self, s):
        self._servizi.append(s)

    def confronta_ore_servizio(self, o, d):
        if float(o) > self._ore_servizio_max:
            self._ore_servizio_max = o
            self._codice_dip_max_servizio = d

    def __str__(self):
        return str(self._codice_cliente) + "\t" + self._nome_cliente + "\t" + str(self._codice_dip_max_servizio) + "\t[" + str([str(s) for s in self._servizi]) + "]"
