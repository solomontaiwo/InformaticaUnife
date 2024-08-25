#!/bin/sh

# identifica_ric.sh dir messaggio

cd "$1"

for i in *
do 
    if [ -f "$i" -a -r "$i" ]
    then
        mc=$(grep -c "$2" "$i")
        if [ $mc -gt 0 ]
        then
            echo "$mc,$(pwd)/$i" >> "$TROVATI"
        fi

        if [ $mc -gt $(cat /tmp/max_counter.tmp) ]
        then
            echo $mc > /tmp/max_counter.tmp
            echo "$(pwd)/$i" > "$MAX"
        fi
    fi
done

for d in *
do
    if [ -d "$d" -a -x "$d" ]
    then
        $0 "$d" "$2"
    fi
done