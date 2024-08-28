#!/bin/sh

# controllo numero argomenti
if test $# -ne 2
then
	echo "errore: numero sbagliato di argomenti"
	echo "usage: cerca_misure <dir> <header>"
	exit 1
fi

dir="$1"
shift
header="$1"
shift

# controllo che <dir> sia nome assoluto
case $dir in
	/* )	;;
	* )	echo "errore: $dir non è nome assoluto"
		exit 2
		;;
esac

# controllo che <dir> sia una directory
if test ! -d $dir
then
	echo "errore: $dir non è una directory"
	exit 3
fi

# controllo che <dir> sia eseguibile
if test ! -x $dir
then
	echo "errore: non posso eseguire in $dir"
	exit 4
fi

# aggiorno la variabile PATH con la directory corrente
PATH=$PATH:`pwd`
export PATH

# creo il file temporaneo per tenere traccia la sottodirectory che
# contiente il maggior numero di file che soddisfano la condizione di
# ricerca
echo "" > /tmp/.dir.tmp
echo "0" > /tmp/.counter.tmp

# creo/sovrascrivo il file misure.txt in $HOME
echo "" > $HOME/misure.txt

sh cerca_misure_ric.sh $dir $header

cat /tmp/.dir.tmp
cat /tmp/.counter.tmp

rm -f /tmp/.dir.tmp
rm -f /tmp/.counter.tmp
