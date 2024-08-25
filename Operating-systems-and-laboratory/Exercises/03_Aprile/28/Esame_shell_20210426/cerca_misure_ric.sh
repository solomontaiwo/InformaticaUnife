#!/bin/sh

cd $1

counter=0
for file in *.log
do
    if test -r $file -a -w $file
    then
        if test `head -n 1 $file | grep -c $2` -ge 1
        then
            echo `pwd`/"$file" >> $FILEMISURE
            counter=`expr $counter + 1`
        fi
    fi
done

if test $counter -gt `cat $MAXFILE`
then
    echo $counter > $MAXFILE
    echo $1 > $NOMEDIRECTORYMAXFILE
fi

for dir in *
do
    if test -x $dir -a -d $dir 
    then
        cerca_misure_ric.sh $dir $2
    fi
done
        