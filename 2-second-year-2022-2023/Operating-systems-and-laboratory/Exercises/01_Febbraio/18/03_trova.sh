#!/bin/sh

if test $# != 2
then 
    echo "Errore: uso <nomedirectory> <nomefile>"
    exit 1
fi

dir="$1"

case "$dir" in
    /*) ;;
    *) echo "Errore: il primo argomento deve essere una directory assoluta"
    exit 2;;
esac

if test ! -d "$dir"
then
   echo "Errore: il primo argomento deve essere una directory assoluta"
   exit 3
fi

file="$2"
PATH=$PATH:`pwd`
export PATH

if test -x "$dir"
then
    cd $dir
    for i in *
    do
        if test -d "$i"
        then
            trova.sh "`pwd`"/"$i" "$file"
        else
            if test -f "$i" -a "$i" = "$file"
            then
                echo `pwd`/$i
            fi
        fi
    done
fi