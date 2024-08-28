#!/bin/sh

num=$1
shift
sorg=$1
shift
dest=$1
shift

cd $sorg

for i in $*
do
    for file in `ls *$ext 2>/dev/null`
    do
        if test -f $file
        then
            if test -r $file -a `wc -l < $file` -gt $num
            then
                echo "Scrittura di riga nel file counter.tmp..."
                echo $i >> /tmp/.counter.tmp
                cp $file $dest/$file
            fi
        fi
    done
done

for r in *
do
    if test -d $r -a -x $r
    then
        ricerca.sh $num `pwd`/$r $dest $*
    fi
done