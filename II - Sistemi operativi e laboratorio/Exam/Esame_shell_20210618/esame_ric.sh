#!/bin/sh

genere="$1"
shift
tipo="$1"
shift
anno="$1"
shift

# entro nella directory
cd "$anno"

# controllo ciascun file con estensione .txt nel PWD
counter=0
for f in *.txt
do
	# controllo di avere permessi di lettura su <f>
	if test -r "$f"
	then
		# conto i titoli di interesse in <f>
		counter=`grep "$genere" "$f" | grep "$tipo" -c`

		# controllo se il file corrente è il file con più
		# titoli di interesse
		if test $counter -gt `cat $MAX_COUNTER`
		then
			echo "$f" > "$MAX_FILE"
			echo "$counter" > "$MAX_COUNTER"
		fi

		# se in <f> ci sono titoli di interesse, riporto
		# recensione, titolo, durata
		if test $counter -gt 0
		then
			grep "$genere" "$f" | grep "$tipo" | cut -d ',' -f 1,3,6 >> $HOME/risultati
		fi
	fi
done

# lancio la ricorsione
for d in *
do
	if test -d "$d" -a -x "$d"
	then
		esame_ric.sh "$genere" "$tipo" `pwd`/"$d"
	fi
done
