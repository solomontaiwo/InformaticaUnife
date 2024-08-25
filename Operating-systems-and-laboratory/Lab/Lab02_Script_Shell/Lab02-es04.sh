#!/bin/sh
# CONTROLLO ARGOMENTI
# tre argomenti
if test $# != 3
then
        echo "Errore: numero errato di argomenti ($#)"
        exit 1
fi

# il primo argomento deve essere un'estensione
estensione="$1"
case $estensione in
        .*) ;;
        *) echo "Errore: il primo argomento deve iniziare con un '.'"
           exit 2;;
esac

# gli altri 2 argomenti devono essere nomi assoluti di direttori
dir1="$2"
case $dir1 in
        /*) ;;
        *) echo "Errore: il secondo argomento deve essere un nome assoluto"
           exit 3;;
esac

if test ! -d "$dir1"
then
        echo "Errore: il secondo argomento non è una directory"
        exit 4
fi

dir2="$3"
case $dir2 in
        /*) ;;
        *) echo "Errore: il terzo argomento deve essere un nome assoluto"
           exit 5;;
esac

if test ! -d "$dir2"
then
        echo "Errore: il terzo argomento non è una directory"
        exit 6
fi

# ESECUZIONE
PATH=$PATH:`pwd` # aggiunge directory script corrente al PATH
export PATH # esporta il PATH
echo "Copiati `Lab02-es04-copia_ric.sh $estensione $dir1 $dir2 | wc -l` files"
