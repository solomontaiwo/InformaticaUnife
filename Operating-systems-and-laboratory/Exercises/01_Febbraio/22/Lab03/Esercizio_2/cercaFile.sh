#!/bin/sh
# cercaFile stringa dir num

if test "$#" != 3
then
    echo "Errore: numero argomenti"
    exit 1
fi

STRINGA="$1"

case "$2" in
    /*) if test ! -d "$2"
        then
            echo "Errore: dir non è un direttorio"
            exit 2
        fi ;;
    *) echo "Errore: dir deve essere un percorso assoluto"
    exit 3;;
esac


dir="$2"

case "$3" in
    *[!0-9]*) echo "Errore: num non è un numero intero"
    exit 4;;
esac

num="$3"


PATH="$PATH":`pwd`
export PATH
export STRINGA

> /tmp/.max_counter.tmp
> /tmp/.max_dirname.tmp

cercaStringa.sh "$STRINGA" "$dir" "$num"

echo La directory con il maggior numero di file è `cat /tmp/.max_dirname.tmp` con `wc -l < /tmp/.max_counter.tmp` file

rm -f /tmp/.max_counter.tmp
rm -f /tmp/.max_dirname.tmp