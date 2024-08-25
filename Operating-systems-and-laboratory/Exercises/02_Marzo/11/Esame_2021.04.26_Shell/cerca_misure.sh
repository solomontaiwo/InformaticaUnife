#!/bin/bash
# interfaccia: cerca_misure dir header

if test $# != 2
then
    echo "Errore argomenti. Uso $0 <dir> <header>"
    exit 1
fi

case $1 in
    /*) if test ! -d $1
        then
            echo "Errore: <dir> non è un direttorio"
            exit 2
        fi;;
    *) echo "Errore: <dir> non è un percorso assoluto"
       exit 3;;
esac

dir=$1
header=$2

export PATH=$PATH:`pwd`

export MISURE=$HOME/misure.txt
> $MISURE

if test -e "$MISURE"
then
    > $MISURE
fi

export MAXFILE=/tmp/maxfile.txt
> $MAXFILE

export NUMMAXFILE=/tmp/nummaxfile.txt
echo 0 > $NUMMAXFILE

cerca_misure_ric.sh "$dir" "$header"

if test `cat $NUMMAXFILE` = 0
then
    echo "Nessun file trovato con header '$header'."
else
    echo "Directory con maggior numero di file: `cat $MAXFILE` ("`cat $NUMMAXFILE`" file trovati)"
fi

rm -f $MAXFILE
rm -f $NUMMAXFILE