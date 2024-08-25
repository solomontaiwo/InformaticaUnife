#!/bin/bash
# interfaccia: esame nome anno

nome="$1"
anno="$2"

cd "$anno"

for file in *.txt
do
    if test -f "$file" -a -r "$file"
    then
        info=`grep "$nome" "$file" | cut -f 1,3,5 -d ','`
        if test "$info"
        then
            echo $info >> $FILELOG
            livello=`echo $info | cut -f 1 -d ','`
            if test "$livello" -lt `cat "$LIVELLOMIN"`
            then
                echo $livello > $LIVELLOMIN
                echo $file > $GIORNOMIN
            fi
        fi
    fi
done

for dir in *
do
    if test -x "$dir" -a -d "$dir"
    then
        esame_ric.sh "$nome" "$dir"
    fi
done