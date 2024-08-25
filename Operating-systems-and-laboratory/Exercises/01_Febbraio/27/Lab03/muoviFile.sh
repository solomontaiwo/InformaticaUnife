#!/bin/sh
# muoviFile num dirSorgente dirDestinazione ext1 ext2...extN

if test $# -lt 4
then
    echo "Errore: uso ./muoviFile.sh <num> <dirSorgente> <dirDestinazione> <ext1> <ext2> ... <extN>"
    exit 1
fi

case $1 in
    *[!0-9]*) echo "Errore: uso ./muoviFile.sh <num> ..."
    exit 2;;
esac

num=$1
shift

case $1 in
    /*) if test ! -d $1
        then
            echo "Errore: <dirSorgente> non è un direttorio"
            exit 3
        fi;;
    *) echo "Errore: <dirSorgente> non è un percorso assoluto"
    exit 4;;
esac

sorg=$1
shift

case $1 in
    /*) if test ! -d $1
        then
            echo "Errore: <dirDestinazione> non è un direttorio"
            exit 5
        fi;;
    *) echo "Errore: <dirDestinazione> non è un percorso assoluto"
    exit 6;;
esac

dest=$1
shift

for ext in $*
do
    case $ext in
        .*) ;;
        *) echo "Errore: $ext non è un'estensione"
        exit 7;;
    esac
done

PATH=$PATH:`pwd`
export PATH

> /tmp/.counter.tmp

ricerca.sh $num "$sorg" "$dest" $*

echo Il numero di file è pari a `wc -l < /tmp/.counter.tmp`

rm -r /tmp/.counter.tmp