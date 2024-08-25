#!/bin/sh

if test "$#" != 2
then
    echo "Errore: uso <dir> <nomefile>"
    exit 1
fi

dir="$1"
file="$2"

case "$dir" in
    /*) ;;
    *) echo "Errore: <dir> deve essere un nome di directory assoluto"
    exit 2;;
esac

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
                echo "`pwd`/"$i""
            fi
        fi
    done
fi