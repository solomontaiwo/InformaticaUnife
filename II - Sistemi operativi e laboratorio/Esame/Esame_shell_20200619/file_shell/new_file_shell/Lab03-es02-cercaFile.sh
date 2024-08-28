#!/bin/sh
# cercaFile.sh <stringa> <dir> <num>

if test $# -ne 3
then
        echo Errore: il numero di argomenti deve essere 3
        echo "Uso corretto: $0 <stringa> <dir> <num>"
        exit 1
fi

if ! test -d "$2"
then
        echo Errore: $2 non è una directory
        exit 2
fi

case $2 in
        /*) ;;
        *) echo Errore: il percorso $2 non è assoluto; exit 3;;
esac

if ! test "$3" -gt 0
then
        echo Errore: $3 non è un numero positivo
        exit 4
fi

> /tmp/.max_counter.tmp
> /tmp/.max_dirname.tmp

PATH=$PATH:`pwd` # aggiunge directory script corrente al PATH
export PATH # esporta il PATH

Lab03-es02-cercaStringa.sh "$1" "$2" $3
echo La directory con il maggior numero di file è: `cat /tmp/.max_dirname.tmp` con `wc -l < /tmp/.max_counter.tmp` file

rm -f /tmp/.max_counter.tmp
rm -f /tmp/.max_dirname.tmp
