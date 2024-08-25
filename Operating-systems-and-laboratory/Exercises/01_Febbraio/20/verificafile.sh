#!/bin/sh

while test "$nome" != "fine"
do
    echo "Scrivi il nome del file: ('fine' per uscire): "
    read nome

    if test "$nome" = "fine"
    then
        continue
    fi

    if test -f "$nome"
    then
        echo ""$nome" è un file"
    else
        if test -d "$nome"
        then
            echo ""$nome" è un direttorio"
        else
            echo ""$nome" non esiste"
        fi
    fi
done