class Filiale:
    def __init__(self, nome, codice, indirizzo):
        self._nome = nome
        self._codice = codice
        self._indirizzo = indirizzo
        self._clienti_attuali = []
        self._clienti_passati = []

    def add_cliente_attuale(self, at):
        self._clienti_attuali.append(at)

    def add_cliente_passato(self, pas):
        self._clienti_passati.append(pas)

    def get_clienti_attuali(self):
        return len(self._clienti_attuali)

    def get_nome_filiale(self):
        return self._nome

    def get_clienti_totali(self):
        return len()

    def __str__(self):
        return self._nome + "\t" + str(len(self._clienti_attuali)) + "\t" + str((len(self._clienti_attuali) + len(self._clienti_passati)))
