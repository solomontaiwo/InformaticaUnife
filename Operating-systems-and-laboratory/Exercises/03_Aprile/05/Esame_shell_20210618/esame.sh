#!/bin/bash
# interfaccia: esame.sh genere tipo anno

if test $# != 3
then
    echo "Errore: uso $0 <genere> <tipo> <anno>"
    exit 1
fi

case $1 in
    /*) echo "Errore: <genere> deve essere una stringa, non un percorso assoluto"
        exit 2;;
    *) if test -d $1
       then
            echo "Errore: <genere> deve essere una stringa, non un direttorio"
            exit 3
        fi;;
esac

case $2 in
    /*) echo "Errore: <tipo> deve essere una stringa, non un percorso assoluto"
        exit 4;;
    *) if test -d $2
       then
            echo "Errore: <tipo> deve essere una stringa, non un direttorio"
            exit 5
        fi;;
esac

case $3 in
    /*) if test ! -d $3
        then
            echo "Errore: <anno> deve essere un direttorio"
            exit 6
        fi;;
    *) echo "Errore: <anno> deve essere un percorso assoluto, non una stringa"
       exit 7;;
esac

export PATH=$PATH:`pwd`

export RISULTATI=$HOME/risultati.txt
touch $RISULTATI

export MAXPUBBLICAZIONI=/tmp/max_pubblicazioni.txt
echo 0 > $MAXPUBBLICAZIONI

export MESEMAXPUBBLICAZIONI=/tmp/mese_max_pubblicazioni.txt
touch $MESEMAXPUBBLICAZIONI

esame_ric.sh $1 $2 $3

echo "`cat $RISULTATI | sort -n -r`"
echo "Mese con maggior numero di titolo: `cat $MESEMAXPUBBLICAZIONI` (`cat $MAXPUBBLICAZIONI` pubblicazioni)"

rm -f $RISULTATI
rm -f $MESEMAXPUBBLICAZIONI
rm -f $MAXPUBBLICAZIONI