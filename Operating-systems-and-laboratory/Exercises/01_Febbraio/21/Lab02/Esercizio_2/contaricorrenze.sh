#!/bin/sh

if test "$#" -lt 2
then
    echo "Errore: numero parametri insufficiente. Uso: contaricorrenze.sh <file> <stringa1> ..."
    exit 1
fi

if test ! -f "$1"
then
    echo "Errore: "$1" non è un file"
    exit 2
fi

file="$1"
shift

for i in $*
do
    count=`grep "$i" "$file" | wc -l`
    echo "Parametro: "$i" - Ricorrenze: "$count""
done