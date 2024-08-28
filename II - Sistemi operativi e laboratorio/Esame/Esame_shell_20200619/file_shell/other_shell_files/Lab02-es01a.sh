#!/bin/sh

# verifico che l'utente abbia inserito una stringa diversa da "fine"
while test "$nome" != fine
do
        # LETTURA PATTERN
        echo "Scrivi il nome del file (inserisci 'fine' per uscire)":
        read nome

        if test "$nome" = fine
        then
                continue
        fi

        # RICERCA PATTERN
        if test -f "$nome"
        then
                echo $nome è un file
        else
                if test -d "$nome"
                then
                        echo $nome è un direttorio
                else
                        echo $nome non esiste
                fi
        fi
done
