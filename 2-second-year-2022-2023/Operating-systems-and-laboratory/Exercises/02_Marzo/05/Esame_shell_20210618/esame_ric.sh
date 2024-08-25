#!/bin/bash
# esame genere tipo anno

cd "$3"
counter=0
for file in *.txt
do
    if test -r "$file"
    then
		counter=`grep "$1" "$file" | grep "$2" -c`
        if test $counter -gt `cat $PUBBLICAZIONIMAX`
        then
            echo "$file" > "$MESEMAX"
            echo $counter > "$PUBBLICAZIONIMAX"         
        fi
                
        if test $counter -gt 0
        then        
            grep "$1" "$file" | grep "$2" | cut -d ',' -f 1,3,6 >> $RISULTATI
        fi
    fi
done

for dir in *
do
    if test -d "$dir" -a -x "$dir"
    then
        esame_ric.sh "$1" "$2" "$dir"
    fi
done