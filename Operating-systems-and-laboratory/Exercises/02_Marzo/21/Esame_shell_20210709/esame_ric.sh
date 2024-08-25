#!/bin/bash
# interfaccia: esame_ric nome anno

cd $2

for file in *.txt
do
    if test -r $file -a -f $file
    then
        info=`grep "$1" "$file" | cut -f 1,3,5 -d ,`
        if test "$info"
        then
            echo $info >> $FILELOG
            livello=`echo "$info" | cut -f 1 -d ,`
            if test "$livello" -lt `cat "$LIVELLOMIN"`
            then
                echo $livello > $LIVELLOMIN
                echo $file > $GIORNOMIN
            fi
        fi
    fi
done

for dir in *
do
    if test -x $dir -a -d $dir
    then
        esame_ric.sh $1 $dir
    fi
done