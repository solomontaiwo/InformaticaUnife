#!/bin/sh

num=$1
shift
sorg=$1
shift
dest=$1
shift

cd "$sorg"

for ext in $*
do
    for file in "`ls *$ext 2>/dev/null`"
    do
        if test -f "$file" 
        then
            if test -r "$file" -a `wc -l < "$file"` -gt $num
            then
                echo "$file" >> /tmp/.counter.tmp
                echo "Copia $file in dest..."
                cp "$file" "$dest/$file"
            fi
        fi
    done
done

for dir in *
do
    if test -d "$dir" -a -x "$dir"
    then
        ricerca.sh $num "$dir" "$dest" $*
    fi
done