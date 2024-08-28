#!/bin/bash
# esame_ric genere tipo anno

genere=$1
tipo=$2
anno=$3

cd "$anno"

for i in *.txt
do
    if test -f "$i" -a -r "$i"
    then
        counter=`grep "$genere" "$i" | grep "$tipo" -c`

        if test "$counter" -gt `cat $MAGGIORINTERESSE`
        then
            echo "$counter" > "$MAGGIORINTERESSE"
            echo "$i" > "$MESEMAGGIORIPUBBLICAZIONI"
        fi

        if test "$counter" -gt 0
        then
            grep "$genere" "$i" | grep "$tipo" | cut -f 1,3,6 -d , >> $RISULTATI
        fi
    fi
done

for dir in *
do
    if test -d "$dir" -a -x "$dir"
    then
        esame_ric.sh "$genere" "$tipo" `pdw`/"$dir"
    fi
done