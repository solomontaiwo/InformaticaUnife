class Cliente:
    def __init__(self, nome):
        self._nome = nome
        self._noleggi = []

    def addNoleggio(self, i):
        self._noleggi.append(i)

    def _CostoTot(self):
        tot = 0.0
        for i in self._noleggi:
            tot += i.getCosto()
        return tot

    def __str__(self):
        return self._nome + "\t" + str(self._CostoTot()) + "\t" + str(len(self._noleggi)) + '\t[' + ' '.join(
            [str(i) for i in self._noleggi]) + ']'
