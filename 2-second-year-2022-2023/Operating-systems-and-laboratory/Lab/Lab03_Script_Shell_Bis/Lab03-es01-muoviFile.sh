#!/bin/sh
# muoviFile.sh num dirSorgente dirDestinazione ext1 ext2...extN

# CONTROLLO  ARGOMENTI
if test $# -lt 4
then
        echo uso: muoviFile num dirSorgente dirDestinazione ext1 ext2...extN
        exit 1
fi

case $1 in
        *[!0-9]*) echo uso: muoviFile num dirSorgente dirDestinazione ext1 ext2...extN
                echo num deve essere un numero
                exit 2;;
esac

num=$1
shift

case $1 in
        /*) if test ! -d $1
            then
                echo uso: muoviFile num dirSorgente dirDestinazione ext1 ext2...extN
                echo dirSorgente deve essere una directory
                exit 3
            fi;;
        *) echo uso: muoviFile num dirSorgente dirDestinazione ext1 ext2...extN
           echo dirSorgente deve essere un path assoluto
           exit 4;;
esac

sorg=$1
shift

case $1 in
        /*) if test ! -d $1
            then
                echo uso: muoviFile num dirSorgente dirDestinazione ext1 ext2...extN
                echo dirDestinazione deve essere una directory
                exit 5
            fi;;
        *) echo uso: muoviFile num dirSorgente dirDestinazione ext1 ext2...extN
           echo dirDestinazione deve essere un path assoluto
           exit 6;;
esac

dest=$1
shift

for ext in $*
do
        case $ext in
                .*) ;;
                *) echo uso: muoviFile num dirSorgente dirDestinazione ext1 ext2...extN
                   echo "I vari ext* devono essere delle estensioni (iniziare con '.')"
                   exit 7;;
        esac
done

# ESTENSIONE DEL PATH E CHIAMATA ALLO SCRIPT RICORSIVO
PATH=$PATH:`pwd` # aggiunge directory script corrente al PATH
export PATH # esporta il PATH

# creo un file temporaneo per salvare i risultati parziali
> /tmp/.counter.tmp

Lab03-es01-ricerca.sh $num "$sorg" "$dest" $*
echo `wc -l < /tmp/.counter.tmp`

rm -f /tmp/.counter.tmp
