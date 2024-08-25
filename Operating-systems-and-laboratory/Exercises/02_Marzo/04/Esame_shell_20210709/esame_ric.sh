#!/bin/bash
# esame_ric nome anno

cd "$2"

for file in *.txt
do
    if test -f "$file" -a -r "$file"
    then
        info=`grep "$1" "$file" | cut -f 1,3,5 -d ,`
        if test "$info"
        then
            echo "$info" >> "$FILELOG"
            livello=`echo "$info" | cut -f 1 -d ,`
            if test "$livello" -gt "`cat "$MINLIVELLO"`"
            then
                echo "$livello" > "$MINLIVELLO"
                echo $file > "$GIORNOMINLIVELLO"
            fi
        fi
    fi
done

for dir in *
do
    if test -d "$dir" -a -x "$dir"
    then
        esame_ric.sh "$1" "$dir"
    fi
done