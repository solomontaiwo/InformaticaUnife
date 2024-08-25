#!/bin/bash
# interfaccia: cerca_misure_ric dir header

dir=$1
header=$2

cd $dir

count=0

for file in *.log
do
    if test -r "$file" -a -w "$file"
    then
        if test `head -n 1 $file | grep -c $header` -ge 1
        then
            echo $file >> $MISURE
            count=`expr $count + 1`
        fi
    fi
done

if test $count -gt `cat $NUMMAXFILE`
then
    echo $count > $NUMMAXFILE
    echo $dir > $MAXFILE
fi

for direttorio in *
do
    if test -x "$direttorio" -a -d "$direttorio"
    then
        cerca_misure_ric.sh "$direttorio" "$header"
    fi
done