#!/bin/sh

while test "$nome" != "fine"
do
    echo "Inserisci un nome ('fine' per chiudere): "
    read -r nome

    if test "$nome" = fine
    then
        continue
    fi 

    if test -f "$nome"
    then
        echo "$nome" è un file
    else 
        if test -d "$nome"
        then
            echo "$nome" è un direttorio
        else
            echo "$nome" non esiste
        fi
    fi
done