#!/bin/bash

if test $# -ne 1
then
	echo "Errore: uso $0 <dir>"
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

LIST_FILE=$HOME/script.txt; export LIST_FILE
touch $LIST_FILE

PATH=$PATH:`pwd`
export PATH

MAX_DIR=/tmp/.maxDir; export MAX_DIR; > $MAX_DIR
MAX_HIT=/tmp/.maxHit; export MAX_HIT; echo 0 > $MAX_HIT
trova_script_ric.sh "$1"

echo La directory contenente il maggior numero di script è `cat $MAX_DIR` con `cat $MAX_HIT` occorrenze totali.
rm $MAX_DIR
rm $MAX_HIT
