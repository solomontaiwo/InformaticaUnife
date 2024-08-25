#!/bin/bash
# interfaccia: esame.sh nome anno

if test $# != 2
then
    echo "Errore: numero argomenti"
    echo "Uso: $0 <nome> <anno>"
    exit 1
fi

case $1 in
    /*) echo "Errore: <nome> deve essere una stringa, non un percorso assoluto"
        exit 2;;
    *);;
esac

case $2 in
    /*) if test ! -d $2
        then
            echo "Errore: <anno> deve essere un direttorio"
            exit 3
        fi;;
    *) echo "Errore: <anno> deve essere un percorso assoluto"
       exit 4;;
esac 

export PATH=$PATH:`pwd`

export FILELOG=$HOME/fiumilog.txt
> "$FILELOG"

export LIVELLOMIN=/tmp/livellomin.txt
echo 10000 > "$LIVELLOMIN"

export GIORNOMIN=/tmp/giornomin.txt
echo "Vuoto" > $GIORNOMIN

esame_ric.sh $1 $2

echo "Giorno con livello idrometrico più basso: `cat $GIORNOMIN` (`cat "$LIVELLOMIN"` metri)"

rm -f $LIVELLOMIN
rm -f $GIORNOMIN

