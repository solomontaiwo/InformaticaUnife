#!/bin/bash
# esame nome anno

if test $# != 2
then
    echo "Errore: numero argomenti. Uso $0 <nome> <anno>"
    exit 1
fi

case $2 in
    /*) if test ! -d "$2"
        then
            echo "Errore: <anno> non è un direttorio"
            exit 2
        fi;;
    *) echo "Errore: <anno> non è un percorso assoluto"
       exit 3;;
esac

export FILELOG="$HOME/fiumilog.txt"
> "$FILELOG"

export PATH=$PATH:`pwd`

if test -e "$FILELOG"
then
    > $FILELOG
fi

export MINLIVELLO=/tmp/min_livello.txt
echo 0 > "$MINLIVELLO"

export GIORNOMINLIVELLO=/tmp/giorno_min_livello.txt
> "$GIORNOMINLIVELLO"

esame_ric.sh "$1" "$2"

echo "Giorno livello idrometrico più basso: `cat "$GIORNOMINLIVELLO"`"

rm -f "$MINLIVELLO"
rm -f "$GIORNOMINLIVELLO"
rm -f "$FILELOG"