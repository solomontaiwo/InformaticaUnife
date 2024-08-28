#!/bin/bash

if test $# != 2
then
    echo "Errore: numero argomenti"
    exit 1
fi

nome_corso=$1
shift

case $1 in
    /*) if test ! -d $1
        then
            echo "Errore: <anno> non è un direttorio"
            exit 2
        fi
        if test ! -x $1
        then
            echo "Non ho i permessi per eseguire in $1"
            exit 3
        fi;;
    *) echo "Errore: <anno> non è un percorso assoluto"
    exit 4;;
esac

cartella_anno=$1
shift

PATH=$PATH:`pwd`
export PATH

FILELOG="$HOME"/fiumilog.txt
export FILELOG

LIVELLOMINIMO=/tmp/livello_minimo.txt
export LIVELLOMINIMO
echo 100000 > "$LIVELLOMINIMO"

GIORNOMINIMO=/tmp/giorno_minimo.txt
export GIORNOMINIMO
> "$GIORNOMINIMO"

if test -e "$FILELOG"
then
    > "$FILELOG"
fi

sh esame_ric.sh "$nome_corso" "$cartella_anno"

echo "Il minimo è stato riscontrato il giorno: `cat $GIORNOMINIMO`"
echo "Livello minimo riscontrato: `cat $LIVELLOMINIMO` metri"

rm -f "$LIVELLOMINIMO"
rm -f "$GIORNOMINIMO"