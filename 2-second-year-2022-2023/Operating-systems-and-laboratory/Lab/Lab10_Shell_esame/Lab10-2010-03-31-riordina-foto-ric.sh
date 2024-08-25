#!/bin/sh

cd $1

for i in *.JPG
do
	if test -f $i -a -r $i
	then
		if test -e "$2/$i"
		then
			# file esistente: lo sposto nella directory $2/duplicati
			count=1
			while test -e "$2/duplicati/$i-$count"
			do
				count=`expr $count + 1`
			done
			mv $i "$2/duplicati/$i-$count"
		else
			# file non esistente: lo sposto nella directory $2
			mv $i "$2/$i"
			# aggiorno il conteggio dei file spostati in $2
			echo "$2/$i" >> /tmp/spostati
		fi
	fi
done

# ricorsione
for d in *
do
	if test -d "$d" -a -x "$d"
	then
		Lab10-2010-03-31-riordina-foto-ric.sh $d $2
	fi
done
