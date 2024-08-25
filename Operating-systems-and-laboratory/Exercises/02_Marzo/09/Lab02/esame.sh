#!/bin/bash
# esame estensione dir1 dir2

if test $# != 3
then
    echo "Errore argomenti. Uso $0 <estensione> <dir1> <dir2>"
    exit 1
fi

case $1 in
    .*) ;;
    *) echo "Errore. <estensione> non è un'estensione"
       exit 2
esac

est=$1
shift

case $1 in
    /*) if test ! -d "$1"
        then
            echo "Errore, <dir1> non è un direttorio"
            exit 3
        fi;;
    *) echo "Errore, <dir1> non è un percorso assoluto"
       exit 4;;
esac

dir1=$1
shift

case $1 in
    /*) if test ! -d "$1"
        then
            echo "Errore, <dir2> non è un direttorio"
            exit 5
        fi;;
    *) echo "Errore, <dir2> non è un percorso assoluto"
       exit 6;;
esac

dir2=$1
shift

export PATH=$PATH:`pwd`

esame_ric.sh "$est" "$dir1" "$dir2"

echo "Copiati `esame_ric.sh "$est" "$dir1" "$dir2" | wc -l` files"