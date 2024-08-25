#!/bin/bash
# trova_errori dir

if test $# -ne 1
then
	echo "Uso: $0 <dir>"
	exit 1
fi

case $1 in
	/*) if test ! -d "$1" -o ! -x "$1"
	then
		echo $1 non è una directory o non si hanno i diritti di accesso
		exit 2
	fi;;
	*) echo $1 non è un path assoluto
		exit 3;;
esac

# Creo file di supporto e ne esporto nome assoluto per usarlo nella ricorsione
ERROR_FILE=$HOME/errori.txt; export ERROR_FILE
> $ERROR_FILE
WARNING_FILE=$HOME/warning.txt; export WARNING_FILE
> $WARNING_FILE

# Export del nuovo path e delle variabili contenenti i nomi dei file temporanei necessari per la ricerca
PATH=$PATH:`pwd`; export PATH
MAX_DIR=/tmp/.maxDir; export MAX_DIR; > $MAX_DIR
MAX_ERRORS=/tmp/.maxErrors; export MAX_ERRORS; echo 0 > $MAX_ERRORS

trova_errori_ric.sh "$1"

echo "La directory contenente il maggior numero di errori di compilazione è `cat $MAX_DIR` con `cat $MAX_ERRORS` errori totali."

rm $MAX_DIR
rm $MAX_ERRORS