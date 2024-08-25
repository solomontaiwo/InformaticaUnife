#!/bin/bash
# esame genere tipo anno

if test $# != 3
then 
	echo "Errore: numero argomenti. Uso $0 <genere> <tipo> <anno>"
	exit 1
fi

case $3 in
	/*) if test ! -d "$3"
		then
			echo "Errore: <anno> non è un direttorio"
			exit 2
		fi;;
	*) echo "Errore: <anno> non è un percorso assoluto"
	   exit 3;;
esac

export RISULTATI=$HOME/risultati.txt
> "$RISULTATI"

export MESEMAX=/tmp/mese_max.txt
> "$MESEMAX"

export PUBBLICAZIONIMAX=/tmp/pubblicazioni_max.txt
echo 0 > "$PUBBLICAZIONIMAX"

sh esame_ric.sh "$1" "$2" "$3"

cat "$RISULTATI" | sort -n -r
echo "Mese max pubblicazioni: `cat "$MESEMAX"`"

rm -f "$MESEMAX"
rm -f "$PUBBLICAZIONIMAX"
rm -f "$RISULTATI"