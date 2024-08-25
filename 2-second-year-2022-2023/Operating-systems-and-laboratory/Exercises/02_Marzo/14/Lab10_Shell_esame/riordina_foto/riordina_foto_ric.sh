#!/bin/bash
# riordina_foto dir_sorgente dir_destinazione

cd $1

for i in *.JPG
do
	if test -f $i -a -r $i
	then
		if test -e "$2/$i"
		then
			count=1
			while test -e "$2/duplicati/$i-$count"
			do
				count=`expr $count + 1`
			done
			mv $i "$2/duplicati/$i-$count"
		else
			mv $i "$2/$i"
			echo "$2/$i" >> /tmp/spostati
		fi
	fi
done

for d in *
do
	if test -d "$d" -a -x "$d"
	then
		riordina_foto_ric.sh $d $2
	fi
done