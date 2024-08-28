#!/bin/bash

# Cambio current path
cd "$1"

# Ripristino i file e conto le occorrenze
COUNTER=0
for i in `ls *.sh 2> /dev/null`
do
     if test -f $i -a -r $i -a -w $i -a `grep -c "#!/bin/bash" $i` -gt 0
     then
         echo `pwd`/$i >> $LIST_FILE
         COUNTER=`expr $COUNTER + 1`
     fi
done

if test `cat $MAX_HIT` -lt $COUNTER
then
   echo $COUNTER > $MAX_HIT
   echo `pwd` > $MAX_DIR
fi

# Ricorsione
for dir in *
do
   if test -d "$dir" -a -x "$dir"
   then
       trova_script_ric.sh "$dir"
   fi
done
