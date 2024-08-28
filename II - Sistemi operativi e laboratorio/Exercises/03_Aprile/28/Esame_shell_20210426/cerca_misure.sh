#!/bin/sh

if test $# != 2
then
    echo "Errore: argomenti. Uso $0 <dir> <header>"
    exit 1
fi

case $1 in
    /*) if test ! -d $1
        then
            echo "Errore: <dir> deve essere un direttorio"
            exit 2
        fi;;
    *) echo "Errore: <dir> deve essere un percorso assoluto"
       exit 3;;
esac

case $2 in
    /*) echo "Errore: <header> deve essere una stringa, non un percorso assoluto"
        exit 3;;
esac

export FILEMISURE=$HOME/misure.txt

if test ! -e $FILEMISURE
then
    > $FILEMISURE
fi

export PATH=$PATH:`pwd`

export MAXFILE=/tmp/maxfile.txt
echo 0 > $MAXFILE

export NOMEDIRECTORYMAXFILE=/tmp/nomedirectorymaxfile.txt
echo "" > $NOMEDIRECTORYMAXFILE

cerca_misure_ric.sh $1 $2

echo "La sottodirectory con il maggior numero di file che soddisfano la condizione di ricerca è `cat $NOMEDIRECTORYMAXFILE` (`cat $MAXFILE` file)."

rm -f $MAXFILE
rm -f $NOMEDIRECTORYMAXFILE
rm -f $FILEMISURE