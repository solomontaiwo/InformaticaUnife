#!/bin/sh

if test $# -lt 4
then
    echo "Errore: uso ./muoviFile.sh <num> <dirSorgente> <dirDestinazione> <ext1> <ext2> ... <extN>"
    exit 1
fi

case $1 in
    *[!0-9]*) echo "Errore: <num> non è un numero intero"
    exit 2;;
esac

num=$1
shift

case $1 in
    /*) 
    if test ! -d $1
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
    /*) 
    if test ! -d $1
    then
        echo "Errore: <dirDestinazione> non è un direttorio"
        exit 5
    fi;;
    *) echo "Errore: <dirDestinazione> non è un percorso assoluto"
    exit 6;;
esac

dest=$1
shift

for stringa in $*
do
    case $stringa in
        .*) ;;
        *) echo "Errore: $stringa non è un'estensione"
        exit 7;;
    esac
done

PATH=$PATH:`pwd`
export PATH

> /tmp/.counter.tmp

ricerca.sh $num $sorg $dest $*

echo Numero totale di file spostati: `wc -l < /tmp/.counter.tmp`

rm -f /tmp/.counter.tmp