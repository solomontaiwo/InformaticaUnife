#!/bin/sh

cd "$2"

for i in *.txt
do 
    if test -f "$i" -a -r "$i"
    then 
        # vado ad analizzare i dati richiesti
        ris=`grep "$1" "$i" | cut -f 1,3,5 -d ,`
        # se nel file di log ci sono informazioni
        # relative al fiume di interesse
        if test "$ris"
        then 
            # aggiungo le informazioni al file di log
            echo "$ris" >> "$FILELOG"
            # prelevo il livello idrometrico
            livello=`echo "$ris" | cut -f 1 -d ,`
            # se il valore riscontrato è più basso di quello trovato
            # finora allora lo aggiorno
            if test "$livello" -lt `cat "$LIVELLOMINIMO"`
                then 
                    echo "$livello" > "$LIVELLOMINIMO"
                    echo "$i" > "$GIORNOMINIMO"
                fi
        fi
    fi
    
done

for dir in *
do
    if test -d "$dir" -a -x "$dir" 
    then 
        sh esame_ric.sh "$1" "$dir"
    fi
done
