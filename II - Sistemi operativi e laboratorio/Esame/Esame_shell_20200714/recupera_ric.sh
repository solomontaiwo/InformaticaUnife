#!/bin/bash

# Cambio current path
cd "$1"

# Ripristino i file e conto le occorrenze
COUNTER=0
for i in *.bak
do
    if test -f $i -a -r $i -a `head -n 1 $i | grep -c $3` -gt 0
    then
       cp $i "$2"
       COUNTER=`expr $COUNTER + 1`
    fi
done

if test `cat $MAX_HIT` -lt $COUNTER
then
   echo $COUNTER >$MAX_HIT
   echo `pwd` >$MAX_DIR
fi

TOT=`cat $TOTALE`
echo `expr $TOT + $COUNTER` > $TOTALE

# Ricorsione
for dir in *
do
  if test -d "$dir" -a -x "$dir"
  then
     $0 "$dir" $2 $3
  fi
done
