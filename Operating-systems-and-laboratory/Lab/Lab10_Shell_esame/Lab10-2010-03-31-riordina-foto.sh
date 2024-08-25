#!/bin/bash

if test $# -ne 2
then
	echo "Errore: uso $0 <dir_sorgente> <dir_destinazione>" >&2
	exit 1
fi

if ! test -d $1
then
	echo "Errore: $1 non è una directory" >&2
	exit 2
fi

case $1 in
	/*) echo "Errore: $1 non è un percorso relativo" >&2
		exit 3;;
	*) ;;
esac

if ! test -d $2
then
	echo "Errore: $2 non è una directory" >&2
	exit 4
fi

case $2 in
	/*) echo "Errore: $2 non è un percorso relativo" >&2
		exit 5;;
	*) ;;
esac

if ! test -d $2/duplicati
then
	# creo la directory duplicati
	mkdir $2/duplicati
fi

PATH=$PATH:`pwd`
export PATH

> /tmp/spostati

Lab10-2010-03-31-riordina-foto-ric.sh $1 `pwd`/$2

echo "Ho spostato `wc -l /tmp/spostati` file."
rm -f /tmp/spostati
