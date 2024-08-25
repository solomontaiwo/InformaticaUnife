#!/bin/sh

if test "$#" -lt 2
then
    echo "Errore: uso <file> <stringhe...>"
    exit 1
fi

file="$1"

if test ! -f "$file"
then
    echo ""$file" non è un file"
    exit 2
fi

shift

echo "Apertura file "$file""

for i in $*
do
    count=`grep "$i" "$file" | wc -l`
    echo "Parametro: "$i" - Ricorrenze: "$count""
done