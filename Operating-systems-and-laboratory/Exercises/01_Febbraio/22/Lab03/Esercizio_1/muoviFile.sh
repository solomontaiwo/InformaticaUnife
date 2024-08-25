#!/bin/sh
# muoviFile num dirSorgente dirDestinazione ex1 ext2...extN

if test "$#" -lt 4
then
    echo "Errore: numero argomenti insufficiente"
    exit 1
fi

case "$1" in
    *[!0-9]*) echo "num deve essere un numero intero"
    exit 2;;
esac 

num="$1"
shift

case "$1" in
    /*) ;;
    *) echo "dirSorgente deve essere un direttorio assoluto"
    exit 3;;
esac

if test ! -d "$1"
then
    echo "dirSorgente non è un direttorio"
    exit 4
fi

sorg="$1"
shift

case "$1" in
    /*) ;;
    *) echo "dirDestinazione deve essere un direttorio assoluto"
    exit 5;;
esac

if test ! -d "$1"
then
    echo "dirDestinazione non è un direttorio"
    exit 6
fi

dest="$1"
shift

for i in "$*"
do
    case "$i" in 
        .*) ;;
        *) echo "Uso: muoviFile num dirSorgente dirDestinazione ext1 ext2...extN"
        echo "I vari ext* devono essere delle estensioni (iniziare con '.')"
        exit 7;;
    esac
done

PATH=$PATH:`pwd`
export PATH

> /tmp/.counter.tmp

ricerca.sh "$num" "$sorg" "$dest" "$*"

echo "Numero totale di file trovati: "`wc -l < /tmp/.counter.tmp`""

rm -f /tmp/.counter.tmp