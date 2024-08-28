#!/bin/sh

while true
do
        # LETTURA PATTERN
        echo "Scrivi il nome del file (inserisci 'fine' per uscire)":
        read nomefile
        if test "$nomefile" = fine;
        then
                echo Ricevuta richiesta di terminazione.
                exit 0
        fi

        # RICERCA PATTERN
        if test -f "$nomefile"
        then
                echo $nomefile è un file
        else
                if test -d "$nomefile"
                then
                        echo "$nomefile è un direttorio"
                else
                        echo "$nomefile non esiste"
                fi
        fi

done
