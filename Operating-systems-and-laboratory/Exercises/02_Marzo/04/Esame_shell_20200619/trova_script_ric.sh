#!/bin/bash
# trova_script_ric dir

cd "$1"

count=0

for file in *.sh
do
    if test -f "$file" -a -r "$file"
    then
        found=`grep "!/bin/bash" "$file" | wc -l`
        if test "$found"
        then
            echo "$file" >> "$SCRIPT"
            count=`expr "$count" + 1`
        fi
    fi
done

if test "$count" -gt "`cat "$MAXCOUNT"`"
then
    echo "$count" > "$MAXCOUNT"
    echo "$1" > "$MAXFILE"
fi

for dir in *
do
    if test -d "$dir" -a -x "$dir"
    then
        trova_script_ric.sh "$dir"
    fi
done