#!/bin/sh

ext=$1
sorg=$2
dest=$3

cd $sorg

for i in *
do
    if test -d $i -a -x $i
    then
        esame_rec.sh $ext "`pwd`/$i" $3
    else
        if test -f $i
        then
            for file in `ls *$ext 2> /dev/null`
            do
                if test ! -e "$dest/$file"
                then
                    echo "Copia di $file in corso..."
                    cp -n $file $dest/$file
                fi
            done
        fi
    fi
done