#!/bin/sh

stringa=$1
dir=$2
num=$3

cd "$dir"

> /tmp/.counter.tmp

for ext in `ls *.txt 2>/dev/null`
do
    if test -r "$ext" -a -f "$ext"
    then
        if test `grep -c $stringa "$ext"` -ge "$num"
        then
            echo "$ext" >> /tmp/.counter.tmp
        fi
    fi
done

if test `wc -l < /tmp/.counter.tmp` -gt `wc -l < /tmp/.max_counter.tmp`
then
    echo `pwd` > /tmp/.max_dirname.tmp
    mv /tmp/.counter.tmp /tmp/.max_counter.tmp
fi

rm -f /tmp/.counter.tmp

for i in *
do
    if test -d "$i" -a -x "$i"
    then
        cercaStringa.sh "$stringa" "$i" "$num"
    fi
done