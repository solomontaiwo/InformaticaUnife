#!/bin/sh

while test "$nome" != "fine"
do
    echo "Scrivi il nome del file ('fine' per terminare): "
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
            echo ""$nome" inesistente"
        fi
    fi
done