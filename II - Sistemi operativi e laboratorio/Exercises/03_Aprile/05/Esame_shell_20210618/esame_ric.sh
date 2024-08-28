#!/bin/bash
# interfaccia: esame_ric.sh genere tipo anno

cd $3
counter=0
for file in *.txt
do
    if test -f $file -a -r $file
    then
        counter=`grep $1 $file | grep $2 -c`
        if test "$counter" -gt `cat $MAXPUBBLICAZIONI`
        then
            echo $file > $MESEMAXPUBBLICAZIONI
            echo $counter > $MAXPUBBLICAZIONI
        fi

        if test $counter -gt 0
        then
            grep "$1" "$file" | grep "$2" | cut -d ',' -f 1,3,6 >> $RISULTATI
        fi
    fi
done

for dir in *
do
    if test -x $dir -a -d $dir
    then
        esame_ric.sh $1 $2 $dir
    fi
done