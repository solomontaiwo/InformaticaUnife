#!/bin/sh

if test $# -ne 2
then
    echo "Errore: uso ./trova.sh <dir> <nomefile>"
    exit 1
fi

case $1 in
    /*) 
    if test ! -d $1
    then
        echo "Errore: <dir> non è un direttorio"
        exit 2
    fi;;
    *) echo "Errore: <dir> non è un percorso assoluto"
    exit 3;;
esac

dir=$1
file=$2

PATH=$PATH:`pwd`
export PATH

cd $dir

for i in *
do
    if test -f $i -a $i = $file
    then
        echo `pwd`/$i
    else
        if test -d $i
        then
            trova.sh `pwd`/$i $file
        fi
    fi
done