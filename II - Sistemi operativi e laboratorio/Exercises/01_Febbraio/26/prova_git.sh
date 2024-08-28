#!/bin/sh

cd /Users/solomontaiwo/Documents/Sistemi-operativi/
mkdir tmp
cd tmp
echo "Questa è una prova" > prova_git.txt

for file in *
do
    git add . && git commit -m "Prova caricamento su git via script" && git push
    rm -f prova_git.txt
    git add . && git commit -m "Prova caricamento su git via script" && git push
done

rmdir /Users/solomontaiwo/Documents/Sistemi-operativi/tmp