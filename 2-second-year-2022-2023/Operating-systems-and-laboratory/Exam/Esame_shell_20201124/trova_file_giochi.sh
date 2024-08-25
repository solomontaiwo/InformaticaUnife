#!/usr/bin/env sh

# Controllo dei parametri
# dir nome relativo di directory
if test $# -lt 1
then
    echo "$0 <dir>"
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

export TROVATO="$HOME/trovato.txt"
# verifico se esiste il file trovato.txt nella home

if test ! -f "$TROVATO"
then
    > "$TROVATO"
fi

# il nome del file con il numero maggiore di righe
# tra quelli che soddisfano le condizioni di ricerca
export MAX_COUNTER=/tmp/.tmp_max_counter
export MAX_FILE=/tmp/.tmp_file_name

echo 0 > "$MAX_COUNTER"
> "$MAX_FILE"

# Chiamo lo script ricorsivo
sh trova_file_giochi_ric.sh "$1" 

echo "Il file che contiene più lungo e' `cat $MAX_FILE` con `cat $MAX_COUNTER` righe"

rm -f "$MAX_COUNTER"
rm -f "$MAX_NAME"


