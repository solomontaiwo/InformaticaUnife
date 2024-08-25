#!/bin/sh

# Verifico che siano stati inseriti almeno due argomenti

if test $# -lt 2
then
    echo "Errore: uso <file> <stringhe...>"
    exit 1
fi

# Assegno il primo argomento alla variabile 'file'

file=$1

# Verifico che 'file' sia effettivamente un file

if test ! -f "$file"
then 
    echo "$file" non è un file
    exit 2
fi

# elimina il primo argomento

shift

for i in $*
do
    count=`grep $i $file | wc -l`
    echo "Parametro: "$i" - Ricorrenze "$count""
done