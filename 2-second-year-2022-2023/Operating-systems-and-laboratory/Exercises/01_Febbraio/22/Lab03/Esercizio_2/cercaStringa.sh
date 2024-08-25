#!/bin/sh

dir="$2"
num="$3"

cd "$dir"
> /tmp/.counter.tmp

for i in `ls *.txt 2> /dev/null`
do
    if test -f "$i" -a -r "$i" -a `grep -c "$STRINGA" "$i"` -ge "$num"
    then
        echo "$i" >> /tmp/.counter.tmp
    fi
done

if test `wc -l < /tmp/.counter.tmp` -gt `wc -l < /tmp/.max_counter.tmp`
then
    mv /tmp/.counter.tmp /tmp/.max_counter.tmp
    echo `pwd` > /tmp/.max_dirname.tmp
fi

rm -f /tmp/.counter.tmp

for dir in *
do
    if test -d "$dir" -a -x "$dir"
    then
        cercaStringa.sh "$STRINGA" "$dir" "$num"
    fi
done