#!/bin/bash
# trova_errori dir

cd "$1"

COUNTER=0

for i in `ls *.log 2> /dev/null`
do
	if test -f $i -a -r $i
	then
		ERRORS=`grep -c "error" $i`
		COUNTER=`expr $COUNTER + $ERRORS`

		grep "error" $i | cut -d ',' -f 1,2,6 >> $ERROR_FILE
		grep "warning" $i | cut -d ',' -f 1,2,6 >> $WARNING_FILE
	fi
done

if test `cat $MAX_ERRORS` -lt $COUNTER
then
	echo $COUNTER > $MAX_ERRORS
	echo `pwd` > $MAX_DIR
fi

for dir in *
do
	if test -d "$dir" -a -x "$dir"
	then
		trova_errori_ric.sh "$dir"
	fi
done