from Operatore import Operatore


class Medico(Operatore):
    def __init__(self, codice, tipo, nome, costo_visita, specialita, n_visite_mese_precedente, ambulatorio):
        super().__init__(codice, tipo, nome, costo_visita)
        self._specialita = specialita
        self._n_visite_mese_precedente = n_visite_mese_precedente
        self._ambulatorio = ambulatorio

    def __str__(self):
        return super().__str__() + "\t" + self._specialita + "\t" + str(self._n_visite_mese_precedente) + "\t" + self._ambulatorio + "\t-\t-\t-\tmedico"
