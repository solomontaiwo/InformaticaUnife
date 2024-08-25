#!/usr/bin/env sh

# Controllo dei parametri
if test $# -lt 2
then
    echo "$0 <dir> <messaggio>"
    exit 1
fi

# Controllo directory relativo
case $1 in 
    /*) echo "$1 deve avere una path relativa";
        exit 2;;

    *) if test ! -d "$1" -o ! -x "$1"
       then
            echo "Errore: $1 non e' una directory o permessi di esecuzione mancanti"
            exit 3
        fi;;      
esac

# Aggiornamento PATH
export PATH=$PATH:`pwd`


# clean files
> "$1/Trovati"
> "$1/Max"

# la directory dir e' relativo alla directory corrente
export TROVATI="`pwd`/$1/Trovati"
export MAX="`pwd`/$1/Max"

echo 0 > /tmp/max_counter.tmp

# Chiamo lo script ricorsivo
sh identifica_ric.sh "$1" "$2"

echo "I 5 file che contengono il maggior numero di occorrenze sono:"
echo `sort -r -n "$TROVATI" | cut -f 2 -d ,`

rm -f /tmp/max_counter.tmp


