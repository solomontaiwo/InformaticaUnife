#!/bin/sh
# identifica.sh dir messaggio

if test $# != 2
then
    echo "Errore: numero argomenti. Uso $0 <dir> <messaggio>"
    exit 1
fi

case $1 in
    /*) echo "Errore: <dir> è un percorso assoluto"
        exit 2;;
    *) if test ! -d $1 -o ! -x $1
       then
            echo "Errore: <dir> non è un direttorio oppure mancano i permessi necessari"
            exit 3
       fi;;
esac 

PATH=$PATH:`pwd`
export PATH

> "$1/Trovati"
> "$1/Max"

export TROVATI="`pwd`/$1/Trovati"
export MAX=`pwd`/$1/Max

identifica_ric.sh "$1" "$2"

cat "$TROVATI" | sort -r -n | head -n 5

rm -f "$MAX"
rm -f "$TROVATI"