#!/bin/bash

cd ~/importante/

fecha=$(date +%Y%m%d)

for i in */; do
    tar -cvzf /media/backup/"${i%/}_$fecha.tgz" "$i";
done

if [ $n_ficheros -eq 6 ]; then
    rm -r $(ls -tr /media/backup | head -1)
fi
