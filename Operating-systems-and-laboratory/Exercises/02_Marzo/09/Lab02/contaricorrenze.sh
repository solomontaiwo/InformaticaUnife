#!/bin/bash

if test $# -lt 2
then
    echo "Errore argomenti. Uso $0 <file> <stringa1> ... <stringaN>"
    exit 1
fi

if test ! -f $1 
then
    echo "Errore, "$1" non è un file"
    exit 2
fi

file=$1
shift

echo "Apertura file $file..."

for stringa in $*
do
    echo "Parametro: $stringa - Ricorrenze: "`grep $stringa $file | wc -l`""
done
