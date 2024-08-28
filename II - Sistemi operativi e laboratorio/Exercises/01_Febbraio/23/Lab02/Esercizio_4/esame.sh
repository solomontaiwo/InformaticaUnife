#!/bin/sh

if test $# -ne 3
then
    echo "Errore: uso ./esame.sh <estensione> <dir1Sorgente> <dir2Destinazione>"
    exit 1
fi

case $1 in
    .*) ;;
    *) echo "Errore: <estensione> non è un'estensione"
    exit 2;;
esac

ext=$1

case $2 in
    /*) if test ! -d $2
        then
            echo "Errore: <dir1> non è un direttorio"
            exit 3
        fi;;
    *) echo "Errore: <dir1> non è un percorso assoluto"
    exit 4;;
esac

sorg=$2

case $3 in
    /*) if test ! -d $3
        then
            echo "Errore: <dir2> non è un direttorio"
            exit 5
        fi;;
    *) echo "Errore: <dir2> non è un percorso assoluto"
    exit 6;;
esac

dest=$3

PATH=$PATH:`pwd`
export PATH

esame_rec.sh $ext $sorg $dest

echo "Numero di file copiati: "`ls $dest | wc -l`""