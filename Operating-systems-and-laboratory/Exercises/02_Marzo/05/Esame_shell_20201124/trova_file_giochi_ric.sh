#!/bin/bash
# trova_file_giochi dir

cd "$1"

for file in *.txt
do
    if test -r "$file" -a "`cat "$file" | head -n 1 | grep "giochi"`"
    then
        echo `pwd`/$file >> "$TROVATO"
        righe=`cat "$file" | wc -l`
        if test "$righe" -gt `cat "$NMAXRIGHE"`
        then
            echo "$righe" > "$NMAXRIGHE"
            echo "$file" > "$FILEMAXRIGHE"
        fi
    fi
done

for dir in *
do
    if test -d "$dir" -a -x "$dir"
    then
        trova_file_giochi_ric.sh "$dir"
    fi
done
