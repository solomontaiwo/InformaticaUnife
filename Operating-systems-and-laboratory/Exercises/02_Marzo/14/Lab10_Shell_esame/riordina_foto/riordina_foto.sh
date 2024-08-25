#!/bin/bash
# riordina_foto dir_sorgente dir_destinazione

if test $# != 2
then
    echo "Errore argomenti. Uso $0 <dir_sorgente> <dir_destinazione>"
    exit 1
fi

case $1 in
    /*) echo "Errore: <dir_sorgente> è un percorso assoluto"
        exit 2;;
    *) if test ! -d $1
       then
            echo "Errore: <dir_sorgente> non è una directory"
            exit 3
        fi;;
esac

case $2 in
    /*) echo "Errore: <dir_destinazione> è un percorso assoluto"
        exit 4;;
    *) if test ! -d $2
       then
            echo "Errore: <dir_destinazione> non è una directory"
            exit 5
        fi;;
esac

if ! test -d $2/duplicati
then
	mkdir $2/duplicati
fi

export PATH=$PATH:`pwd`

> /tmp/spostati

riordina_foto_ric.sh $1 `pwd`/$2

echo "Ho spostato `wc -l /tmp/spostati` file."
rm -f /tmp/spostati