#!/bin/bash
# trova_script dir

if test $# != 1
then
    echo "Errore: numero argomenti. Uso $0 <dir>"
    exit 1
fi

case $1 in
    /*) if test ! -d "$1"
        then
            echo "Errore: <dir> non è un direttorio"
            echo "Uso: $0 <dir>"
            exit 2
        fi;;
    *) echo "Errore: <dir> non è un percorso assoluto"
       exit 3;;
esac

SCRIPT="/$HOME/script.txt"
export SCRIPT

if test ! -e "$SCRIPT"
then
    > "$SCRIPT"
fi

MAXFILE="/tmp/max_files.txt"
export MAXFILE
> "$MAXFILE"

MAXCOUNT="/tmp/max_count.txt"
export MAXCOUNT
echo 0 > "$MAXCOUNT"

COUNT="/tmp/count.txt"
export COUNT
echo 0 > "$COUNT"

PATH=$PATH:`pwd`
export PATH

trova_script_ric.sh "$1"

echo "La directory con il numero maggiore di file è: `cat "$MAXFILE"`"

rm -f "$MAXFILE"
rm -f "$SCRIPT"