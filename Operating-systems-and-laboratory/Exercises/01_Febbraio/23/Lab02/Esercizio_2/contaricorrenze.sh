#!/bin/sh

if test $# -lt 2
then
    echo "Errore: uso ./contaricorrenze.sh <file> <stringa1> ..."
    exit 1
fi

if test ! -f $1
then
    echo "Errore: <file> non è un file"
    exit 2
fi

file=$1
shift

for stringa in $*
do
    count=`grep "$stringa" "$file" | wc -l`
    echo "Parametro: "$stringa" - Ricorrenze: "$count""
done