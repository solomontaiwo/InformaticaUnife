from Operatore import Operatore


class Terapista(Operatore):
    def __init__(self, codice, tipo, nome, costo_visita, terapia, studio, n_sedute_terapia):
        super().__init__(codice, tipo, nome, costo_visita)
        self._terapia = terapia
        self._studio = studio
        self._n_sedute_terapia = n_sedute_terapia

    def __str__(self):
        return super().__str__() + "\t-\t-\t-\t" + self._terapia + "\t" + self._studio + "\t" + str(self._n_sedute_terapia) + "\tterapista"
