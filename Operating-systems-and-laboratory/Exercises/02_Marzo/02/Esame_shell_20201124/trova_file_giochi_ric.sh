#!/bin/bash
# trova_file_giochi_ric dir

cd $1

for i in *.txt
do
    if test -r "$i" -a `cat "$i" | head -n 1` = "giochi"
    then
        echo `pwd`/"$i" >> "$TROVATO"
        linee=`cat "$i" | wc -l`
        if test "$linee" -gt `cat "$MAX_COUNTER"`
        then
            echo "$linee" > "$MAX_COUNTER"
            echo `pwd`/"$i" > "$MAX_NAME"
        fi
    fi
done

for dir in *
do
    if test -d "$dir" -a -x "$dir"
    then
        sh trova_file_giochi_ric.sh "$dir"
    fi
done