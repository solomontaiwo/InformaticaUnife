#!/bin/sh

if "$#" -lt 5
then
    echo "Errore: uso <num> <dirSorgente> <dirDestinazione> <ext1> <ext2> ... <extN>"
    exit 1
fi

num="$1"
shift

sorg="$1"
shift

dest="$1"
shift

case "$num" in
    *[!0-9]*) 
    echo "Errore: uso <num> ..."
    exit 2;;
esac

case "$sorg" in
    /*) ;;
    *) echo "Errore: uso <...> <dirSorgente> <...> <...> <...> ... <...>"
    exit 3;;
esac

if test ! -d "$sorg"
then
    echo ""$sorg" non è un direttorio"
    exit 4
fi

case "$dest" in
    /*) ;;
    *) echo "Errore: uso <...> <...> <dirDestinazione> <...> <...> ... <...>"
    exit 5;;
esac

if test ! -d "$dest"
then
    echo ""$dest" non è un direttorio"
    exit 6
fi

for i in $*
do
    case "$i" in
        /*) ;;
        *) echo ""$i" non è un'estensione"
        exit 7;;
    esac
done

PATH="$PATH":`pwd`
export PATH

touch counter.tmp

for i in "$*"
do
    ricerca.sh "$num" "$sorg" "$dest" "$i"
    echo "Numero di file con estensione "$i" trovati: `wc -l "counter.tmp"`"
done

rm -f counter.tmp