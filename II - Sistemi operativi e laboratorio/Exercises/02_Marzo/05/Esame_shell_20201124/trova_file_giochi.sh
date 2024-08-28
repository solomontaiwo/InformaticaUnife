#!/bin/bash
# trova_file_giochi dir

if test $# != 1
then
    echo "Errore: uso $0 <dir>"
    exit 1
fi

case $1 in 
    /*) echo "Errore: <dir> è un percorso assoluto"
        exit 2;;
    *) if test ! -d $1
       then 
            echo "Errore: <dir> non è un direttorio"
            exit 3
        fi;;
esac

export PATH=$PATH:`pwd`

export TROVATO=$HOME/trovato.txt

if test ! -e "$TROVATO"
then
    > "$TROVATO"
fi

export FILEMAXRIGHE=/tmp/file_max_righe.txt
> "$FILEMAXRIGHE"

export NMAXRIGHE=/tmp/n_max_righe.txt
echo 0 > "$NMAXRIGHE"

trova_file_giochi_ric.sh "$1"

echo "Il file con il numero maggiore di righe si chiama \"`cat "$FILEMAXRIGHE"`\""

rm -f "$TROVATO"
rm -f "$FILEMAXRIGHE"
rm -f "$NMAXRIGHE"