#!/bin/bash
# interfaccia: esame nome anno

if test $# != 2
then
    echo "Errore: numero argomenti"
    echo "Uso $0 <nome> <anno>"
    exit 1
fi

nome="$1"

case $2 in
    /*) if test ! -d "$2"
        then
            echo "Errore: <anno> non è un direttorio"
            exit 2
        fi;;
    *) echo "Errore: <anno> non è un percorso assoluto"
       exit 3;;
esac

anno="$2"

export PATH=$PATH:`pwd`

export FILELOG=$HOME/fiumilog.txt
touch $FILELOG

export GIORNOMIN=/tmp/giorno_min.txt
touch $GIORNOMIN

export LIVELLOMIN=/tmp/livello_min.txt
echo 10000 > $LIVELLOMIN

if test -e "$FILELOG"
then
    > "$FILELOG"
fi

esame_ric.sh "$nome" "$anno"

echo "Giorno con rilevazione livelloidrometrico minimo: `cat $GIORNOMIN`, `cat "$LIVELLOMIN"` metri"

rm -f $GIORNOMIN
rm -f $LIVELLOMIN
rm -f $FILELOG