#!/bin/sh

if test $# != 3
then
    echo "Errore: numero argomenti"
    exit 1
fi

stringa=$1

case $2 in
    /*)
    if test ! -d $2
    then
        echo "Errore: <dir> non è un direttorio"
        exit 2
    fi;;
    *) echo "Errore: <dir> non è un percorso assoluto"
    exit 3;;
esac

dir=$2

case $3 in
    *[!0-9]*) echo "Errore: <num> non è un numero intero"
    exit 4;;
esac

num=$3

PATH=$PATH:`pwd`
export PATH

> /tmp/.max_counter.tmp
> /tmp/.max_dirname.tmp

cercaStringa.sh $stringa $dir $num

echo "La directory con il maggior numero di file che soddisfano la condizione è `cat /tmp/.max_dirname.tmp`"

rm -f /tmp/.max_counter.tmp
rm -f /tmp/.max_dirname.tmp