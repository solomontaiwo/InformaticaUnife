#!/usr/bin/env sh

# apro la directory

cd "$1"

# Cerco i file con estensione .txt sui quali ho diritto di lettura
# che contengono la stringa giochi nella prima riga
for i in *.txt
do
    if test -f "$i" -a -r "$i"
    then
        # file che abbiano come riga la stringa giochi
        if test `head -1 "$i"` = "giochi"
        then
            # memorizzo la path di $i
            echo "`pwd`/$i" >> "$TROVATO"
            nl=`wc -l < "$i"`
            # Controllo del massimo
            if test $nl -gt `cat "$MAX_COUNTER"`
            then
                echo $nl > "$MAX_COUNTER"
                echo "`pwd`/$i" > "$MAX_FILE"
            fi
        fi
    fi
done

# esploro ricorsivamente il sottoalbero definito da dir
for d in *
do
    if test -d "$d" -a -x "$d"
    then
        sh $0 "$d"
    fi
done
