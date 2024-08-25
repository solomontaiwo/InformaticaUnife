#!/bin/sh 

# controllo numero argomenti
if test $# != 2
then
    echo "$0 <nome> <anno>"
    exit 1
fi

case $2 in
        /* ) if test ! -d "$2"
                then
                echo "$2 non è una directory "
                exit 2
            fi
            if test ! -x "$2"
                then
                echo "non ho i permessi per eseguire in $2"
                exit
            fi
            ;;
        * ) echo "$2 non ha una path assoluta!"
            exit 2
            ;;
esac

# aggiorno PATH
PATH=$PATH:`pwd`
export PATH

FILELOG="$HOME"/fiumilog.txt
export FILELOG

LIVELLOMINIMO=/tmp/livello_minimo.txt;
export LIVELLOMINIMO
echo 100000 > "$LIVELLOMINIMO"

GIORNOMINIMO=/tmp/giorno_minimo.txt;
export GIORNOMINIMO
> "$GIORNOMINIMO"

# elimino il file di log se esiste
if test -e "$FILELOG"
then 
    > "$FILELOG"
fi

sh esame_ric.sh "$1" "$2"

echo "Il minimo è stato riscontrato il giorno: `cat $GIORNOMINIMO`"
echo "Livello minimo riscontrato: `cat $LIVELLOMINIMO` metri"

rm -f "$LIVELLOMINIMO"
rm -f "$GIORNOMINIMO"
