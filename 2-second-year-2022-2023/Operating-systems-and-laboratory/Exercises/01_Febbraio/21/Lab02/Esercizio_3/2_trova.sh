#!/bin/sh

if test "$#" -ne 2
then
    echo "Errore: numero parametri"
    exit 1
fi

dir="$1"
shift

case "$dir" in
    /*) ;;
    *) echo "Errore: <dir> non è un directory assoluto"
    exit 2;;
esac

if test ! -d "$dir"
then
    echo "<dir> non è un direttorio"
    exit 3
fi

nomeFile="$1"
shift

PATH="$PATH":`pwd`
export PATH

if test -x "$dir"
then
    cd "$dir"
    for i in *
    do
        if test -f "$i" -a "$i" = "$nomeFile"
        then
            echo "`pwd`/"$i""
        else
            if test -d "$i"
            then
                2_trova.sh "`pwd`/"$i"" "$nomeFile"
            fi
        fi
    done
fi