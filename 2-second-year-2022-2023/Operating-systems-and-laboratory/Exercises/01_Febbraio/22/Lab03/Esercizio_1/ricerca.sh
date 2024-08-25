#!/bin/sh

num="$1"
shift
sorg="$1"
shift
dest="$1"
shift

cd "$sorg"

for ext in "$*"
do
    for file in "`ls *$ext 2>/dev/null`"
    do
        if test -f "$file"
        then
            if test -r "$file" -a `wc -l < "$file"` -gt "$num"
            then
                echo "$file" >> /tmp/.counter.tmp
                cp "$file" "$dest/$file"
            fi
        fi
    done
done

for i in *
do
    if test -d "$i" -a -x "$i"
    then
        ricerca.sh "$num" "$i" "$dest" "$*"
    fi
done