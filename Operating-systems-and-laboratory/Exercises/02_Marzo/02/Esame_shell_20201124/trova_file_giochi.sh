#!/bin/bash
# trova_file_giochi dir

if test $# != 1
then
    echo "Errore: numero argomenti. Uso $0 <dir>"
    exit 1
fi

case $1 in 
    /*) echo "$1 deve essere un percorso relativo";
        exit 2;;

    *) if test ! -d "$1" -o ! -x "$1"
       then
            echo "Errore: $1 non e' una directory o mancano i permessi di esecuzione"
            exit 3
        fi;;      
esac

PATH=$PATH:`pwd`
export PATH

TROVATO="$HOME/trovato.txt"
export TROVATO

if test ! -f "$TROVATO"
then
    > "$TROVATO"
fi

export MAX_COUNTER=/tmp/.tmp_max_counter
export MAX_FILE=/tmp/.tmp_file_name

echo 0 > "$MAX_COUNTER"
> "$MAX_FILE"

sh trova_file_giochi_ric.sh "$1" 

echo "Il file che contiene più lungo e' `cat $MAX_FILE` con `cat $MAX_COUNTER` righe"

rm -f "$MAX_COUNTER"
rm -f "$MAX_NAME"