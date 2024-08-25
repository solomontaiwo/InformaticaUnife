#!/bin/bash
# recupera dir recuperati titolo

if test $# != 3
then
    echo "Errore: numero argomenti. Uso $0 <dir> <recuperati> <titolo>"
    exit 1
fi

case $1 in
    /*) if test ! -d "$1" -a ! -x "$1"
        then
            echo "Errore: <dir> non è un direttorio oppure permessi insufficienti"
            exit 2
        fi;;
    *) echo "Errore: <dir> no è un percorso assoluto"
       exit 3;;
esac

case $2 in
    /*) if test ! -d "$2" -a ! -x "$2"
        then
            echo "Errore: <recuperati> non è un direttorio oppure permessi insufficienti"
            exit 4
        fi;;
    *) echo "Errore: <recuperati> no è un percorso assoluto"
       exit 5;;
esac

RECUPERATI="$2/recuperati"
export RECUPERATI

if test ! -d "$RECUPERATI"
then
    mkdir "$RECUPERATI"
fi

export PATH=$PATH:`pwd`

MAXRECUPERATI=/tmp/max_recuperati.txt
export MAXRECUPERATI
> "$MAXRECUPERATI"

NMAXRECUPERATI=/tmp/n_max_recuperati.txt
export NMAXRECUPERATI
echo 0 > "$NMAXRECUPERATI"

NRECUPERATI=/tmp/n_recuperati.txt
export NRECUPERATI
echo 0 > "$NRECUPERATI"

recupera_ric.sh "$1" "$RECUPERATI" "$3"

echo "Directory con il maggior numero di file recuperati: `cat "$MAXRECUPERATI"`"
echo "Numero file recuperati: `cat "$NRECUPERATI"`"

rm -f "$MAXRECUPERATI"
rm -f "$NMAXRECUPERATI"
rm -f "$NRECUPERATI"
rm -f "$RECUPERATI"/*
rmdir "$RECUPERATI"