#!/bin/bash
# interfaccia: esame nome anno

if test $# != 2
then
    echo "Errore argomenti: uso $0 <nome> <anno>"
    exit 1
fi

case $1 in
    /*) echo "Errore: <nome> deve essere una stringa"
        exit 2;;
    *);;
esac

case $2 in 
    /*) if test ! -d $2
        then
            echo "Errore: $2 non è un direttorio"
            exit 3
        fi;;
    *) echo "Errore: $2 deve essere un nome assoluto"
       exit 4;;
esac

export FILELOG="$HOME/fiumilog.txt"
> $FILELOG

export LIVELLOMIN="/tmp/.livellomin.txt"
echo 10000 > "$LIVELLOMIN"

export GIORNOMIN="/tmp/.giornomin.txt"
echo "" > "$GIORNOMIN"

export PATH=$PATH:`pwd`

esame_ric.sh $1 $2

echo "Giorno livello minimo: `cat $GIORNOMIN` (`cat $LIVELLOMIN` metri)"

rm -f $GIORNOFILE
rm -f $LIVELLOMIN