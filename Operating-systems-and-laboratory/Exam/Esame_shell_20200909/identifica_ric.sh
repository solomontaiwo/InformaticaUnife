#!/usr/bin/env sh

# apro la directory

cd "$1"

# Cerco i file sui quali ho diritto di lettura
# che contengono il messaggio definito in $2
for i in *
do
    if test -f "$i" -a -r "$i"
    then
        # message counter
        mc=`grep -c "$2" "$i"`
        if test $mc -gt 0
        then
            echo "$mc,`pwd`/$i" >> "$TROVATI"
        fi

        # Controllo del massimo
        if test $mc -gt `cat /tmp/max_counter.tmp`
        then
            echo $mc > /tmp/max_counter.tmp
            echo "`pwd`/$i" > "$MAX"
        fi
    fi
done

# esploro ricorsivamente il sottoalbero definito da dir
for d in *
do
    if test -d "$d" -a -x "$d"
    then
        sh $0 "$d" "$2"
    fi
done
