#!/bin/sh

# VERIFICA ARGOMENTI
# servono almeno 2 argomenti
if test $# -lt 2
then
        echo "Uso: contaricorrenze <file> <stringhe...>"
        exit 1
fi

#il primo argomento deve essere un file
file=$1
if test ! -f "$file"
then
        echo "Errore: il primo argomento deve essere un file"
        exit 2
fi

# elimino il primo argomento dalla lista
shift

# RICERCA PATTERN
echo Apertura file $file
for i in $*
do
        count=`grep "$i" "$file" | wc -l`
        echo "Parametro: $i - Ricorrenze: $count"
done
