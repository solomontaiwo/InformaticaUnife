#!/bin/sh
# identifica_ric.sh dir messaggio

cd "$1"
max_conta=0

for file in *.txt
do
    if test -r "$file" -a -f "$file"
    then
        conta=`grep "$2" $file | wc -l`
        if test "$conta"
        then
            echo "$conta" "$file" >> $TROVATI
            if test "$conta" -gt "$max_conta"
            then
                max_conta=`echo $conta`
                echo "`pwd`/$file" > "$MAX"
            fi
        fi
    fi
done

for dir in *
do
    if test -d "$dir" -a -x "$dir"
    then
        identifica_ric.sh "$dir" "$2"
    fi
done