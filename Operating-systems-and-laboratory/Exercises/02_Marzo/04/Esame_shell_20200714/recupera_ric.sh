#!/bin/bash
# recupera dir recuperati titolo

cd "$1"

count=0

for file in *.bak
do
    if test -r "$file"
    then
        ricerca=`cat "$file" | head -n 1 | grep "$3"`
        if test "$ricerca"
        then
            cp "$file" "$RECUPERATI"/$file
            count=`expr $count + 1`
        fi
    fi
done

rec=`cat $NRECUPERATI`

expr $count + $rec > "$NRECUPERATI"

if test "$count" -gt `cat $NMAXRECUPERATI`
then
    echo "$count" > "$NMAXRECUPERATI"
    echo "$1" > "$MAXRECUPERATI"
fi

for dir in *
do
    if test -d "$dir" -a -x "$dir"
    then
        recupera_ric.sh "$dir" "$RECUPERATI" "$3"
    fi
done