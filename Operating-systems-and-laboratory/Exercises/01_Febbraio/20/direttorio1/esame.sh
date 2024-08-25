#!/bin/sh

if test "$#" != 3
then
    echo "Errore: uso <estensione> <dir1> <dir2>"
    exit 1
fi

est="$1"
shift

case "$est" in
    .*) ;;
    *) echo "Errore: uso <estensione> ..."
    exit 2;;
esac

dir1="$1"
shift

case "$dir1" in 
    /*) ;;
    *) echo "Errore: uso ... <dir1> ..."
    exit 3;;
esac

if test ! -d "$dir1"
then
    echo "Errore: <dir1> non è un direttorio"
    exit 4
fi

dir2="$1"
shift

case "$dir2" in
    /*) ;;
    */) echo "Errore: uso ... ... <dir2>"
    exit 5
esac

if test ! -d "$dir2"
then
    echo "Errore: <dir2> non è un direttorio"
    exit 6
fi

PATH="$PATH":`pwd`
export PATH

esame_rec.sh "$est" "$dir1" "$dir2"