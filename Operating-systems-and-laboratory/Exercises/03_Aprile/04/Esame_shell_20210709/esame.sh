#!/bin/sh
# interfaccia: esame nome anno

if test $# != 2
then
    echo "Errore: uso $0 <nome> <anno>"
    exit 1
fi

case $1 in
    /*) echo "Errore: <nome> deve essere una stringa, non un percorso assoluto"
        exit 2;;
    *) if test -d $1
       then
            echo "Errore: <nome> deve essere una stringa, non un direttorio"
            exit 3
        fi;;
esac

case $2 in
    /*) if test ! -d $2
        then
            echo "Errore: <anno> deve essere un direttorio"
            exit 4
        fi;;
    *) echo "Errore: <anno> deve essre un percorso assoluto, non una stringa"
       exit 5;;
esac

export FILELOG=$HOME/fiumilog.txt
> $FILELOG

export LIVELLOMIN=/tmp/livellomin.txt
echo 10000 > $LIVELLOMIN

export FIUMELIVELLOMIN=/tmp/fiumelivellomin.txt
> $FIUMELIVELLOMIN

export PATH=$PATH:`pwd`

esame_ric.sh $1 $2

echo "Giorno con livello idrometrico più basso: `cat $FIUMELIVELLOMIN` (`cat $LIVELLOMIN` metri)"

rm -f $FIUMELIVELLOMIN
rm -f $LIVELLOMIN