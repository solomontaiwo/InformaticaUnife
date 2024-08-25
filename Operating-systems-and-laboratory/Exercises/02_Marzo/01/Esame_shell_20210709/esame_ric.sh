#!/bin/bash

nome_corso=$1
cartella_anno=$2

cd "$cartella_anno"

for i in *.txt
do
    if test -f "$i" -a -r "$i"
    then
        ris=`grep "$1" "$i" | cut -f 1,3,5 -d ,`
        if test "$ris"
        then
            echo "$ris" >> "$FILELOG"
            livello=`echo "$ris" | cut -f 1 -d ,`
            if test "$livello" -lt `cat "$LIVELLOMINIMO"`
            then
                echo "$livello" > "$LIVELLOMINIMO"
                echo "$i" > "$GIORNOMINIMO"
            fi
        fi
    fi
done

for dir in *
do
    if test -d "$dir" -a -x "$dir"
    then
        sh esame_ric.sh "$nome_corso" "$dir"
    fi
done      