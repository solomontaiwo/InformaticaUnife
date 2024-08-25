#!/bin/bash

while test "$nome" != fine
do
    echo "Scrivi il nome del file ('fine' per uscire): "
    read nome

    if test "$nome" = fine
    then
        continue
    fi
    
    if test -d "$nome"
    then
        echo "$nome è un direttorio"
    else 
        if test -f "$nome"
        then
            echo "$nome è un file"
        else
            echo "$nome" inesistente
        fi
    fi
done