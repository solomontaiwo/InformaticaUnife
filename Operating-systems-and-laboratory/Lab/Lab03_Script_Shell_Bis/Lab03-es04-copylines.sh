#!/bin/bash

str_err="esame.sh <dir_ass> <stringa> <nomefile1> [<nomefile2> ... <nomefileN>]"

if test $# -lt 3
then
    echo "Errore: numero argomenti deve essere almeno 3"
    echo "Lanciare come $str_err"
    exit 1
fi

case $1 in
    /*) ;;
    *) echo "Errore: il percorso $1 non è assoluto"; exit 2;;
esac

dir="$1"; shift
STRINGA=$1; shift

for par in $*
do
    case $par in
        *[^a-z]*) echo "Errore: i nomi di file non possono contenere caratteri diversi dai caratteri minuscoli";
                  exit 3;;
               *);;
    esac
done

# Aggiunge il percorso corrente al PATH e lo esporta
PATH=$PATH:`pwd`
export PATH
export STRINGA

> /tmp/.risultati
> /tmp/.stringhe

while true
do
    Lab03-es04-copylines_ric.sh "$dir" $*

    num_ris=`cat /tmp/.risultati | wc -l`
    if test $num_ris -gt 0
    then
        echo "Sono stati spostati $num_ris file"
        cat /tmp/.stringhe
        rm -f /tmp/.risultati /tmp/.stringhe
        exit 0
    else
        echo "Nessun file trovato che corrisponde alle richieste. Attendo un'ora..."

        sleep `expr 60 \* 60`
    fi
done
