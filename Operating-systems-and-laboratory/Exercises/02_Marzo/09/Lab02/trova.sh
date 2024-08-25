#!/bin/bash

if test $# != 2
then
    echo "Errore argomenti. Uso $0 <dir> <nomefile>"
    exit 1
fi

case $1 in
    /*) if test ! -d $1
        then
            echo "Errore. <dir> non è un direttorio"
            exit 2
        fi;;
    *) echo "Errore. <dir> non è un percorso assoluto"
       exit 3;;
esac

cd "$1"

for file in *
do
    if test -f "$file" -a "$file" = "$2"
    then
        echo "`pwd`/$file"
    fi

    if test -d "$file"
    then
        /Users/solomontaiwo/Documents/Sistemi-operativi/Esercizi/02_Marzo/09/Lab02/trova.sh `pwd`/$file $2
    fi
done