#!/bin/sh
# identifica dir messaggio

if [ $# -lt 2 ]
then
    echo "Uso: $0 <dir> <messaggio>"
    exit 1
fi

case $1 in 
    /*) echo "$1 deve essere relativo"
    exit 2;;
    *)  if [ ! -d "$1" -o ! -x "$1" ]
        then
            echo "$1 non è una directory o non posso entrare"
            exit 3
        fi;;
esac

PATH=$PATH:$(pwd)
export PATH

> "$1/Trovati"
> "$1/Max"

TROVATI="$(pwd)/$1/Trovati"
MAX="$(pwd)/$1/Max"

export TROVATI
export MAX

echo 0 > /tmp/max_counter.tmp

# programma ricorsivo
identifica_ric.sh "$1" "$2"

echo "I 5 file con il maggior numero di '$2'"
# comandi per stampare i 5 file
sort -r -n "$1"/Trovati | cut -f 2 -d , | head -n 5

echo "Il file con il maggior numero di occorrenze"
cat "$1"/Max

rm -f /tmp/max_counter.tmp