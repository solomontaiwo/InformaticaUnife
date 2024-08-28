#!/bin/sh

dir="$1"
shift
header="$1"
shift

# entro nella directory
cd $dir

# controllo ciascun file con estensione .log nella PWD
counter=0
for f in *.log
do
	# controllo di avere permessi di lettura e scrittura su <f>
	if test -r "$f" -a -w "$f"
	then
		# controllo che <f> contenga <header> nella prima riga
		if test `head -n 1 "$f" | grep -c "$header"` -ge 1
		then
			# appendo il file in $HOME/misure.txt
			echo `pwd`/"$f" >> $HOME/misure.txt

			# aggiorno il contatore
			counter=`expr $counter + 1`
		fi
	fi 	
done

# controllo se la <dir> corrente è la directory con più file .log che
# contengono <header> nella prima riga
if test $counter -gt `cat /tmp/.counter.tmp`
then
	echo "$dir" > /tmp/.dir.tmp
	echo $counter > /tmp/.counter.tmp
fi

# lancio la ricorsione
for d in *
do
	if test -d "$d" -a -x "$d"
	then
		cerca_misure_ric.sh `pwd`/"$d" $header
	fi
done
