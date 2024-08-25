#!/bin/sh

if test $# != 3
then 
    echo "Errore: uso <estensione> <dir1> <dir2>"
    exit 1
fi

est="$1"
dir1="$2"
dir2="$3"

case "$est" in
    .*) ;;
    *) echo "Errore: il primo argomento "$est" non è un'estensione"
    exit 2;;
esac

case "$dir1" in
    /*) ;;
    *) echo "Errore: il secondo argomento "$dir1" non è un direttorio"
    exit 3;;
esac

case "$dir2" in
    /*) ;;
    *) echo "Errore: il terzo argomento "$dir2" non è un direttorio"
    exit 4;;
esac

PATH=$PATH:`pwd`
export PATH
echo "Copiati `04_esame_rec.sh "$est" "$dir1" "$dir2" | wc -l` files"