#!/bin/bash
# esame genere tipo anno

if test $# != 3
then
    echo "Errore: numero argomenti. Uso $0 <genere> <tipo> <anno>"
    exit 1
fi

case $3 in
    /*) if test ! -d "$3"
        then
            echo "Errore: <anno> non è un direttorio"
            exit 2
        fi;;
    *) echo "Errore: <anno> non è un percorso assoluto"
       exit 3;;
esac

genere=$1
tipo=$2
anno=$3

PATH=$PATH:`pwd`
export PATH

RISULTATI="$HOME"/risultati.txt
export RISULTATI
> "$RISULTATI"

MESEMAGGIORIPUBBLICAZIONI=/tmp/mese_maggiori_pubblicazioni.txt
export MESEMAGGIORIPUBBLICAZIONI
echo "mese" > "$MESEMAGGIORIPUBBLICAZIONI"

MAGGIORINTERESSE=/tmp/maggior_interesse.txt
export MAGGIORINTERESSE
echo 0 > "$MAGGIORINTERESSE"

if test -e "$RISULTATI"
then
     > "$RISULTATI"
fi

esame_ric.sh "$genere" "$tipo" "$anno"

if test `cat $MAGGIORINTERESSE` -gt 0
then
    cat "$RISULTATI" | sort -r -n
    echo "Mese con maggior numero di risultati: `cat "$MESEMAGGIORIPUBBLICAZIONI"`"
else
    echo "Attenzione: nessun titolo di interesse trovato"
fi

rm -f $MESEMAGGIORIPUBBLICAZIONI
rm -f $MAGGIORINTERESSE